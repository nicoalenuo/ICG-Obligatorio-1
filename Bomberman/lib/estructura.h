#pragma once

#ifndef ESTRUCTURA_H
#define ESTRUCTURA_H

#include "objeto.h"

class estructura : public objeto {
private:
	bool destructible; 
public:
	estructura(posicion pos, tamanio tam, bool dest);

	bool getDestructible();
	void setDestructible(bool dest);

	void actualizar();
	void dibujar();
};


#endif

