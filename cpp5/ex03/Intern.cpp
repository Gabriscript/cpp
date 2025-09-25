#include "Intern.hpp"
#include <map>

Intern::Intern() {}
Intern::Intern(const Intern &) {}
Intern &Intern::operator=(const Intern &) { return *this; }
Intern::~Intern() {}


static AForm *createPresidentialPardon(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

static AForm *createRobotomyRequest(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

static AForm *createShrubberyCreation(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

static AForm *SuccessForm(const std::string form, const std::string target, AForm*(*creator)(const std::string&))
{
    std::cout << "Intern creates " << form << std::endl;
    return creator(target);
}

static AForm *FailForm(const std::string form)
{
    std::cout << "Intern can not create a form called " << form << std::endl;
    return nullptr;
}

AForm *Intern::makeForm(const std::string form, const std::string target)
{
    std::map<std::string, AForm*(*)(const std::string&)> forms = {
        {"presidential pardon", createPresidentialPardon},
        {"robotomy request",    createRobotomyRequest},
        {"shrubbery creation",  createShrubberyCreation}
    };
    
    auto it = forms.find(form);
    return (forms.find(form) != forms.end()) ? 
    SuccessForm(form, target, it->second) : FailForm(form);
}