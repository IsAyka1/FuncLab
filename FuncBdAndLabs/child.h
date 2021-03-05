#pragma once

#include "man.h"

#include <string>

class Child : public Man
{
private:
	bool m_IsTwins;

public:
	Child(const std::string& in_FirstName, const std::string& in_LastName, const std::string& in_Partonymic,
		std::size_t in_Year, bool in_bGender, std::size_t in_Salary, bool in_IsTwins);
	bool IsTwins() const;
};