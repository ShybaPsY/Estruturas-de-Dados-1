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
	inicializar(f);
	int semaforo = 0;
	int cont=0;
	TpCarro carro;
	
	srand(time(0));
	do{
		if(semaforo < 4){
			carro.modelo = rand()%5;
			switch(carro.modelo){
				case 0:{
					printf("\nPalio entrou no semaforo");
					break;
				}
				case 1:{
					printf("\nFord KA entrou no semaforo");
					break;
				}
				case 2:{
					printf("\nGol quadrado com nitro entrou no semaforo");
					break;
				}
				case 3:{
					printf("\nFiat Uno entrou no semaforo");
					break;
				}
				case 4:{
					printf("\nHB20 entrou no semaforo");
					break;
				}
			}
			inserir(f, carro.modelo, semaforo);
		}
		else{
			if(semaforo<8){
				carro = retirar(f);
				switch(carro.modelo){
					case 0:{
						printf("\nPalio saiu no semaforo");
						break;
					}
					case 1:{
						printf("\nFord KA saiu no semaforo");
						break;
						}
					case 2:{
						printf("\nGol quadrado com nitro saiu no semaforo");
						break;
					}
					case 3:{
						printf("\nFiat Uno saiu no semaforo");
						break;
					}
					case 4:{
						printf("\nHB20 saiu no semaforo");
						break;
					}
				}
				cont++;
			}
			else{
				semaforo = -1;
			}
		}
		semaforo++;
	}while(!kbhit());
	
	printf("\n\n\n\n\n");
	
	while(!filaVazia(f.qtde)){
		printf("\nPosicao %d: ", f.qtde);
		carro = retirar(f);
		switch(carro.modelo){
			case 0:{
				printf("Palio ");
				break;
			}
			case 1:{
				printf("Ford KA ");
				break;
				}
			case 2:{
				printf("Gol quadrado com nitro ");
				break;
			}
			case 3:{
				printf("Fiat Uno ");
				break;
			}
			case 4:{
				printf("HB20 ");
				break;
			}
		}
		printf("e ficou %d segundos no semaforo", semaforo - carro.tempo);
	}
	
	getch();
	getch();
	return 0;
}
