#include "BackPack.h"

BackPack::BackPack() {
	MTotalSlots = 24;
}

void BackPack::CreateItem(int GoW) {
	if (MTotalItems < MTotalSlots)
	{
		if (GoW == 1)
		{
			CreateRealWeapon();
		}
		else
		{
			CreateRealGear();
		}
		if (ori == NULL) {
			ori = aux;
			endP = aux;
			MTotalItems += 1;
		}
		else
		{
			aux->preP = endP;
			endP->sigP = aux;
			endP = aux;
			MTotalItems += 1;
		}

	}
		
}

void BackPack::CreateRealWeapon() {
	srand((unsigned int)time(NULL));
	int weaponRand = rand() % 12;

	switch (weaponRand)
	{
	case 0: {
		aux = new weapon(520, 40, "Circuitous Gyre", 3, 0, 4, "Whirl Whirl until you see yourself again", 23038, 2, 517);
		aux->setitemImg("assets/CircuitousGyre.png");
	}break;
	case 1: {
		aux = new weapon(509, 40, "Last Rites", 3, 0, 2, "But it's time for you to find it on your own", 20033, 3, 375);
		aux->setitemImg("assets/LastRites.png");
	}break;
	case 2: {
		aux = new weapon(520, 40, "Reign of Arrows", 2, 0, 4, "...From A lacerated sky", 30820, 4, 0);
		aux->setitemImg("assets/ReignofArrows.png");
	}break;
	case 3: {
		aux = new weapon(530, 40, "Dry'l's Legacy", 3, 1, 3, "Born of The fiery depths", 28798, 0, 237);
		aux->setitemImg("assets/DrylsLegacy.png");
	}break;
	case 4: {
		aux = new weapon(510, 40, "Live Wire", 1, 1, 4, "the lightning. it's good for you!", 21775, 2, 362);
		aux->setitemImg("assets/LiveWire.png");
	}break;
	case 5: {
		aux = new weapon(539, 40, "Heckwader", 1, 1, 2, "rip and tear", 33117, 0, 144);
		aux->setitemImg("assets/Heckwader.png");
	}break;
	case 6: {
		aux = new weapon(550, 40, "Carrouser", 2, 2, 4, "if you're not getting around, you're standing still", 31445, 0, 2027);
		aux->setitemImg("assets/Carrouser.png");
	}break;
	case 7: {
		aux = new weapon(550, 40, "Antique Greatbow", 3, 2, 4, "It'd be worth a hefty sum if it was never fired", 71093, 3, 6515);
		aux->setitemImg("assets/AntiqueGreatbow.png");
	}break;
	case 8: {
		aux = new weapon(550, 40, "Skeep Prod", 1, 2, 4, "Not free-range", 35546, 2, 750);
		aux->setitemImg("assets/SkeepProd.png");
	}break;
	case 9: {
		aux = new weapon(510, 40, "Donkey", 4, 3, 4, "... Your breath STINKS.", 33389, 1, 160);
		aux->setitemImg("assets/Donkey.png");
	}break;
	case 10: {
		aux = new weapon(520, 40, "Rogue Imp", 0, 3, 4, "It's a great day for an incineration!", 38397, 0, 876);
		aux->setitemImg("assets/RogueImp.png");
	}break;
	case 11: {
		aux = new weapon(519, 40, "Mistrial", 1, 3, 2, "All rise", 33967, 4, 0);
		aux->setitemImg("assets/Mistrial.png");
	}break;

	default:
		break;
	}
};

