#include<time.h>
#include<string.h>
#include "moldura.h"

struct TpData{
	int dia;
	int mes;
	int ano;
};

struct TpCaixaTarefa{
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
	TpCaixaTarefa *inicio,*fim;
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

TpCaixaTarefa *retirarTarefa(TpDescDev &dev, char nome[50]);

void inicializarDev(TpDescDev &descDev){
	descDev.qtde = 0;
	descDev.inicio = descDev.fim = NULL;
}

TpCaixaDev *criarCaixaDev(char nome[50]){
	
	TpCaixaDev *dev = new TpCaixaDev;
	
	strcpy(dev->nome, nome);
	dev->descTarefas.qtde=0;
	dev->descTarefas.inicio=NULL;
	dev->descTarefas.fim=NULL;
	dev->descTarefas.concluidas = NULL;
	dev->ant = dev->prox = NULL;
	return dev;
}

TpCaixaTarefa *criarCaixaTarefa(int prioridade, int tempo, char desc[50], char responsavel[50], TpData data){
	
	TpCaixaTarefa *tarefa = new TpCaixaTarefa;
	
	tarefa->prioridade = prioridade;
	tarefa->tempo = tempo;
	strcpy(tarefa->desc, desc);
	strcpy(tarefa->responsavel, responsavel);
	tarefa->data.dia = data.dia;
	tarefa->data.mes = data.mes;
	tarefa->data.ano = data.ano;
	tarefa->inicio = clock();
	tarefa->fim = 0;
	tarefa->prox = NULL;
	
	return tarefa;
}

bool devVazio(TpDescDev dev){
	return dev.inicio == NULL && dev.fim == NULL;
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
			if(caixa->prioridade >= dev.inicio->descTarefas.inicio->prioridade){
				caixa->prox = dev.inicio->descTarefas.inicio;
				dev.inicio->descTarefas.inicio = caixa;
				dev.inicio->descTarefas.qtde++;
			}
			else{
				if(caixa->prioridade <= dev.inicio->descTarefas.fim->prioridade){
					dev.inicio->descTarefas.fim->prox = caixa;
					dev.inicio->descTarefas.fim = caixa;
					dev.inicio->descTarefas.qtde++;
				}
				else{
					TpCaixaTarefa *aux;
					aux = dev.inicio->descTarefas.inicio;
					while(aux->prox->prioridade >= caixa->prioridade){
						aux = aux->prox;
					}
					caixa->prox = aux->prox;
					aux->prox = caixa;
					dev.inicio->descTarefas.qtde++;
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
				if(caixa->prioridade >= dev.fim->descTarefas.inicio->prioridade){
					caixa->prox = dev.fim->descTarefas.inicio;
					dev.fim->descTarefas.inicio = caixa;
					dev.fim->descTarefas.qtde++;
				}
				else{
					if(caixa->prioridade <= dev.fim->descTarefas.fim->prioridade){
						dev.fim->descTarefas.fim->prox = caixa;
						dev.fim->descTarefas.fim = caixa;
						dev.fim->descTarefas.qtde++;
					}
					else{
						TpCaixaTarefa *aux;
						aux = dev.fim->descTarefas.inicio;
						while(aux->prox->prioridade >= caixa->prioridade){
							aux = aux->prox;
						}
						caixa->prox = aux->prox;
						aux->prox = caixa;
						dev.fim->descTarefas.qtde++;
					}
				}
			}
		}
		else{
			TpCaixaDev *atual;
			atual = dev.inicio->prox;
			while(atual!=NULL && strcmp(atual->nome, nome) != 0){
				atual = atual->prox;
			}
			if(atual!=NULL){
				if(atual->descTarefas.inicio == NULL){
					atual->descTarefas.inicio = atual->descTarefas.fim = caixa;
				}
				else{
					if(caixa->prioridade >= atual->descTarefas.inicio->prioridade){
						caixa->prox = atual->descTarefas.inicio;
						atual->descTarefas.inicio = caixa;
						atual->descTarefas.qtde++;
					}
					else{
						if(caixa->prioridade <= atual->descTarefas.fim->prioridade){
							atual->descTarefas.fim->prox = caixa;
							atual->descTarefas.fim = caixa;
							atual->descTarefas.qtde++;
						}
						else{
							TpCaixaTarefa *aux;
							aux = atual->descTarefas.inicio;
							while(aux->prox->prioridade >= caixa->prioridade){
								aux=aux->prox;
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
}

void excluirDev(TpDescDev &dev, char nome[50]){
	TpCaixaTarefa *aux;
	if(dev.qtde <= 1){
		printf("Nao e possivel excluir");
	}
	else{
		if(strcmp(dev.inicio->nome,nome) == 0){
			TpCaixaDev *atual;
			
			while(dev.inicio->descTarefas.inicio !=NULL){
				atual=dev.inicio->prox;
				while(dev.inicio->descTarefas.inicio!=NULL && atual!=NULL){
					aux = retirarTarefa(dev, dev.inicio->nome);
					inserirTarefa(dev, atual->nome, aux);
					atual = atual->prox;
				}
			}
			dev.inicio = dev.inicio->prox;
			delete(dev.inicio->ant);
			dev.inicio->ant = NULL;
			dev.qtde--;
		}
		else{
			if(strcmp(dev.fim->nome,nome) == 0){
				TpCaixaDev *atual;
				while(dev.fim->descTarefas.inicio !=NULL){
					atual=dev.fim->ant;
					while(dev.fim->descTarefas.inicio!=NULL && atual!=NULL){
						aux = retirarTarefa(dev, dev.fim->nome);
						inserirTarefa(dev, atual->nome, aux);
						atual = atual->ant;
					}
				}
				dev.fim = dev.fim->ant;
				delete(dev.fim->prox);
				dev.fim->prox = NULL;
				dev.qtde--;
			}
			else{
				TpCaixaDev *excluido;
				excluido = dev.inicio->prox;
				while(excluido !=NULL && strcmp(excluido->nome,nome) != 0){
					excluido=excluido->prox;
				}
				if(excluido != NULL){
					TpCaixaDev *atual;
					while(dev.inicio->descTarefas.inicio !=NULL){
						atual=dev.inicio;
						while(dev.inicio->descTarefas.inicio!=NULL && atual!=NULL){
							if(atual!=excluido){
								aux = retirarTarefa(dev, excluido->nome);
								inserirTarefa(dev, atual->nome, aux);
								atual = atual->prox;
							}
						}
					}
					excluido->ant->prox = excluido->prox;
					excluido->prox->ant = excluido->ant;
					delete(excluido);
					dev.qtde--;
				}
			}
		}
	}
}

TpCaixaTarefa *retirarTarefa(TpDescDev &dev, char nome[50]){
	
	TpCaixaTarefa *aux = NULL;
	
	if(strcmp(dev.inicio->nome, nome) == 0){
		aux = dev.inicio->descTarefas.inicio;
		dev.inicio->descTarefas.inicio = aux->prox;
		aux->prox = NULL;
		dev.inicio->descTarefas.qtde--;
	}
	else{
		if(strcmp(dev.fim->nome,nome) == 0){
			aux = dev.fim->descTarefas.inicio;
			dev.fim->descTarefas.inicio = aux->prox;
			aux->prox = NULL;
			dev.fim->descTarefas.qtde--;
		}
		else{
			TpCaixaDev *atual;
			atual = dev.inicio->prox;
			while(atual!=NULL && strcmp(atual->nome,nome) != 0){
				atual=atual->prox;
			}
			if(atual!=NULL){
				aux = atual->descTarefas.inicio;
				atual->descTarefas.inicio = aux->prox;
				aux->prox=NULL;
				atual->descTarefas.qtde--;
			}
		}
	}
	
	return aux;
}

void exibirTarefas(TpCaixaTarefa *aux, int y){
	if(aux != NULL){
		gotoxy(40, y);
		printf("Prioridade: %d Tempo: %d Descricao: %s Responsavel: %s data: %d-%d-%d\n", aux->prioridade, aux->tempo, aux->desc, aux->responsavel, aux->data.dia, aux->data.mes, aux->data.ano);
		if(y==23)
			y=6;
		exibirTarefas(aux->prox, ++y);
	}
}

void exibirDev(TpDescDev dev, char nome[50]){
	
	if(strcmp(dev.inicio->nome,nome) == 0){  //Verifica se é o dev no incio
	
		printf("\tDev %s\n",dev.inicio->nome);
		exibirTarefas(dev.inicio->descTarefas.inicio, 6);
	}
	else{
		if(strcmp(dev.fim->nome,nome) == 0){
			printf("\tDev %s\n",dev.fim->nome);
			exibirTarefas(dev.fim->descTarefas.inicio, 6);
		}
		else{
			TpCaixaDev *aux;
			aux = dev.inicio->prox;
			while(aux!=NULL && strcmp(aux->nome,nome) != 0){
				aux=aux->prox;
			}
			if(aux!=NULL){
				printf("\tDev %s\n",aux->nome);
				exibirTarefas(aux->descTarefas.inicio, 6);
			}
		}
	}
}

void concluirTarefa(TpDescDev &d, char nome[50]){
	TpCaixaTarefa *aux;
	if(strcmp(d.inicio->nome, nome)==0){  //Verifica se é o dev do começo
		if(!tarefaVazia(d, nome)){  //Verifica se tem de onde tirar
			if(d.inicio->descTarefas.concluidas == NULL){
				d.inicio->descTarefas.concluidas = retirarTarefa(d, nome);
			}
			else{
				aux=retirarTarefa(d, nome);
				aux->prox = d.inicio->descTarefas.concluidas;
				d.inicio->descTarefas.concluidas = aux;
			}
			
		}
	}
	else{
		if(strcmp(d.fim->nome, nome) == 0){   //Verifica se é o dev do fim
			if(!tarefaVazia(d, nome)){  //Verifica se tem de onde tirar
				if(d.fim->descTarefas.concluidas == NULL){
					d.fim->descTarefas.concluidas = retirarTarefa(d, nome);
				}
				else{
					aux=retirarTarefa(d, nome);
					aux->prox = d.fim->descTarefas.concluidas;
					d.fim->descTarefas.concluidas = aux;
				}
			}
		}
		else{  //Se não for nenhum dos 2, verifica se vai ser um do meio
			TpCaixaDev *atual;
			atual = d.inicio;
			while(atual!=NULL && strcmp(atual->nome,nome)!=0){
				atual=atual->prox;
			}
			if(atual!=NULL){  //Verifica se achou o dev
				if(!tarefaVazia(d, atual->nome)){  //Verifica se tem de onde tirar
					if(atual->descTarefas.concluidas == NULL){
						atual->descTarefas.concluidas = retirarTarefa(d, nome);
					}
					else{
						aux=retirarTarefa(d, nome);
						aux->prox = atual->descTarefas.concluidas;
						atual->descTarefas.concluidas = aux;
					}
				}
			}
		}
	}
}

bool devsSemTarefas(TpDescDev dev){
	int cont=0;
	TpCaixaDev *atual;
	atual = dev.inicio;
	while(atual!=NULL){
		if(tarefaVazia(dev, atual->nome)){
			cont++;
		}
		atual=atual->prox;
	}
	return dev.qtde == cont;
}















