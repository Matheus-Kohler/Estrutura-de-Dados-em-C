#include <stdio.h>

struct Receita {
    char nome[100];
    int tempoPreparoMinutos;
    int porcoes;
};

void preencheReceita(struct Receita *r) {
    printf("Nome da receita: ");
    scanf("%s", r->nome);

    printf("Tempo de preparo (minutos): ");
    scanf("%d", &r->tempoPreparoMinutos);

    printf("Numero de porcoes: ");
    scanf("%d", &r->porcoes);
}

void imprimeReceita(struct Receita r) {
    printf("\nReceita: %s\n", r.nome);
    printf("Tempo de preparo: %d minutos\n", r.tempoPreparoMinutos);
    printf("Porcoes: %d\n", r.porcoes);
}

void ajustaPorcoes(struct Receita *r, int novoNumPorcoes) {
    r->porcoes = novoNumPorcoes;
}

int main() {
    struct Receita r;
    int novasPorcoes;

    preencheReceita(&r);

    printf("\n--- Receita cadastrada ---\n");
    imprimeReceita(r);

    printf("\nDigite o novo numero de porcoes: ");
    scanf("%d", &novasPorcoes);

    ajustaPorcoes(&r, novasPorcoes);

    printf("\n--- Receita atualizada ---\n");
    imprimeReceita(r);

    return 0;
}
