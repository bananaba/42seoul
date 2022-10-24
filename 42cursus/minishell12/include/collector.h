/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snoh <snoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:42:31 by snoh              #+#    #+#             */
/*   Updated: 2022/10/01 21:40:03 by snoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLECTOR_H
# define COLLECTOR_H
# include "libftprintf.h"
# include <limits.h>


// The smallest unit in which a process runs
// matched with 1 process
typedef struct s_memory_box
{
	int		cur;
	void	*tape[10000];

}t_mbox;

typedef struct s_memory_function_box
{
	int		cur;
	void	*tape[20000];

}t_mfbox;


/*Memory Manage*/
void	*collector(t_mbox *box, void *pointer);
//void	*collector_f(t_mbox *box, void *pointer, void *destroyer);

#endif	