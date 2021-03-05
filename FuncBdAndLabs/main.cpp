#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>
#include <iomanip>
#include <random>
#include <vector>

#include "family.h"

/*
* Вариант №15 Написать программу инвертирования списка.
*/

/*
* Вариант №19 Написать программу подсчета количества вхождений элемента в список.
*/

/*
* Вариант №1 Предметная область – семья.
* Каждая семья может быть описана структурой из трех компонентов: мужа, жены и детей.
* Каждый член семьи может быть описан структурой: имя, отчество, фамилия, год рождения, пол, ежемесячный доход.
* Для детей добавить поле «близнец». Реализовать следующие типы запросов:
*	1. Проверить, существует ли в БД заданный человек (по ФИО).
*	2. Найти всех работающих детей.
*	3. Найти всех работающих мужей, чей доход больше, чем у жены.
*	4. Найти всех людей, которые не работают и родились до указанного года.
*	5. Найти число семей, у которых есть близнецы.
*/

template<typename T>
std::ostream& operator<<(std::ostream& in_Stream, const std::list<T>& in_List)
{
	bool is_first = true;
	for (const auto& elem : in_List)
	{
		if (!is_first)
		{
			in_Stream << " " << elem;
		}
		else
		{
			in_Stream << elem;
			is_first = false;
		}
	}
	return in_Stream;
}

std::list<std::size_t> FillListRandomValues(std::size_t in_Count, std::size_t in_Begin=0, std::size_t in_End=5)
{
	std::list<std::size_t> list(in_Count);
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<std::size_t> dist(in_Begin, in_End);

	for (auto& elem : list)
		elem = dist(mt);
	return list;
}

