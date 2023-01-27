#include "text.h"


Text::Text(SDL_Renderer* renderer, const std::string& fontPath, int fontSize, const std::string& text, const SDL_Color& color) {

	MTextTexture = loadFont(renderer,fontPath,fontSize,text,color);
	SDL_QueryTexture(MTextTexture, nullptr, nullptr, &MtextRect.w, &MtextRect.h);
}

Text::~Text() {
	if (this->MTextTexture != NULL) {
		SDL_DestroyTexture(this->MTextTexture);
		this->MTextTexture = NULL;
	}
}

void Text::Display(int x, int y, SDL_Renderer *renderer) {

	MtextRect.x = x;
	MtextRect.y = y;
	SDL_RenderCopy(renderer, MTextTexture, nullptr, &MtextRect);
}

void Text::SetText(SDL_Renderer* renderer, const std::string& fontPath, int fontSize, const std::string& text, const SDL_Color& color) {
	TTF_Font* font = TTF_OpenFont(fontPath.c_str(), fontSize);
	auto textSurface = TTF_RenderText_Solid(font, text.c_str(), color);

	auto textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

	SDL_FreeSurface(textSurface);
	if (this->MTextTexture != NULL) {
		SDL_DestroyTexture(this->MTextTexture);
		this->MTextTexture = NULL;
	}
	MTextTexture = textTexture;
}

int Text::GetTextRectW() {
	return MtextRect.w;
}
int Text::GetTextRectH() {
	return MtextRect.h;
}

SDL_Texture* Text::loadFont(SDL_Renderer *renderer , const std::string &fontPath, int fontSize, const std::string& text, const SDL_Color& color) {
	TTF_Font *font = TTF_OpenFont(fontPath.c_str(), fontSize);
	
	auto textSurface = TTF_RenderText_Solid(font, text.c_str(), color);

	auto textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

	SDL_FreeSurface(textSurface);
	return textTexture;

}