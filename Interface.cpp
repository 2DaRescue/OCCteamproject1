#include"Interface.h"
#include"DonorType.h"
#include"DonorList.h"
#include<iostream>
#include<string>


void displayMenu()
{
	std::cout << "*************************************************\n"
		<< "                    MAIN MENU\n" <<
		"*************************************************\n"
		<< "Select one of the following:\n\n    1. Add a donor\n"
		<< "    2. Delete a donor\n    3. Print all donors\n    4: To exit\n" << std :: endl;
		
}
void processSelection(DonorList& obj)
{
	int selection;
	std::string toContinue = "y";
	bool exit = false;
	while ((toContinue == "y") && !exit)
	{
		std::cout << "  => Enter your selection:" << std::endl;
		std::cin >> selection;
		switch (selection)
		{
		case 1:
			addDonor(obj);
			break;
		case 2:
			deleteDonor(obj);
			break;
		case 3:
			printAllDonors(obj);
			break;
		case 4:
			std::cout << "  => Thank you for visiting our site!" << std::endl;

			break;
		default:
			std::cout << " => Sorry. That is not a selection. " << std::endl;
		}
		if (!exit)
		{
			std::cout << " => Would you like to continue? (y/n)" << std::endl;
			std::cin >> toContinue;
			if (toContinue == "y")
			{
				displayMenu();
				
			}
			
		}
	}
}
void addDonor( DonorList& obj)
{
	std :: string firstName;
	std :: string LastName;
	int memberNumber;
	double dotation;
	std :: cout << "  => Enter donor's first name: " << std::endl;
	std :: cin >> firstName;
	std :: cout << "  => Enter donor's last name: " << std::endl;
	std :: cin >> LastName;
	std :: cout << "  => Enter donor's membership number: " << std::endl;
	std :: cin >> memberNumber;
	std :: cout << " => Enter amount donated: $ " << std::endl;
	std :: cin >> dotation;

	obj.addDonor(firstName, LastName, memberNumber, dotation);
	std :: cout << " => Donor has been added. \n";

}
void deleteDonor( DonorList& obj)
{
	int memberNumber;
	std::cout << "    => Enter donor's membership number: " << std::endl;
	std::cin >> memberNumber;
	if (obj.searchID(memberNumber))
	{
		obj.deleteDonor(memberNumber);
	}
	else
	{
		std::cerr << "Donor is not in the list." << std :: endl;
	}
}

void printAllDonors(DonorList& obj) 
{
	obj.printAllDonors();
}
