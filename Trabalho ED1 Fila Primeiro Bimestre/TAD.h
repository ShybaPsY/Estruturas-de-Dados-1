#define MAXFILA 1000

struct TpFila{
	int fila[MAXFILA];
	int fim;
};

void inicializar(TpFila &f);
void inserir(TpFila &f, int aux);
int retirar(TpFila &f);
bool vazia(int fim);
bool cheia(int fim);
void exibir(TpFila f);
void esvaziar(TpFila &f);
int ultimoValor(TpFila f);
int primeiroValor(TpFila f);

void inicializar(TpFila &f){
	f.fim = -1;
}

void inserir(TpFila &f, int aux){
	f.fila[++f.fim] = aux;
}

int retirar(TpFila &f){
	int aux = f.fila[0];
	for(int i=0; i< f.fim; i++)
		f.fila[i] = f.fila[i+1];
	f.fim--;
	return aux;
}

bool vazia(int fim){
	return fim == -1;
}

bool cheia(int fim){
	return fim == MAXFILA-1;
}

void exibir(TpFila f){
	while(!vazia(f.fim)){
		printf("valor: %d\n", retirar(f));
	}
}

void esvaziar(TpFila &f){
	while(!vazia(f.fim)){
		printf("valor: %d\n", retirar(f));
	}
}

int ultimoValor(TpFila f){
	return f.fila[f.fim];
}

int primeiroValor(TpFila f){
	return f.fila[0];
}
