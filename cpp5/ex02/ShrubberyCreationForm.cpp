#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): 
AForm("ShrubberyCreationForm", 145, 137) , m_target("standard")
{}
ShrubberyCreationForm::ShrubberyCreationForm(std::string &target): 
AForm("ShrubberyCreationForm", 145, 137) , m_target(target)
{}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
{
	*this = other;
}
ShrubberyCreationForm  &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if(this != &other)
		*this = other;
	return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{}
std::string  ShrubberyCreationForm::GetTarget() const
{
	return m_target;
}

static void TreeGenerator()
{
	size_t rows = 8;
	for (size_t i = 1; i <= rows; i++)
	{
		for (size_t j = 1; j <= rows - i; j++)
			std::cout << " ";
		for( size_t k = 0;k != 2 * i - 1;k++)
			std::cout << "*";

		std::cout << std::endl;
	}
	for (size_t r = 0; r <= rows / 4; r++) {
		for (size_t j = 1; j < rows - 1; j++) 
			std::cout << " ";

		std::cout << "|||" << std::endl;
}

	}
	void	ShrubberyCreationForm::execute(Bureaucrat const &executor)const
	{
		std::ofstream outFile(this->GetTarget() + "_shrubbery");
		TreeGenerator();
		(outFile).close();
		
	}