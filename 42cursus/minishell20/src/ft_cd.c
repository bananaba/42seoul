/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:54:17 by balee             #+#    #+#             */
/*   Updated: 2022/10/25 03:32:59 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*set_dir(char *dir, char *home, char *pwd, char *oldpwd)
{
	char	*temp;

	if (dir == NULL)
		dir = ft_strdup(home);
	else if (dir[0] == '~')
	{
		temp = ft_strjoin(home, &dir[1]);
		free(dir);
		dir = temp;
	}
	else if (dir[0] == '-' && dir[1] == 0 && oldpwd == NULL)
		dir = ft_strdup(pwd);
	else if (dir[0] == '-' && dir[1] == 0)
		dir = ft_strdup(oldpwd);
	else if (dir[0] != '/')
	{
		temp = ft_strjoin("/", dir);
		free(dir);
		dir = ft_strjoin(pwd, temp);
		free(temp);
	}
	return (dir);
}

void	set_value(t_mp *mp, char *target, char *value)
{
	int		i;
	t_list	*envp;

	envp = mp->envp;
	while (envp != NULL)
	{
		if (ft_strncmp(envp->content, target, ft_strlen(target)) == 0)
		{
			free(envp->content);
			envp->content = value;
		}
		envp = envp->next;
	}
}

void	ft_cd(t_mp *mp, char *dir)
{
	char	*home;
	char	*pwd;
	char	*oldpwd;

	home = find_value(mp, "HOME=");
	pwd = find_value(mp, "PWD=");
	oldpwd = find_value(mp, "OLDPWD=");
	dir = set_dir(dir, home, pwd, oldpwd);
	if (chdir(dir) == 0)
	{
		free(dir);
		dir = getcwd(NULL, 0);
		set_value(mp, "OLDPWD", ft_strjoin("OLDPWD=", pwd));
		set_value(mp, "PWD=", ft_strjoin("PWD=", dir));
	}
	if (home)
		free(home);
	free(pwd);
	if (oldpwd)
		free(oldpwd);
	free(dir);
}
