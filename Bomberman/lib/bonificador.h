#pragma once

#ifndef BONIFICADOR_H
#define BONIFICADOR_H

#include "objeto.h"

enum tipo_poder { //Colocar aca los tipos
	AUMENTAR_ALCANCE_BOMBAS,
	INMORTALIDAD, //nose, tirar ideas aca
	AUMENTAR_VELOCIDAD,
	BOMBAS_ATRAVIESAN_ESTRUCTURAS,
};

class bonificador : public objeto {
private:
	tipo_poder tipo; 
public:
	bonificador(posicion pos, tamanio tam, tipo_poder tipo);

	tipo_poder getTipo();
	void setTipo(tipo_poder tipo);

	void actualizar();
	void dibujar();
};


#endif

