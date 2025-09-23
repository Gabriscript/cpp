#pragma once

#include <iostream>
#define MAXVALUE 1
#define MINVALUE 150

# include "Form.hpp"

class Form; 

class Bureaucrat
{
private:
	const std::string m_name = "Mario";
	int m_grade = 60;

public:
	Bureaucrat();
	Bureaucrat(Bureaucrat &bureaucrat);
	Bureaucrat& operator=(Bureaucrat const &bureaucrat);
	Bureaucrat(const std::string name, int grade);
	~Bureaucrat();

	std::string getName() const;
	int getGrade() const;
	void Increase(int value);
	void Decrease(int value);
	void signForm(Form &form);  

	class GradeTooHighException: public std::exception
	{
		public:
			const char* what() const noexcept;
	};
	
	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const noexcept;
	};
	class GradeIsNegative : public std::exception
	{
		public:
			const char* what() const noexcept;
	};


};
	std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);


