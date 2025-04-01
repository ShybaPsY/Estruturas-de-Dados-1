#define MAXFILA 5
#include <time.h>

struct TpCarro{
	char nome[100];
	clock_t entrada;
};

struct TpFila{
	TpCarro fila[MAXFILA];
	int fim;
};

void inicializar(TpFila &f){
	f.fim = -1;
}

bool filaCheia(int fim){
	return fim==MAXFILA-1;
}

bool filaVazia(int fim){
	return fim==-1;
}

void inserir(TpFila &f, TpCarro aux){
	f.fila[++f.fim] = aux;
}

TpCarro retirar(TpFila &f){
	TpCarro aux = f.fila[0];
	for(int i=0;i<f.fim;i++){
		f.fila[i] = f.fila[i+1];
	}
	f.fim--;
	return aux;
}

TpCarro primeiroFila(TpFila f){
	return f.fila[0];
}

TpCarro ultimoFila(TpFila f){
	return f.fila[f.fim];
}

