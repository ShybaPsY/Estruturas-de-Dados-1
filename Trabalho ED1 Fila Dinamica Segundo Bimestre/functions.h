#include "tad.h"
#include <conio2.h>


void adicionarDevs(TpDescDev &d){
	char nomeAux[50];
	printf("Digite o nome do dev a ser adicionado: ");
	gets(nomeAux);
	while(strcmp(nomeAux, "\0")!=0){
		inserirDev(d, nomeAux);
		printf("Dev adicionado");
		printf("Digite o nome do dev a ser adicionado: ");
		gets(nomeAux);
	}
}


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

void simular(TpDescDev &dev, char nomeArq[50]){
	int duracao;
	char op = 'N', op2, nome[50];
	clock_t clockEspera = 0, aux = 0;
	FILE *arq = fopen(nomeArq, "r+");
	TpCaixaDev *atual;
	TpCaixaTarefa *caixa;
	
	
	adicionarDevs(dev);
	if(devVazio(dev)){
		printf("Nenhum dev adicionado");
		getch();
	}
	else{
		printf("Digite o tempo de duracao da simulacao");
		scanf("%d",&duracao);
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
				//printf("asdasda\n");
				atual=dev.inicio;
				while(atual!=NULL){
					if(!tarefaVazia(dev, atual->nome)){
						atual->descTarefas.inicio->tempo--;
						if(atual->descTarefas.inicio->tempo == 0){
							atual->descTarefas.inicio->fim = clock() - clockEspera;
							concluirTarefa(dev, atual->nome);
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
			printf("Deseja parar a simulacao?");
			op = toupper(getch());
			if(op == 'N'){
				printf("Deseja excluir um dev?");
				op2 = toupper(getch());
				if(op2 == 'S'){
					printf("Qual dev deseja excluir?");
					gets(nome);
					excluirDev(dev, nome);
				}
			}
			clockEspera = clock() - aux;
		}
	}
}











