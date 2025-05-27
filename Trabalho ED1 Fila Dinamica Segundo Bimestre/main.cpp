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
#include "tad.h"
#include <conio2.h>


int main(){
	
	TpDescDev d;
	
	inicializarDev(d);
	inserirDev(d, "Gabriel");
	TpData data;
	data.dia = data.mes = data.ano = 1;
	TpCaixaTarefa *aux = criarCaixaTarefa(2, 15, "Teste numero 1", "Thiago", data);
	inserirTarefa(d, "Gabriel", aux);
	aux = criarCaixaTarefa(0, 15, "Teste numero 2", "Leandro", data);
	inserirTarefa(d, "Gabriel", aux);
	aux = criarCaixaTarefa(1, 15, "Teste numero 3", "Robson", data);
	inserirTarefa(d, "Gabriel", aux);
	aux = criarCaixaTarefa(2, 15, "Teste numero 4", "Rafael", data);
	inserirTarefa(d, "Gabriel", aux);
	inserirDev(d, "Fabio");
	inserirDev(d, "Hugo");
	inserirDev(d, "Joao");
	
	excluirDev(d, "Gabriel");
	if(!devVazio(d)){
		exibirDev(d, "Hugo");
		printf("\n\n");
		exibirDev(d, "Fabio");
		printf("\n\n");
		exibirDev(d, "Joao");
		
		
		//printf("\tDev %s\n",dev.fim->nome)
	}
	
	
	
	return 0;
}
