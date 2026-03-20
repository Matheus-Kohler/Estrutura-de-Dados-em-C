#include <stdio.h>
#include <stdbool.h>

struct Livro {
    char titulo[100];
    char autor[50];
    int anoPublicacao;
    int exemplaresDisponiveis;
};

struct Livro criaLivro(char titulo[], char autor[], int ano, int exemplares) {
    struct Livro l;
    int i = 0;
    while (titulo[i] != '\0') {
        l.titulo[i] = titulo[i];
        i++;
    }
    l.titulo[i] = '\0';
    
    i = 0;
    while (autor[i] != '\0') {
        l.autor[i] = autor[i];
        i++;
    }
    l.autor[i] = '\0';
    
    l.anoPublicacao = ano;
    l.exemplaresDisponiveis = exemplares;
    return l;
}

bool emprestaLivro(struct Livro *livro) {
    if (livro->exemplaresDisponiveis > 0) {
        livro->exemplaresDisponiveis--;
        return true;
    }
    return false;
}

void devolveLivro(struct Livro *livro) {
    livro->exemplaresDisponiveis++;
}

void exibeLivro(struct Livro livro) {
    printf("\nTitulo: %s\n", livro.titulo);
    printf("Autor: %s\n", livro.autor);
    printf("Ano de publicacao: %d\n", livro.anoPublicacao);
    printf("Exemplares disponiveis: %d\n", livro.exemplaresDisponiveis);
}

int main() {
    struct Livro l1;
    char titulo[100], autor[50];
    int ano, exemplares;

    printf("Digite o titulo do livro: ");
    scanf("%s", titulo);
    printf("Digite o autor do livro: ");
    scanf("%s", autor);
    printf("Digite o ano de publicacao: ");
    scanf("%d", &ano);
    printf("Digite o numero de exemplares: ");
    scanf("%d", &exemplares);

    l1 = criaLivro(titulo, autor, ano, exemplares);

    exibeLivro(l1);

    if (emprestaLivro(&l1)) {
        printf("\nLivro emprestado com sucesso!\n");
    } else {
        printf("\nNao ha exemplares disponiveis para emprestimo.\n");
    }

    exibeLivro(l1);

    devolveLivro(&l1);
    printf("\nLivro devolvido.\n");
    exibeLivro(l1);

    return 0;
}
