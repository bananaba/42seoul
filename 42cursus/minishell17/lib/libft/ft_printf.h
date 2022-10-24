/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:23:20 by snoh              #+#    #+#             */
/*   Updated: 2022/05/20 16:17:20 by snoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libftprintf.h"

/* for ft_printf	*/
char	*convert_c(char *str, va_list *ap);
char	*convert_s(char *str, va_list *ap);
char	*convert_p(char *str, va_list *ap);
char	*convert_d(char *str, va_list *ap);
char	*convert_i(char *str, va_list *ap);
char	*convert_u(char *str, va_list *ap);
char	*convert_x(char *str, va_list *ap);
char	*convert_large_x(char *str, va_list *ap);
char	*convert_percent(char *str, va_list *ap);
int		ft_printf_lstcheck(t_list *lst);
#endif
