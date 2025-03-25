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
#include<conio2.h>


char menu(){
	gotoxy(7,10);  printf("[ A ] Definir nome do arquivo a ser simulado");
	gotoxy(7,12);  printf("[ B ] Simular arquivo texto");
	
	gotoxy(7,15);  printf("[Esc] Sair");
	
	gotoxy(6,17);  printf(" Opcao: ");
	
	return toupper(getch());
}


void Apagar(int x)
{
	int i, y, j=83;
	
	if(x==1)
	{
		gotoxy(6,5);	printf("                                                                                  ");
	}
		
	for(i=9;i<33;i++)	
	{
		gotoxy(6,i);	printf("                                                                                  ");
	}
}
void ApagarTUDO(int x)
{
	int i, y;
		
	for(i=1;i<55;i++)	
	{
		gotoxy(1,i);	printf("                                                                                                ");
	}
}
void Moldura(int xi , int xf, int yi, int yf)
{
	int i;
	
	gotoxy(xi,yi); 
	printf("%c",201);//------|
	                 //      |
	gotoxy(xi,yf);   //      |
	printf("%c",200);//      |
	                 //      | > Cantos da janela
	gotoxy(xf,yi);   //      |
	printf("%c",187);//      |
	                 //      |
	gotoxy(xf,yf);   //      |
	printf("%c",188);//------|
	
	for(i=xi+1;i<xf;i++)
	{
		gotoxy(i,yi);	printf("%c",205);
		gotoxy(i,yf);	printf("%c",205);
	}
	for(i=yi+1;i<yf;i++)
	{
		gotoxy(xi,i);	printf("%c",186);
		gotoxy(xf,i);	printf("%c",186);
	}
}	

void Bordarear(int x)
{
/*
	CE > coluna da esqueda 
	CD > coluna da direita 
	
	LC > linha de cima	
	LB > linha de baixo 
*/
	Apagar(x);
	//      CE  CD  LC  LB  
	Moldura( 3, 90,  3, 37);// EXTERNA
	Moldura( 5, 88,  4,  6);// INTERNA DE CIDA
	Moldura( 5, 88,  8, 36);// INTERNA DE BAIXO
}
void Bordarear_RELATORIO_GRANDE(int x)
{
/*
	CE > coluna da esqueda 
	CD > coluna da direita 
	
	LC > linha de cima	
	LB > linha de baixo 
*/
	Apagar(x);
	//      CE  CD  LC  LB  
	Moldura( 3, 90,  3, 51);// EXTERNA
	Moldura( 5, 88,  4,  6);// INTERNA DE CIDA
	Moldura( 5, 88,  8, 49);// INTERNA DE BAIXO
}



int main()
{
	TpFila f;
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
					printf("Você vai simular o arquivo  ");
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
}
