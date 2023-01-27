#define main SDL_main
#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "image.h"
#include "item.h"
#include "text.h"
#include "BackPack.h"
#include "Equipo.h"


void GameLoop(SDL_Window* window);