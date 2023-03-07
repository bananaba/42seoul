#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct s_list
{
	char			**cmd;
	int				count;
	int				type;
	int				pipe[2];
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	if (str == NULL)
		return (0);
	while (str[len])
		len++;
	return (len);
}

void	print_err(char *str)
{
	if (str != NULL)
		write(2, str, ft_strlen(str));
}

void	exit_fatal(void)
{
	print_err("error: fatal\n");
	exit(1);
}

char	*ft_strdup(char *str)
{
	int		i;
	int		len;
	char	*new;

	len = ft_strlen(str);
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		exit_fatal();
	i = 0;
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = 0;
	return (new);
}

void	add_arg(t_list *lst, char *argv)
{
	char	**temp;
	int		i;

	i = 0;
	temp = (char **)malloc(sizeof(char *) * (lst->count + 2));
	if (temp == NULL)
		exit_fatal();
	while (i < lst->count)
	{
		temp[i] = lst->cmd[i];
		i++;
	}
	if (lst->count != 0)
		free(lst->cmd);
	lst->cmd = temp;
	lst->cmd[i++] = ft_strdup(argv);
	lst->cmd[i] = 0;
	lst->count++;
}

t_list	*last_list(t_list **lst)
{
	t_list	*temp;

	temp = *lst;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

void	list_push(t_list **lst, char *argv)
{
	t_list	*new;
	t_list	*temp;

	new = (t_list *)malloc(sizeof(t_list));
	new->cmd = NULL;
	new->type = 0;
	new->count = 0;
	new->next = NULL;
	if (*lst == NULL)
	{
		new->prev = NULL;
		*lst = new;
	}
	else
	{
		temp = last_list(lst);
		temp->next = new;
		new->prev = temp;
	}
	add_arg(new, argv);
}

void	parse_arg(t_list **lst, char *argv)
{
	int	is_break;

	is_break = 0;
	if (strcmp(";", argv) == 0)
		is_break = 1;
	if (is_break && !*lst)
		return ;
	else if (is_break)
		last_list(lst)->type = 2;
	else if (strcmp("|", argv) == 0 && !*lst)
		return ;
	else if (strcmp("|", argv) == 0)
		last_list(lst)->type = 1;
	else if (!*lst || last_list(lst)->type != 0)
		list_push(lst, argv);
	else
		add_arg(last_list(lst), argv);
}

int	exec_cmd(t_list *lst, char **env)
{
	pid_t	pid;
	int		ret;
	int		status;

	if (lst->type == 1)
		if (pipe(lst->pipe))
			exit_fatal();
	pid = fork();
	if (pid < 0)
		exit_fatal();
	else if (pid == 0)
	{
		if (lst->prev && lst->prev->type == 1)
			dup2(lst->prev->pipe[0], 0);
		if (lst->type == 1)
			dup2(lst->pipe[1], 1);
		if (execve(lst->cmd[0], lst->cmd, env))
			exit_fatal();
	}
	else
	{
		if (lst->prev && lst->prev->type == 1)
		{
			close(lst->prev->pipe[0]);
			close(lst->prev->pipe[1]);
		}
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			ret = WEXITSTATUS(status);
	}
	return (ret);
}

int	exec_cmds(t_list **lst, char **env)
{
	int	ret;
	t_list	*temp;

	ret = 0;
	temp = *lst;
	while (temp)
	{
		if (strcmp("cd", temp->cmd[0]) == 0)
		{
			ret = 0;
			if (temp->count != 2)
			{
				print_err("error: cd: bad arguments\n");
				ret = 1;
			}
			else if (chdir(temp->cmd[1]) != 0)
			{
				print_err("error: cd: cannot change directory to ");
				print_err(temp->cmd[1]);
				print_err("\n");
				ret = 1;
			}
		}
		else
			ret = exec_cmd(temp, env);
		temp = temp->next;
	}
	return (ret);
}

int	main(int argc, char **argv, char **env)
{
	t_list	*lst;
	int		i;
	int		ret;

	lst = NULL;
	i = 1;
	while(i < argc)
		parse_arg(&lst, argv[i++]);
	if (lst)
		ret = exec_cmds(&lst, env);
}