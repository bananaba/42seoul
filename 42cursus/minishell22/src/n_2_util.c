/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_2_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 02:48:04 by balee             #+#    #+#             */
/*   Updated: 2022/10/26 03:52:11 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//variable_expansion()
int		variable_expansion(t_list *token_start, t_list *envp);
int		variable_expansion_token(t_token *text_token, t_list *envp);
void	expande_str(char *buffer, char *str, t_list *envp);
int		expanded_lenght_of_str(char *str, t_list *envp);
char	*get_envp(char *str, t_list *envp);
int		ft_varlen(char *str);

int	ft_varlen(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '?')
		return (1);
	while (ft_isalnum(str[i]) || str[i] == '_')
		i++;
	return (i);
}
