#include "gear.h"

gear::gear(std::string itemName) {
	this->SetName(itemName);
	this->SetType(2);
};
gear::gear(int itmScore, int lvlReq, std::string itemName, int manufacturer, int type, int rarity, std::string description, int price, int DamageStats, float SeconStatDesc) {
	this->SetItmScore(itmScore);
	this->SetLvlReq(lvlReq);
	this->SetName(itemName);
	this->SetManufacturer(manufacturer);
	this->SetType(type);
	this->SetRarity(rarity);
	this->SetDescription(description);
	this->SetPrice(price);
	this->MDamageStats = DamageStats;
	this->MSecondaryStatsDescription = SeconStatDesc;
};

gear::~gear() {
};
int gear::GetDamageStat() {
	return MDamageStats;
};
void gear::SetDamageStat(int newDamageStats) {
	MDamageStats = newDamageStats;
};
float gear::GetSecondaryStatsDescription() {
	return MSecondaryStatsDescription;
};
void gear::SetSecondaryStatsDescription(float newSeconStatDesc) {
	MSecondaryStatsDescription = newSeconStatDesc;
};