#pragma once
#include "item.h"
//la clase equipo se creo para manejar los slots de objetos equipados que tiene el jugador pero se quedo en desarrollo por lo que por el momento
//solo puede equiparse 3 item sin importar el tipo
class Equipo
{
public:
    //constructor y destructor no utilizados
    Equipo() {};
    ~Equipo() {};
    //inicializa las imagenes que no cambian a lo largo del programa para esto ocupan como parametro el renderer que se esta usando actualmente
    void InitImage(SDL_Renderer*);
    //aqui se borra lo que tenga el slot del inventario que se manda ademas de volverlo null esto sirve para ser mandado llamar al final del programa y asegurar que no se quede memoria volando
    void CleanSolt(item*);
    /*regresa la variable MblockKey que sirve para saber si se esa en medio de un proseco de equipar o desequipar un item evitando que se mueva a alguna otra parte*/
    int GetBlockKey();
    /*se le asigna un nuevo valor a MblockKey para saber es estatus del jugador siendo
    0=libre
    1=equipando un item
    2=desequipando un item
    para esto se envia un nuevo valor en el parametro*/
    void SetBlockKey(int);
    /*muestra todos los item equipados asi como el recuadro de la izquierda y en caso de estar en medio de el proceso de equipar o desequipar un item muestra un mendaje para que lo sepa
    el jugador*/
    void RenderItem(SDL_Renderer*);
    /*estos tres punteros son los tres slots donde el jugador puede tener sus armas*/
    item* slot1;
    item* slot2;
    item* slot3;
private:
    Img::Image MEquipo;
    Img::Image MMensaje;
    int MblockKey = false;
};

