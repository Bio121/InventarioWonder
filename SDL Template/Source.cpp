#include "Header.h"

using namespace std;

#define WIDTH 1920
#define HEIGHT 1080
#define FPS 24
#define frameDelay (1000/FPS)
#define ITEM_PER_PAGE 8
#define IMG_PATH "sample.png"

SDL_Renderer* renderer = NULL;

SDL_Rect srcR;
/*La variable fondo contiene una imagen que además de ser una imagen del
juego de donde se basó el inventario también cuenta con las teclas que se usan para que cualquiera al correr el programa pueda saber que tecla hace cada cosa*/
Img::Image fondo;
//Bag es el que se encarga de almacenar, crear y borrar los objetos ademas de manejar la listas doblemente ligadas de los items.
BackPack Bag;
/*Jugador es una variable de tipo equipo que se quedo en desarrollo. Se encarga de almacenar y manejar los slots de equipo pero por el momento solo cuenta con 3 que no diferencias entre arma o gear*/
Equipo jugador;


int main(int argc, char* args[]) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
       std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    //se inicia el ttf para poder usar el la libreria y permitirnos escribir
    if (TTF_Init() == -1) {
        std::cout << "ttf Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    SDL_Window* window = SDL_CreateWindow("r/gamedev", 100, 100, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    

    /*Carga la imagen de fondo así como ajustar su posición y tamaño en caso de querer quitar el fondo y solo dejar las teclas que se pueden usar se puede cambiar la imagen por assets/controles.png*/
    Img::SetRenderer(renderer);
    Bag.Init(renderer);
    jugador.InitImage(renderer);
    Img::LoadImage("assets/fondo.png", fondo);
    fondo.rect.x = 0;
    fondo.rect.y = 0;
    fondo.rect.w = 1920;
    fondo.rect.h = 1080;

    SDL_Event event;
    bool quit = false;

    Uint32 frameStart;
    int frameTime;

    while (!quit) {

        frameStart = SDL_GetTicks();

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            else if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_ESCAPE) {
                quit = true;
            }
            //verifica si se puede mover
            if (jugador.GetBlockKey() == 0) {
                //cambia la paguina en la que se encuentra
                if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_RIGHT)
                {
                    Bag.SetInPage(Bag.GetInPage() + 1);
                }
                if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_LEFT)
                {
                    Bag.SetInPage(Bag.GetInPage() - 1);
                }
                //crea un arma aleatoria
                if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_c)
                {
                
                    Bag.CreateItem(1);
                    Bag.UpdateItemStats(renderer);
                }
                //crea un gear aleatorio
                if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_v)
                {
                    Bag.CreateItem(0);
                    Bag.UpdateItemStats(renderer);
                }
                //borra el item seleccionado
                if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_b)
                {
                    Bag.DeleteOneItem(Bag.GetPosSelect());
                    Bag.UpdateItemStats(renderer);
                }
                //entra en proceso de equipacion de un arma si se esta seleccionando una
                if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_e)
                {
                    if (Bag.GetPosSelect() < Bag.GetTotalItems())
                        jugador.SetBlockKey(1);
                }
                //entra en proceso de desequipar un arma
                if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_r)
                {
                       jugador.SetBlockKey(2);
                }

                //W A S D sirven para moverte por la mochila 
                if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_d)
                {
                    Bag.SetPosSelect(Bag.GetPosSelect() + 1);
                    Bag.UpdatePosition();
                    Bag.UpdateItemStats(renderer);
                }
                if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_a)
                {
                    Bag.SetPosSelect(Bag.GetPosSelect() - 1);
                    Bag.UpdatePosition();
                    Bag.UpdateItemStats(renderer);
                }
                if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_w)
                {
                    Bag.SetPosSelect(Bag.GetPosSelect() - 2);
                    Bag.UpdatePosition();
                    Bag.UpdateItemStats(renderer);
                }
                if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_s)
                {
                    Bag.SetPosSelect(Bag.GetPosSelect() + 2);
                    Bag.UpdatePosition();
                    Bag.UpdateItemStats(renderer);
                }
            }
            //equipa el objeto seleccionado en el slot 1 en caso de estar ocupado manda el item de ese lugar al final de la mochila
            if ((event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_1) && jugador.GetBlockKey() == 1)
            {
                Bag.PointOneItem(jugador.slot1, Bag.GetPosSelect());
                Bag.UpdateItemStats(renderer);
                jugador.SetBlockKey(0);
            }
            if ((event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_1) && jugador.GetBlockKey() == 2)
            {
                Bag.UnequipItem(jugador.slot1);
                jugador.SetBlockKey(0);
            }
            //equipa el objeto seleccionado en el slot 2 en caso de estar ocupado manda el item de ese lugar al final de la mochila
            if ((event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_2) && jugador.GetBlockKey() == 1)
            {
                Bag.PointOneItem(jugador.slot2, Bag.GetPosSelect());
                Bag.UpdateItemStats(renderer);
                jugador.SetBlockKey(0);
            }
            if ((event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_2) && jugador.GetBlockKey() == 2)
            {
                Bag.UnequipItem(jugador.slot2);
                jugador.SetBlockKey(0);
            }
            //equipa el objeto seleccionado en el slot 3 en caso de estar ocupado manda el item de ese lugar al final de la mochila
            if ((event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_3) && jugador.GetBlockKey() == 1)
            {
                Bag.PointOneItem(jugador.slot3, Bag.GetPosSelect());
                Bag.UpdateItemStats(renderer);
                jugador.SetBlockKey(0);
            }
            if ((event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_3) && jugador.GetBlockKey() == 2)
            {
                Bag.UnequipItem(jugador.slot3);
                jugador.SetBlockKey(0);
            }
        }

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }

        // clear the screen
        SDL_RenderClear(renderer);

        //Do render and game logic
        GameLoop(window);

        // flip the backbuffer
        // this means that everything that we prepared behind the screens is actually shown
        SDL_RenderPresent(renderer);
    }
    // en esta parte se borra todo lo que esta almacenado en los punteros para asegurarse que no quede nada flotando en la computadora
    //se eliminan los objetos de los slots del jugador liberando el especio en memoria
    jugador.CleanSolt(jugador.slot1);
    jugador.CleanSolt(jugador.slot2);
    jugador.CleanSolt(jugador.slot3);
    //Bag manda primero eliminar el texto ecistente con Deletet All para despues mandar borrar todo los Item en la mochila
    Bag.DelteAll();
    Bag.DeleteAllItem();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    TTF_Quit();
    return 0;
}

void GameLoop(SDL_Window* window) {
    //al momento de hacer el render primero se manda la imagen de fondo con las teclas
    SDL_RenderCopy(renderer, fondo.texture, NULL, &fondo.rect);
    //Despues se hace un render de las cosas que tiene la mochila asi como todo lo de la ventana de la derecha esto se hace dentro de la mochila
    Bag.RenderInBackPack(renderer);
    //aqui se manda hacer el render de las estadisticas del arma en que estamos posicionados pero en caso de no estar sobre ninguna aqui no se hace nada 
    Bag.RenderItemStats(renderer);
    //para terminar se hace un render de la ventana del lado izquierdo que tiene los objetos equipados 
    jugador.RenderItem(renderer);

}