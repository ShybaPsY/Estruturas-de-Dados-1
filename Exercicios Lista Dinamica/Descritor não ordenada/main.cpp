#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#include <direct.h>
#include <conio.h>
#include "TadListaDinamicaDesc.h"



int main(){
	
	TpDesc d;
	inicializar(d);
	inserir(d, 17);
	inserir(d, 20);
	inserir(d, 15);
	inserir(d, 14);
	inserir(d, 13);
	
	exibir(d);
	printf("\n");
	
	alterar(d,15,36);
	
	if(buscaExaustiva(d, 16)!=NULL){
		printf("\n\nValor: %d\n",buscaExaustiva(d,16)->valor);	
	}
	else{
		printf("Valor nao existe\n");
	}
	
	printf("\n");
	exibir(d);
	
	return 0;
}
