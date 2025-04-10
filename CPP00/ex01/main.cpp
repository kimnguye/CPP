#include <iostream>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int		main()
{
	PhoneBook	repertoire;
	Contact		contact;
	std::string command;

    std::cout << "\033[34m🎉📞 Welcome to your PhoneBook 📞🎉\033[0m" << std::endl;
    std::cout <<std::endl << "\033[34mWhat can I do for you today ?\033[0m" << std::endl;
	while (42)
	{
		std::cin >> command;
		if (!command.compare("EXIT"))
			break ;
		else if (!command.compare("ADD"))
		{
			std::cout << "\033[34mLet's add your new friend! 😊\033[0m" << std::endl;
			contact.collect();
			repertoire.add(contact);
			std::cout << "\033[34mNew friend has been added ✅\033[0m" << std::endl;
		}
		else if (!command.compare("SEARCH"))
			repertoire.search();
	}
	std::cout << "\033[34m👋📞 Goodbye! 📞👋\033[0m" << std::endl;
	return 0;
}

//std::cout << "\033[34mDo you want to ADD, SEARCH or EXIT ?\033[0m" << std::endl;
