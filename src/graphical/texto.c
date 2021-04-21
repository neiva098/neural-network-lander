#include <GL/glew.h>
#include <GL/freeglut.h>
#include <string.h>

void escreveTexto(void *font, char *s, float x, float y, float z)
{
    glColor3f(1.0, 0, 0);
    glRasterPos3f(x, y, z);

    for (int i = 0; i < strlen(s); i++)
    {
        glutBitmapCharacter(font, s[i]);
    }

    glFlush();
}

void menu()
{
    escreveTexto(GLUT_BITMAP_HELVETICA_18, "PARA CONTINUAR TECLE P", 25, 60, 0);
    escreveTexto(GLUT_BITMAP_HELVETICA_18, "PARA SAIR TECLE ESC", 25, 50, 0);
    escreveTexto(GLUT_BITMAP_HELVETICA_18, "PARA REINICIAR TECLE R", 25, 40, 0);
    escreveTexto(GLUT_BITMAP_HELVETICA_10, "Objetivo do jogo e pousar na area demarcada", 1, 90, 0);
    escreveTexto(GLUT_BITMAP_HELVETICA_10, "a uma velocidade em y menor que 0.12", 1, 86, 0);
}
