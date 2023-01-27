#include "item.h"


item::item(std::string tipoArmaI, std::string rarezaI, int nivelI, int costoI) {

};

item::item() {
};

int item::GetElement() {
	return 1;
};
void item::SetItmScore(int newItemScore) {
	MitmScore = newItemScore;
};
int item::GetItmScore() {
	return MitmScore;
};
void item::SetLvlReq(int NewLvlReq) {
	MlvlReq = NewLvlReq;
};
int item::getLvlReq() {
	return MlvlReq;
};
std::string item::GetName() {
	return Mname;
};
void item::SetName(std::string NewName) {
	Mname = NewName;
};

int item::GetManufacturer() {
	return Mmanufacturer;
};
void item::SetManufacturer(int newManufacturer) {
	Mmanufacturer = newManufacturer;
};
int item::GetType() {
	return Mtype;
};
void item::SetType(int newType) {
	Mtype = newType;
};
int item::GetRarity() {
	return Mrarity;
};
void item::SetRarity(int newRarity) {
	Mrarity = newRarity;
};
std::string item::GetDescription() {
	return MDescription;
};
void item::SetDescription(std::string newDescription) {
	MDescription = newDescription;
};
int item::GetPrice() {
	return Mprice;
};
void item::SetPrice(int newPrice) {
	Mprice = newPrice;
};
void item::setitemImg(const char* path) {
	Img::LoadImage(path, itemImg);
};

Img::Image item::getitemImg() {
	return itemImg;
};

void item::render(SDL_Renderer* renderer) {
	SDL_RenderCopy(renderer, itemImg.texture, NULL,  &itemImg.rect);
};

void item::setItemImgRect(int x, int y) {
	itemImg.rect.x = x;
	itemImg.rect.y = y;
}