#ifndef item_h
#define item_h

#include <iostream>
#include <string>
#include "image.h"

class item
{
public:
	item(std::string, std::string, int, int);
	item();
	item* preP = NULL;
	item* sigP = NULL;

	void SetItmScore(int newItemScore);
	int GetItmScore() ;
	void SetLvlReq(int NewLvlReq);
	int getLvlReq();
	std::string GetName();
	void SetName(std::string NewName);
	int GetManufacturer();
	void SetManufacturer(int newManufacturer);
	int GetType();
	void SetType(int newType);
	int GetRarity();
	void SetRarity(int newRarity);
	std::string GetDescription();
	void SetDescription(std::string newDescription);
	int GetPrice();
	void SetPrice(int newPrice);
	virtual int GetElement();

	void setItemImgRect(int, int);
	void render(SDL_Renderer*);
	Img::Image getitemImg();
	void setitemImg(const char*);

private:

	Img::Image itemImg;
	int MitmScore;
	int MlvlReq;
	std::string Mname;
	int Mmanufacturer;
	int Mtype;
	int Mrarity;
	std::string MDescription;
	int Mprice;
	

};

#endif item_h