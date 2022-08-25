#include "../includes/pipex.h"

void	check_err(int err)
{
	if (err == 0 && errno == 0)
		return ;
	else if (err != 0 && errno != err)
		errno = err;
	perror("Error");
	exit(errno);
}

void	child_process(t_pipex *pipex, char **envp, int i, int cmd_num)
{
	if (i == 0)
		dup2(pipex->infile, STDIN_FILENO);
	else
		dup2(pipex->fd[i - 1][0], STDIN_FILENO);
	if (i == cmd_num)
		dup2(pipex->outfile, STDOUT_FILENO);
	else
		dup2(pipex->fd[i][1], STDOUT_FILENO);
	close_all(pipex);
	execve(pipex->cmd[i][0], pipex->cmd[i], envp);
	check_err(errno);
}

void	link_pipe(int cmd_num, t_pipex *pipex)
{
	int i;

	i = 0;
	pipex->fd = (int **)malloc(sizeof(int *) * (cmd_num));
	check_err(errno);
	while (i < cmd_num - 1)
	{
		pipex->fd[i] = (int *)malloc(sizeof(int) * 2);
		check_err(errno);	
		pipe(pipex->fd[i]);
		check_err(errno);
		i++;
	}
	pipex->fd[i] = NULL;
}

void	make_pipe(int cmd_num, char **envp, t_pipex *pipex)
{
	pid_t	pid;
	int		i;
//	int		status;

	i = 0;
	link_pipe(cmd_num, pipex);
	while (i < cmd_num)
	{
		pid = fork();
		if (pid < 0)
			check_err(errno);
		else if (pid == 0)
			child_process(pipex, envp, i, cmd_num - 1);
	//	waitpid(pid, &status, 0);
		i++;
	}
}

void	close_all(t_pipex *pipex)
{
	int	i;

	i = 0;
	close(pipex->infile);
	close(pipex->outfile);
	while (pipex->fd[i] != NULL)
	{
		close(pipex->fd[i][0]);
		close(pipex->fd[i][1]);
		free(pipex->fd[i]);
		pipex->fd[i] = NULL;
	}
	free(pipex->fd);
	pipex->fd = NULL;
}

void	free_all(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i] != NULL)
		free(ptr[i++]);
	free(ptr);
}

void	safe_exit(t_pipex *pipex)
{
	int	i;

	i = 0;
	close_all(pipex);
	free_all(pipex->path);
	while (pipex->cmd[i] != NULL)
		free_all(pipex->cmd[i++]);
	free(pipex->cmd);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc < 5)
		check_err(8);
	parse(argc - 1, argv, envp, &pipex);
	set_cmd(&pipex);
	pipex.infile = open(argv[1], O_RDONLY);
	pipex.outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	make_pipe(argc - 3, envp, &pipex);
	safe_exit(&pipex);
	system("leaks pipex");
	return (0);
}