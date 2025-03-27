#include "TadFilaCirc.h"
#include <conio2.h>
#include <time.h>

//funções
void getNomeArq(char nome[100]);
void getDadosArq(TpFilaCirc &f, FILE *auxArq);
void exibirFilaQtde(TpFilaCirc f, int qtde);
void simular(TpFilaCirc f);
//funções

//funções menu
char menu();
void Apagar(int x);
void Moldura(int xi , int xf, int yi, int yf);
void Bordarear(int x);
//funções menu


char menu(){
	gotoxy(7,10);  printf("[ A ] Definir nome do arquivo a ser simulado");
	gotoxy(7,12);  printf("[ B ] Simular arquivo texto");
	
	gotoxy(7,15);  printf("[Esc] Sair");
	
	gotoxy(6,17);  printf(" Opcao: ");
	
	return toupper(getch());
}
void Apagar(int x){
	int i, y;
	
	if(x==1)
	{
		gotoxy(6,5);	printf("                                                                                  ");
	}
		
	for(i=9;i<32;i++)	
	{
		gotoxy(6,i);	printf("                                                                                  ");
	}
}
void Moldura(int xi , int xf, int yi, int yf){
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
void Bordarear(int x){
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


// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=


void getNomeArq(char nome[100]){
	char aux[100];
	
	gotoxy(57, 10); textcolor(15); printf("Arquivo: ");
	gotoxy(66, 10); textcolor(14); printf("%s", nome);
	
	textcolor(7);
	
	gotoxy(7, 14);
	printf("Nome do arquivo a ser atualizado: ");
	fflush(stdin);
	gets(aux);
	
	if(strcmp(aux, "\0") != 0 )
	{
		FILE *auxArq = fopen(aux, "r+");
		
		if(auxArq == NULL){
			gotoxy(7, 26);
			printf("Arquivo invalido!");
		}
		else{
			gotoxy(7, 26);
			printf("Arquivo valido!");
			strcpy(nome, aux);
		}
		getch();
		fclose(auxArq);
	}
}


void getDadosArq(TpFilaCirc &f, FILE *auxArq){
	char aux[10];
	int i;
	TpTarefa tarefa;
	while(!feof(auxArq)){
		fscanf(auxArq,"%[^,],%d,%[^\n]\n",&aux,&tarefa.tempo,&tarefa.desc);
		if(strcmp("Urgente", aux) == 0){
			tarefa.prioridade = 3;
			f.qtdeU++;
		}
		else{
			if(strcmp("Normal", aux) == 0){
				tarefa.prioridade = 2;
				f.qtdeN++;
			}
			else{
				tarefa.prioridade = 1;
				f.qtdeO++;
			}
		}
		if(!filaCheia(f.fim)){
			inserir(f,tarefa);
			for(i=f.fim; i>f.inicio && f.fila[i].prioridade > f.fila[i-1].prioridade; i--){
				tarefa = f.fila[i];
				f.fila[i] = f.fila[i-1];
				f.fila[i-1] = tarefa;
			}
		}
	}
}

void exibirFilaQtde(TpFilaCirc f, int qtde){
	int i=0, y=18, auxMenu = 18;
	TpTarefa aux;
	while(!filaVazia(f.fim) && i<qtde){
		gotoxy(9,y);
		printf("                                                                          ");
		gotoxy(9,y);
		aux = retirar(f);
		printf("Fila %d: %s - tempo: %d", i+1, aux.desc, aux.tempo);
		i++;
		y++;
	}
}



void simular(TpFilaCirc f){
	FILE *auxArq = fopen(f.nome, "r+");
	FILE *auxRel = fopen("Relatorio.txt", "w");
	int qtdeTotal, qtdeTrab, duracao, qtdeTerminada=0, tempoTrabalhado=0;
	int i, y=10, auxMenu=10;
	clock_t t;
	fseek(auxArq,0,0);
	getDadosArq(f, auxArq);
	qtdeTotal = f.fim;
	
    gotoxy(7,5);
      
    textcolor(14); printf("<");
    textcolor(13); printf("[");
    textcolor(10); printf(" FABRICA DE BRINQUEDOS ");
    textcolor(14); printf(">>");
    textcolor(10); printf(" ARQUIVO = ");
    textcolor(6); printf(" tarefas_geradas ");
    textcolor(14); printf(">>");
    textcolor(10); printf(" SENDO SIMULACAO ");
    textcolor(13); printf("]");
    textcolor(14); printf(">");
      
    textcolor(7);
              
    Bordarear(0);
	                
	gotoxy(7, 14);
	printf("Digite a quantidade de operadores (inteiros de 1 a 5): ");
	scanf("%d", &qtdeTrab);
	if(qtdeTrab >5 || qtdeTrab<1){
		gotoxy(7,16);
		printf("quantidade invalida!!");
	}
	else{
		TpTarefa trabalhando[qtdeTrab];
		for(i=0;i<qtdeTrab;i++){
			trabalhando[i] = retirar(f);
		}
		gotoxy(7, 16);
		printf("Digite a duracao da simulacao (inteiros de 1 a 10000): ");
		scanf("%d", &duracao);
		Apagar(0);
		if(duracao>0){
			fprintf(auxRel,"Prioridade - Estado - Tempo - Operador - Descricao\n");
			gotoxy(9, 9);
			printf("Trabalhadores:");
			gotoxy(9,17);
			printf("Fila:");
			exibirFilaQtde(f, 5);
			t = clock();
			do{
				for(i=0; i<qtdeTrab; i++){
					if(trabalhando[i].tempo == 0){
						fprintf(auxRel, "%d - Concluido - %d - %s\n",trabalhando[i].prioridade, i+1 ,trabalhando[i].desc);
						qtdeTerminada++;
						switch(trabalhando[i].prioridade){
							case 3:
								f.u += clock() - t;
							case 2:
								f.n += clock() - t;
							case 1:
								f.o += clock() - t;
								break;
						}
						if(!filaVazia(f.qtde)){
							trabalhando[i] = retirar(f);
							exibirFilaQtde(f, qtdeTrab);
						}
					}
					if(trabalhando[i].tempo>-1){
						trabalhando[i].tempo--;
					}
					if(trabalhando[i].tempo ==9){
						exibirFilaQtde(f, qtdeTrab);
					}
					gotoxy(9,y);
					printf("                                                                          ");
					gotoxy(9,y);
					printf("Trabalhador %d: %s - tempo: %d", i+1 , trabalhando[i].desc, trabalhando[i].tempo);
					y++;
					if(y==auxMenu+qtdeTrab)
						y=10;
				}
				//Sleep(100);
				tempoTrabalhado++;
				duracao--;
				gotoxy(66 , 9);
				printf("                      ");
				gotoxy(66, 9);
				textcolor(8);
				printf("Tempo Restante: %d", duracao+1);
				textcolor(7);
			}while(!kbhit() && duracao > 0);
			
			if(duracao > 0){
				gotoxy(9, 25);
				printf("Simulacao encerrada antecipadamente!!");
			}
			else{
				gotoxy(9, 25);
				printf("Simulacao encerrada!!");
			}
			for(i=0; i<qtdeTrab; i++){
				if(trabalhando[i].tempo == 0){
					fprintf(auxRel, "%d - Concluido - %d - %s\n",trabalhando[i].prioridade, i+1 ,trabalhando[i].desc);
					qtdeTerminada++;
				}
				if(trabalhando[i].tempo>0){
					fprintf(auxRel, "%d - Inconcluido - %d - %d - %s\n",trabalhando[i].prioridade,trabalhando[i].tempo, i+1 ,trabalhando[i].desc);
				}	
			}
			gotoxy(9, 27);
			printf("Tempo trabalhado: %d", tempoTrabalhado);
			gotoxy(9, 28);
			printf("Numero Total de Tarefas Concluidas: %d", qtdeTerminada);
			gotoxy(9, 29);
			printf("Numero total de tarefas não concluidas: %d", (qtdeTotal-qtdeTerminada)+1);
			gotoxy(9,31);
			
			printf("Media de:   Opcional=%f   Normal=%f   Urgente=%f",((f.o/CLOCKS_PER_SEC)*(qtdeTotal-(f.qtdeU+f.qtdeN)))/(qtdeTotal-(f.qtdeU+f.qtdeN)),((f.n/CLOCKS_PER_SEC)*(qtdeTotal-(f.qtdeU+f.qtdeO)))/(qtdeTotal-(f.qtdeU+f.qtdeO)), ((f.u/CLOCKS_PER_SEC)*(qtdeTotal-(f.qtdeO+f.qtdeN)))/(qtdeTotal-(f.qtdeO+f.qtdeN)));
			/*clock_t teste;
			teste = clock();
			printf("\nclock agora %d", teste);
			Sleep(5000);
			printf("\nclock agora %d ---- %d", clock(), ((clock()-teste)/CLOCKS_PER_SEC));*/
		}
	}
	fclose(auxArq);
	fclose(auxRel);
}











