.#include<time.h>
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
	dev->ant = dev->prox = NULL;
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

bool devVazio(TpDescDev dev){
	return dev.inicio == NULL;
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
		dev.qtde++;
	}
	else{
		dev.fim->prox = criarCaixaDev(nome);
		dev.fim->prox->ant = dev.fim;
		dev.fim = dev.fim->prox;
		dev.qtde++;
	}
}

void inserirTarefa(TpDescDev &dev, char nome[50], TpCaixaTarefa *caixa){
	
	if(strcmp(dev.inicio->nome, nome) == 0){
		dev.inicio->descTarefas.fim->prox = caixa;
		dev.inicio->descTarefas.fim = caixa;
		dev.inicio->descTarefas.qtde++;
	}
	else{
		if(strcmp(dev.fim->nome, nome) == 0){
			dev.fim->descTarefas.fim->prox = caixa;
			dev.fim->descTarefas.fim = caixa;
			dev.fim->descTarefas.qtde++;
		}
		else{
			TpCaixaDev *atual = dev.inicio;
			while(atual->prox != dev.fim && strcmp(atual->prox->nome, nome)!=0){
				atual = atual->prox;
			}
			if(strcmp(atual->prox->nome, nome)==0){
				atual->prox->descTarefas.fim->prox = caixa;
				atual->prox->descTarefas.fim = caixa;
				atual->prox->descTarefas.qtde++;
			}
		}
	}
}

void excluirDev(TpDescDev &dev, char nome[50]){
	
	
	if(strcmp(dev.inicio->nome,nome) == 0){
		if(dev.qtde == 1){
			TpCaixaTarefa caixa = dev.inicio->descTarefas.inicio->prox;
			TpCaixaTarefa ant= dev.inicio->descTarefas.inicio;
			while(caixa!=NULL){
				delete(ant);
				ant = caixa;
				caixa = caixa->prox;
			}
			delete(ant);
			delete(dev.inicio);
			dev.inicio = NULL;
		}
		else{
			TpCaixaTarefa *caixa = dev.inicio->descTarefas.inicio;
			TpCaixaDev *atual;
			while(caixa!=NULL){
				for(atual = dev.inicio->prox; atual!=NULL; atual=atual->prox){
					atual->descTarefas.fim->prox=caixa;
					atual->descTarefas.fim = caixa;
					caixa = caixa->prox;
				}
			}
			for(atual = dev.inicio->prox; atual!=NULL; atual=atual->prox){
				atual->descTarefas.fim->prox = NULL;
			}
			dev.incio=dev.inicio->prox;
			delete(dev.inicio->ant);
			dev.inicio->ant = NULL;
		}
	}
	else{
		TpCaixaDev *atual = dev.inicio;
		while(atual->prox != NULL && strcmp(atual->prox->nome, nome)!=0){
			atual = atual->prox;
		}
		if(strcmp(atual->prox->nome, nome)==0){
			TpCaixaDev *excluir = atual->prox;
			TpCaixaTarefa *caixa = excluir->descTarefas.inicio;
			while(caixa!=NULL){
				for(atual = dev.inicio;atual!=NULL;atual=atual->prox){
					if(atual == excluir){
						atual=atual->prox;
					}
					atual->descTarefas.fim->prox= caixa;
					atual->descTarefas.fim = caixa;
					caixa = caixa->prox;
				}
			}
			for(atual = dev.inicio->prox; atual!=NULL; atual=atual->prox){
				if(atual == excluir){
					atual=atual->prox;
				}
				atual->descTarefas.fim->prox = NULL;
			}
			excluir->ant->prox=excluir->prox;
			excluir->prox->ant=excluir->ant;
			delete(excluir);
		}
	}
}


















