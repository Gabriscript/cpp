#include "Form.hpp"


Form::Form(const Form &form) : m_name(form.m_name), m_signed(form.m_signed),
                                  m_signGrade(form.m_signGrade), m_executeGrade(form.m_executeGrade)
{
    std::cout << "Copy constructor called for " << m_name << std::endl;
}

Form &Form::operator=(const Form &form)
{
    if (this != &form)
        m_signed = form.isSigned();
    return *this;
}

Form::~Form()
{
    std::cout << "Form deleted..." << std::endl;
}

Form::Form(std::string name, int signGrade, int execGrade)
    : m_name(name), m_signed(false), m_signGrade(signGrade), m_executeGrade(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

std::string Form::getName() const
{
    return m_name;
}

int Form::getSignGrade() const
{
    return m_signGrade;
}

int Form::getExecuteGrade() const
{
    return m_executeGrade;
}

bool Form::isSigned() const
{
    return m_signed;
}

void Form::beSigned(const Bureaucrat &b)
{
    if (m_signed)
        throw FormAlreadySignedException();
    if (b.getGrade() > getSignGrade())
        throw GradeTooLowException();
    m_signed = true;
}

const char *Form::GradeTooHighException::what() const noexcept
{
    return "Form Grade is too high!";
}

const char *Form::GradeTooLowException::what() const noexcept
{
    return "Form Grade is too low!";
}

const char *Form::GradeIsNegativeException::what() const noexcept
{
    return "Form Grade must be a positive number.";
}

const char *Form::FormAlreadySignedException::what() const noexcept
{
    return "Form signed already.";
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    std::string sign = form.isSigned() ? "✅" : "❌";
    os << "Form: " << form.getName()
       << "\nSign Grade: " << form.getSignGrade()
       << "\nExec Grade: " << form.getExecuteGrade()
       << "\nSigned: " << sign;
    return os;
}