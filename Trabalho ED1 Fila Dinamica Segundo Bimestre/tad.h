#include<time.h>
#include<string.h>
struct TpData{
	int dia;
	int mes;
	int ano;
};

struct TpCaixaTarefa{
	bool status;
	int prioridade;
	int tempo;
	char desc[50];
	char responsavel[50];
	TpData data;
	clock_t fim;
	clock_t inicio;
	
	TpCaixaTarefa *prox;
};

struct TpDescTarefa{
	
	int qtde;
	TpCaixaTarefa *inicio,*fim
};

struct TpCaixaDev{
	
	char nome[50];
	TpDescTarefa descTarefas;
	TpCaixaDev *ant, *prox;
};

struct TpDescDev{
	int qtde;
	TpCaixaDev *inicio, *fim;
};


void inicializarDev(TpDescDev &descDev){
	qtde = 0;
	descDev.inicio = descDev.fim = NULL;
}

TpCaixaDev *criarCaixaDev(char nome[50]){
	TpCaixaDev *dev = new TpCaixaDev;
	strcpy(dev->nome, nome);
	dev->descTarefas.inicio=NULL;
	dev->descTarefas.fim=NULL;
	dev->inicio = dev->fim = NULL;
	return dev;
}

TpCaixaTarefa *criarCaixaTarefa(int prioridade, int tempo, char desc[50], char responsavel[50], TpData data){
	TpCaixaTarefa *tarefa = new TpCaixaTarefa;
	tarefa->status = 0;
	tarefa->prioridade = prioridade;
	tarefa->tempo = tempo;
	strcpy(tarefa->desc, desc);
	strcpy(tarefa->responsavel, responsavel);
	tarefa->data.dia = data.dia;
	tarefa->data.mes = data.mes;
	tarefa->data.ano = data.ano;
	tarefa->inicio = clock();
	tarefa->fim = NULL;
	tarefa->prox = NULL;
	
	return tarefa;
}

bool devVazio(TpDescDev d){
	return d.inicio == NULL;
}

bool tarefaVazia(TpDescDev dev, char nome[50]){
	
	if(strcmp(dev.inicio->nome, nome) == 0){
		return dev.inicio->descTarefas.inicio==NULL;
	}
	else{
		if(strcmp(dev.fim->nome,nome) == 0){
			return dev.fim->descTarefas.inicio == NULL;
		}
		else{
			while(dev.inicio->prox!=dev.fim && strcmp(dev.inicio->prox->nome,nome) != 0){
				dev.inicio=dev.inicio->prox;
			}
			return strcmp(dev.inicio->prox->nome,nome);
		}
	}
}

void inserirDev(TpDescDev &dev, char nome[50]){
	
	if(dev.inicio==NULL){
		dev.inicio = dev.fim = criarCaixaDev(nome);
	}else{
		
	}
	
}


















