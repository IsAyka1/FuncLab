#include "family.h"

Family::Family(const std::shared_ptr<Man>& in_Husband, const std::shared_ptr<Man>& in_Wife, const std::list<std::shared_ptr<Child>>& in_Childs)
{
	m_Husband = in_Husband;
	std::shared_ptr<Family> family(this);
	m_Husband->SetFamily(family);
	m_Wife = in_Wife;
	m_Wife->SetFamily(family);
	m_Childs = in_Childs;
	for (auto& child : m_Childs)
		child->SetFamily(family);
}


void Family::AddPeopleInFamily(const std::shared_ptr<Man>& in_Husband, const std::shared_ptr<Man>& in_Wife, const std::list<std::shared_ptr<Child>>& in_Childs)
{
	m_Husband = in_Husband;
	std::shared_ptr<Family> family(this);
	m_Husband->SetFamily(family);
	m_Wife = in_Wife;
	m_Wife->SetFamily(family);
	m_Childs = in_Childs;
	for (auto& child : m_Childs)
		child->SetFamily(family);
}

std::list<std::shared_ptr<Child>> Family::GetChilds() const
{
	return m_Childs;
}

std::shared_ptr<Man> Family::GetHusband() const
{
	return m_Husband;
}

std::shared_ptr<Man> Family::GetWife() const
{
	return m_Wife;
}