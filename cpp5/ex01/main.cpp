#include "Form.hpp"


int main(){

	std::cout << "\n" << std::endl;
    
    try {
     
        std::cout << "\n\t--- Test 1: Creating a valid form ---" << std::endl;
        Form taxForm("Tax Form", 100, 50);
        std::cout << taxForm << std::endl;
        
      
        std::cout << "\n\t--- Test 2: Creating bureaucrats ---" << std::endl;
        Bureaucrat highRanking("Peach", 10); 
        Bureaucrat lowRanking("Mario", 120); 
        
        
      
        std::cout << "\n\t--- Test 3: High ranking bureaucrat signs form ---" << std::endl;
        highRanking.signForm(taxForm);
        std::cout << taxForm << std::endl;
        
    
        std::cout << "\n\t--- Test 4: Trying to sign an already signed form ---" << std::endl;
        highRanking.signForm(taxForm);
        

        std::cout << "\n\t--- Test 5: Low ranking bureaucrat tries to sign high-grade form ---" << std::endl;
        Form donationForm("Donation Form", 50, 25);
        lowRanking.signForm(donationForm);
        std::cout << donationForm << std::endl;
        
        
        std::cout << "\n\t--- Test 6: Low ranking bureaucrat signs suitable form ---" << std::endl;
        Form simpleForm("Simple Form", 140, 140);
        lowRanking.signForm(simpleForm);
        std::cout << simpleForm << std::endl;
        
     
        std::cout << "\n\t--- Test 7: Creating invalid forms ---" << std::endl;
        std::cout << "Attempting to create form with grade 0:" << std::endl;
        try {
            Form invalidForm1("Invalid Form", 0, 50);
        } catch (std::exception &e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
        
        std::cout << "Attempting to create form with grade 151:" << std::endl;
        try {
            Form invalidForm2("Invalid Form", 100, 151);
        } catch (std::exception &e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
		
		
		std::cout << "\n\t--- Test 8: Promote bob for Donation Form ---" << std::endl;
		lowRanking.Increase(100);
		std::cout << lowRanking << std::endl;
		lowRanking.signForm(donationForm);
		std::cout << std::endl;
        
    } catch (std::exception &e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }
    
    return 0;

	
	
}