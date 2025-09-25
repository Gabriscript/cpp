#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
protected:
    AForm(std::string name, int signGrade, int execGrade);
private:
	std::string const m_name;
	bool m_signed = false;
	const int m_signGrade;
	const int m_executeGrade;
	AForm();
	
	public:
	AForm(const AForm &form);
	virtual ~AForm();
	AForm& operator=(const AForm  &form);


	std::string getName() const;
	int getSignGrade() const;
	int getExecuteGrade() const;
	bool isSigned() const;
	void beSigned(const Bureaucrat &b);

	virtual void execute(Bureaucrat const & executor) const = 0;	
	



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
	class FormNotSignedException : public std::exception
	{
		public:
			const char* what() const noexcept;
	};
};


std::ostream& operator<<(std::ostream& os, const AForm& form);


