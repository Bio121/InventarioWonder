#include "itemInfo.h"
std::string itemInfo::GetElement(int x) {
	return this->MElementList[x];
};
std::string itemInfo::GetRarity(int x) {
	return this->MRarityList[x];
};
std::string itemInfo::GetWeaponType(int x) {
	return this->MWeaponType[x];
};
std::string itemInfo::GetWeaponManufacturer(int x) {
	return this->MWeaponsManufacturers[x];
};
std::string itemInfo::GetGearManufacturer(int x) {
	return this->MGearManufacturers[x];
};
std::string itemInfo::GetDamageStat(int x) {
	return this->MDamageStatsList[x];
};
void itemInfo::RenderElement(SDL_Renderer* renderer, int x, int y, int element) {
	MImageElements[element].rect.x = x;
	MImageElements[element].rect.y = y;
	SDL_RenderCopy(renderer, MImageElements[element].texture, NULL, &MImageElements[element].rect);

};
int itemInfo::GetRForRarity(int rarity) {
	switch (rarity)
	{
	case 0: {
		return 125;
	}break;
	case 1: {
		return 128;
	}break;
	case 2: {
		return 255;
	}break;
	case 3: {
		return 255;
	}break;
	case 4: {
		return 255;
	}break;
	default:
		break;
	}
};
int itemInfo::GetGForRarity(int rarity) {
	switch (rarity)
	{
	case 0: {
		return 125;
	}break;
	case 1: {
		return 0;
	}break;
	case 2: {
		return 30;
	}break;
	case 3: {
		return 120;
	}break;
	case 4: {
		return 255;
	}break;
	default:
		break;
	}
};
int itemInfo::GetBForRarity(int rarity) {
	switch (rarity)
	{
	case 0: {
		return 125;
	}break;
	case 1: {
		return 128;
	}break;
	case 2: {
		return 255;
	}break;
	case 3: {
		return 80;
	}break;
	case 4: {
		return 80;
	}break;
	default:
		break;
	}
};
void itemInfo::RenderManufacturer(SDL_Renderer* renderer, int x, int y, int type, int Manufacture, int rarity) {
	if (type < 4) {
		SDL_SetTextureColorMod(MImageWeaponManufacturer[Manufacture].texture, GetRForRarity(rarity), GetGForRarity(rarity), GetBForRarity(rarity));
		MImageWeaponManufacturer[Manufacture].rect.x = x;
		MImageWeaponManufacturer[Manufacture].rect.y = y;
		SDL_RenderCopy(renderer, MImageWeaponManufacturer[Manufacture].texture, NULL, &MImageWeaponManufacturer[Manufacture].rect);

	}
	else {
		SDL_SetTextureColorMod(MImageGearManufacturer[Manufacture].texture, GetRForRarity(rarity), GetGForRarity(rarity), GetBForRarity(rarity));
		MImageGearManufacturer[Manufacture].rect.x = x;
		MImageGearManufacturer[Manufacture].rect.y = y;
		SDL_RenderCopy(renderer, MImageGearManufacturer[Manufacture].texture, NULL, &MImageGearManufacturer[Manufacture].rect);
	};

};
void itemInfo::RenderImages(SDL_Renderer* renderer, int x, int y, int type, int Manufacture, int element, int rarity) {
	MImageTypeItem[type].rect.x = x;
	MImageTypeItem[type].rect.y = y;

	SDL_SetTextureColorMod(MImageTypeItem[type].texture, GetRForRarity(rarity), GetGForRarity(rarity), GetBForRarity(rarity));
	SDL_RenderCopy(renderer, MImageTypeItem[type].texture, NULL, &MImageTypeItem[type].rect);
	RenderManufacturer(renderer, x + 50, y + 250, type, Manufacture, rarity);
};

itemInfo::itemInfo() {

};
void itemInfo::InitImageType() {
	Img::LoadImage("assets/Shotgun.png", MImageTypeItem[0]);
	Img::LoadImage("assets/SMG.png", MImageTypeItem[1]);
	Img::LoadImage("assets/sniper.png", MImageTypeItem[2]);
	Img::LoadImage("assets/asault.png", MImageTypeItem[3]);
	Img::LoadImage("assets/Amulets.png", MImageTypeItem[4]);
	Img::LoadImage("assets/Amulets.png", MImageTypeItem[5]);
	Img::LoadImage("assets/ring.png", MImageTypeItem[6]);

	Img::LoadImage("assets/SkulduggerGun.png", MImageWeaponManufacturer[0]);
	Img::LoadImage("assets/DAHLIAGun.png", MImageWeaponManufacturer[1]);
	Img::LoadImage("assets/BlackpowderGun.png", MImageWeaponManufacturer[2]);
	Img::LoadImage("assets/HyperiusGun.png", MImageWeaponManufacturer[3]);
	Img::LoadImage("assets/StokerGun.png", MImageWeaponManufacturer[4]);

	Img::LoadImage("assets/kleaveGear.png", MImageGearManufacturer[0]);
	Img::LoadImage("assets/swifftGear.png", MImageGearManufacturer[1]);
	Img::LoadImage("assets/valoraGear.png", MImageGearManufacturer[2]);
	Img::LoadImage("assets/VatuGear.png", MImageGearManufacturer[3]);

	Img::LoadImage("assets/Incendiary.png", MImageElements[0]);
	Img::LoadImage("assets/Corrosive.png", MImageElements[1]);
	Img::LoadImage("assets/Shock.png", MImageElements[2]);
	Img::LoadImage("assets/cryo.png", MImageElements[3]);
	Img::LoadImage("assets/none.png", MImageElements[4]);
};
