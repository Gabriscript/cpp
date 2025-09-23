#include "Bureaucrat.hpp"

	Bureaucrat::Bureaucrat()
	{
		std::cout << "New bureaucrat hired..." << std::endl;
	}

	Bureaucrat::Bureaucrat(Bureaucrat &bureaucrat) :
	 m_name(bureaucrat.m_name), m_grade(bureaucrat.m_grade)
	{
		std::cout << "Copy constructor called for " << m_name << std::endl;
	}

	Bureaucrat::Bureaucrat(const std::string name, int grade) :
	 	m_name(name)
	{
		if (grade > MINVALUE)
			throw GradeTooLowException();
		if (grade < MAXVALUE)
			throw GradeTooHighException();
		m_grade = grade;
		std::cout << m_name << ", bureaucrat grade " << m_grade<< std::endl;

	}

	Bureaucrat &Bureaucrat::operator=(const Bureaucrat  &bureaucrat)
	{
		if (this != &bureaucrat)
			m_grade = bureaucrat.getGrade();
		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
		os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
		return os;
	}

	Bureaucrat::~Bureaucrat()
	{
		std::cout << "Bureaucrat " << m_name << " has been fired." << std::endl;
	}

	std::string Bureaucrat::getName() const
	{
		return m_name;
	}

	int Bureaucrat::getGrade() const
	{
		return m_grade;

	}

	void Bureaucrat::Increase(int value)
	{
		if (value < 0)
			throw GradeIsNegative();
		if (getGrade() - value < MAXVALUE)
			throw GradeTooHighException();
		m_grade -= value; 
	}

	void Bureaucrat::Decrease(int value)
	{
		if (value < 0)
			throw GradeIsNegative();
		if (getGrade() + value > MAXVALUE)
			throw GradeTooLowException();
		m_grade += value; 
	}

	void Bureaucrat::signForm(Form &form)
	{
		try{
			form.beSigned(*this);
			std::cout << getName() << " signed " << form.getName() << std::endl;
		}
		catch (std::exception & e){
			std::cout << getName() << " couldn’t sign " 
			<< form.getName() << " because " << e.what() << std::endl;
		}
	}

	const char* Bureaucrat::GradeIsNegative::what() const noexcept {
		return "Grade must be a positive number.";
	}

	const char* Bureaucrat::GradeTooHighException::what() const noexcept {
		return "Grade is too high! Valid grades are 1-150.";
	}

	const char* Bureaucrat::GradeTooLowException::what() const noexcept {
		return "Grade is too low! Valid grades are 1-150.";
	}