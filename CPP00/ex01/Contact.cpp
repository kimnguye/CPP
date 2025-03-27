#include "Contact.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact(void)
{
	this->firstname = "";
	this->lastname = "";
	this->nickname = "";
	this->phone = "I don't have his phone number 😳";
	this->secret = "I cannot tell you 🤫";
	return;
}
Contact::~Contact(void)
{
	return;
}

void	Contact::print(void) const
{
	std::cout << "\033[34m";
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "First name: \033[0m" << firstname << std::endl;
	std::cout << "\033[34mLast name: \033[0m" << lastname << std::endl;
	std::cout << "\033[34mNickname: \033[0m" << nickname << std::endl;
	std::cout << "\033[34m📞: \033[0m" << phone << std::endl;
	std::cout << "\033[34m🤫 Big secret: \033[0m" << secret << std::endl;
	std::cout << "\033[0m";
}

bool	Contact::empty() const
{
	if (firstname.empty())
		return true;
	return false;
}

void	reformat(std::string	str)
{
	int	n = str.length();

	std::cout << "|";
	std::cout << std::setfill (' ') << std::setw (10);
	if (n > 10)
	{
		str = str.substr(0, 10);
		str[9] = '.';
	}
	std::cout << str;
}

void	Contact::idx_print() const
{
	reformat(firstname);
	reformat(lastname);
	reformat(nickname);
}

void	Contact::default_fill()
{
	firstname = "No";
	lastname = "New friend";
	nickname = "BFF";
}

void	Contact::copy(Contact contact)
{
	this->firstname = contact.firstname;
	this->lastname = contact.lastname;
	this->nickname = contact.nickname;
	this->phone = contact.phone;
	this->secret = contact.secret;
}

/*return false if ctrl-D*/
bool	Contact::fill(std::string *str)
{
	do
	{
		std::getline(std::cin, *str);
		if (std::cin.eof())
			return false;
	}
	while ((*str).empty());
	return true;
}

/*return true if collect was OK, false if ctrl-D*/
bool	Contact::collect(void)
{
	std::cin.ignore();
	std::cout << "\033[34mWhat is your friend name?\033[0m" << std::endl;
	if (!fill(&firstname))
		return false;
	std::cout << "\033[34mWhat is \033[0m" << firstname << " \033[34mlast name?\033[0m" << std::endl;
	if (!fill(&lastname))
		return false;
	std::cout << "\033[34mGive \033[0m" << firstname<< " "<< lastname<<" \033[34ma nickname\033[0m" << std::endl;
	if (!fill(&nickname))
		return false;
	std::cout << "\033[34mWhat is his phone number ? 📞\033[0m" << std::endl;
	if (!fill(&phone))
		return false;
	std::cout << "\033[34mWhat is \033[0m" << nickname << " \033[34mdarkest secret ? 👀\033[0m" << std::endl;
	if (!fill(&secret))
		return false;
	return true;
}
