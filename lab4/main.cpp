#include "mailbox.h"

template<typename T>
void show(const T & val)
{
	std::cout << val << '\n';
}

int main()
{
	MailBox box(3);

	box[0] = {"Janne", "2018-12-10", "Får man vara pepparkaksgubbe på lucia?"};
	box[1] = {"BjarneBoy65", "1990-11-11", "Du måeste gissa roetterna"};
	box[2] = {"Lind", "2017-04-07", "Motivera ditt svar"};

	box.push({"Ante", "2018-12-09", "Vem är den här funktor?"});
	box.push({"Isak (min broder)", "2018-12-10", "Vem är den här funktor?"});
	box.push({"Isac (Reinfeldt)", "2018-12-12", "Kan du hjälpa mig med min maze?"});
	box.push({"Master Chief", "2006-12-01", "Finishing this fight"});
	box.push({"Palex", "2018-09-04", "Varför har du hjul?"});

	std::for_each(box.begin(), box.end(), [](const Email & email)
	{
		show(email);
	});

	std::cout << '\n';
	box.sortWho();

	std::for_each(box.begin(), box.end(), [](const Email & email)
	{
		show(email);
	});

	std::cout << '\n';
	box.sortDate();

	std::for_each(box.begin(), box.end(), [](const Email & email)
	{
		show(email);
	});

	std::cout << '\n';
	box.sortSubject();

	std::for_each(box.begin(), box.end(), [](const Email & email)
	{
		show(email);
	});
	return 0;
}
