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
	TpCaixaTarefa *concluidas;
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
	dev->descTarefas.concluidas = NULL;
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
			return dev.inicio->prox->descTarefas.inicio == NULL;
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
		if(dev.inicio->descTarefas.inicio == NULL){
			dev.inicio->descTarefas.inicio = dev.inicio->descTarefas.fim = caixa;
		}
		else{
			if(caixa->prioridade >= dev.inicio->descTarefas.inicio){
				caixa->prox = dev.inicio->descTarefas.inicio->prox;
				dev.inicio->descTarefas->inicio->prox = caixa;
				dev.inicio->descTarefas.qtde++;
			}
			else{
				if(caixa->prioridade <= dev.inicio->descTarefas.fim){
					dev.inicio->descTarefas.fim->prox = caixa;
					dev.inicio->descTarefas.fim = caixa;
					dev.inicio->descTarefas->qtde++;
				}
				else{
					TpCaixaTarefa *aux;
					aux = dev.inicio->descTarefas->inicio;
					while(aux->prox->prioridade >= caixa->prioridade){
						aux = aux->prox;
					}
					caixa->prox = aux->prox;
					aux->prox = caixa;
					dev.inicio->descTarefas->qtde++;
				}
			}
		}
		
	}
	else{
		if(strcmp(dev.fim->nome, nome) == 0){
			if(dev.fim->descTarefas.inicio == NULL){
				dev.fim->descTarefas.inicio = dev.fim->descTarefas.fim = caixa;
			}
			else{
				if(caixa->prioridade >= dev.fim->descTarefas.inicio){
					caixa->prox = dev.fim->descTarefas.inicio->prox;
					dev.fim->descTarefas->inicio->prox = caixa;
					dev.fim->descTarefas.qtde++;
				}
				else{
					if(caixa->prioridade <= dev.fim->descTarefas.fim){
						dev.fim->descTarefas.fim->prox = caixa;
						dev.fim->descTarefas.fim = caixa;
						dev.fim->descTarefas->qtde++;
					}
					else{
						TpCaixaTarefa *aux;
						aux = dev.fim->descTarefas->inicio;
						while(aux->prox->prioridade >= caixa->prioridade){
							aux = aux->prox;
						}
						caixa->prox = aux->prox;
						aux->prox = caixa;
						dev.fim->descTarefas->qtde++;
					}
				}
			}
		}
		else{
			TpCaixaDev *atual;
			atual = dev.inicio->prox;
			while(strcmp(atual->nome, nome) != 0){
				atual = atual->prox;
			}
			if(atual->descTarefas.inicio == NULL){
				atual->descTarefas.inicio = atual->descTarefas.fim = caixa;
			}
			else{
				if(caixa->prioridade >= atual->descTarefas.inicio){
					caixa->prox = atual->descTarefas.inicio->prox;
					atual->descTarefas.inicio->prox = caixa;
					atual->qtde++;
				}
				else{
					if(caixa->prioridade <= atual->descTarefas.fim){
						atual->descTarefas.fim->prox = caixa;
						atual->descTarefas.fim = caixa;
						atual->descTarefas.qtde++;
					}
					else{
						TpCaixaTarefa *aux;
						aux = atual->descTarefas.inicio;
						while(caixa->prioridade <= aux->prox->prioridade){
							atual=atual->prox;
						}
						caixa->prox = aux->prox;
						aux->prox = caixa;
						atual->descTarefas.qtde++;
					}
				}
			}
		}
	}
}

void excluirDev(TpDescDev &dev, char nome[50]){
	
	if(dev.qtde == 1){
		TpCaixaTarefa *aux;
		aux = dev.inicio->descTarefas.inicio->prox;
		while(aux!=NULL){
			delete(dev.inicio->descTarefas.inicio);
			dev.inicio->descTarefas.inicio = aux;
			aux = aux->prox;
		}
		delete(dev.inicio->descTarefas.inicio);
		delete(dev.inicio);
		dev.qtde--;
	}
	else{
		if(strcmp(dev.inicio->nome,nome) == 0){
			TpCaixaDev *atual;
			while(dev.inicio->descTarefas->inicio !=NULL){
				atual=dev.inicio->prox;
				while(dev.inicio->descTarefas->inicio!=NULL && atual!=NULL){
					inserirTarefa(dev, atual->nome, dev.inicio->descTarefas->inicio);
					atual = atual->prox;
					dev.inicio->descTarefas->inicio = dev.inicio->descTarefas->inicio->prox;
				}
			}
			dev.inicio = dev.inicio->prox;
			delete(dev.inicio->ant);
			dev.inicio->ant = NULL;
		}
		else{
			if(strcmp(dev.fim->nome,nome) == 0){
				TpCaixaDev *atual;
				while(dev.fim->descTarefas->inicio !=NULL){
					atual=dev.fim->ant;
					while(dev.fim->descTarefas->inicio!=NULL && atual!=NULL){
						inserirTarefa(dev, atual->nome, dev.fim->descTarefas->inicio);
						atual = atual->ant;
						dev.fim->descTarefas->inicio = dev.fim->descTarefas->inicio->prox;
					}
				}
				dev.fim = dev.fim->ant;
				delete(dev.fim->prox);
				dev.fim->prox = NULL;
			}
			else{
				TpCaixaDev *excluido;
				excluido = dev.inicio->prox;
				while(strcmp(excluido->nome,nome) != 0){
					excluido=excluido->prox;
				}
				if(excluido != NULL){
					TpCaixaDev *atual;
					while(dev.inicio->descTarefas->inicio !=NULL){
						atual=dev.inicio;
						while(dev.inicio->descTarefas->inicio!=NULL && atual!=NULL){
							if(atual!=excluido){
								inserirTarefa(dev, atual->nome, excluido->descTarefas->inicio);
								excluido->descTarefas->inicio = excluido->descTarefas->inicio->prox;
							}
							atual = atual->ant;
						}
					}
					excluido->ant->prox = excluido->prox;
					excluido->prox->ant = excluido->ant;
					delete(excluido);
				}
			}
		}
	}
}

void exibir
















