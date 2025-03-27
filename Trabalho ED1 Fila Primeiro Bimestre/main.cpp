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

/*
Daniel Sodre
Gabriel Lopes
Thiago Marques

888888ba                    oo          dP    .d88888b                 dP                   
88    `8b                               88    88.    "'                88                   
88     88 .d8888b. 88d888b. dP .d8888b. 88    `Y88888b. .d8888b. .d888b88 88d888b. .d8888b. 
88     88 88'  `88 88'  `88 88 88ooood8 88          `8b 88'  `88 88'  `88 88'  `88 88ooood8 
88    .8P 88.  .88 88    88 88 88.  ... 88    d8'   .8P 88.  .88 88.  .88 88       88.  ... 
8888888P  `88888P8 dP    dP dP `88888P' dP     Y88888P  `88888P' `88888P8 dP       `88888P'


 .88888.           dP                oo          dP    dP                                            
d8'   `88          88                            88    88                                            
88        .d8888b. 88d888b. 88d888b. dP .d8888b. 88    88        .d8888b. 88d888b. .d8888b. .d8888b. 
88   YP88 88'  `88 88'  `88 88'  `88 88 88ooood8 88    88        88'  `88 88'  `88 88ooood8 Y8ooooo. 
Y8.   .88 88.  .88 88.  .88 88       88 88.  ... 88    88        88.  .88 88.  .88 88.  ...       88 
 `88888'  `88888P8 88Y8888' dP       dP `88888P' dP    88888888P `88888P' 88Y888P' `88888P' `88888P' 
                                                                          88                         
                                                                          dP

d888888P dP       oo                               8888ba.88ba                                                        
   88    88                                        88  `8b  `8b                                                       
   88    88d888b. dP .d8888b. .d8888b. .d8888b.    88   88   88 .d8888b. 88d888b. .d8888b. dP    dP .d8888b. .d8888b. 
   88    88'  `88 88 88'  `88 88'  `88 88'  `88    88   88   88 88'  `88 88'  `88 88'  `88 88    88 88ooood8 Y8ooooo. 
   88    88    88 88 88.  .88 88.  .88 88.  .88    88   88   88 88.  .88 88       88.  .88 88.  .88 88.  ...       88 
   dP    dP    dP dP `88888P8 `8888P88 `88888P'    dP   dP   dP `88888P8 dP       `8888P88 `88888P' `88888P' `88888P' 
                                   .88                                                  88                            
                               d8888P                                                   dP

*/
int main()
{
	TpFilaCirc f;
	char op, auxOp;
	
	Bordarear(0);
	
	inicializar(f);
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
