#define MAXPILHA 10

struct TpPilha{
	int pilha[MAXPILHA];
	int topo;
};

void inicializar(TpPilha &p);
void inserir(TpPilha &p, int aux);
bool pilhaCheia(int topo);
bool pilhaVazia(int topo);
int retirar(TpPilha &p);
void exibir(TpPilha p);
void esvaziar(TpPilha &p);
int ultimoValor(TpPilha p);

void inicializar(TpPilha &p){
	p.topo = -1;
}

void inserir(TpPilha &p, int aux){
	p.pilha[++p.topo] = aux;
}

bool pilhaCheia(int topo){
	return topo == MAXPILHA-1;
}

bool pilhaVazia(int topo){
	return topo == -1;
}

int retirar(TpPilha &p){
	return p.pilha[p.topo--];
}

void exibir(TpPilha p){
	while(!pilhaVazia(p.topo)){
		printf("\nPosicao %d: ", p.topo);
		printf("%d",retirar(p));
	}
}

void esvaziar(TpPilha &p){
	while(!pilhaVazia(p.topo)){
		printf("\nPosicao %d: ", p.topo);
		printf("%d", retirar(p));
	}
}

int ultimoValor(TpPilha p){
	return p.pilha[p.topo];
}
