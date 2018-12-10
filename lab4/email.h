#ifndef EMAIL_H
#define EMAIL_H

#include <string>
#include <iostream>

struct CompWhoDateSubject;
struct CompDateWhoSubject;
struct CompSubjectWhoDate;

struct Email
{
	Email(const std::string & _sender = "", const std::string & _date = "",
			const std::string & _subject = "");
		
	friend std::ostream & operator<<(std::ostream & lhs, const Email & rhs);

	friend struct CompWhoDateSubject;
	friend struct CompDateWhoSubject;
	friend struct CompSubjectWhoDate;

private:
	std::string sender;
	std::string date;
	std::string subject;

};

std::ostream & operator<<(std::ostream & os, const Email & email);

struct CompWhoDateSubject 
{
	bool operator()(const Email & lhs, const Email & rhs) const;
};

struct CompDateWhoSubject
{
	bool operator()(const Email & lhs, const Email & rhs) const;
};

struct CompSubjectWhoDate
{
	bool operator()(const Email & lhs, const Email & rhs) const;
};

#endif
