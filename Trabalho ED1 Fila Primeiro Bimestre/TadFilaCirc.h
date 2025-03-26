#define MAXFILA 1500


struct TpTarefa{
	int prioridade;
	int tempo;
	char desc[100];
};


struct TpFilaCirc{
	TpTarefa fila[MAXFILA];
	int fim, inicio, qtde;
	char nome[100];
};

void inicializar(TpFilaCirc &f);
void inserir(TpFilaCirc &f, TpTarefa aux);
TpTarefa retirar(TpFilaCirc &f);
bool filaCheia(int qtde);
bool filaVazia(int qtde);
TpTarefa ultimoValor(TpFilaCirc f);
TpTarefa primeiroValor(TpFilaCirc f);
void exibir(TpFilaCirc f);
void esvaziar(TpFilaCirc &f);

void inicializar(TpFilaCirc &f){
	f.fim = -1;
	f.inicio = 0;
	f.qtde = 0;
	strcpy(f.nome, "Vazio");
}

void inserir(TpFilaCirc &f, TpTarefa aux){
	if(f.fim == MAXFILA-1){
		f.fim = 0;
	}
	else{
		f.fim++;
	}
	
	f.fila[f.fim] = aux;
	f.qtde++;
}

TpTarefa retirar(TpFilaCirc &f){
	TpTarefa valor = f.fila[f.inicio];
	if(f.inicio == MAXFILA -1){
		f.inicio = 0;
	}
	else{
		f.inicio++;
	}
	f.qtde--;
	return valor;
}

bool filaCheia(int qtde){
	return qtde == MAXFILA-1;
}

bool filaVazia(int qtde){
	return qtde==0;
}

TpTarefa ultimoValor(TpFilaCirc f){
	return f.fila[f.fim];
}

TpTarefa primeiroValor(TpFilaCirc f){
	return f.fila[f.inicio];
}

void exibir(TpFilaCirc f){
	TpTarefa aux;
	while(!filaVazia(f.qtde)){
		printf("\nPosicao %d: ",f.qtde);
		aux = retirar(f);
		printf("Prioridade: %d Tempo: %d Desc: %s",aux.prioridade, aux.tempo, aux.desc);
	}
}

void esvaziar(TpFilaCirc &f){
	TpTarefa aux;
	while(!filaVazia(f.qtde)){
		printf("\nPosicao %d: ",f.qtde);
		aux = retirar(f);
		printf("Prioridade: %d Tempo: %d Desc: %s",aux.prioridade, aux.tempo, aux.desc);
	}
}
