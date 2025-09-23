#include "Form.hpp"

	AForm::AForm()
	{
		std::cout << "New form created..." << std::endl;
	}

	AForm::AForm(const AForm &form) : m_name(form.m_name), m_signed(form.m_signed), 
	m_signGrade(form.m_signGrade), m_executeGrade(form.m_executeGrade)
	{
		std::cout << "Copy constructor called for " << m_name << std::endl;
	}

	AForm& AForm::operator=(const AForm  &form)
	{
		if (this != &form)
			m_signed = form.isSigned();
		return *this;
	}

	AForm::~AForm()
	{
		std::cout << "Form deleted..." << std::endl;
	}

	AForm::AForm(std::string name, int signGrade, int execGrade) : m_name(name),
	 m_signGrade(signGrade), m_executeGrade(execGrade)
	{
	if(signGrade < 0 || execGrade < 0)
		throw GradeIsNegativeException();
	if(signGrade > MINVALUE || execGrade > MINVALUE)
		throw GradeTooLowException();
	if(signGrade < MAXVALUE || execGrade < MAXVALUE)
		throw GradeTooHighException();
	}

	std::string AForm::getName() const
	{
		return m_name;
	}

	int AForm::getSignGrade() const
	{
		return m_signGrade;
	}

	int AForm::getExecuteGrade() const
	{
		return m_executeGrade;
	}

	bool AForm::isSigned() const
	{
		return m_signed;
	}

	void AForm::beSigned(const Bureaucrat &b)
	{
		if(m_signed)
			throw FormAlreadySignedException();
		if(b.getGrade() > getSignGrade())
			throw GradeTooLowException();
	   	 m_signed = true;
	}

	const char* AForm::GradeTooHighException::what() const noexcept {
		return "Form Grade is too high! Valid grades are 1-150.";
	}

	const char* AForm::GradeTooLowException::what() const noexcept {
		return "Form Grade is too low! Valid grades are 1-150.";
	}

	const char* AForm::GradeIsNegativeException::what() const noexcept {
		return "Form Grade must be a positive number.";
	}

	const char* AForm::FormAlreadySignedException::what() const noexcept {
		return "Form signed already";
	}

	std::ostream& operator<<(std::ostream& os, const AForm& form)
	{
		std::string sign = "❌";
		if (form.isSigned())
			sign = "✅";
	os << "Form: " << form.getName()
	<< "\nSign Grade: " << form.getSignGrade()
	<< "\nExec Grade: " << form.getExecuteGrade()
	<<"\nSigned: " << sign;
	return os; 

	}