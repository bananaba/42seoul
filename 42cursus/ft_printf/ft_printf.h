/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 01:28:46 by balee             #+#    #+#             */
/*   Updated: 2022/03/26 18:55:17 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_info
{
	int		minus;
	int		zero;
	int		width;
	int		prec;
	int		length;
	int		plus;
	int		space;
	int		sharp;
	char	type;
}	t_info;

int		print_char(char c, t_info *info);
int		print_str(char *str, t_info *info);
int		print_decimal(long long d, t_info *info);
int		print_hexa_decimal(long long d, t_info *info);
int		find_figures(unsigned long long n, t_info *info, int d, int *zero_len);
void	print_space(int zero, int len);
void	print_nbr(unsigned long long n, t_info *info, int d);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *str);

#endif