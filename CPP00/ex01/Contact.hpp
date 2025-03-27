#include <string>

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

class Contact
{
	public:
		bool		collect(void);
		void		print(void) const;
		void		copy(Contact contact);
		void		default_fill(void);
		void		idx_print(void) const;
		bool		empty() const;
		Contact(void);
		~Contact(void);

	private:
		std::string	firstname;
		std::string	lastname;
		std::string	nickname;
		std::string	phone;
		std::string	secret;
		bool		fill(std::string *);
};

#endif
