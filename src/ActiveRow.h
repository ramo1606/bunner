#pragma once
#include "Row.h"

class ActiveRow : public Row
{
public:
	ActiveRow(MoverType childType, std::vector<int>& dxs, std::string& baseImage, int index, float y);
	ActiveRow(const ActiveRow&) = default;
	ActiveRow& operator=(const ActiveRow&) = default;
	~ActiveRow() = default;

	virtual void update() override;

protected:
	MoverType m_ChildType{ 0 };		// Class to be used for child objects (e.g. Car)
	int m_Timer{ 0 };
};