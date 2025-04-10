#include "Contact.hpp"
#include <iostream>

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

void	Contact::print(void)
{
	if (this->firstname.empty())
	{
		std::cout << "\033[34mCannot find the contact 😔\033[0m" << std::endl;
		return ;
	}
	std::cout << "\033[34m";
	std::cout << "first name: " << this->firstname << std::endl;
	std::cout << "last name: " << this->lastname << std::endl;
	std::cout << "nickname: " << this->nickname << std::endl;
	std::cout << "📞 " << this->phone << std::endl;
	std::cout << "🤫 " << this->secret << std::endl;
	std::cout << "\033[0m";

}

void	Contact::collect(void)
{
	std::cin.ignore();
	std::cout << "\033[34mWhat is your friend name?\033[0m" << std::endl;
	do
		std::getline(std::cin, this->firstname);
	while (this->firstname.empty());
	std::cout << "\033[34mWhat is \033[0m" << this->firstname << " \033[34mlast name?\033[0m" << std::endl;
	do
		std::getline(std::cin, this->lastname);
	while (this->lastname.empty());
	std::cout << "\033[34mGive \033[0m" << this->firstname<< " "<< this->lastname<<" \033[34ma nickname\033[0m" << std::endl;
	do
		std::getline(std::cin, this->nickname);
	while (this->nickname.empty());
	std::cout << "\033[34mWhat is his phone number ? 📞\033[0m" << std::endl;
	do
		std::getline(std::cin, this->phone);
	while (this->phone.empty());
	std::cout << "\033[34mWhat is \033[0m" << this->nickname << " \033[34mdarkest secret ? 👀\033[0m" << std::endl;
	do
		std::getline(std::cin, this->secret);
	while (this->secret.empty());
}
