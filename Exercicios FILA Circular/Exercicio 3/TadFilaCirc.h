#define MAXFILA 100


struct TpFilaCirc{
	int fila[MAXFILA];
	int inicio, fim, qtde;
};

void inicializar(TpFilaCirc &f){
	f.qtde = 0;
	f.inicio = 0;
	f.fim = -1;
}

bool filaCheia(int qtde){
	return qtde == MAXFILA-1;
}

bool filaVazia(int qtde){
	return qtde == 0;
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
	int aux = f.fila[f.inicio];
	if(f.inicio == MAXFILA-1){
		f.inicio = 0;
	}
	else{
		f.inicio++;
	}
	f.qtde--;
	return aux;
}

int primeiroFila(TpFilaCirc f){
	return f.fila[f.inicio];
}

int ultimoFila(TpFilaCirc f){
	return f.fila[f.fim];
}
