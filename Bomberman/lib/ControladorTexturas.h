#pragma once

#ifndef CONTROLADORTEXTURAS_H
#define CONTROLADORTEXTURAS_H

#include <map>

#include "SDL_opengl.h"
#include "FreeImage.h"
#include <GL/glu.h>

#include "../constantes/constantes.h"

using namespace std;

enum tipo_textura { //agregar aca en caso de agregar mas texturas, y la direccion en el cpp
	ESTRUCTURA_DESTRUCTIBLE,
	ESTRUCTURA_NO_DESTRUCTIBLE,
	PLAYER,
	TEXTURA_BOMBA,
	TEXTURA_PUERTA,
	TEXTURA_AUMENTAR_ALCANCE_BOMBA,
	TEXTURA_AUMENTAR_CANTIDAD_BOMBA,
	TEXTURA_AUMENTAR_VELOCIDAD,
	TEXTURA_BOMBAS_ATRAVIESAN_ESTRUCTURAS,
	TEXTURA_INMORTALIDAD,
};

class ControladorTexturas{
private:
	static map<tipo_textura, char*> direcciones_texturas;
	static map<tipo_textura, GLuint> texturas;
public:
	static void cargarTexturas();
	static GLuint getTextura(tipo_textura tipo) { return texturas[tipo]; };
};

#endif
