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
#include <conio2.h>







int main()
{
	TpFilaCirc f;
	char op, auxOp;
	
	Bordarear(0);
	
	inicializar(f);
	strcpy(f.nome, "tarefas_geradas.txt");
	do
	{
		Apagar(1);
		gotoxy(7,5);
		
		textcolor(14); printf("<");
		textcolor(13); printf("[");
		textcolor(10); printf(" FABRICA DE BRINQUEDOS ");
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
                textcolor(10); printf(" FABRICA DE BRINQUEDOS ");
                textcolor(14); printf(">>");
                textcolor(10); printf(" SIMULAR ARQUIVO TEXTO ");
                textcolor(13); printf("]");
                textcolor(14); printf(">");
                  
                textcolor(7);
                          
                Bordarear(0);
                
				getNomeArq(f.nome);
				break;
			}
			case 'B':{
				
				if(strcmp(f.nome, "Vazio") == 0){
					gotoxy(7, 26);
					printf("Arquivo não inserido, considere inserir na opcao A");
					getch();
				}
				else{
					
					clrscr();
	                gotoxy(7,5);
	                  
	                textcolor(14); printf("<");
	                textcolor(13); printf("[");
	                textcolor(10); printf(" FABRICA DE BRINQUEDOS ");
	                textcolor(14); printf(">>");
	                textcolor(10); printf(" NOME ARQUIVO A SER SIMULADO ");
	                textcolor(13); printf("]");
	                textcolor(14); printf(">");
	                  
	                textcolor(7);
	                          
	                Bordarear(0);
		                
					gotoxy(7, 12);
					printf("Voce vai simular o arquivo ");
					textcolor(14);printf("%s", f.nome);textcolor(7);
					printf(" deseja continuar?");
					printf("s/n");
					
					auxOp = getch();
					if(auxOp == 's'){
						
						simular(f);
						getch();
					}
				}
				break;
			}
		}
	}while(op!= 27);
	return 0;
}
