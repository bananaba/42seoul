#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

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
		int const			_gradeToSign;
		int const			_gradeToExecute;

};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */