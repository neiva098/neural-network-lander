#include "redeNeural.c"

#ifndef _TYPES_H_
#define _TYPES_H_

typedef struct twoDimensionsValues {
    float x;
    float y;
} twoDimensionsValues;

typedef struct pouso{
    int inicio;
    int fim;
} pouso;

typedef struct tamanho2D {
    float largura, altura;
} tamanho2D;

typedef struct inimigo {
    twoDimensionsValues velocidade;
    twoDimensionsValues coordenadas;
    tamanho2D tamanho;
    GLuint textura;
} inimigo;

typedef struct personagem {
    twoDimensionsValues coordenadas;
    float vida;
    RedeNeural* Cerebro;
    twoDimensionsValues velocidadeAtual;
    twoDimensionsValues velocidadeAnterior;
    twoDimensionsValues aceleracao;
    inimigo inimigos[4];
    tamanho2D tamanho;
    int tamanhoFogo;
    GLuint textura;
    GLuint texturaFogo;
} personagem;

#endif 