#include "variables.h"
#include "entitys.c"
#include <GL/freeglut.h>

void guardaVelocidadeAtual(int idHeroi)
{
    heroi[idHeroi].velocidadeAnterior.y = heroi[idHeroi].velocidadeAtual.y;
    heroi[idHeroi].velocidadeAnterior.x = heroi[idHeroi].velocidadeAtual.x;
}

void fimdejogo(int isVitory)
{
    if (isVitory == 0)
        escreveTexto(GLUT_BITMAP_HELVETICA_18, "DERROTA", 25, 80, 0);
    if (isVitory == 1)
        escreveTexto(GLUT_BITMAP_HELVETICA_18, "VITORIA", 25, 80, 0);
}

void inicializaInimigos(int numEnimigos)
{
    char textures[4][30] = {"Meteoro1.png", "Meteoro2.png", "NaveInimiga1.png", "NaveInimiga2.png"};
    for (int i = 0; i < numEnimigos; i++)
    {
        inimigos[i].coordenadas.x = rand() % 100;
        inimigos[i].coordenadas.y = rand() % 100;
        inimigos[i].tamanho.largura = rand() % 4 + 1;
        inimigos[i].tamanho.altura = rand() % 4 + 1;
        inimigos[i].velocidade.x = rand() % 2 + 1;
        inimigos[i].velocidade.y = (rand() % 3) + 1;
        setTexture(textures[rand() % 4], &inimigos[i].textura);
    }
}

void inicializaHerois(int numeroHerois)
{
    for (int i = 0; i < numeroHerois; i++)
    {
        heroi[i].tamanhoFogo = 3;
        heroi[i].coordenadas.x = rand() % 100;
        heroi[i].coordenadas.y = 15 + rand() % 85;
        heroi[i].tamanho.largura = 5;
        heroi[i].tamanho.altura = 5;
        heroi[i].vida = 100;
        setTexture("NaveMãe.png", &heroi[i].textura);
        setTexture("Fogo.png", &heroi[i].texturaFogo);
    }
    setTexture("Explosao.jpg", &texturaExplosao);
}

void inicializaPersonagens()
{
    inicializaHerois(numHerois);
    inicializaInimigos(numInimigos);
}

void sairDoJogo()
{
    if (pause == 1)
    {
        exit(0);
    }
    else
    {
        pause = 1;
    }
}

void pause()
{
    if (pause == 0)
    {
        pause = 1;
    }
    else
    {
        pause = 0;
    }
}

void reinicia()
{
    if (pause == 1)
    {
        reinicia = 1;
        pause = 0;
    }
    else
    {
        pause = 1;
    }
}

void reiniciaLocalDePouso()
{
    localPouso.inicio = rand() % 70;
    localPouso.fim = localPouso.inicio + 10 + rand() % 10;
}

void reiniciaHandler()
{
    reiniciaPosicaoHerois();
    reiniciaPosicoesInimigos();
    reiniciaLocalDePouso();
    reinicia = 0;
}

void limiteTelaInimigosHandler()
{
    for (int i = 0; i < numInimigos; i++)
    {
        if (inimigos[i].coordenadas.x > 100 || inimigos[i].coordenadas.x < 0 ||
            inimigos[i].coordenadas.y > 100 || inimigos[i].coordenadas.y < 0)
        {
            inimigos[i].velocidade.x = -inimigos[i].velocidade.x;
            inimigos[i].velocidade.y = -inimigos[i].velocidade.y;
        }
    }
}

void limiteTelaHeroisHandler()
{
    for (int i = 0; i < numHerois; i++)
    {
        if (heroi[i].coordenadas.x > 100 || heroi[i].coordenadas.x < 0 ||
            heroi[i].coordenadas.y > 100 || heroi[i].coordenadas.y < 0)
        {

            guardaVelocidadeAtual(i);
            heroi[i].velocidadeAtual.x = -heroi[i].velocidadeAtual.x;
            heroi[i].velocidadeAtual.y = -heroi[i].velocidadeAtual.y;
        }
    }
}

void limiteTelaHandler()
{
    limiteTelaHeroisHandler();
    limiteTelaInimigosHandler();
}

void colisoesHandler()
{
    for (int i = 0; i < numInimigos; i++)
    {
        for (int j = 0; j < numHerois; j++)
        {
            heroi[j].vida -= rand() % 50;
            twoDimensionsValues velocidadeInimigo = inimigos[i].velocidade;
            twoDimensionsValues velociadadeHeroi = heroi[j].velocidadeAtual;

            inimigos[i].velocidade.x = velociadadeHeroi.x + velocidadeInimigo.x;
            inimigos[i].velocidade.y = velociadadeHeroi.y + velocidadeInimigo.y;

            heroi[j].velocidadeAtual.x = velociadadeHeroi.x + velocidadeInimigo.x;
            heroi[j].velocidadeAtual.y = velociadadeHeroi.y + velocidadeInimigo.y;

            if (abs(velociadadeHeroi.x) > abs(velocidadeInimigo.x))
            {
                inimigos[i].velocidade.x = velociadadeHeroi.x - velocidadeInimigo.x;
                heroi[i].velocidadeAtual.x = velociadadeHeroi.x + velocidadeInimigo.x;
            }
            else
            {
                inimigos[i].velocidade.x = velociadadeHeroi.x + velocidadeInimigo.x;
                heroi[i].velocidadeAtual.x = velociadadeHeroi.x - velocidadeInimigo.x;
            }
            heroi[i].vida -= rand() % 50;
        }
    }
}

void endGameHandler()
{
    for (int i = 0; i < numHerois; i++)
    {
        int isFlying = heroi[i].coordenadas.y >= 10;
        int isOutOfLandingArea = heroi[i].coordenadas.x <= localPouso.inicio || heroi[i].coordenadas.x >= localPouso.fim;
        int haveLife = heroi[i].vida >= 0;

        if (isFlying && isOutOfLandingArea)
        {
            if (!haveLife)
            {
                heroi[i].vida = 0;
                looseGame();
            }
            glutPostRedisplay();
        }
        else
        {
            if (!isOutOfLandingArea && heroi[i].velocidadeAtual.y >= -0.12)
            {
                winGame();
            }
            else
            {
                looseGame();
            }
        }
    }
}

void looseGame()
{
    fimdejogo(0);
    pause = 1;
    reinicia = 1;
}

void winGame()
{
    fimdejogo(1);
    pause = 1;
    reinicia = 1;
}

void atualizaEstado()
{
    if (pause == 1)
        menu();
    glutTimerFunc(33, atualiza, 0);
    handleStarsAnimation();
}