void BackPack::CreateRealGear() {
	srand((unsigned int)time(NULL));
	int weaponRand = rand() % 9;

	switch (weaponRand)
	{
	case 0: {
		aux = new weapon(435, 70, "Barboload", 3, 4, 4, "Served with a side and salt", 26516, 0, 47.4);
		aux->setitemImg("assets/Barboload.png");
	}break;
	case 1: {
		aux = new weapon(439, 40, "Rivote's Amulet", 3, 4, 2, "Thou hast seen nothing yet.", 30494, 1, 45.1);
		aux->setitemImg("assets/RivotesAmulet.png");
	}break;
	case 2: {
		aux = new weapon(440, 49, "Sacrificial Skeep", 3, 4, 4, "Skeepin' it real", 30494, 2, 47.4);
		aux->setitemImg("assets/SacrificialSkeep.png");
	}break;
	case 3: {
		aux = new weapon(474, 30, "Armor That Sucks", 2, 5, 2, "Wow, you did it", 23744, 3, 0);
		aux->setitemImg("assets/ArmorThatSucks.png");
	}break;
	case 4: {
		aux = new weapon(495, 40, "Claw", 0, 5, 4, "One fish, two fish; red dragon, blue dragon", 46946, 3, 0);
		aux->setitemImg("assets/Claw.png");
	}break;
	case 5: {
		aux = new weapon(495, 43, "Steel Gauntlets", 2, 5, 3, "Protection for any size hands", 46946, 3, 0);
		aux->setitemImg("assets/SteelGauntlets.png");
	}break;
	case 6: {
		aux = new weapon(439, 45, "Driftwood", 3, 6, 2, "Home sweet home", 18043, 4, 21.6);
		aux->setitemImg("assets/Driftwood.png");
	}break;
	case 7: {
		aux = new weapon(473, 48, "Daemon Blight", 3, 6, 4, "Haxed, but unvexed", 21994, 5, 26.3);
		aux->setitemImg("assets/DaemonBlight.png");
	}break;
	case 8: {
		aux = new weapon(396, 4, "Fealty Oath", 3, 6, 4, "All together now", 7724, 6, 15);
		aux->setitemImg("assets/FealtyOath.png");
	}break;

	default:
		break;
	}
};

void BackPack::RenderAllItem(SDL_Renderer* renderer) {
	aux = ori;
	int i = 0;
	while (aux != NULL)
	{
		SDL_SetTextureColorMod(Mitems[i].texture, Minterprete.GetRForRarity(aux->GetRarity()), Minterprete.GetGForRarity(aux->GetRarity()), Minterprete.GetBForRarity(aux->GetRarity()));
		aux->setItemImgRect(Mitems[i].rect.x, Mitems[i].rect.y);
		if (((ITEM_PER_PAGE * MinPage) <= i) && ((ITEM_PER_PAGE * MinPage) + 8 > i)) {
			aux->render(renderer);
			Minterprete.RenderManufacturer(renderer, Mitems[i].rect.x + 20, Mitems[i].rect.y + 70, aux->GetType(), aux->GetManufacturer(), aux->GetRarity());
			if (aux->GetType() < 4)
				Minterprete.RenderElement(renderer, Mitems[i].rect.x + 150, Mitems[i].rect.y + 75, aux->GetElement());
		}
		aux = aux->sigP;
		i++;
	};
	
};

void BackPack::DeleteAllItem() {
	aux = endP;
	while (endP != NULL)
	{
		endP = endP->preP;
		delete aux;
		aux = endP;

	};
};

void BackPack::DeleteOneItem(int pos) {
	if (pos < MTotalItems)
	{
		aux = ori;
		for (int i = 0; i < pos; i++)
		{
			aux = aux->sigP;
			
		}
		if (aux->sigP == NULL && aux->preP == NULL) {
			ori = NULL;
			endP = NULL;
			delete aux;
			aux = NULL;
			MTotalItems -= 1;
			return;
		}
		if (aux->preP == NULL) {
			ori = aux->sigP;
			aux->sigP->preP = aux->preP;
			delete aux;
			MTotalItems -= 1;
			return;
		}
		if (aux->sigP == NULL) {
			endP = aux->preP;
			aux->preP->sigP = aux->sigP;
			delete aux;
			MTotalItems -= 1;
			return;
		}
		if (aux->sigP != NULL && aux->preP != NULL) {
			aux->preP->sigP = aux->sigP;
			aux->sigP->preP = aux->preP;
			delete aux;
			MTotalItems -= 1;
			return;
		}
	}


};

void BackPack::UnequipItem(item*& Apuntador) {
	if (MTotalItems < MTotalSlots)
	{
		if (Apuntador != NULL) {
			if (endP == NULL)
			{
				ori = Apuntador;
				endP = Apuntador;
				MTotalItems += 1;
				Apuntador = NULL;
			}
			else {
				endP->sigP = Apuntador;
				Apuntador->preP = endP;
				endP = Apuntador;
				MTotalItems += 1;
				Apuntador = NULL;
			}
		}

	}


};

void BackPack::PointOneItem(item*& Apuntador, int pos) {
	if (pos < MTotalItems)
	{
		aux = ori;
		MTotalItems -= 1;
		for (int i = 0; i < pos; i++)
		{
			aux = aux->sigP;

		}
		if (Apuntador != NULL)
		{
			UnequipItem(Apuntador);
		}
		if (aux->sigP == NULL && aux->preP == NULL) {
			ori = NULL;
			endP = NULL;
			aux->sigP = NULL;
			aux->preP = NULL;
			Apuntador = aux;
			aux = NULL;
			
			return;
		}
		if (aux->preP == NULL) {
			ori = aux->sigP;
			aux->sigP->preP = aux->preP;
			aux->sigP = NULL;
			aux->preP = NULL;
			Apuntador = aux;
			return;
		}
		if (aux->sigP == NULL) {
			endP = aux->preP;
			aux->preP->sigP = aux->sigP;
			aux->sigP = NULL;
			aux->preP = NULL;
			Apuntador = aux;
			return;
		}
		if (aux->sigP != NULL && aux->preP != NULL) {
			aux->preP->sigP = aux->sigP;
			aux->sigP->preP = aux->preP;
			aux->sigP = NULL;
			aux->preP = NULL;
			Apuntador = aux;
			return;
		}
	}


};

void BackPack::GetOneItem(int x) {
	if (x < MTotalItems) {
		aux = ori;
		for (int i = 0; i < x ; i++)
		{
			aux = aux->sigP;
		}
	}
};

int BackPack::GetInPage() {
	return MinPage;
};

void BackPack::SetInPage(int newInPague) {
	MinPage = newInPague;
	if (MinPage < 0)
	{
		MinPage = 2;
	}
	if (MinPage == 3)
	{
		MinPage = 0;
	}
};

int BackPack::GetPosSelect() {
	return MposSel;
};

void BackPack::SetPosSelect(int newPosSelect) {
	MposSel = newPosSelect;
	if (MposSel > 7)
	{
		MposSel -= 8;
	}
	if (MposSel < 0)
	{
		MposSel += 8;
	}
};

void BackPack::UpdateItemStats(SDL_Renderer* renderer) {
	if ((MposSel + (ITEM_PER_PAGE * MinPage)) < MTotalItems) {
		this->CleanItemStats();
		this->GetOneItem(MposSel + (ITEM_PER_PAGE * MinPage));
		MLastTypeItemInStatus = aux->GetType();
		MLastManufactureItemInStatus = aux->GetManufacturer();
		MLastElementItemInStatus = aux->GetElement();
		MLastRarityItemInStatus = aux->GetRarity();
		SDL_SetTextureColorMod(MitemStats.texture, Minterprete.GetRForRarity(MLastRarityItemInStatus), Minterprete.GetGForRarity(MLastRarityItemInStatus), Minterprete.GetBForRarity(MLastRarityItemInStatus));
		this->NewItemStats(renderer, std::to_string(aux->GetItmScore()), std::to_string(aux->getLvlReq()), Minterprete.GetRarity(aux->GetRarity()), aux->GetDescription()
			, aux->GetName(), std::to_string(aux->GetPrice()));
	}
};

int BackPack::GetTotalItems() {
	return MTotalItems;
};

void BackPack::Init(SDL_Renderer* renderer) {
	MtexItemScore = new Text(renderer, "assets/arial.ttf", 20, "ITEM SCORE", { 125, 125, 125, 255 });
	MtexLvlReq = new Text(renderer, "assets/arial.ttf", 20, "LVL REQ.", { 125, 125, 125, 255 });
	Img::LoadImage("assets/select.png", MitemSelect);
	MitemSelect.rect.x = 1460;
	MitemSelect.rect.y = (55 * (MposSel % ITEM_PER_PAGE)) + 300;
	Img::LoadImage("assets/itemStats.png", MitemStats);
	MitemStats.rect.x = 800;
	MitemStats.rect.y = 100;
	Img::LoadImage("assets/inventory.png", MImageBag);
	MImageBag.rect.x = 1400;
	MImageBag.rect.y = 100;
	for (int i = 0; i < 24; i++)
	{
		if (i % 2 == 0)
		{
			if (i < 8)
			{
				Img::LoadImage("assets/empty.png", Mitems[i]);
			}

			if (i > 7 && i < 16)
			{
				Img::LoadImage("assets/empty2.png", Mitems[i]);
			}
			if (i > 15 && i < 24)
			{
				Img::LoadImage("assets/empty3.png", Mitems[i]);
			}
			Mitems[i].rect.x = 1460;
			Mitems[i].rect.y = ((55 * (i % ITEM_PER_PAGE)) + 300);

		}
		else
		{
			if (i < 8)
			{
				Img::LoadImage("assets/empty.png", Mitems[i]);
			}

			if (i > 7 && i < 16)
			{
				Img::LoadImage("assets/empty2.png", Mitems[i]);
			}
			if (i > 15 && i < 24)
			{
				Img::LoadImage("assets/empty3.png", Mitems[i]);
			}
			Mitems[i].rect.x = 1669;
			Mitems[i].rect.y = ((55 * ((i % ITEM_PER_PAGE) - 1)) + 300);
		}
	}
	Minterprete.InitImageType();
	UpdateItemStats(renderer);
};

