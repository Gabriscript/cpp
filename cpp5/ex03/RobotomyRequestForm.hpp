#pragma once
#include "AForm.hpp"
#include <fstream>

class AForm;

class RobotomyRequestForm : public AForm
{
	private:
		RobotomyRequestForm();
		std::string m_target;
	
	public:

		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm  &operator=(const RobotomyRequestForm &other);
		~RobotomyRequestForm();

		std::string  GetTarget() const;

		void execute(Bureaucrat const & executor) const;

    };

