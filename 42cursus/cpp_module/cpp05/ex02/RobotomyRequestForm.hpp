#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <ctime>
# include "AForm.hpp"

class RobotomyRequestForm: public AForm
{

	public:

		RobotomyRequestForm();
		RobotomyRequestForm(std::string const target);
		RobotomyRequestForm( RobotomyRequestForm const & src );
		~RobotomyRequestForm();

		RobotomyRequestForm &		operator=( RobotomyRequestForm const & rhs );

		void	execute(Bureaucrat const &executor) const;
		void	robotomize(void) const;

	private:

};

std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i );

#endif /* ********************************************* ROBOTOMYREQUESTFORM_H */