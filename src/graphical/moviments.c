void acaoSubir(int heroiId)
{
    guardaVelocidadeAtual(heroiId);
    heroi[heroiId].velocidadeAtual.y += 0.02;

    if (heroi[heroiId].tamanhoFogo < 6)
    {
        heroi[heroiId].tamanhoFogo += 1;
    }
}

void acaoVirarEsquerda(int heroiId)
{
    guardaVelocidadeAtual(heroiId);
    heroi[heroiId].velocidadeAtual.y += 0.01;
    heroi[heroiId].velocidadeAtual.x -= 0.01;
    if (heroi[heroiId].tamanhoFogo < 6)
    {
        heroi[heroiId].tamanhoFogo += 0.5;
    }
}

void acaoVirarADireita(int heroiId)
{
    guardaVelocidadeAtual(heroiId);
    heroi[heroiId].velocidadeAtual.y += 0.01;
    heroi[heroiId].velocidadeAtual.x += 0.01;
    if (heroi[heroiId].tamanhoFogo < 6)
    {
        heroi[heroiId].tamanhoFogo += 1;
    }
}

void doNothing(int heroiId)
{
    guardaVelocidadeAtual(heroiId);
    if (heroi[heroiId].tamanhoFogo > 2)
    {
        heroi[heroiId].tamanhoFogo -= 0.1;
    }
}

void tecladoHandler(int key, int heroiId)
{
    switch (key)
    {
    case GLUT_KEY_UP:
        acaoSubir(heroiId);
        break;
    case GLUT_KEY_LEFT:
        acaoVirarEsquerda(heroiId);
        break;
    case GLUT_KEY_RIGHT:
        acaoVirarADireita(heroiId);
        break;
    case 27:
        sairDoJogo();
        break;
    case 'p':
        pause();
        break;
    case 114:
        reinicia();
        break;
    default:
        doBothing(heroiId);
        break;
    }
}

void atualizaMovimentoHeroi()
{
    for (int i = 0; i < numHerois; i++)
    {
        heroi[i].coordenadas.x += heroi[i].velocidadeAtual.x;
        heroi[i].coordenadas.y += heroi[i].velocidadeAtual.y;

        heroi[i].velocidadeAtual.y -= g;

        if (heroi[i].velocidadeAtual.x > 0)
            heroi[i].velocidadeAtual.x -= atrito;

        if (heroi[i].velocidadeAtual.x < 0)
            heroi[i].velocidadeAtual.x += atrito;
    }
}

void atualizaMovimentoInimigo()
{
    for (int i = 0; i < numInimigos; i++)
    {
        inimigos[i].coordenadas.x += inimigos[i].velocidade.x;
        inimigos[i].coordenadas.y += inimigos[i].velocidade.y;
    }
}

void reiniciaPosicaoHerois()
{
    for (int i = 0; i < numHerois; i++)
    {
        heroi[i].coordenadas.x = 5 + rand() % 80;
        heroi[i].coordenadas.y += 20 + rand() % 80;
        heroi[i].velocidadeAtual.x = 0;
        heroi[i].velocidadeAtual.y = 0;
        heroi[i].vida = 100;
    }
}

void reiniciaPosicoesInimigos()
{
    for (int i = 0; i < numInimigos; i++)
    {
        inimigos[i].coordenadas.x += rand() % 100;
        inimigos[i].coordenadas.y += 20 + rand() % 80;
        inimigos[i].velocidade.x = rand() % 4 + 1;
        inimigos[i].velocidade.y = rand() % 4 + 1;
    }
}

void handleStarsAnimation()
{
    if (raio >= 0.1)
        raio = 0;
    raio += 0.01;
}