/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmc.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:42:31 by snoh              #+#    #+#             */
/*   Updated: 2022/10/27 22:49:57 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMC_H
# define LIBMC_H
# include "libftprintf.h"
# include "minishell.h"

typedef struct s_mem_box
{
	void	**array;
	int		capacity;
	int		size;
}	t_mem_box;

void	*memorybox(char *method, void *arg);
void	*make_box(t_mem_box *box, int capacity);
void	*add_arg_in_box(t_mem_box *box, void *arg);
void	*del_arg_in_box(t_mem_box *box, void *arg);
void	*pop_nth_from_box(t_mem_box *box, int index);
int		find_index(t_mem_box *box, void *arg);
void	*dest_box(t_mem_box *box);
int		make_box_bigger(t_mem_box *box);
int		is_box_full(t_mem_box *box);

void	*mc_malloc(size_t size);
void	mc_free(void *pointer);
int		mc_freeint(void *pointer);

void	*mc_calloc(size_t count, size_t size);
char	*mc_itoa(int n);
void	mc_lstclear(t_list **lst, void (*del)(void *));
void	mc_lstdelone(t_list *lst, void (*del)(void *));
t_list	*mc_lstnew(void *content);

char	**mc_split(char const *s, char c);
void	*mc_split_free(char **splited);

char	*mc_strdup(const char *s1);
char	*mc_strjoin(char const *s1, char const *s2);

char	*mc_getcwd(void);

#endif