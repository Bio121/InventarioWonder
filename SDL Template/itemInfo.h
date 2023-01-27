#pragma once
#include <string>
#include "image.h"

class itemInfo
{
public:
	itemInfo();
	void InitImageType();
	void RenderImages(SDL_Renderer*, int, int, int, int, int,int);
	void RenderElement(SDL_Renderer* renderer, int x, int y, int element);
	void RenderManufacturer(SDL_Renderer* renderer, int x, int y, int type, int Manufacture, int rarity);
	std::string GetElement(int);
	std::string GetRarity(int);
	std::string GetWeaponType(int);
	std::string GetWeaponManufacturer(int);
	std::string GetGearManufacturer(int);
	std::string GetDamageStat(int);
	int GetRForRarity(int);
	int GetGForRarity(int);
	int GetBForRarity(int);
private:
	std::string MElementList[5] = { "Incendiary", "Corrosive", "Shock", "cryo","none" };
	std::string MDamageStatsList[7] = { "fire", "lightning", "frost", "none","ability", "status effect", "skul dugger gun" };
	std::string MRarityList[5] = { "Common", "Epic", "Rare", "Very Rare", "Legendary" };
	std::string MWeaponType[7] = { "Shotgun", "Submachine", "Sniper", "Assault Rifle", "amulets", "armors", "rings" };
	std::string MWeaponsManufacturers[5] = { "Skuldugger", "Dahlia", "BlackPowder", "Hyperion", "Stoker" };
	std::string MGearManufacturers[4] = { "kleave", "swifft", "valora", "vatu" };
	Img::Image MImageTypeItem[7];
	Img::Image MImageWeaponManufacturer[5];
	Img::Image MImageGearManufacturer[4];
	Img::Image MImageElements[5];
};

