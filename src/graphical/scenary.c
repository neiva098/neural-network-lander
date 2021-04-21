#include <GL/freeglut.h>
#include "variables.h"

void inicializaCenario()
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void desenhaEstrela(int pX, int pY)
{
    float rx, ry;
    double l = PI / 20;

    glColor3f(1, 1, 1);
    glBegin(GL_LINE_LOOP);

    for (double i = 0; i < 6.29; i += l)
    {
        rx = pX + raio * PI * cos(i);
        ry = pY + raio * PI * sin(i);

        glVertex2f(rx, ry);
    }
    glEnd();
}

void desenhaHUD(int heroiId)
{
    char vY[30] = "Velocidade em y  ";
    sprintf(vY + strlen(vY), "%.2f", heroi[heroiId].velocidadeAtual.y);
    char vX[30] = "Velocidade em x   ";
    sprintf(vX + strlen(vX), "%.4f", heroi[heroiId].velocidadeAtual.x); //colocar numero na string
    char h[30] = "Altitude  ";
    sprintf(h + strlen(h), "%.2f", heroi[heroiId].coordenadas.y);
    char aY[30] = "Aceleracao em y  ";
    sprintf(aY + strlen(aY), "%.3f", heroi[heroiId].velocidadeAtual.y - heroi[heroiId].velocidadeAnterior.y); //VELOCIDADE ATUAL MENOS ANTERIOR
    char aX[30] = "Aceleracao em x  ";
    sprintf(aX + strlen(aX), "%.3f", heroi[heroiId].velocidadeAtual.x - heroi[heroiId].velocidadeAnterior.x);
    char vida[30] = "Vida:  ";
    sprintf(vida + strlen(vida), "%.1f", heroi[heroiId].vida);

    glColor3f(1.0, 0, 0);
    escreveTexto(GLUT_BITMAP_HELVETICA_10, h, 75, 90, 0);
    escreveTexto(GLUT_BITMAP_TIMES_ROMAN_10, vY, 75, 85, 0);
    escreveTexto(GLUT_BITMAP_TIMES_ROMAN_10, vX, 75, 80, 0);
    escreveTexto(GLUT_BITMAP_TIMES_ROMAN_10, aY, 75, 75, 0);
    escreveTexto(GLUT_BITMAP_TIMES_ROMAN_10, aX, 75, 70, 0);
    escreveTexto(GLUT_BITMAP_TIMES_ROMAN_10, vida, 75, 95, 0);
    glEnd();
    ;
}

void desenhaChao()
{
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_POLYGON);
    glVertex2f(0, 0);
    glVertex2f(0, 10);
    glVertex2f(100, 10);
    glVertex2f(100, 0);
    glEnd();
}

void desenhaAreaDePouso()
{
    glColor3f(0, 1, 0);
    glBegin(GL_POLYGON);
    glVertex2f(localPouso.inicio, 10);
    glVertex2f(localPouso.inicio + 3, 13);
    glVertex2f(localPouso.fim, 13);
    glVertex2f(localPouso.fim + 3, 10);
    glEnd();
}

void inicializaCenario()
{
    desenhaChao();
    desenhaAreaDePouso();
}

void redimensiona(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 100, 0, 100, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}