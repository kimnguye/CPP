#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

#include "Contact.hpp"

class	PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	add(Contact contact);
		void	search(void) const;
		void	fill(void);
		void	printall(void) const;
	private:
		int		i;
		Contact tab[8];
		void	index(int i) const;
};

#endif
