#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#include <direct.h>
#include <conio.h>
#include "functions.h"
// === Funções de interface ===

// Desenha borda retangular
void desenhaBorda(int x1, int y1, int x2, int y2) {
    textcolor(LIGHTCYAN);

    gotoxy(x1, y1); printf("%c", 201); // canto sup. esquerdo
    gotoxy(x2, y1); printf("%c", 187); // canto sup. direito
    gotoxy(x1, y2); printf("%c", 200); // canto inf. esquerdo
    gotoxy(x2, y2); printf("%c", 188); // canto inf. direito

    for (int x = x1 + 1; x < x2; x++) {
        gotoxy(x, y1); printf("%c", 205); // linha topo
        gotoxy(x, y2); printf("%c", 205); // linha base
    }

    for (int y = y1 + 1; y < y2; y++) {
        gotoxy(x1, y); printf("%c", 186); // lateral esquerda
        gotoxy(x2, y); printf("%c", 186); // lateral direita
    }
}

// Escreve texto na tela com cor e posição
void escreveTexto(int x, int y, int cor, const char *texto) {
    textcolor(cor);
    gotoxy(x, y);
    printf("%s", texto);
}

// Desenha barra lateral esquerda
void barraLateral() {
    desenhaBorda(5, 3, 30, 22);

    escreveTexto(8, 5, LIGHTGREEN, "== MENU ==");

    escreveTexto(8, 8, WHITE, "[A] Inserir Nome");
    escreveTexto(8, 9, WHITE, "[B] Simular Arq.");
    escreveTexto(8, 10, WHITE, "[ESC] Sair");
}

// Limpa somente a área de execução (direita)
void limpaAreaExecucao() {
    for (int y = 4; y <= 21; y++) {
        for (int x = 33; x <= 99; x++) {
            gotoxy(x, y);
            printf(" ");
        }
    }
}

// === Código Original Adaptado para a Interface ===

char menu() {
    gotoxy(35, 6);
    printf("[A] Inserir nome do arquivo");
    gotoxy(35, 7);
    printf("[B] Simular arquivo");
    gotoxy(35, 9);
    printf("Escolha uma opcao: ");
    return toupper(getch());
}

int main() {
    TpDescDev d;
    char op, auxOp, nomeArq[50];

    inicializarDev(d);
    strcpy(nomeArq, "Vazio");
    strcpy(nomeArq, "Dados.txt");   // Ferramenta do desenvolvedor

    // Desenha a interface inicial
    barraLateral();
    desenhaBorda(32, 3, 100, 22);

    do {
        limpaAreaExecucao();

        escreveTexto(35, 5, LIGHTCYAN, "<[ DESENVOLVEDORES DE SOFTWARE ]>");

        op = menu();

        switch(op) {
            case 'A': {
                limpaAreaExecucao();

                escreveTexto(35, 5, LIGHTCYAN, "<[ DESENVOLVEDORES DE SOFTWARE ]>> INSERIR NOME DO ARQUIVO");

                getNomeArq(nomeArq);
                break;
            }
            case 'B': {
                if(strcmp(nomeArq, "Vazio") == 0) {
                    gotoxy(35, 12);
                    printf("Arquivo nao inserido. Use a opcao A.");
                    getch();
                } else {
                    limpaAreaExecucao();

                    escreveTexto(35, 5, LIGHTCYAN, "<[ DESENVOLVEDORES DE SOFTWARE ]>> SIMULAR ARQUIVO");

                    gotoxy(35, 10);
                    printf("Voce vai simular o arquivo ");
                    textcolor(LIGHTMAGENTA);
                    printf("%s", nomeArq);
                    textcolor(WHITE);
                    printf(". Deseja continuar? (s/n)");

                    auxOp = getch();
                    if(auxOp == 's' || auxOp == 'S') {
                        simular(d, nomeArq);
                        getch();
                    }
                }
                break;
            }
        }
    } while(op != 27); // 27 = ESC

    limpaAreaExecucao();
    escreveTexto(45, 12, LIGHTCYAN, "Programa finalizado!");
    escreveTexto(40, 14, WHITE, "Pressione qualquer tecla para sair...");
    getch();

    return 0;
}
