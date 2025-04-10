#include <string>

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

class Contact
{
	public:
		std::string	firstname;
		std::string	lastname;
		std::string	nickname;
		std::string	phone;
		std::string	secret;
		void		collect(void);
		void		print(void);
		Contact(void);
		~Contact(void);
};

#endif
