#pragma once
#include "item.h"
/*la clase gear es hija de la clase item esta tiene como principal diferencia que no cuenta con un daño elemental al menos los gear con los que se esta trabajando*/
class gear : public item
{
public:
	/*como minimo para ser creado te pide un nombre*/
	gear(std::string);
	/*aqui es donde se crea y llenan todos los datos del gear usadno los metodos set de su padre para esto se requiere los siguientes datos
	la puntuacion del gear
	el nivel
	nombre 
	manufactura numero de 0 a 4
	tipo de item siendo un numero de 4 a 6
	rareza siendo un numero del 0 a 4
	la descripcion
	el precio en entero
	la estadistica del daño siendo un numero del 0 al 6
	y el porcentaje del daño que aumenta esto puede tener decimal*/
	gear(int, int, std::string, int, int, int, std::string, int, int, float);

	~gear();
	/*se obtiene o asigna un valor a las variables que se encuentrar privadas*/
	int GetDamageStat();
	void SetDamageStat(int );
	float GetSecondaryStatsDescription();
	void SetSecondaryStatsDescription(float );

private:
	int MDamageStats;
	float MSecondaryStatsDescription;
};

