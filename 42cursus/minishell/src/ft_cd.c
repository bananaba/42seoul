/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:54:17 by balee             #+#    #+#             */
/*   Updated: 2022/10/27 23:35:22 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*set_dir(char *dir, char *home, char *pwd, char *oldpwd)
{
	char	*temp;
	char	*ret;

	if (dir == NULL)
		ret = mc_strdup(home);
	else if (dir[0] == '~')
		ret = mc_strjoin(home, &dir[1]);
	else if (dir[0] == '-' && dir[1] == 0 && oldpwd == NULL)
		ret = mc_strdup(pwd);
	else if (dir[0] == '-' && dir[1] == 0)
		ret = mc_strdup(oldpwd);
	else if (dir[0] == '/')
		ret = mc_strdup(dir);
	else
	{
		temp = mc_strjoin("/", dir);
		ret = mc_strjoin(pwd, temp);
		mc_free(temp);
	}
	return (ret);
}

void	set_value(t_mp *mp, char *target, char *value)
{
	t_list	*envp;
	int		len;

	envp = mp->envp;
	len = ft_strlen(target);
	while (envp != NULL)
	{
		if (ft_strncmp(envp->content, target, len - 1) == 0
			&& (((char *)envp->content)[len] == '='
			|| ((char *)envp->content)[len] == 0))
		{
			mc_free(envp->content);
			envp->content = value;
			return ;
		}
		envp = envp->next;
	}
	ft_lstlast(mp->envp)->next = ft_lstnew(value);
}

void	ft_cd(t_mp *mp, char *dir)
{
	char	*home;
	char	*pwd;
	char	*oldpwd;
	char	*new;

	home = find_value(mp, "HOME=");
	pwd = find_value(mp, "PWD=");
	if (pwd == NULL)
		pwd = mc_getcwd();
	oldpwd = find_value(mp, "OLDPWD=");
	new = set_dir(dir, home, pwd, oldpwd);
	if (chdir(new) == 0)
	{
		mc_free(new);
		new = mc_getcwd();
		set_value(mp, "OLDPWD=", mc_strjoin("OLDPWD=", pwd));
		set_value(mp, "PWD=", mc_strjoin("PWD=", new));
	}
	mc_free(new);
	mc_free(home);
	mc_free(pwd);
	mc_free(oldpwd);
}
