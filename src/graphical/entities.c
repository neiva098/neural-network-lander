#include <GL/glew.h>
#include <SOIL/SOIL.h>

void setTexture(char *file[], GLuint *ptr)
{
    glClearColor(0, 0, 0, 0);

    *ptr = SOIL_load_OGL_texture(
        "NaveMãe.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y);
}

void desenhaHerois()
{
    for (int i = 0; i < numHerois; i++)
    {
        glBindTexture(GL_TEXTURE_2D, heroi[i].textura);
        glBegin(GL_POLYGON);
        glTexCoord2f(0, 0);
        glVertex3f(heroi[i].coordenadas.x, heroi[i].coordenadas.y, 0);
        glTexCoord2f(1, 0);
        glVertex3f(heroi[i].coordenadas.x + heroi[i].tamanho.largura, heroi[i].coordenadas.y, 0);
        glTexCoord2f(1, 1);
        glVertex3f(heroi[i].coordenadas.x + heroi[i].tamanho.largura, heroi[i].coordenadas.y + heroi[i].tamanho.altura, 0);
        glTexCoord2f(0, 1);
        glVertex3f(heroi[i].coordenadas.x, heroi[i].coordenadas.y + heroi[i].tamanho.altura, 0);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, heroi[i].texturaFogo);
        glBegin(GL_POLYGON);
        glTexCoord2f(0, 0);
        glVertex3f(heroi[i].coordenadas.x + 1.25, heroi[i].coordenadas.y - heroi[i].tamanhoFogo, 0);
        glTexCoord2f(1, 0);
        glVertex3f(heroi[i].coordenadas.x + 6.25, heroi[i].coordenadas.y - heroi[i].tamanhoFogo, 0);
        glTexCoord2f(1, 1);
        glVertex3f(heroi[i].coordenadas.x + 6.25, heroi[i].coordenadas.y, 0);
        glTexCoord2f(0, 1);
        glVertex3f(heroi[i].coordenadas.x + 1.25, heroi[i].coordenadas.y, 0);
        glEnd();
    }
}

void desenhaInimigos()
{
    for (int i = 0; i < numInimigos; i++)
    {
        glBindTexture(GL_TEXTURE_2D, inimigos[i].textura);
        glBegin(GL_POLYGON);
        glTexCoord2f(0, 0);
        glVertex3f(inimigos[i].coordenadas.x, inimigos[i].coordenadas.y, 0);
        glTexCoord2f(1, 0);
        glVertex3f(inimigos[i].coordenadas.x + inimigos[i].tamanho.largura, inimigos[i].coordenadas.y, 0);
        glTexCoord2f(1, 1);
        glVertex3f(inimigos[i].coordenadas.x + inimigos[i].tamanho.largura, inimigos[i].coordenadas.y + inimigos[i].tamanho.altura, 0);
        glTexCoord2f(0, 1);
        glVertex3f(inimigos[i].coordenadas.x, inimigos[i].coordenadas.y + inimigos[i].tamanho.altura, 0);
        glEnd();
    }
}

void desenhaPersonagens()
{
    glClear(GL_COLOR_BUFFER_BIT);

    for (int i = 0; i < 6; i++)
    {
        estrela(rand() % 100, rand() % 100);
    }

    glColor3f(1, 1, 1);
    glEnable(GL_TEXTURE_2D);

    desenhaHerois();
    desenhaInimigos();

    glFlush();
    glutSwapBuffers();
    glDisable(GL_TEXTURE_2D);
}