int main()
{
	setlocale(LC_ALL, "");
	std::list<std::size_t> list1{ 1, 2, 3, 4, 5, 6 };
	std::cout << list1 << std::endl;
	std::reverse(list1.begin(), list1.end());
	std::cout << list1 << std::endl;

	std::cout << "*" << std::setw(11) << std::setfill('-') << "*" << std::endl;

	std::list<std::size_t> list2 = FillListRandomValues(10);
	std::size_t value = 2;
	std::cout << list2 << std::endl;
	auto count = std::count(list2.begin(), list2.end(), value);
	std::cout << "Count " << value << " - " << count << std::endl;

	std::cout << "*" << std::setw(11) << std::setfill('-') << "*" << std::endl;
	
	
	std::vector<std::shared_ptr<Man>> peoples{ 
				std::make_shared<Man>("Alex", "Ivanov", "Petrovich", 1960, false, 70000),
				std::make_shared<Man>("Anna", "Ivanova", "Michina", 1964, true, 30000),
				std::make_shared<Child>("Petya", "Ivanov", "Alexeevich", 2000, false, 0, false),
				std::make_shared<Child>("Pipa", "Ivanova", "Alexeevna", 1990, true, 30000, false),
				std::make_shared<Man>("Andrey", "Smitt", "Pavlov", 1975, false, 50000),
				std::make_shared<Man>("Aria", "Smitt", "Narkova", 1977, true, 50000),
				std::make_shared<Child>("Pavel", "Smitt", "Andreyevich", 2005, false, 0, true),
				std::make_shared<Child>("Pasha", "Smitt", "Andreyevich", 2005, false, 0, true),
				std::make_shared<Man>("Mark", "Jenner", "Jecsonovish", 1971, false, 50000),
				std::make_shared<Man>("Milla", "Jenner", "Nevskova", 1970, true, 65000),
				std::make_shared<Child>("Kataya", "Jenner", "Markovna", 1999, true, 15000, true),
				std::make_shared<Child>("Karina", "Jenner", "Markovna", 1999, true, 17000, true),
				std::make_shared<Man>("Nail", "Horan", "Ivanovish", 1968, false, 100000),
				std::make_shared<Man>("Katarina", "Horan", "Tagirovna", 1970, true, 80000),
				std::make_shared<Child>("Lim", "Horan", "Nailovich", 1994, false, 35000, false),
				std::make_shared<Child>("Polina", "Horan", "Nailovna", 1996, true, 27000, false),
				std::make_shared<Man>("Harry", "Potter", "Djamsevich", 1982, false, 110000),
				std::make_shared<Man>("Jinny", "Potter", "Arturovna", 1988, false, 0),
				std::make_shared<Child>("Djamse", "Potter", "Harryevich", 2008, false, 0, true),
				std::make_shared<Child>("Severus", "Potter", "Harryevich", 2008, false, 0, true)
	};

	std::vector<std::shared_ptr<Family>> familys;
	for (std::size_t i = 0; i < peoples.size(); i += 4)
	{
		std::initializer_list<std::shared_ptr<Child>> list{ std::static_pointer_cast<Child>(peoples[i + 2]), std::static_pointer_cast<Child>(peoples[i + 3]) };
		familys.push_back(std::make_shared<Family>(peoples[i], peoples[i + 1], list));
	}
	

	std::size_t operation;

	std::cout << "1. Проверить, существует ли в БД заданный человек (по ФИО)." << std::endl
		<< "2. Найти всех работающих детей." << std::endl
		<< "3. Найти всех работающих мужей, чей доход больше, чем у жены." << std::endl
		<< "4. Найти всех людей, которые не работают и родились до указанного года." << std::endl
		<< "5. Найти число семей, у которых есть близнецы." << std::endl;


	while (std::cin >> operation)
	{
		switch (operation)
		{
		case 1:
		{
			std::string firstName;
			std::string lastName;
			std::string partonymic;
			std::cin >> firstName >> lastName >> partonymic;

			auto it = std::find_if(peoples.begin(), peoples.end(), [&firstName, &lastName, &partonymic](const auto& man) {
				return man->GetFirstName() == firstName && man->GetLastName() == lastName && man->GetPartonymic() == partonymic;
				});

			std::cout << (it != peoples.end() ? "Exist" : "Not exist") << std::endl;
		} break;
		case 2:
		{
			std::list<std::shared_ptr<Child>> childs;
			for (const auto& family : familys)
				childs.splice(childs.end(), family->GetChilds());

			std::vector<std::shared_ptr<Child>> results;
			std::for_each(childs.begin(), childs.end(), [&results](const auto& child) {
				if (child->GetSalary() != 0)
					results.push_back(child);
				});

			for (const auto& child : results)
				std::cout << child->GetFirstName() << " " << child->GetLastName() << " " << child->GetPartonymic() << std::endl;
		} break;
		case 3:
		{
			std::vector<std::shared_ptr<Man>> husbands;
			std::for_each(familys.begin(), familys.end(), [&husbands](const auto& family) {
				if (family->GetHusband()->GetSalary() > family->GetWife()->GetSalary())
					husbands.emplace_back(family->GetHusband());
				});

			for (const auto& man : husbands)
				std::cout << man->GetFirstName() << " " << man->GetLastName() << " " << man->GetPartonymic() << std::endl;
		} break;
		case 4:
		{
			std::vector<std::shared_ptr<Man>> loafers;
			std::size_t year;
			std::cin >> year;
			std::for_each(peoples.begin(), peoples.end(), [&loafers, year](const auto& man) {
				if (man->GetSalary() == 0 && man->GetYear() < year)
					loafers.emplace_back(man);
				});

			for (const auto& man : loafers)
				std::cout << man->GetFirstName() << " " << man->GetLastName() << " " << man->GetPartonymic() << std::endl;
		} break;
		case 5:
		{
			std::size_t count = 0;
			std::for_each(familys.begin(), familys.end(), [&count](const auto& family) {
				auto childs = family->GetChilds();
				if (std::find_if(childs.begin(), childs.end(), [](const auto& child) {
					return child->IsTwins();
					}) != childs.end()) {
					++count;
				}
			});

			std::cout << "Count: " << count << std::endl;
		} break;
		default:
			std::cout << "Invalid operation" << std::endl;
			break;
		}
	}

	return 0;
}