#include "TAD.h"
#include<conio2.h>

//funções
void getNomeArq(char nome[100]);
void getDadosArq(TpFila &f, FILE *auxArq);
void exibirFilaQtde(TpFila f, int qtde);
void simular(TpFila f);
//funções


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


void getDadosArq(TpFila &f, FILE *auxArq){
	char aux[10];
	int i;
	TpTarefa tarefa;
	while(!feof(auxArq)){
		fscanf(auxArq,"%[^,],%d,%[^\n]\n",&aux,&tarefa.tempo,&tarefa.desc);
		
		if(strcmp("Urgente", aux) == 0){
			tarefa.prioridade = 3;
		}
		else{
			if(strcmp("Normal", aux) == 0){
				tarefa.prioridade = 2;
			}
			else{
				tarefa.prioridade = 1;
			}
		}
		if(!cheia(f.fim)){
			inserir(f,tarefa);
			for(i=f.fim; i>0 && f.fila[i].prioridade > f.fila[i-1].prioridade; i--){
				tarefa = f.fila[i];
				f.fila[i] = f.fila[i-1];
				f.fila[i-1] = tarefa;
			}
		}
	}
}

void exibirFilaQtde(TpFila f, int qtde){
	int i=0;
	TpTarefa aux = retirar(f);
	while(!vazia(f.fim) && i<qtde){
		printf("Tarefa: %s - tempo: %d", aux.desc, aux.tempo);
		i++;
	}
}

void simular(TpFila f){
	FILE *auxArq = fopen(f.nome, "r+");
	FILE *auxRel = fopen("Relatorio.txt", "w");
	int qtdeTotal, qtdeTrab, duracao, qtdeTerminada=0, tempoTrabalhado=0;
	int i;
	fseek(auxArq,0,0);
	getDadosArq(f, auxArq);
	qtdeTotal = f.fim;
	
	gotoxy(7, 14);
	printf("Digite a quantidade de operadores: ");
	scanf("%d", &qtdeTrab);
	
	TpTarefa trabalhando[qtdeTrab];
	if(qtdeTrab>0){
		for(i=0;i<qtdeTrab;i++){
			trabalhando[i] = retirar(f);
		}
		gotoxy(7, 16);
		printf("Digite a duração da simulação em minutos inteiros: ");
		scanf("%d", &duracao);
		
		if(duracao>0){
			fprintf(auxRel,"Prioridade - Estado - Tempo - Descrição\n");
			exibirFilaQtde(f, 5);
			do{
				for(i=0; i<qtdeTrab; i++){
					if(trabalhando[i].tempo == 0){
						fprintf(auxRel, "%d - Concluido - %s\n",trabalhando[i].prioridade,trabalhando[i].desc);
						qtdeTerminada++;
						if(!vazia(f.fim))
							trabalhando[i] = retirar(f);
							exibirFilaQtde(f, 5);
					}
					else{
						trabalhando[i].tempo--;
						printf("Tarefa: %s - tempo: %d", trabalhando[i].desc, trabalhando[i].tempo);
					}
				}
				tempoTrabalhado++;
				duracao--;
			}while(!kbhit() && duracao > 0);
			
			if(duracao > 0){
				for(i=0; i<qtdeTrab; i++){
					if(trabalhando[i].tempo == 0){
						fprintf(auxRel, "%d - Concluido - %s\n",trabalhando[i].prioridade,trabalhando[i].desc);
						qtdeTerminada++;
					}
					if(trabalhando[i].tempo>0){
						fprintf(auxRel, "%d - Inconcluido - %d - %s\n",trabalhando[i].prioridade,trabalhando[i].tempo ,trabalhando[i].desc);
					}
				}
				printf("Simulacao encerrada antecipadamente!!");
			}
			else{
				for(i=0; i<qtdeTrab; i++){
					if(trabalhando[i].tempo == 0){
						fprintf(auxRel, "%d - Concluido - %s\n",trabalhando[i].prioridade,trabalhando[i].desc);
						qtdeTerminada++;
					}
					if(trabalhando[i].tempo>0){
						fprintf(auxRel, "%d - Inconcluido - %d - %s\n",trabalhando[i].prioridade,trabalhando[i].tempo ,trabalhando[i].desc);
					}
				}
				printf("Simulacao encerrada!!");
			}
			printf("Tempo trabalhado: %d", tempoTrabalhado);
			printf("Numero Total de Tarefas Concluidas: %d", qtdeTerminada);
			printf("Numero total de tarefas não concluidas: %d", (qtdeTotal-qtdeTerminada));
		}
	}
	fclose(auxArq);
	fclose(auxRel);
}











