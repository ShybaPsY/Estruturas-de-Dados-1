#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#include <direct.h>
#include <conio.h>
#include "TadFilaDuplaDinamicaDesc.h"
#include <conio2.h>

int main(){
	
	TpDesc d;
	inicializar(d);
	
	inserirInicio(d, "Gabriel");
	inserirInicio(d, "Joao");
	inserirInicio(d, "Roberto");
	inserirInicio(d, "Agnaldo");
	inserirInicio(d, "Thiago");
	
	exibir(d);
	printf("\n\n");
	exibirInvertido(d);
	
	excluirFim(d);
	printf("\n\n");
	exibir(d);
	inserirFim(d,"Robson");
	printf("\n\n");
	exibir(d);
	
	liberarLista(d);
	if(vazio(d)){
		printf("\n\n");
		printf("vazia\n");
		inserirFim(d, "Leandro");
		exibir(d);
	}
	return 0;
}
