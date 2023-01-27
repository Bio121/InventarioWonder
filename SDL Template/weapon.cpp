#include "weapon.h"

weapon::weapon(std::string itemName) {
	this->SetName(itemName);
	this->SetType(1);
};
weapon::weapon(int itmScore, int lvlReq, std::string itemName, int manufacturer, int type, int rarity, std::string description, int price, int element, float elementDMG) {
	this->SetItmScore(itmScore);
	this->SetLvlReq(lvlReq);
	this->SetName(itemName);
	this->SetManufacturer(manufacturer);
	this->SetType(type);
	this->SetRarity(rarity);
	this->SetDescription(description);
	this->SetPrice(price);
	this->MElement = element;
	this->MElementDMG = elementDMG;
};
weapon::~weapon() {
};
void weapon::SetElement(int newElement) {
	MElement = newElement;
};
int weapon::GetElement() {
	return MElement;
};
float weapon::GetElementDMG() {
	return MElementDMG;
};
void weapon::SetElementDMG(float newElementDmg) {
	MElementDMG = newElementDmg;
};