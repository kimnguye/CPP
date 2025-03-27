#include "PhoneBook.hpp"
#include <iostream>
#include <limits>
#include <iomanip>

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
	this->tab[i].copy(contact);
	this->i++;
}


void	PhoneBook::index(int i) const
{
	std::cout << std::setfill (' ') << std::setw (10);
	std::cout << i;
	tab[i].idx_print();
	std::cout << std::endl;
}

void	PhoneBook::search(void) const
{
	int	i;

	if (this->tab[0].empty())
	{
		std::cout << "\033[34mYour PhoneBook is empty 😢\033[0m" << std::endl;
		return ;
	}
	std::cout << "\033[34m❤️ My top 8 friends ❤️" << std::endl;
	std::cout << "     index|first name| last name|  nickname" << std::endl;
	for (i = 0; i < 8; i++)
	{
		if (this->tab[i].empty())
			break ;
		this->index(i);
	}
	std::cout << "Enter the index:\033[0m" << std::endl;
	while (42)
	{
		std::cin >> i;
		if (!std::cin.fail() && !std::cin.eof() && i >= 0 && i <= 7)
			break;
		std::cout << "\033[34m❌ Incorrect index! Try again:\033[0m" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	if (this->tab[i].empty())
		std::cout << "\033[34mCannot find the contact 😔\033[0m" << std::endl;
	else
		this->tab[i].print();
}

void	PhoneBook::fill(void)
{
	Contact		contact;

	contact.default_fill();
	for (int i = 0; i < 8; i++)
		this->add(contact);
	std::cout << "\033[34mPhoneBook is full of friends 🤩\033[0m" << std::endl;
}

void	PhoneBook::printall(void) const
{
	if (this->tab[0].empty())
	{
		std::cout << "\033[34mYour PhoneBook is empty 😢\033[0m" << std::endl;
		return ;
	}
	std::cout << "❤️ My top 8 friends ❤️" << std::endl;
	for (int i = 0; i < 8; i++)
		this->tab[i].print();
}
