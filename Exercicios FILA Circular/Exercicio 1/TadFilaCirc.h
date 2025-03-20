#define MAXFILA 10

struct TpFilaCirc{
	int fila[MAXFILA];
	int fim, inicio, qtde;
};

void inicializar(TpFilaCirc &f);
void inserir(TpFilaCirc &f, int aux);
int retirar(TpFilaCirc &f);
bool filaCheia(int qtde);
bool filaVazia(int qtde);
int ultimoValor(TpFilaCirc f);
int primeiroValor(TpFilaCirc f);
void exibir(TpFilaCirc f);
void esvaziar(TpFilaCirc &f);

void inicializar(TpFilaCirc &f){
	f.fim = -1;
	f.inicio = 0;
	f.qtde = 0;
}

void inserir(TpFilaCirc &f, int aux){
	if(f.fim == MAXFILA-1){
		f.fim = 0;
	}
	else{
		f.fim++;
	}
	
	f.fila[f.fim] = aux;
	f.qtde++;
}

int retirar(TpFilaCirc &f){
	int valor = f.fila[f.inicio];
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

int ultimoValor(TpFilaCirc f){
	return f.fila[f.fim];
}

int primeiroValor(TpFilaCirc f){
	return f.fila[f.inicio];
}

void exibir(TpFilaCirc f){
	while(!filaVazia(f.qtde)){
		printf("\nPosicao %d: ",f.qtde);
		printf("%d", retirar(f));
	}
}

void esvaziar(TpFilaCirc &f){
	while(!filaVazia(f.qtde)){
		printf("\nPosicao %d: ",f.qtde);
		printf("%d", retirar(f));
	}
}
