#ifndef MAILBOX_H
#define MAILBOX_H

#include "email.h"

#include <vector>
#include <algorithm>

class MailBox
{
public:
	using Iterator = std::vector<Email>::iterator;
	using ConstIterator = std::vector<Email>::const_iterator;

	MailBox(size_t _size = 0);

	void push(const Email & email);

	void sortWho();
	void sortDate();
	void sortSubject();

	Email & operator[](size_t index);
	const Email & operator[](size_t index) const;

	size_t size() const;

	Iterator begin();
	ConstIterator begin() const;
	Iterator end();
	ConstIterator end() const;

private:
	std::vector<Email> m_mail;
};

#endif
