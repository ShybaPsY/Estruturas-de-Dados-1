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




char menu(){
	printf("[A]inserir nome do arquivo\n");
	printf("[B]Simular arquivo\n");
	
	return toupper(getch());
}


int main()
{
	TpDescDev d;
	char op, auxOp, nomeArq[50];
	
	
	inicializarDev(d);
	strcpy(nomeArq, "Vazio");
	strcpy(nomeArq, "Dados.txt");   // Ferramenta do desenvolvedor
	do
	{
		gotoxy(7,5);
		
		textcolor(14); printf("<");
		textcolor(13); printf("[");
		textcolor(10); printf(" DESENVOLVEDORES DE SOFTWARE ");
		textcolor(13); printf("]");
		textcolor(14); printf(">");
		
		textcolor(7);
		
		op = menu();
		
		switch(op)
		{
			case 'A':{

				clrscr();
                gotoxy(7,5);
                  
                textcolor(14); printf("<");
                textcolor(13); printf("[");
                textcolor(10); printf(" DESENVOLVEDORES DE SOFTWARE ");
                textcolor(14); printf(">>");
                textcolor(10); printf(" SIMULAR ARQUIVO TEXTO ");
                textcolor(13); printf("]");
                textcolor(14); printf(">");
                  
                textcolor(7);
                
				getNomeArq(nomeArq);
				break;
			}
			case 'B':{
				
				if(strcmp(nomeArq, "Vazio") == 0){
					gotoxy(7, 26);
					printf("Arquivo não inserido, considere inserir na opcao A");
					getch();
				}
				else{
					
					clrscr();
	                gotoxy(7,5);
	                  
	                textcolor(14); printf("<");
	                textcolor(13); printf("[");
	                textcolor(10); printf(" DESENVOLVEDORES DE SOFTWARE ");
	                textcolor(14); printf(">>");
	                textcolor(10); printf(" NOME ARQUIVO A SER SIMULADO ");
	                textcolor(13); printf("]");
	                textcolor(14); printf(">");
	                  
	                textcolor(7);
		                
					gotoxy(7, 12);
					printf("Voce vai simular o arquivo ");
					textcolor(14);
					printf("%s", nomeArq);
					textcolor(7);
					printf(" deseja continuar?");
					printf("s/n");
					
					auxOp = getch();
					if(auxOp == 's'){
						
						simular(d, nomeArq);
						getch();
					}
				}
				break;
			}
		}
	}while(op!= 27);
	return 0;
}
