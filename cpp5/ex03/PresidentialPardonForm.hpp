#pragma once
#include "AForm.hpp"
#include "fstream"

class PresidentialPardonForm : public AForm
{
	private:
		PresidentialPardonForm();
        std::string m_target;
	
	public:

		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm  &operator=(const PresidentialPardonForm &other);
		~PresidentialPardonForm();

		std::string  GetTarget() const;

		void execute(Bureaucrat const & executor) const;
};
