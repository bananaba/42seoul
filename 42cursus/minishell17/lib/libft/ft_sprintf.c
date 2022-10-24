/* ************************************************************************** */
/*	                                                                          */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:33:45 by snoh              #+#    #+#             */
/*   Updated: 2022/05/21 11:16:10 by snoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "ft_printf.h"

static	void	split_into_lists(t_list **lst, const char *format_string);
static	int		ft_sprintf_lst_flush(t_list *lst, char *dst);
static	void	*convert_conversion(void *pstr);

static va_list	g_ap;
static char		*g_cov_lst = "cspdiuxX%";
static char		*(*g_fp[10])(char *, va_list *) = {convert_c, \
	convert_s, convert_p, convert_d, convert_i, convert_u, \
	convert_x, convert_large_x, convert_percent, 0};

int		ft_sprintf(char *dst, const char *str, ...)
{
	t_list	*format_str;
	t_list	*printable_str;
	int		r;

	r = 0;
	va_start(g_ap, str);
	format_str = 0;
	printable_str = 0;
	split_into_lists(&format_str, str);
	if (ft_printf_lstcheck(format_str))
	{
		printable_str = ft_lstmap(format_str, convert_conversion, free);
		if (ft_printf_lstcheck(printable_str))
		{
			r = ft_sprintf_lst_flush(printable_str, dst);
		}
		ft_lstclear(&printable_str, free);
	}
	ft_lstclear(&format_str, free);
	va_end(g_ap);
	return (r);
}

static int ft_sprintf_lst_flush(t_list *lst, char *dst)
{
	t_list	*p;
	int		count;
	int		len;

	count = 0;
	p = lst;
	while (p)
	{
		len = ft_strlen(((char *) p->content) + 1);
		if (((char *) p->content)[0] == 'c')
			len = 1;
		if (len)
			count += len;
		p = p->next;
	}
	count = 0;
	p = lst;
	while (p)
	{
		len = ft_strlen(((char *) p->content) + 1);
		ft_strlcpy(&dst[count], (char *) p->content + 1, len + 1);
		if (len)
			count += len;
		p = p->next;
	}
	return (count);
}

static	void	split_into_lists(t_list **lst, const char *format_string)
{
	const char	*cur;
	const char	*nxt;

	cur = format_string;
	while (cur[0])
	{
		nxt = ft_strchr(cur, '%');
		if (!nxt)
			return (ft_lstadd_back(lst, ft_lstnew(ft_strdup(cur))));
		if (nxt - cur != 0)
			ft_lstadd_back(lst, ft_lstnew(ft_substr(cur, 0, nxt - cur)));
		if (ft_strchr(g_cov_lst, nxt[1]) && nxt[1])
			ft_lstadd_back(lst, ft_lstnew(ft_substr(nxt, 0, 2)));
		else
			return (ft_lstclear(lst, free));
		cur = nxt + 2;
	}
}

static	void	*convert_conversion(void *pstr)
{
	char	*str;
	char	*r;
	char	*r2;

	str = (char *) pstr;
	if (str[0] == '%')
	{
		if (ft_strchr(g_cov_lst, str[1]))
		{
			r = g_fp[ft_strchr(g_cov_lst, str[1]) - g_cov_lst](pstr, &g_ap);
			r2 = 0;
			if (r)
			{
				r2 = ft_strdupc(str[1], r);
				free(r);
			}
			return (r2);
		}
	}
	else
	{
		return (ft_strdupc('s', str));
	}
	return (0);
}
