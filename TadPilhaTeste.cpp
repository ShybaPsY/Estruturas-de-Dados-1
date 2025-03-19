#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#include <direct.h>
#include <conio.h>
#include "TadPilha.h"

int main(){
	TpPilha p;
	int valor, op;
	inicializar(p);
	srand(time(0));
	
	do{
		valor = rand()%99+1;
		op =rand()%2;
		if(op == 1){
			if(!pilhaCheia(p.topo)){
				printf("\nInserido: %d", valor);
				inserir(p, valor);
			}
		}
		else{
			if(!pilhaVazia(p.topo)){
				printf("\nRetirado: %d", retirar(p));
			}
		}
	}while(!kbhit());
	getch();
	printf("\n\n");
	exibir(p);
	getch();
	printf("\n\n");
	esvaziar(p);
	getch();
	printf("\n\n");
	return 0;
}

