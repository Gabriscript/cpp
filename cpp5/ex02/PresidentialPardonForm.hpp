#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		PresidentialPardonForm();
	
	public:

		PresidentialPardonForm(std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm  &operator=(const PresidentialPardonForm &other);
		~PresidentialPardonForm();

		std::string  GetTarget() const;

		void execute(Bureaucrat const & executor) const;
};