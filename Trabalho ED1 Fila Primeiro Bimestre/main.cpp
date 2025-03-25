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
#include "TAD.h"


char menu(){
	printf("[A] Definir nome do arquivo a ser simulado");
	printf("[B] Simular arquivo texto");
	return toupper(getch());
}

int main(){
	TpFila f;
	char op, auxOp;
	inicializar(f);
	do{
		op = menu();
		switch(op){
			case 'A':{
				getNomeArq(f.nome);
				break;
			}
			case 'B':{
				if(strcmp(f.nome, "") == 0){
					printf("Arquivo não inserido, considere inserir na opcao A");
					getch();
				}
				else{
					printf("Você vai simular o arquivo %s deseja continuar?", f.nome);
					printf("s/n");
					auxOp = getch();
					if(auxOp == 's'){
						simular(f);
						getch();
					}
				}
				break;
			}
	}while(op!= 27);
}
