#include "PhoneBook.hpp"
#include <iostream>
#include <limits>

PhoneBook::PhoneBook(void)
{
	//std::cout << "Constructor called: PhoneBook" << std::endl;
	this->i = 0;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	//std::cout << "Destructor called: PhoneBook" << std::endl;
	return ;
}

void	PhoneBook::add(Contact contact)
{
	if (this->i == 8)
		this->i = 0;
	this->tab[i].firstname = contact.firstname;
	this->tab[i].lastname = contact.lastname;
	this->tab[i].nickname = contact.nickname;
	this->tab[i].phone = contact.phone;
	this->tab[i].secret = contact.secret;
	this->i++;
}

void	format(std::string	str)
{
	int	n = str.length();

	std::cout << "|";
	while (n++ < 10)
		std::cout << " ";
	if (n > 10)
	{
		str = str.substr(0, 10);
		str[9] = '.';
	}
	std::cout << str;
}

void	PhoneBook::index(int i)
{
	std::cout << "         " << i;
	format(this->tab[i].firstname);
	format(this->tab[i].lastname);
	format(this->tab[i].nickname);
	std::cout << std::endl;
}

void	PhoneBook::search(void)
{
	int	i;

	if (this->tab[0].firstname.empty())
	{
		std::cout << "\033[34mYour PhoneBook is empty 😢\033[0m" << std::endl;
		return ;
	}
	std::cout << "\033[34m❤️ My top 8 friends ❤️" << std::endl;
	std::cout << "     index|first name| last name|  nickname" << std::endl;
	for (i = 0; i < 8; i++)
	{
		if (this->tab[i].firstname.empty())
			break ;
		this->index(i);
	}
	std::cout << "Enter the index:\033[0m" << std::endl;
	do
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> i;
	}
	while (std::cin.fail());
	this->tab[i].print();
}

void	PhoneBook::printall(void)
{
	if (this->tab[0].firstname.empty())
	{
		std::cout << "\033[34mYour PhoneBook is empty 😢\033[0m" << std::endl;
		return ;
	}
	std::cout << "❤️ My top 8 friends ❤️" << std::endl;
	for (int i = 0; i < 8; i++)
		this->tab[i].print();
}
