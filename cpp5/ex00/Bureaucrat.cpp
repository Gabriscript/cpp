#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
    std::cout << "New bureaucrat hired..." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
    : m_name(bureaucrat.m_name), m_grade(bureaucrat.m_grade)
{
    std::cout << "Copy constructor called for " << m_name << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : m_name(name)
{
    if (grade > 150)
        throw GradeTooLowException();
    if (grade < 0)
        throw GradeIsNegative();
    if (grade < 1)
        throw GradeTooHighException();
    m_grade = grade;
    std::cout << m_name << ", bureaucrat grade " << m_grade << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
    if (this != &bureaucrat)
        m_grade = bureaucrat.getGrade();
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
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
    if (getGrade() - value < 1)
        throw GradeTooHighException();
    m_grade -= value;
}

void Bureaucrat::Decrease(int value)
{
    if (value < 0)
        throw GradeIsNegative();
    if (getGrade() + value > 150)
        throw GradeTooLowException();
    m_grade += value;
}


const char *Bureaucrat::GradeIsNegative::what() const noexcept
{
    return "Grade must be a positive number.";
}

const char *Bureaucrat::GradeTooHighException::what() const noexcept
{
    return "Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const noexcept
{
    return "Grade is too low!";
}
