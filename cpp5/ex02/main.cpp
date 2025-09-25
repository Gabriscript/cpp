
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    std::cout << "==== PresidentialPardonForm ====" << std::endl;
    {
        Bureaucrat assistant("Assistant", 140);
        Bureaucrat ceo("CEO", 4);
        PresidentialPardonForm form("Donation Form");

        std::cout << form << std::endl;

        assistant.signForm(form);
        std::cout << form << std::endl;

        ceo.signForm(form);
        std::cout << form << std::endl;

        ceo.executeForm(form);
        std::cout << std::endl;
    }

    std::cout << "==== RobotomyRequestForm ====" << std::endl;
    {
        Bureaucrat employee("Employee", 100);
        Bureaucrat manager("Manager", 40);
        RobotomyRequestForm form("Bender");

        std::cout << form << std::endl;

        employee.signForm(form);
        std::cout << form << std::endl;

        manager.signForm(form);
        std::cout << form << std::endl;

        for (int i = 0; i < 5; i++)
            manager.executeForm(form);
        std::cout << std::endl;
    }

    std::cout << "==== ShrubberyCreationForm ====" << std::endl;
    {
        Bureaucrat worker("Worker", 150);
        Bureaucrat gardener("Gardener", 100);
        ShrubberyCreationForm form("garden");

        std::cout << form << std::endl;

        worker.signForm(form);
        std::cout << form << std::endl;

        gardener.signForm(form);
        std::cout << form << std::endl;

        gardener.executeForm(form);
        std::cout << std::endl;
    }

    return 0;
}
