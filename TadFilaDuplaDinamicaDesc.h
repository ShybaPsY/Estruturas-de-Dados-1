
struct TpCaixa{
	char nome[20];
	TpCaixa *ant,*prox;
};

struct TpDesc{
	TpCaixa *ant,*prox;
};

TpCaixa *novaCaixa(char nome[20]){
	TpCaixa *caixa = new TpCaixa;
	strcpy(caixa->nome,nome);
	caixa->prox = caixa->ant = NULL;
	return caixa;
}

void inicializar(TpDesc &d){
	d.inicio = d.fim = NULL;
}

bool vazio(TpDesc &d){
	return d.inicio == NULL;
}

void inserirInicio(TpDesc &d, char nome[20]){
	
	if(d.inicio == NULL){
		d.inicio = d.fim = novaCaixa(nome);
	}
	else{
		TpCaixa *caixa = novaCaixa(nome);
		caixa ->prox = d.inicio;
		d.inicio->ant = caixa;
		d.inicio = caixa;
	}
}

void inserirFim(TpDesc &d, char nome[20]){
	if(d.fim == NULL){
		d.inicio = d.fim = novaCaixa(nome);
	}
	else{
		TpCaixa *caixa = novaCaixa(nome);
		caixa->ant = d.fim;
		d.fim->prox = caixa;
		d.fim = caixa;
	}
}

void excluirInicio(TpDesc &d, char nome[20]){
	if(d.inicio!=NULL){
		d.inicio = d.inicio->prox;
		delete(d.inicio->ant);
		d.inicio->ant = NULL;
	}
}

void elementoInicio(TpDesc &d, char nome[20]){
	strcpy(nome,d.inicio->nome);
}

void elementoFim(TpDesc &d, char nome[20]){
	strcpy(nome,d.fim->nome);
}

void excluirFim(TpDesc &d, char nome[20]){
	if(d.fim!=NULL){
		d.fim=d.fim->ant;
		delete(d.fim->prox);
		d.fim->prox = NULL;
	}
}

void exibir(TpDesc d){
	for(;d.inicio!=NULL;d.inicio=d.inicio->prox)
		printf("%s\n",d.inicio->nome);
}

void exibirInvertido(TpDesc d){
	for(;d.fim!=NULL;d.fim=d.fim->ant)
		printf("%s\n",d.fim->nome);
}

void liberarLista(TpDesc &d){
	if(d.inicio !=NULL){
		while(d.inicio!=d.fim){
			d.inicio=d.inicio->prox;
			delete(d.inicio->ant);
		}
		delete(d.inicio);
		d.inicio = d.fim = NULL;
	}
}




