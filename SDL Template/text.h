#pragma once
#include <SDL_ttf.h>
#include <SDL.h>
#include <string>

class Text
{
public:
	Text(SDL_Renderer* renderer, const std::string &fontPath, int fontSize, const std::string &text, const SDL_Color &color);
	void Display(int , int, SDL_Renderer*);
	SDL_Texture* loadFont(SDL_Renderer*,const std::string&, int , const std::string& , const SDL_Color& );
	
	~Text();
	int GetTextRectW();
	int GetTextRectH();
	void SetText(SDL_Renderer*, const std::string&, int, const std::string&, const SDL_Color&);
private:
	SDL_Texture* MTextTexture = nullptr;
	SDL_Rect MtextRect;
};

