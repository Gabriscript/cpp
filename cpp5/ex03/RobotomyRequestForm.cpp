#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() 
: AForm("RobotomyRequestForm", 72, 45), m_target("standard")
{
}
RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
 : AForm("RobotomyRequestForm", 72, 45), m_target(target)
{
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), m_target(other.m_target) {}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
        *this = other;
    return *this;
}
RobotomyRequestForm::~RobotomyRequestForm()
{
}
std::string RobotomyRequestForm::GetTarget() const
{
    return m_target;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!this->isSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getExecuteGrade())
        throw Bureaucrat::GradeTooLowException();

    int randomNumber = rand() % 2;
    (randomNumber % 2 == 0) ? 
    std::cout << "Makes some drilling noises: " << this->GetTarget() << " has been robotomized" << std::endl 
    : std::cout << "robotomy failed" << std::endl;
}



