#define MAXFILA 1000

struct TpTarefa{
	int prioridade;
	int tempo;
	char desc[100];
};


struct TpFila{
	TpTarefa fila[MAXFILA];
	char nome[100];
	int fim;
};

void inicializar(TpFila &f);
void inserir(TpFila &f, int aux);
TpTarefa retirar(TpFila &f);
bool vazia(int fim);
bool cheia(int fim);
void exibir(TpFila f);
void esvaziar(TpFila &f);
TpTarefa ultimoValor(TpFila f);
TpTarefa primeiroValor(TpFila f);

void inicializar(TpFila &f){
	f.fim = -1;
	strcpy(f.nome, "Vazio");
}

void inserir(TpFila &f, TpTarefa aux){
	f.fila[++f.fim] = aux;
}

TpTarefa retirar(TpFila &f){
	TpTarefa aux = f.fila[0];
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
	TpTarefa t;
	while(!vazia(f.fim)){
		t = retirar(f);
		printf("Prioridade: %d - Tempo: %d - Descricao: %s\n", t.prioridade, t.tempo, t.desc);
	}
}

void esvaziar(TpFila &f){
	TpTarefa t;
	while(!vazia(f.fim)){
		t = retirar(f);
		printf("Prioridade: %d - Tempo: %d - Descricao: %s\n", t.prioridade, t.tempo, t.desc);
	}
}

TpTarefa ultimoValor(TpFila f){
	return f.fila[f.fim];
}

TpTarefa primeiroValor(TpFila f){
	return f.fila[0];
}
