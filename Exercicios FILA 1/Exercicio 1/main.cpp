#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#include <direct.h>
#include <conio.h>
#include "TadFila.h"


int main(){
	TpFila f;
	inicializar(f);
	srand(time(0));
	int i=0, j;
	do{
		i = rand()%2;
		if(i==1){
			if(!cheia(f.fim)){
				j = rand()%100;
				printf("Inserido: %d\n", j);
				inserir(f,j);
			}
		}
		else{
			if(!vazia(f.fim))
				printf("Retirado: %d\n",retirar(f));
		}
	}while(!kbhit());
	printf("\n\n\n\n");
	exibir(f);
	getch();
	return 0;
}
