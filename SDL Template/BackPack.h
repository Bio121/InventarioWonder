#pragma once
#include "weapon.h"
#include "gear.h"
#include "itemInfo.h"
#include "text.h"
#include "image.h"
/*se define cuando objetos estaran en total en la paguina, por el momento por la forma en que 
se muestra cambiar este numero puede hacer que el inventario se desacomode o no funcione de la manera que se espera*/
#define ITEM_PER_PAGE 8
/*la clase BackPack es la que se encarga de almacenar y manejar los item usando listas ligadas, tambien es donde se crean los item de manera aleatoria de una lista existente
 y aqui es donde se ralizan la mayoria de los render del lado izquierdo*/
class BackPack
{
public:
    // en el constructor se inicializa la cantidad de espacios que se tiene en la mochila, esto se hace de manera directa con 24 espacios y dichos espacios pueden cambiar despues usando otros metodos
	BackPack();
    /*esta funcion se manda a llamar dandole como parametro un int con el que se decide si crear un arma o un gear de la lista, para que sea un arma se debe mandar 1 y cualquier otro numero
    manda crear un gear. ademas de ser aqui donde se agrega el elemento creado al final de la lista y aumenta en 1 la cantidad de objetos que se tiene en la mochila*/
	void CreateItem(int);
    /*CreateRealWeapon crea de manera aleatoria un arma escoguiendo de una lista de 12 que tiene y lo coloca en el puntero aux de la clase, este metodo se necesita llamar
    dentro de la clase create item para ser colocado dentro de la lista en caso contrario aunque se cree el item no sera colocado dentro y posteriormente quedara volando en la computadora*/
	void CreateRealWeapon();
    /*CreateRealGear crea de manera aleatoria un gear escoguiendo de una lista de 9 objetos que tiene y lo coloca en el puntero aux de la clase, este metodo se necesita llamar
  dentro de la clase create item para ser colocado dentro de la lista en caso contrario aunque se cree el item no sera colocado dentro y posteriormente quedara volando en la computadora*/
	void CreateRealGear();
    /*Aqui se tiene que mandar el renderer para usarlo al mandar renderizar todo lo que aparece en los slots de la mochila, estos son
    la manufactura del item ademas de cambiarle el color segun la rareza del item, en caso de ser un arma tambien renderiza su elemento,
    cambia el color de los slots segun la rareza de los items y la imagen del item*/
	void RenderAllItem(SDL_Renderer*);
	/*aqui se borra todo item de la mochila eliminando todo objeto de la lista esto sirve para asegurarse de que no se quede con nada al momento de terminar el programa pero
    tambien tiene uso para poder vaciar el inventario en caso de ser necesario*/
    void DeleteAllItem();
    /*como su nombre lo indica esta funcion elimina un objeto de la lista, para indicar que objeto es el que se va a borrar se manda la posicion como parametro
    ademas de restar 1 a la cantidad de objetos en la mochila. Como seguridad si la posicion mandada es menor que la cantidad de objetos en la mochila no hace nada*/
	void DeleteOneItem(int);
    /*esta funcion sirve para posicionar el puntero aux en un item especifico de la lista, la manera que lo hace es mandandole la posicion que se quiere en el parametro
    esta funcion esta pensada mas que nada para ser llamada dentro de la misma clase. Como seguridad si la posicion mandada es menor que la cantidad de objetos en la mochila no hace nada */
	void GetOneItem(int);
    /*regresa en que paguina del inventario se encuentra actualmente el jugador*/
    int GetInPage();
    /*asinga un nuevo valor a la variable MinPage enviado en el parametro asi mismo verifica que este dentro de 0 y 2 debido a que solo se tienen 3 paguinas de inventario
    es mas usado para ir incrementando o disminuyendo  de uno en uno la paguina*/
    void SetInPage(int);
    /* regresa la poscion en la que se encuentra actualmente del inventario*/
    int GetPosSelect();
    /*asigna la posicion actual del usuario dentro del inventario usando el parametro que se tiene*/
    void SetPosSelect(int);
    /*este metodo se le Manda como parametro la dirreccion de memoria de un puntero tipo item para que apunte a un item especifico de la lista siendo ese item el que se pide
    usando el segundo parametro que es la posicion de la lista del item. para una vez hecho esto quitarlo de la lista, importante remarcar que solo lo esta quitando mas no borrando
    esto se utiliza para poder hacer que el puntero del slot de equipo del jugador tenga ahora el objeto seleccionado y deje de estar en la mochila*/
    void PointOneItem(item* &, int);
    /*en el parametro se manda la direccion de memoria de un puntero para agregarlo a la lista de objetos que se tiene en la mochila y como seguro convierte en null el puntero del slot para
    evitar que el mismo objeto este equipado y en la mochila al mismo tiempo. como seguridad antes de hacerlo checa que se tenga espacio en la mochila y el puntero enviado sea diferente de NULL
    en caso de que algo de esto no se cumpla aqui no se hace nada*/
    void UnequipItem(item*& );
    /*regresas la cantidad de item que se tiene en la mochila*/
    int GetTotalItems();
    /*aqui se cargan todas las imagenes y textos que siemre se encuentran en pantalla o que no cambian tales como los recudaros del los slots de la mochila, el cuadro grande
    de la mochila, algunos textos que nunca cambian. para hacer esto se ocupa el renderer y por esa misma razon se hace en esta funcion en lugar de en el constructor ya que
    se tiene que esperar a que el programa lo cree antes de aqui se pueda cargar las cosas*/
    void Init(SDL_Renderer*);
    /*aqui se limpian los punteros de texto que se tienen para mostrar la informacion del arma que se tiene seleccionada*/
    void CleanItemStats();
    /*este metodo borrado todo los textos que se tienen en la clase. esto se debe mandar a llamar al finalizar el programa para que se libere la memoria de los textos.
    la diferencia con el metodo de arriba es que borra tambien los textos que son estaticos*/
    void DelteAll();
    /*aqui se crea los nuevos textos que muestran la informacion del objeto seleccionado el orden en el que se debe enviar es:
    renderer el renderer que se esta usando
    itemScore es la puntuacion que tiene el item
    lvlReq el nivel minimo que pide el item
    rarity la rareza que tiene el item
    description la descripcion del item
    itemName el nombre del item
    price cuanto vale el item*/
    void NewItemStats(SDL_Renderer*, const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, const std::string&);
    /*esta funcion muestra el recuadro de las estadisticas del item que se tiene seleccionado para esto requiere que se le envie el renderer que se esta usando*/
    void RenderItemStats(SDL_Renderer* renderer);
    /*aqui actualiza la posicion de la imagen que sirve como apolo visual para ver que item esta siendo seleccionado en este momento*/
    void UpdatePosition();
    /*esta es el metodo que se manda a llamar a cada rato en el programa por lo que se coloca dentro todo lo que se piensa mostrara de la mochila
    aqui dentro van muchas de las funciones pasada que mostraban item. como las demas ocupa el renderer actual para poder mostrar las cosas en pantalla*/
    void RenderInBackPack(SDL_Renderer* renderer);
    /* este metodo se debe mandar a llamar cada vez que se mueve la posicion o que ocurre un cambio en la mochila para que verifique que las estadisticas a mostrar son 
    las del arma que se tiene seleccionada, aqui se limpian los punteros del texto ademas de volver a ponerles la informacion del objeto que se esta seleccionando*/
    void UpdateItemStats(SDL_Renderer* renderer);

private:	
    item* ori = NULL;
	item* endP = NULL;
	item* aux = NULL;
	itemInfo Minterprete;
	int MTotalSlots;
	int MTotalItems = 0;
    int MinPage = 0;
    int MposSel = 0;
    int MLastTypeItemInStatus;
    int MLastManufactureItemInStatus;
    int MLastElementItemInStatus;
    int MLastRarityItemInStatus;
	Text* MtexItemScoreNum = nullptr;
	Text* MtexItemScore = nullptr;
	Text* MtexLvlReq = nullptr;
	Text* MtexLvlReqNum = nullptr;
	Text* MtexItemName = nullptr;
	Text* MtexItemRarity = nullptr;
	Text* MtexDescription = nullptr;
	Text* MtexitemPrice = nullptr;
    Img::Image MitemSelect, MitemStats, MImageBag;
    Img::Image Mitems[24];
};