void BackPack::CleanItemStats() {
	delete MtexItemScoreNum;
	delete MtexLvlReqNum;
	delete MtexItemName;
	delete MtexItemRarity;
	delete MtexDescription;
	delete MtexitemPrice;
}

void BackPack::DelteAll() {
	this->CleanItemStats();
	delete MtexItemScore;
	delete MtexLvlReq;
};

void BackPack::NewItemStats(SDL_Renderer* renderer, const std::string& itemScore, const std::string& lvlReq, const std::string& rarity, const std::string& description, const std::string& itemName, const std::string& price) {
	MtexItemScoreNum = new Text(renderer, "assets/arial.ttf", 30, itemScore.c_str(), { 125, 125, 125, 255 });
	MtexLvlReqNum = new Text(renderer, "assets/arial.ttf", 30, lvlReq.c_str(), { 125, 125, 125, 255 });
	MtexItemRarity = new Text(renderer, "assets/arial.ttf", 20, rarity.c_str(), { (Uint8)Minterprete.GetRForRarity(MLastRarityItemInStatus), (Uint8)Minterprete.GetGForRarity(MLastRarityItemInStatus), (Uint8)Minterprete.GetBForRarity(MLastRarityItemInStatus), 255 });
	MtexDescription = new Text(renderer, "assets/arial.ttf", 15, description.c_str(), { 190, 0, 0, 255 });
	MtexItemName = new Text(renderer, "assets/arial.ttf", 30, itemName.c_str(), { (Uint8)Minterprete.GetRForRarity(MLastRarityItemInStatus), (Uint8)Minterprete.GetGForRarity(MLastRarityItemInStatus), (Uint8)Minterprete.GetBForRarity(MLastRarityItemInStatus), 255 });
	MtexitemPrice = new Text(renderer, "assets/arial.ttf", 30, price.c_str(), { 125, 125, 125, 255 });
};

void BackPack::RenderItemStats(SDL_Renderer* renderer) {
	if ((MposSel + (ITEM_PER_PAGE * MinPage)) < MTotalItems) {
		SDL_RenderCopy(renderer, MitemStats.texture, NULL, &MitemStats.rect);
		MtexItemScore->Display(930, 130, renderer);
		MtexItemScoreNum->Display(850, 130, renderer);
		MtexLvlReqNum->Display(1280, 130, renderer);
		MtexLvlReq->Display(1180, 130, renderer);
		MtexItemName->Display(((MitemStats.rect.x + 285)) - (MtexItemName->GetTextRectW() / 2), 200, renderer);
		MtexItemRarity->Display(930 - (MtexItemRarity->GetTextRectW() / 2), 250, renderer);
		MtexDescription->Display(880, 480, renderer);
		MtexitemPrice->Display(((MitemStats.rect.x + 285)) - (MtexitemPrice->GetTextRectW() / 2), 650, renderer);

		Minterprete.RenderImages(renderer, 800, 100, MLastTypeItemInStatus, MLastManufactureItemInStatus, MLastElementItemInStatus, MLastRarityItemInStatus);
	}
};

void BackPack::UpdatePosition() {


	if (MposSel % 2 == 0)
	{
		MitemSelect.rect.x = 1460;
		MitemSelect.rect.y = (55 * (MposSel % ITEM_PER_PAGE)) + 300;
	}
	else
	{
		MitemSelect.rect.x = 1669;
		MitemSelect.rect.y = (55 * ((MposSel % ITEM_PER_PAGE) - 1)) + 300;
	}
};

void BackPack::RenderInBackPack(SDL_Renderer* renderer) {

	SDL_RenderCopy(renderer, MImageBag.texture, NULL, &MImageBag.rect);
	for (int i = 0; i < ITEM_PER_PAGE; i++)
	{
		if ((i + 1) + 8 * MinPage > MTotalItems)
		{
			SDL_SetTextureColorMod(Mitems[i + 8 * MinPage].texture, 255, 255, 255);

		}
		SDL_RenderCopy(renderer, Mitems[i + (ITEM_PER_PAGE * MinPage)].texture, NULL, &Mitems[i + (ITEM_PER_PAGE * MinPage)].rect);
		RenderAllItem(renderer);
	}
	SDL_RenderCopy(renderer, MitemSelect.texture, NULL, &MitemSelect.rect);
};

