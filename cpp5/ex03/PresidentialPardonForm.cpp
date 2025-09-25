#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), m_target("standard")
{
}
PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), m_target(target)
{
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
: AForm(other), m_target(other.m_target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
        *this = other;
    return *this;
}
PresidentialPardonForm::~PresidentialPardonForm()
{
}
std::string PresidentialPardonForm::GetTarget() const
{
    return m_target;
}
void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (!this->isSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getExecuteGrade())
        throw Bureaucrat::GradeTooLowException();

    std::cout << this->GetTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

