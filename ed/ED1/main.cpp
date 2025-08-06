#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#include <direct.h>
#include <conio.h>
#include <conio2.h>
#include "functions.h"


// Gabriel Mendes Lopes
// Thiago Marques Cristino
// Daniel Sodré



char menu() {
    gotoxy(8, 12);
    printf("Escolha uma opcao: ");
    return toupper(getch());
}

int main() {
    TpDescDev d;
    char op, auxOp, nomeArq[50];

    inicializarDev(d);
    strcpy(nomeArq, "Vazio");
    strcpy(nomeArq, "Dados.txt");

    barraLateral();
    desenhaBorda(36, 3, 180, 25);

    do {
        limpaAreaExecucao();

        escreveTexto(45, 5, LIGHTCYAN, "<[ DESENVOLVEDORES DE SOFTWARE ]>");

        op = menu();

        switch(op) {
            case 'A': {
               limpaAreaExecucao();

			    // Título da operação (ajustado para não invadir a barra lateral)
			    escreveTexto(45, 5, LIGHTCYAN, ">>> INSERIR NOME DO ARQUIVO <<<");
			
			    // Mensagem de instrução para o usuário
			    gotoxy(45, 7);
			    printf("Digite o nome do arquivo:");
			
			    // Local onde o usuário digita (na linha de baixo)
			    gotoxy(45, 9);
			    textcolor(WHITE);
			    getNomeArq(nomeArq);

                break;
            }
            case 'B': {
                limpaAreaExecucao();  //Limpa antes de mostrar qualquer coisa

			    escreveTexto(45, 5, LIGHTCYAN, ">>> SIMULAR ARQUIVO <<<");
			
			    if(strcmp(nomeArq, "Vazio") == 0) {
			        gotoxy(45, 7);
			        printf("Arquivo nao inserido.");
			        gotoxy(45, 8);
			        printf("Use a opcao [A] para inserir.");
			        getch();
			    } else {
			        gotoxy(45, 7);
			        printf("Nome do arquivo a ser simulado:");
			
			        textcolor(LIGHTMAGENTA);
			        printf(" %s", nomeArq);
			        textcolor(WHITE);
			
			        gotoxy(45, 9);
			        printf("Deseja continuar? (s/n)");
			
			        auxOp = getch();
			        if(auxOp == 's' || auxOp == 'S') {
			            limpaAreaExecucao(); // ?? Limpa antes de rodar a simulação
			            simular(d, nomeArq);
			            getch();
			        }
			    }
                break;
            }
        }
    } while(op != 27);

    limpaAreaExecucao();
    escreveTexto(50, 12, LIGHTCYAN, "Programa finalizado!");
    escreveTexto(45, 14, WHITE, "Pressione qualquer tecla para sair...");
    getch();

    return 0;
}

