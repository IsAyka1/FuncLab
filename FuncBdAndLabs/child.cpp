#include "child.h"

Child::Child(const std::string& in_FirstName, const std::string& in_LastName, const std::string& in_Partonymic,
	std::size_t in_Year, bool in_bGender, std::size_t in_Salary, bool in_IsTwins)
	: Man(in_FirstName, in_LastName, in_Partonymic, in_Year, in_bGender, in_Salary),
	m_IsTwins(in_IsTwins)
{

}

bool Child::IsTwins() const
{
	return m_IsTwins;
}