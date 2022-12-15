/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:17:08 by balee             #+#    #+#             */
/*   Updated: 2022/12/15 16:17:09 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{

	public:

		Form();
		Form( Form const & src );
		Form(std::string const name);
		Form(int const gradeToSign, int const gradeToExecute);
		Form(std::string const name, int const gradeToSign, int const gradeToExecute);
		~Form();

		Form &		operator=( Form const & rhs );

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

		void	beSigned(Bureaucrat const & rhs);

		std::string	getName(void) const;
		bool		getSigned(void) const;
		int			getGradeToSign(void) const;
		int			getGradeToExecute(void) const;
		void		setName(std::string const name);
		void		setSigned(bool sign);
		void		setGradeToSign(int const gradeToSign);
		void		setGradeToExecute(int const gradeToExecute);

	private:

		std::string const	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;

};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */