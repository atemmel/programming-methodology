#include "mailbox.h"

using Iterator = std::vector<Email>::iterator;
using ConstIterator = std::vector<Email>::const_iterator;

MailBox::MailBox(size_t _size)
	: m_mail(_size)
{
}

void MailBox::push(const Email & email)
{
	m_mail.push_back(email);
}

void MailBox::sortWho()
{
	CompWhoDateSubject predicate;
	std::sort(m_mail.begin(), m_mail.end(), predicate);
}

void MailBox::sortDate()
{
	CompDateWhoSubject predicate;
	std::sort(m_mail.begin(), m_mail.end(), predicate);
}

void MailBox::sortSubject()
{
	CompSubjectWhoDate predicate;
	std::sort(m_mail.begin(), m_mail.end(), predicate);
}

Email & MailBox::operator[](size_t index)
{
	return m_mail[index];
}

const Email & MailBox::operator[](size_t index) const
{
	return m_mail[index];
}

size_t MailBox::size() const 
{
	return m_mail.size();
}


Iterator MailBox::begin()
{
	return m_mail.begin();
}

ConstIterator MailBox::begin() const
{
	return m_mail.begin();
}

Iterator MailBox::end()
{
	return m_mail.end();
}

ConstIterator MailBox::end() const
{
	return m_mail.end();
}
