#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#include <direct.h>
#include <conio.h>
#include "TadFilaCirc.h"

int main(){
	TpFilaCirc f;
	int valor, op;
	inicializar(f);
	srand(time(0));
	
	do{
		valor = rand()%99+1;
		op =rand()%2;
		if(op == 1){
			if(!filaCheia(f.qtde)){
				printf("\nInserido: %d", valor);
				inserir(f, valor);
			}
		}
		else{
			if(!filaVazia(f.qtde)){
				printf("\nRetirado: %d", retirar(f));
			}
		}
	}while(!kbhit());
	getch();
	printf("\n\n");
	exibir(f);
	getch();
	printf("\n\n");
	esvaziar(f);
	getch();
	printf("\n\n");
	exibir(f);
	getch();
	return 0;
}

