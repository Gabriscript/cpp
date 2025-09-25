#pragma once

#include <iostream>

#include "AForm.hpp"

class AForm; 

class Bureaucrat
{
private:
	const std::string m_name;
	int m_grade;

public:
    Bureaucrat();
    Bureaucrat(const std::string name, int grade);
    Bureaucrat(const Bureaucrat &bureaucrat);
    Bureaucrat &operator=(const Bureaucrat &bureaucrat);
    ~Bureaucrat();

	std::string getName() const;
	int getGrade() const;
	void Increase(int value);
	void Decrease(int value);
	void signForm(AForm &form);  

	void executeForm(AForm const & form);

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


