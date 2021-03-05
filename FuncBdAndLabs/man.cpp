#include "man.h"

Man::Man(const std::string& in_FirstName, const std::string& in_LastName, const std::string& in_Partonymic,
	std::size_t in_Year, bool in_bGender, std::size_t in_Salary)
	: m_FirstName(in_FirstName), m_LastName(in_LastName), m_Partonymic(in_Partonymic),
	m_Year(in_Year), m_bGender(in_bGender), m_Salary(in_Salary)
{

}

std::string Man::GetFirstName() const
{
	return m_FirstName;
}

std::string Man::GetLastName() const
{
	return m_LastName;
}

std::string Man::GetPartonymic() const
{
	return m_Partonymic;
}

std::size_t Man::GetYear() const
{
	return m_Year;
}

bool Man::GetGender() const
{
	return m_bGender;
}

std::size_t Man::GetSalary() const
{
	return m_Salary;
}

void Man::SetFamily(const std::shared_ptr<Family>& in_Family)
{
	m_Family = in_Family;
}

std::shared_ptr<Family> Man::GetFamily() const
{
	return m_Family;
}