/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_3_2_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 02:48:04 by balee             #+#    #+#             */
/*   Updated: 2022/10/26 06:27:54 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		variable_expansion(t_list *token_start, t_list *envp);
int		variable_expansion_token(t_token *text_token, t_list *envp);
void	expande_str(char *buffer, char *str, t_list *envp);
int		expanded_lenght_of_str(char *str, t_list *envp);
char	*get_envp(char *str, t_list *envp);
int		ft_varlen(char *str);

int	variable_expansion(t_list *token_start, t_list *envp)
{
	t_list	*now;
	t_token	*now_token;

	now = token_start;
	while (now)
	{
		now_token = (t_token *) now->content;
		if (DEBUG)
			print_token(now_token, "now_token", 0);
		if (now_token->type == "text"[0]
			|| now_token->type == "double_quote"[0])
		{
			if (variable_expansion_token(now_token, envp))
			{
				ft_lstclear(&token_start, (void (*)(void *))destroy_token);
				return (1);
			}
		}
		if (DEBUG)
			print_token(now_token, "processed_token", 1);
		now = now->next;
	}
	return (0);
}

int	variable_expansion_token(t_token *text_token, t_list *envp)
{
	char	*str;
	char	*result;
	int		len;

	str = text_token->text;
	result = 0;
	len = expanded_lenght_of_str(str, envp);
	if (0 <= len)
	{
		result = ft_calloc(sizeof(char), len + 31);
		if (result)
		{
			expande_str(result, str, envp);
			free(str);
			text_token->text = result;
			return (0);
		}
	}
	return (1);
}

void	expande_str(char *buffer, char *str, t_list *envp)
{
	int		i;
	int		temp_len;
	char	*temp_str;

	i = 0;
	while (str[i])
	{
		temp_len = ft_strlen_c(&str[i], '$');
		ft_strlcat(buffer, &str[i], ft_strlen(buffer) + temp_len + 1);
		i += temp_len;
		if (str[i])
			i++;
		temp_str = get_envp(&str[i], envp);
		if (DEBUG)
			ft_printf("\ttemp_str = %s\n", temp_str);
		if (temp_str)
		{
			ft_strlcat(buffer, temp_str,
				ft_strlen(buffer) + ft_strlen(temp_str) + 1);
		}
		i += ft_varlen(&str[i]);
	}
}

int	expanded_lenght_of_str(char *str, t_list *envp)
{
	char	*t;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			t = get_envp(&str[++i], envp);
			if (t)
			{	
				len += ft_strlen(t);
			}
			i += ft_varlen(&str[i]);
		}	
		else
		{
			len++;
			i++;
		}
	}
	return (len);
}

char	*get_envp(char *str, t_list *envp)
{
	t_list	*now;

	now = envp;
	while (now)
	{
		if (ft_strncmp(str, now->content,
				int_max(ft_strlen_c(now->content, '='), ft_varlen(str))) == 0)
		{
			return (ft_strchr(now->content, '=') + 1);
		}
		now = now->next;
	}
	return (0);
}
