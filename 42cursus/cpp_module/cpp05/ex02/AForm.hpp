#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{

	public:

		AForm();
		AForm( AForm const & src );
		AForm(std::string const name);
		AForm(std::string const name, std::string const target);
		AForm(int const gradeToSign, int const gradeToExecute);
		AForm(std::string const name, int const gradeToSign, int const gradeToExecute);
		AForm(std::string const name, std::string const target, int const gradeToSign, int const gradeToExecute);
		virtual	~AForm();

		AForm &		operator=( AForm const & rhs );

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
		class NotSignedException: public std::exception
		{
			public:
				const char*	what() const throw();
		};
		class TargetOpenFailException: public std::exception
		{
			public:
				const char*	what() const throw();
		};

		void			beSigned(Bureaucrat const & rhs);
		virtual void	execute(Bureaucrat const &executor) const = 0;

		std::string	getName(void) const;
		std::string	getTarget(void) const;
		bool		getSigned(void) const;
		int			getGradeToSign(void) const;
		int			getGradeToExecute(void) const;
		void		setName(std::string const name);
		void		setTarget(std::string const name);
		void		setSigned(bool sign);
		void		setGradeToSign(int const gradeToSign);
		void		setGradeToExecute(int const gradeToExecute);

	private:

		std::string const	_name;
		std::string const	_target;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;

};

std::ostream &			operator<<( std::ostream & o, AForm const & i );

#endif /* ************************************************************ AForm_H */