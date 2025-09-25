#pragma once
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		ShrubberyCreationForm();
		std::string m_target;
	
	public:

		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm  &operator=(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm();

		std::string  GetTarget() const;

		void execute(Bureaucrat const & executor) const;
};



