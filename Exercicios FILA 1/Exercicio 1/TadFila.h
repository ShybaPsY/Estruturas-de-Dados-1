#define MAXFILA 10

struct TpFila{
	int fila[MAXFILA];
	int fim;
};

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

int vazia(int fim){
	return fim == -1;
}

int cheia(int fim){
	return fim == MAXFILA-1;
}

void exibir(TpFila f){
	while(!vazia(f.fim)){
		printf("valor: %d\n", retirar(f));
	}
}
