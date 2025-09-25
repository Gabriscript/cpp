
#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main() {
    Intern      someRandomIntern;
    Bureaucrat  ceo("CEO", 1); // ha grado alto, può firmare tutto
    AForm*      form;

    form = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form) {
        std::cout << *form << std::endl;
        ceo.signForm(*form);
        std::cout << *form << std::endl;
        delete form;
    }

    std::cout << "\n";

    form = someRandomIntern.makeForm("shrubbery creation", "Garden");
    if (form) {
        std::cout << *form << std::endl;
        ceo.signForm(*form);
        std::cout << *form << std::endl;
        delete form;
    }

    return 0;
}

