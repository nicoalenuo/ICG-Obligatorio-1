#include "../lib/bomba.h"

bomba::bomba(GLfloat x, GLfloat z, float tiempo, int largo) : objeto(x,z) {
	this->tiempoBomba = tiempo;
	this->largoBomba = largo;
	this->jugador = nullptr;
}

float bomba::getTiempoBomba() {
	return this->tiempoBomba;
}

void bomba::setTiempoBomba(float tiempo) {
	this->tiempoBomba = tiempo;
}

int bomba::getLargoBomba() {
	return this->largoBomba;
}

void bomba::setLargoBomba(int largo) {
	this->largoBomba = largo;
}

personaje* bomba::getJugador() {
	return this->jugador;
}

void bomba::setJugador(personaje* jug) {
	this->jugador = jug;
}

void bomba::actualizar() {

}

void bomba::dibujar() {

}