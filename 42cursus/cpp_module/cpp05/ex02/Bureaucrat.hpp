#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class AForm;

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

		void		signForm(AForm & form);
		void 		executeForm(AForm const &form);

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