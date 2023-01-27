#pragma once
#include "item.h"
class weapon : public item
{
public:
	weapon(std::string);
	weapon(int, int, std::string, int, int, int, std::string, int, int, float);
	~weapon();
	void SetElement(int);
	int GetElement();
	float GetElementDMG();
	void SetElementDMG(float);
private:
	int MElement;
	float MElementDMG;
};

