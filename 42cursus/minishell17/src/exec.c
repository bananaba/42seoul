#include "minishell.h"

void	exec_proc(t_e *ex, char **argv, char **envp, int **pipes)
{
	dup2(pipes[0][0], STDIN_FILENO);
	dup2(pipes[1][1], STDOUT_FILENO);
	if (errno != 0)
	{
		printf("Error: ");
		printf("%s : ", argv[0]);
		if (errno == 127)
			printf("%s\n", "command not found");
		else
			printf("%s\n", strerror(errno));
		exit(errno);
	}
	if (check_builtin(argv[0]))
		exit(0);
	execve(argv[0], argv, envp);
	exit(errno);
}

void	do_builtin(t_mp *mp, char **argv, int **pipes)
{
	int		len;

	len = ft_strlen(argv[0]);
	if (ft_strncmp(argv[0], "cd", len))
		ft_cd(mp, argv[1]);
//	else if (ft_strncmp(argv[0], "exit", len))
//		ft_exit();
	else if (ft_strncmp(argv[0], "unset", len))
		ft_unset(mp, &argv[1]);
	else if (ft_strncmp(argv[0], "export", len))
		ft_export(mp, &argv[1], pipes);
	else if (ft_strncmp(argv[0], "pwd", len))
		ft_pwd(mp, pipes);
	else if (ft_strncmp(argv[0], "env", len))
		ft_env(mp, pipes);
	else if (ft_strncmp(argv[0], "echo", len))
		ft_echo(mp, &argv[1], pipes);
}

pid_t	run_proc(t_mp *mp, t_e *excutable, int **pipes)
{
	char	**envp;
	char	**argv;
	pid_t	pid;

	if (check_builtin(excutable->argv[0]))
		do_builtin(mp, excutable->argv, pipes);
	else
	{
		argv = set_argv(mp, excutable->argv);
		envp = set_envp(mp, argv[0]);
	}
	pid = fork();
	if (pid == 0)
		exec_proc(excutable, argv, envp, pipes);
	free_arg_env(argv, envp);
	mp->error_flag = errno;
	return (pid);
}

void	set_recent_exit_code(t_mp *mp)
{
	char	*str[3];

	str[1] = ft_itoa(mp->recent_exit_code);
	str[0] = ft_strdup("?");
	add_env(mp->envp, str);
	free(str[1]);
	free(str[0]);
}

int	run(t_mp *mp)
{
	int		i;
	int		status;
	int		**pipes;
	pid_t	pid;

	if (mp->error_flag != 0)
		return (mp->error_flag);
	i = -1;
	pipes = init_pipe(mp->runnable);
	set_pipes(mp->runnable, pipes);
	while (mp->runnable->excutables[++i])
	{
		errno = 0;
		close(pipes[i][1]);
		pid = run_proc(mp, mp->runnable->excutables[i], &pipes[i]);
		if (mp->error_flag)
			break ;
		waitpid(pid, &status, 0);
		close(pipes[i][0]);
		mp->recent_exit_code = WEXITSTATUS(status);
		set_recent_exit_code(mp);
	}
	pipes = free_pipes(pipes, i);
	return (errno);
}
