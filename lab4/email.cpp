#include "email.h"

Email::Email(const std::string & _sender, const std::string & _date,
		const std::string & _subject)
	: sender(_sender), date(_date), subject(_subject)
{
}

std::ostream & operator<<(std::ostream & os, const Email & email)
{
	os << email.sender << ", " << email.date << ", " << email.subject;
	return os;
}

bool CompWhoDateSubject::operator()(const Email & lhs, const Email & rhs) const
{
	if(lhs.sender < rhs.sender) return true;
	else if(lhs.sender == rhs.sender)
	{
		if(lhs.date < rhs.date) return true;
		else if(lhs.date == rhs.date) 
		{
			if(lhs.subject < rhs.subject) return true;
		}
	}
	return false;
}

bool CompDateWhoSubject::operator()(const Email & lhs, const Email & rhs) const
{
	if(lhs.date < rhs.date) return true;
	else if(lhs.date == rhs.date)
	{
		if(lhs.sender < rhs.sender) return true;
		else if(lhs.sender == rhs.sender) 
		{
			if(lhs.subject < rhs.subject) return true;
		}
	}
	return false;
}

bool CompSubjectWhoDate::operator()(const Email & lhs, const Email & rhs) const
{
	if(lhs.subject < rhs.subject) return true;
	else if(lhs.subject == rhs.subject)
	{
		if(lhs.sender < rhs.sender) return true;
		else if(lhs.sender == rhs.sender) 
		{
			if(lhs.date < rhs.date) return true;
		}
	}
	return false;
}

