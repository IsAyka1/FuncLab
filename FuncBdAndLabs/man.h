#pragma once

#include <string>
#include <memory>

class Family;

class Man
{
private:
	std::string m_FirstName;
	std::string m_LastName;
	std::string m_Partonymic;
	std::size_t m_Year;
	bool m_bGender;
	std::size_t m_Salary;
	std::shared_ptr<Family> m_Family;

public:
	Man(const std::string& in_FirstName, const std::string& in_LastName, const std::string& in_Partonymic,
		std::size_t in_Year, bool in_bGender, std::size_t in_Salary);
	std::string GetFirstName() const;
	std::string GetLastName() const;
	std::string GetPartonymic() const;
	std::size_t GetYear() const;
	bool GetGender() const;
	std::size_t GetSalary() const;
	void SetFamily(const std::shared_ptr<Family>& in_Family);
	std::shared_ptr<Family> GetFamily() const;
};