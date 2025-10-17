#include "raylib.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define LARGURA 600
#define ALTURA 600

int main(){

    InitWindow(LARGURA, ALTURA, "Quadrado"); //Inicializa janela, com certo tamanho e titulo
    SetTargetFPS(60);// Ajusta a janela para 60 frames por segundo
    srand(time(NULL));

    int x = rand() % 581;
    int y = rand() % 581;

    //Este laco repete enquanto a janela nao for fechada
    //Utilizamos ele para atualizar o estado do programa / jogo
    while (!WindowShouldClose())
    {
	// Trata entrada do usuario e atualiza estado do jogo
	if (IsKeyPressed(KEY_RIGHT)) {
	    x += 20;
	}
	if (IsKeyPressed(KEY_LEFT)) {
	    x -= 20;
	}
	if (IsKeyPressed(KEY_UP)) {
	    y -= 20;
	}
	if (IsKeyPressed(KEY_DOWN)) {
	    y +=20;
	}
	if (x > 600 || x < 0 || y > 600 || y < 0)
	{
	    CloseWindow();
	}


	// Atualiza o que eh mostrado na tela a partir do estado do jogo
	BeginDrawing(); //Inicia o ambiente de desenho na tela
	ClearBackground(RAYWHITE); //Limpa a tela e define cor de fundo
	DrawRectangle(x, y, 20, 20, GREEN);
	EndDrawing(); //Finaliza o ambiente de desenho na tela
    }

    CloseWindow(); // Fecha a janela
    return 0;
}

