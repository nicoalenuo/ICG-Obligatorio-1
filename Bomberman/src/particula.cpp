#include "../lib/particula.h"

particula::particula(vector_3 pos, vector_3 tam, vector_3 ac, vector_3 vel) : objeto(pos, tam) {
    tiempoParticula = 0;
    pos_y_inicial = pos.y;
    this->ac = ac;
    this->vel = vel;
}

GLfloat tiempoSegundos;
void particula::actualizar() {
    tiempoSegundos = GLfloat(tiempoParticula) / 1000.0f;
    pos.x = pos.x + vel.x;
    pos.y = ac.y * tiempoSegundos * tiempoSegundos + 
        vel.y * tiempoSegundos + 
        pos.y;
    pos.z = pos.z + vel.z;
    tiempoParticula += frameDelay;
}

void particula::dibujar() {
    glPushMatrix();

    glTranslatef(pos.x, pos.y, pos.z);
    glBegin(GL_QUADS);

    glColor3f(1.0, 1.0, 1.0);

    glVertex3f(-tam.x, 0, -tam.z);
    glVertex3f(tam.x, 0, -tam.z);
    glVertex3f(tam.x, 0, tam.z);
    glVertex3f(-tam.x, 0, tam.z);

    // Cara de arriba
    glVertex3f(-tam.x, tam.y, -tam.z);
    glVertex3f(tam.x, tam.y, -tam.z);
    glVertex3f(tam.x, tam.y, tam.z);
    glVertex3f(-tam.x, tam.y, tam.z);

    // Cara de atras
    glVertex3f(-tam.x, 0, -tam.z);
    glVertex3f(tam.x, 0, -tam.z);
    glVertex3f(tam.x, tam.y, -tam.z);
    glVertex3f(-tam.x, tam.y, -tam.z);

    // Cara de adelante
    glVertex3f(-tam.x, 0, tam.z);
    glVertex3f(tam.x, 0, tam.z);
    glVertex3f(tam.x, tam.y, tam.z);
    glVertex3f(-tam.x, tam.y, tam.z);

    // Cara izquierda
    glVertex3f(-tam.x, 0, -tam.z);
    glVertex3f(-tam.x, 0, tam.z);
    glVertex3f(-tam.x, tam.y, tam.z);
    glVertex3f(-tam.x, tam.y, -tam.z);

    // Cara derecha
    glVertex3f(tam.x, 0, -tam.z);
    glVertex3f(tam.x, 0, tam.z);
    glVertex3f(tam.x, tam.y, tam.z);
    glVertex3f(tam.x, tam.y, -tam.z);
    glEnd();
    glPopMatrix();
}