#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), m_target("standard")
{
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), m_target(target)
{
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
: AForm(other), m_target(other.m_target) {}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
        *this = other;
    return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}
std::string ShrubberyCreationForm::GetTarget() const
{
    return m_target;
}

static void TreeGenerator(std::ostream &out)
{
    size_t rows = 8;
    for (size_t i = 1; i <= rows; i++)
    {
        for (size_t j = 1; j <= rows - i; j++)
            out << " ";
        for (size_t k = 0; k != 2 * i - 1; k++)
            out << "*";
        out << std::endl;
    }
    for (size_t r = 0; r <= rows / 4; r++)
    {
        for (size_t j = 1; j < rows - 1; j++)
            out << " ";
        out << "|||" << std::endl;
    }
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!this->isSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getExecuteGrade())
        throw Bureaucrat::GradeTooLowException();

    std::ofstream outFile(this->GetTarget() + "_shrubbery");
    if (!outFile)
        throw std::runtime_error("Could not open file");

    TreeGenerator(outFile);
    outFile.close();
}

