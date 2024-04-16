#pragma once

#ifndef GLOBAL_H
#define GLOBAL_H

#include <list>

#include "SDL.h"
#include "SDL_opengl.h"
#include <GL/glu.h>


#include <stdio.h>
#include <iostream>

using namespace std;

class bomba;

class global { 
private:
	static global* instancia;
	global();
public:

	bool moverArriba;
	bool moverIzquierda;
	bool moverDerecha;
	bool moverAbajo;

	int mouseX;
	const double generadorTerreno = 0.6; //probabilidad de 0 a 1 de generar terreno destructible
	const GLfloat largoEstructura = 2;
	static global* getInstance();
};


#endif