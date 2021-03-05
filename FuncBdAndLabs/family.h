#pragma once

#include "child.h"

#include <list>
#include <memory>
#include <vector>

class Family
{
private:
	std::shared_ptr<Man> m_Husband;
	std::shared_ptr<Man> m_Wife;
	std::list<std::shared_ptr<Child>>	m_Childs;

public:
	Family(const std::shared_ptr<Man>& in_Husband, const std::shared_ptr<Man>& in_Wife, const std::list<std::shared_ptr<Child>>& in_Childs);
	void AddPeopleInFamily(const std::shared_ptr<Man>& in_Husband, const std::shared_ptr<Man>& in_Wife, const std::list<std::shared_ptr<Child>>& in_Childs);
	std::shared_ptr<Man> GetHusband() const;
	std::shared_ptr<Man> GetWife() const;
	std::list<std::shared_ptr<Child>> GetChilds() const;
};