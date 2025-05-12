


struct TpCaixa{
	TpCaixa *prox;
	int valor;
};

struct TpDesc{
	TpCaixa *inicio,*fim;
};

void inicializar(TpDesc &d){
	d.inicio = NULL;
	d.fim = NULL;
}

TpCaixa *novaCaixa(int aux){
	TpCaixa *caixa = new TpCaixa;
	caixa->prox = NULL;
	caixa->valor = aux;
	return caixa;
}

void inserir(TpDesc &d, int aux){
	
	TpCaixa *caixa = novaCaixa(aux);
	
	if(d.inicio == NULL){
		d.inicio = d.fim = caixa;
	}
	else{
		caixa->prox = d.inicio;
		d.inicio = caixa;
	}
}


void excluir(TpDesc &d, int aux){
	
	TpCaixa *atual;
	
	if(d.inicio == NULL){
		printf("Lista Vazia\n");
	}
	else{
		if(d.inicio->valor == aux){
			atual = d.inicio->prox; 
			delete(d.inicio);
			d.inicio = atual;
		}
		else{
			atual=d.inicio;
			while(atual->prox != d.fim && atual->prox->valor!=aux){
				atual=atual->prox;
			}
			if(atual->prox->valor !=aux){
				printf("Valor não existe\n");
			}
			else{
				TpCaixa *temp=atual->prox;
				atual->prox=temp->prox;
				delete(temp);
				printf("Valor excluido\n");
			}
		}
	}
}

TpCaixa *buscaExaustiva(TpDesc &d, int aux){
	
	TpCaixa *atual;
	
	if(d.inicio == NULL){
		return NULL;
	}
	else{
		if(d.inicio->valor == aux){
			return d.inicio;
		}
		else{
			if(d.fim->valor == aux){
				return d.fim;
			}
			else{
				atual=d.inicio->prox;
				while(atual != d.fim && atual->valor!=aux){
					atual=atual->prox;
				}
				if(atual == d.fim){
					return NULL;
				}
				else{
					return atual;
				}
			}
		}
	}
}

void alterar(TpDesc &d, int aux, int valor){
	
	TpCaixa *atual;
	
	if(d.inicio == NULL){
		printf("Lista Vazia\n");
	}
	else{
		if(d.inicio->valor == aux){
			d.inicio->valor = valor;
			printf("Valor Alterado\n");
		}
		else{
			if(d.fim->valor == aux){
				d.fim->valor = valor;
				printf("Valor Alterado\n");
			}
			else{
				atual = d.inicio->prox;
				while(atual!=d.fim && atual->valor != aux){
					atual = atual->prox;
				}
				if(atual == d.fim){
					printf("Valor Nao Existe\n");
				}
				else{
					atual->valor = valor;
					printf("Valor alterado\n");
				}
			}
		}
	}
	
}

void exibir(TpDesc &d){
	
	TpCaixa *atual;
	
	if(d.inicio==NULL){
		printf("Lista Vazia\n");
	}
	else{
		atual=d.inicio;
		while(atual!=NULL){
			printf("Valor: %d\n",atual->valor);
			atual = atual->prox;
		}
	}
}

void exibirInvertido(TpCaixa c){
	
	if(c->prox!=NULL){
		exibirInvertido(c->prox);
	}
	printf("Valor: %d\n",c->valor);
}


















