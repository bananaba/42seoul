#ifndef INTERN_HPP
# define INTERN_HPP

# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{

	public:

		Intern();
		Intern( Intern const & src );
		~Intern();

		Intern &		operator=( Intern const & rhs );

		AForm	*makeForm(std::string Name, std::string Target);

		class UnknownForm : public std::exception
		{
		public:
			const char *what(void) const throw();
		};

	private:

		AForm	*form[3];

};

std::ostream &			operator<<( std::ostream & o, Intern const & i );

#endif /* ********************************************************** INTERN_H */