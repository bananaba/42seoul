#include "AForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AForm::AForm(): _name("default"), _target("none"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	// std::cout << "AForm Default Constructor called" << std::endl;
}

AForm::AForm( const AForm & src ): _gradeToSign(150), _gradeToExecute(150)
{
	// std::cout << "AForm copy Constructor called" << std::endl;
	*this = src;
}

AForm::AForm(std::string const name): _name(name), _target("none"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	// std::cout << "AForm Conversion constructor called" << std::endl;
}

AForm::AForm(std::string const name, std::string const target): _name(name), _target(target), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	// std::cout << "AForm Conversion constructor called" << std::endl;
}

AForm::AForm(int const gradeToSign, int const gradeToExecute): _name("default"), _target("none"), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	// std::cout << "AForm Normal constructor called" << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(std::string const name, int const gradeToSign, int const gradeToExecute): _name(name), _target("none"), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	// std::cout << "AForm Normal constructor called" << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(std::string const name, std::string const target, int const gradeToSign, int const gradeToExecute): _name(name), _target(target), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	// std::cout << "AForm Normal constructor called" << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AForm::~AForm()
{
	// std::cout << "AForm destructor called." << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AForm &				AForm::operator=( AForm const & rhs )
{
	// std::cout << "AForm Copy assignment operator called" << std::endl;
	if ( this != &rhs )
	{
		this->setName(rhs.getName());
		this->setSigned(rhs.getSigned());
		this->setGradeToSign(rhs.getGradeToSign());
		this->setGradeToExecute(rhs.getGradeToExecute());
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, AForm const & i )
{
	o << i.getName() << ", signed : " << i.getTarget() << ", signed : " << std::boolalpha
		<< i.getSigned() << std::noboolalpha << ", sign grade : " << i.getGradeToSign()
		<< ", execute grade : "<< i.getGradeToExecute() << ".";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}

const char *AForm::NotSignedException::what(void) const throw()
{
	return ("Not signed");
};

const char *AForm::TargetOpenFailException::what(void) const throw()
{
	return ("Target open fail");
};

void	AForm::beSigned(Bureaucrat const & rhs)
{
	if (this->getSigned() == true)
		std::cout << rhs.getName() << " couldn't sign " << this->getName()
			<< " because " << this->getName() << " already signed" << std::endl;
	else if (rhs.getGrade() > this->getGradeToExecute() || rhs.getGrade() > this->getGradeToSign())
		throw AForm::GradeTooLowException();
	else
	{
		this->setSigned(true);
		std::cout << rhs.getName() << " signed " << this->getName() << std::endl;
	}
		
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	AForm::getName(void) const
{
	return (this->_name);
}

std::string	AForm::getTarget(void) const
{
	return (this->_target);
}

bool		AForm::getSigned(void) const
{
	return (this->_signed);
}

int			AForm::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int			AForm::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

void		AForm::setName(std::string const name)
{
	const_cast<std::string &>(this->_name) = name;
}

void		AForm::setTarget(std::string const name)
{
	const_cast<std::string &>(this->_target) = name;
}

void		AForm::setSigned(bool sign)
{
	this->_signed = sign;
}

void		AForm::setGradeToSign(int const gradeToSign)
{
	if (gradeToSign < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150)
		throw AForm::GradeTooLowException();
	else
		const_cast<int &>(this->_gradeToSign) = gradeToSign;
}

void		AForm::setGradeToExecute(int const gradeToExecute)
{
	if (gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	else
		const_cast<int &>(this->_gradeToExecute) = gradeToExecute;
}


/* ************************************************************************** */