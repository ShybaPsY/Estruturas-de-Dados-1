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


void sortearCarro(TpCarro &carro){
	srand(time(0));
	int op = rand()%5;
	
	switch(op){
		case 0:{
			strcpy(carro.nome, "Fusca");
			break;
		}
		case 1:{
			strcpy(carro.nome, "Camaro");
			break;
		}
		case 2:{
			strcpy(carro.nome, "Corolla");
			break;
		}
		case 3:{
			strcpy(carro.nome, "Civic");
			break;
		}
		case 4:{
			strcpy(carro.nome, "Jeep");
			break;
		}
	}
}


int main(){
	srand(time(0));
	TpFila f;
	TpCarro carro;
	int qtdeSaida=0, op, semaforo = 0;
	inicializar(f);
	do{		
		op = rand()%2;
		if(op == 1){
			if(!filaCheia(f.fim)){
				carro.entrada = clock();
				sortearCarro(carro);
				inserir(f, carro);
				printf("\nEntrou no semaforo: %s", carro.nome);
			}
			else{
				printf("\nSemaforo cheio");
			}
		}
		
		if(semaforo < 4){
			if(!filaVazia(f.fim)){
				carro = retirar(f);
				printf("\nSaiu do semaforo: %s entrou ao tempo %d e esperou %d", carro.nome, carro.entrada/CLOCKS_PER_SEC, (clock() - carro.entrada)/CLOCKS_PER_SEC);
				qtdeSaida++;
			}
			else{
				printf("\nSemaforo Vazio");
			}
		}
		else
			if(semaforo == 7)
				semaforo = -1;
		semaforo++;
		Sleep(1000);
	}while(!kbhit());
	getch();
	getch();
	return 0;
}













