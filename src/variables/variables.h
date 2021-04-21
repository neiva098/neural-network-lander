#include "types.h"
#include <GL/glew.h>


#define g 0.004
#define PI 3.1415926535897932
#define atrito 0.001
#define numInimigos 4
#define numHerois 20

inimigo inimigos[4];
personagem heroi[];
pouso localPouso;
GLuint texturaExplosao;
float raio = 0;
int pause = 0;
int reinicia = 0;