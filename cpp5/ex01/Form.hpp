#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	std::string const m_name = "Jack";
	bool m_signed = false;
	const int m_signGrade = 50;
	const int m_executeGrade = 50;
	
public:
	Form();
	Form(const Form &form);
	Form& operator=(const Form  &form);
	~Form();

	Form(std::string name, int signGrade, int execGrade);

	std::string getName() const;
	int getSignGrade() const;
	int getExecuteGrade() const;
	bool isSigned() const;
	void beSigned(const Bureaucrat &b);
	



	class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const noexcept;
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const noexcept;
		};
		class GradeIsNegativeException : public std::exception
		{
			public:
				const char* what() const noexcept;
		};
		class FormAlreadySignedException : public std::exception
		{
			public:
				const char* what() const noexcept;
		};
};


std::ostream& operator<<(std::ostream& os, const Form& form);
