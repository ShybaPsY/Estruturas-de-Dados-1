#include <conio2.h>

// === Funções de interface ===

// Desenha borda retangular
void desenhaBorda(int x1, int y1, int x2, int y2) {
    textcolor(LIGHTCYAN);

    gotoxy(x1, y1); printf("%c", 201); // canto sup. esquerdo
    gotoxy(x2, y1); printf("%c", 187); // canto sup. direito
    gotoxy(x1, y2); printf("%c", 200); // canto inf. esquerdo
    gotoxy(x2, y2); printf("%c", 188); // canto inf. direito

    for (int x = x1 + 1; x < x2; x++) {
        gotoxy(x, y1); printf("%c", 205); // linha topo
        gotoxy(x, y2); printf("%c", 205); // linha base
    }

    for (int y = y1 + 1; y < y2; y++) {
        gotoxy(x1, y); printf("%c", 186); // lateral esquerda
        gotoxy(x2, y); printf("%c", 186); // lateral direita
    }
}

void escreveTexto(int x, int y, int cor,char texto[100]) {
    textcolor(cor);
    gotoxy(x, y);
    printf("%s", texto);
}

void barraLateral() {
    desenhaBorda(5, 3, 35, 25);

    escreveTexto(9, 5, LIGHTGREEN, "== MENU ==");

    escreveTexto(8, 8, WHITE, "[A] Inserir Nome");
    escreveTexto(8, 9, WHITE, "[B] Simular Arquivo");
    escreveTexto(8, 10, WHITE, "[ESC] Sair");

    escreveTexto(7, 23, LIGHTCYAN, "Desenvolvedores");
    escreveTexto(9, 24, LIGHTCYAN, "de Software");
}

void limpaAreaExecucao() {
    for (int y = 4; y <= 24; y++) {
        for (int x = 37; x <= 179; x++) {
            gotoxy(x, y);
            printf(" ");
        }
    }
}

// === Código Principal ===
