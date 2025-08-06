#include "tad.h"
#include <conio2.h>


void adicionarDevs(TpDescDev &d){
	char nomeAux[50];
	gotoxy(45, 5);
	printf("Digite o nome do dev a ser adicionado: ");
	gets(nomeAux);
	while(strcmp(nomeAux, "\0")!=0){
		inserirDev(d, nomeAux);
		gotoxy(45, 7);
		printf("Dev adicionado");
		gotoxy(45, 5);
		printf("Digite o nome do dev a ser adicionado: ");
		gets(nomeAux);
	}
}


void getNomeArq(char nome[100]){
	char aux[100];
	
	gotoxy(57, 10); textcolor(15); printf("Arquivo: ");
	gotoxy(66, 10); textcolor(14); printf("%s", nome);
	
	textcolor(7);
	
	gotoxy(57, 12);
	printf("Arquivo a ser atualizado: ");
	fflush(stdin);
	gets(aux);
	
	if(strcmp(aux, "\0") != 0 )
	{
		FILE *auxArq = fopen(aux, "r+");
		
		if(auxArq == NULL){
			gotoxy(57, 14);
			printf("Arquivo invalido!");
		}
		else{
			gotoxy(57, 14);
			printf("Arquivo valido!");
			strcpy(nome, aux);
		}
		getch();
		fclose(auxArq);
	}
}

TpCaixaTarefa *retirarArq(FILE *arq){
	
	TpCaixaTarefa *caixa;
	TpData data;
	char tipo[50], nomeTarefa[50], responsavel[50];
	int tempo;
	
	fscanf(arq,"%[^,],%d,%[^,],%[^,],%d-%d-%d\n",&tipo, &tempo, &nomeTarefa, &responsavel,&data.ano, &data.mes, &data.dia);
	
	if(strcmp(tipo,"Critico") == 0){
		caixa = criarCaixaTarefa(2,tempo,nomeTarefa,responsavel,data);
	}
	else{
		if(strcmp(tipo,"Importante") == 0){
			caixa = criarCaixaTarefa(1,tempo,nomeTarefa,responsavel,data);
		}
		else{
			caixa = criarCaixaTarefa(0,tempo,nomeTarefa,responsavel,data);	
		}
	}
	return caixa;
}

void relatorio(TpDescDev d){
	TpCaixaDev *atual;
	TpCaixaTarefa *aux;
	clock_t tempo2=0, tempo1=0, tempo0=0;
	int cont2=0, cont1=0, cont0=0, contAux=0;
	atual = d.inicio;
	printf("Tarefas por Tipo:");
	while(atual!=NULL){
		aux = atual->descTarefas.inicio;
		while(aux!=NULL){
			if(aux->prioridade == 2){
				cont2++;
			}
			else{
				if(aux->prioridade ==1){
					cont1++;
				}
				else{
					cont0++;
				}
			}
			aux=aux->prox;
		}
	}
	printf("Critico: %d Importante: %d Melhoria: %d", cont2, cont1, cont0);
	printf("Numero Total de tarefas concluidas por desenvolvedor:");
	atual = d.inicio;
	while(atual!=NULL){
		aux=atual->descTarefas.inicio;
		while(aux!=NULL){
			contAux++;
		}
		printf("Nome: %s  Quantidade: %d",atual->nome,contAux);
	}
	
	while(atual!=NULL){
		aux = atual->descTarefas.inicio;
		while(aux!=NULL){
			if(aux->prioridade == 2){
				tempo2+= (aux->fim - aux->inicio);
			}
			else{
				if(aux->prioridade ==1){
					tempo1+= (aux->fim - aux->inicio);
				}
				else{
					tempo0+= (aux->fim - aux->inicio);
				}
			}
			aux=aux->prox;
		}
	}
	printf("Tempo medio para Critico: %.2f Importante: %.2f Melhoria: %.2f", tempo2/CLOCKS_PER_SEC, tempo1/CLOCKS_PER_SEC, tempo0/CLOCKS_PER_SEC);
	printf("Numero de tarefas não concluidas:");
	atual = d.inicio;
	while(atual!=NULL){
		printf("%s quantidade %d", atual->descTarefas.qtde);
	}
}

void simular(TpDescDev &dev, char nomeArq[50]){
	int duracao;
	char op = 'N', op2, nome[50];
	clock_t clockEspera = 0, aux = 0;
	FILE *arq = fopen(nomeArq, "r+");
	TpCaixaDev *atual;
	TpCaixaTarefa *caixa;
	
	
	adicionarDevs(dev);
	if(devVazio(dev)){
		gotoxy(45, 9);
		printf("Nenhum dev adicionado");
		getch();
	}
	else{
		gotoxy(45, 9);
		printf("Digite o tempo de duracao da simulacao: ");
		scanf("%d",&duracao);
		limpaAreaExecucao();
		while(duracao>0 && op == 'N'){
			do{
				atual=dev.inicio;
				while(atual!=NULL){
					if(!feof(arq)){
						if((rand()%2) == 1){
							caixa = retirarArq(arq);
							inserirTarefa(dev,atual->nome,caixa);
						}
					}
					atual=atual->prox;
				}
				atual=dev.inicio;
				while(atual!=NULL){
					if(!tarefaVazia(dev, atual->nome)){
						atual->descTarefas.inicio->tempo--;
						if(atual->descTarefas.inicio->tempo == 0){
							atual->descTarefas.inicio->fim = clock() - clockEspera;
							concluirTarefa(dev, atual->nome);
							limpaAreaExecucao();
						}
					}
					atual=atual->prox;
				}
				atual=dev.inicio;
				while(atual!=NULL){
					exibirDev(dev, atual->nome);
					atual=atual->prox;
				}
				Sleep(500);
			}while(!kbhit() && !devsSemTarefas(dev));
			aux = clock();
			gotoxy(45, 11);
			printf("Deseja parar a simulacao?");
			op = toupper(getch());
			if(op == 'N'){
				gotoxy(45, 12);
				printf("Deseja excluir um dev?");
				op2 = toupper(getch());
				if(op2 == 'S'){
					gotoxy(45, 13);
					printf("Qual dev deseja excluir?");
					gets(nome);
					excluirDev(dev, nome);
				}
			}
			clockEspera = clock() - aux;
		}
	}
}











