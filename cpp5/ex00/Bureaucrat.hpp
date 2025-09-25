#pragma once

#include <iostream>


class Bureaucrat
{
private:
	const std::string m_name = "Mario";
	int m_grade = 15;

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


