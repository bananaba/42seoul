/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:23:20 by snoh              #+#    #+#             */
/*   Updated: 2022/10/26 03:20:46 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

/*# include <errno.h>*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/*PART 1*/
/*	p1_issomething*/
int			ft_isalpha(int ch);
int			ft_isdigit(int ch);
int			ft_isalnum(int ch);
int			ft_isascii(int ch);
int			ft_isprint(int ch);

int			ft_isspace(int ch);
int			ft_isquote(int ch);
/*	p1_tosomething*/
int			ft_toupper(int ch);
int			ft_tolower(int ch);

/*	p1_strsomething_1*/
size_t		ft_strlen(const char *str);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_strchr(const char *str, int ch);
char		*ft_strrchr(const char *str, int ch);

size_t		ft_strlen_c(const char *str, char c);
size_t		ft_strlen_s(const char *str, char *set);

/*	p1_strsomething_2*/
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_atoi(const char *str);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);

/*	p1_memsomething*/
void		*ft_memset(void *b, int c, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);

/*	p1_mallocsomething*/
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strdup(const char *s1);

/*PART2*/
/*	p2_somethin_1*/
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);

/*	p2_ft_split*/
char		**ft_split(char const *s, char c);

/*	p2_something_2*/
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));

/*	p2_something_3*/
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

/*bonus*/
/*	b_lstsomething_1_bonus*/
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);

/*	b_lstsomething_2_bonus*/
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* addition */
t_list		*ft_lstnth(t_list *p, int index);
void		*ft_lstadd_next(t_list *node, t_list *new);
void		ft_lstdel_next(t_list *lst, void (*del)(void *));
t_list		*ft_lstpop_nth(t_list *p, int index);
t_list		*ft_lstpop_nth_p(t_list **lst, int index);
/* for ft_printf	*/
int			ft_printf(const char *str, ...);
int			ft_eprintf(const char *str, ...);
int			ft_sprintf(char *dst, const char *str, ...);
char		*ft_mprintf(const char *str, ...);
void		ft_str_nreplace(char **s1, char *s2, int len2);
void		ft_str_djoin(char **s1, char *s2, int len2);
char		*ft_strdupc(char s1, char const *s2);

/* addition */
int			int_max(int a, int b);
int			int_min(int a, int b);

#endif
