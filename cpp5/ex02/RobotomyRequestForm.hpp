#pragma once
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		RobotomyRequestForm();
	
	public:

		RobotomyRequestForm(std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm  &operator=(const RobotomyRequestForm &other);
		~RobotomyRequestForm();

		std::string  GetTarget() const;

		void execute(Bureaucrat const & executor) const;
};