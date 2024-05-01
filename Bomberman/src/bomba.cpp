#include "../lib/bomba.h"

bomba::bomba(vector_3 pos, vector_3 tam, int tiempo, int largo) : objeto(pos, tam) {
	tiempoBomba = tiempo;
	largoBomba = largo;
    agrandandose = false;
    scale = 1.0f;
}

int xBomba, zBomba, dx, dz, nx, nz;
void bomba::actualizar() {
    if (agrandandose) {
        scale += 0.01f;
        if (scale > 1.1f)
            agrandandose = false;
    }
    else {
        scale -= 0.01f;
        if (scale < 0.9f)
            agrandandose = true;
    }

    tiempoBomba -= frameDelay * velocidad_juego;
    bool alcanza;
    if (tiempoBomba <= 0) {
        xBomba = getIndiceTablero(pos.x);
        zBomba = getIndiceTablero(pos.z);

        for (int dir = 0; dir < 4; dir++) {
            dx = 0;
            dz = 0;
            alcanza = false;

            if (dir == 0)  // z fijo, x incrementa
                dx = 1;
            else if (dir == 1)  // z fijo, x decrementa
                dx = -1;
            else if (dir == 2)  // x fijo, z incrementa
                dz = 1;
            else if (dir == 3)  // x fijo, z decrementa
                dz = -1;

            for (int i = 1; i <= largoBomba && !alcanza; i++) {
                nx = xBomba + i * dx;
                nz = zBomba + i * dz;

                if (nx >= 0 && nx < largoTablero && nz >= 0 && nz < anchoTablero) {
                    if (ControladorPoderes::getEstaActivo(BOMBAS_ATRAVIESAN_ESTRUCTURAS) || estructuras[nx][nz] == nullptr) {
                        if (fuegos[nx][nz] != nullptr)
                            delete fuegos[nx][nz];

                        fuegos[nx][nz] = new fuego(
                            { GLfloat(nx * tile_size) + tile_size / 2 , 0.0f, GLfloat(nz * tile_size) + tile_size / 2 },
                            { tile_size / 2, tile_size, tile_size / 2 },
                            1500
                        );
                    }

                    if (estructuras[nx][nz] != nullptr) {
                        alcanza = !ControladorPoderes::getEstaActivo(BOMBAS_ATRAVIESAN_ESTRUCTURAS);
                        estructura* est = dynamic_cast<estructura*>(estructuras[nx][nz]);
                        if (est->getDestructible()) {
                            estructuras[nx][nz] = nullptr;
                            delete est;
                        }
                    }
                }
                else {
                    alcanza = true; 
                }
            }
        }

        if (fuegos[xBomba][zBomba] != nullptr) 
            delete fuegos[xBomba][zBomba];

        fuegos[xBomba][zBomba] = new fuego(
            { GLfloat(xBomba * tile_size) + tile_size / 2 , 0.0f, GLfloat(zBomba * tile_size) + tile_size / 2 },
            { tile_size / 2, tile_size, tile_size / 2 },
            1500
        );

        jugador->disminuirCantBomba();

        ControladorCamara::sacudir(1000);

        bombas[xBomba][zBomba] = nullptr;
        delete this;
    }
}


void bomba::dibujar() {
    glPushMatrix();
    glTranslatef(pos.x, pos.y, pos.z);
    glScalef(scale, scale, scale);
    ControladorObjetos::dibujar(OBJ_BOMBA);
    glPopMatrix();
}