/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:21:56 by balee             #+#    #+#             */
/*   Updated: 2022/11/27 21:21:57 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACER_HPP
# define REPLACER_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <sstream>

void	replaceStr(std::string &content, std::string s1, std::string s2);
int		exitErr(std::string str);

#endif
