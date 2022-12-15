/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:17:00 by balee             #+#    #+#             */
/*   Updated: 2022/12/15 16:17:01 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class Form;

class Bureaucrat
{

	public:

		Bureaucrat();
		Bureaucrat( Bureaucrat const & src );
		Bureaucrat(std::string const name);
		Bureaucrat(int const grade);
		Bureaucrat(std::string const name, int const grade);
		~Bureaucrat();

		Bureaucrat &		operator=( Bureaucrat const & rhs );

		class GradeTooLowException: public std::exception
		{
			public:
				const char*	what() const throw();
		};
		class GradeTooHighException: public std::exception
		{
			public:
				const char*	what() const throw();
		};

		void		signForm(Form & form);

		std::string	getName(void) const;
		int			getGrade(void) const;
		void		setName(std::string const name);
		void		setGrade(int grade);
		void		incrementGrade(void);
		void		decrementGrade(void);

	private:

		std::string const	_name;
		int					_grade;

};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );

#endif /* ****************************************************** BUREAUCRAT_H */