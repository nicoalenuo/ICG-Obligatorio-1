#pragma once

#ifndef GLOBAL_H
#define GLOBAL_H

#include "../constantes/constantes.h"
#include <list>

using namespace std;

struct vector_3 {
	GLfloat x;
	GLfloat y;
	GLfloat z;
};

class objeto;
class particula;
class bomberman;
class door;
class enemigo;

extern int velocidad_juego;

extern bool moverArriba;
extern bool moverAbajo;
extern bool moverDerecha;
extern bool moverIzquierda;

extern GLfloat mouseX;
extern GLfloat mouseY;
extern GLfloat mouseY_invertido;

extern int cantLuces;

extern bool pausa;
extern bool pararTiempo;
extern bool wireframe;
extern bool pantallaCompleta;
extern bool texturas_habilitadas;
extern bool mute;

extern unsigned int pasos;

extern int puntaje;
extern bool tipoLuz;
extern bool inmortal;
extern bool atravesar_paredes;

extern objeto*** estructuras;
extern objeto*** bombas;
//extern objeto*** enemigos;
extern objeto*** fuegos;
extern objeto*** bonificadores;

extern list<objeto*> borde;
extern list<particula*> particulas;

extern list<enemigo*> enemigos;

extern bomberman* jugador;
extern door* puerta;

extern int getIndiceTablero(GLfloat coord);

extern bool fin;
extern bool finJuego;
extern int nivel;
extern int puntaje; 
extern int tiempoJuego; //segundos
extern bool puertaAbierta;

extern void toggle_pausa(); //muestra la interfaz de settings ademas de pausar
extern void toggle_wireframe();
extern void toggle_texturas();
extern void toggle_tipoLuz();
extern void toggle_inmortal();
extern void toggle_atravesar_paredes();

extern void aumentarNivel();
extern void sumarPuntaje(int puntos);
extern void disminuirTiempo(int segundos);
extern void pausarTiempo();

extern int largoPantalla;
extern int altoPantalla;
#endif
