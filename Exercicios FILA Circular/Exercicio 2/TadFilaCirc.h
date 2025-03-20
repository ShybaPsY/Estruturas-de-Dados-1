#define MAXFILA 10

struct TpCarro{
	int modelo;
	int tempo;
};

struct TpFilaCirc{
	TpCarro fila[MAXFILA];
	int fim, inicio, qtde;
	int tempo;
};

void inicializar(TpFilaCirc &f);
void inserir(TpFilaCirc &f, int aux, int tempo);
TpCarro retirar(TpFilaCirc &f);
bool filaCheia(int qtde);
bool filaVazia(int qtde);
TpCarro ultimoValor(TpFilaCirc f);
TpCarro primeiroValor(TpFilaCirc f);
void exibir(TpFilaCirc f);
void esvaziar(TpFilaCirc &f);

void inicializar(TpFilaCirc &f){
	f.fim = -1;
	f.inicio = 0;
	f.qtde = 0;
}

void inserir(TpFilaCirc &f, int aux, int tempo){
	if(f.fim == MAXFILA-1){
		f.fim = 0;
	}
	else{
		f.fim++;
	}
	
	f.fila[f.fim].modelo = aux;
	f.fila[f.fim].tempo = tempo;
	f.qtde++;
}

TpCarro retirar(TpFilaCirc &f){
	TpCarro carro = f.fila[f.inicio];
	if(f.inicio == MAXFILA -1){
		f.inicio = 0;
	}
	else{
		f.inicio++;
	}
	f.qtde--;
	return carro;
}

bool filaCheia(int qtde){
	return qtde == MAXFILA-1;
}

bool filaVazia(int qtde){
	return qtde==0;
}

TpCarro ultimoValor(TpFilaCirc f){
	return f.fila[f.fim];
}

TpCarro primeiroValor(TpFilaCirc f){
	return f.fila[f.inicio];
}

void exibir(TpFilaCirc f){
	TpCarro aux;
	while(!filaVazia(f.qtde)){
		printf("\nPosicao %d: ",f.qtde);
		aux = retirar(f);
		printf("Modelo: %d	tempo: %d",aux.modelo, aux.tempo);
	}
}

void esvaziar(TpFilaCirc &f){
	TpCarro aux;
	while(!filaVazia(f.qtde)){
		printf("\nPosicao %d: ",f.qtde);
		aux = retirar(f);
		printf("Modelo: %d	tempo: %d",aux.modelo, aux.tempo);
	}
}

