#include <stdio.h>

struct Produto {
    int id;
    char nome[50];
    float preco;
    int quantidadeEstoque;
};

struct Produto criaProduto(int id, char *nome, float preco, int estoque) {
    struct Produto p;
    p.id = id;
    int i = 0;
    while (nome[i] != '\0') {
        p.nome[i] = nome[i];
        i++;
    }
    p.nome[i] = '\0';
    p.preco = preco;
    p.quantidadeEstoque = estoque;
    return p;
}

void atualizaEstoque(struct Produto *p, int delta) {
    p->quantidadeEstoque += delta;
}

void exibeProduto(struct Produto prod) {
    printf("\nID: %d\n", prod.id);
    printf("Nome: %s\n", prod.nome);
    printf("Preco: %.2f\n", prod.preco);
    printf("Quantidade em estoque: %d\n", prod.quantidadeEstoque);
}

int main() {
    struct Produto p1;
    char nome[50];
    int id, estoque, delta;
    float preco;

    printf("Digite o ID do produto: ");
    scanf("%d", &id);
    printf("Digite o nome do produto: ");
    scanf("%s", nome);
    printf("Digite o preco do produto: ");
    scanf("%f", &preco);
    printf("Digite a quantidade em estoque: ");
    scanf("%d", &estoque);

    p1 = criaProduto(id, nome, preco, estoque);

    printf("\n--- Produto cadastrado ---\n");
    exibeProduto(p1);

    printf("\nDigite a alteracao de estoque (positivo ou negativo): ");
    scanf("%d", &delta);

    atualizaEstoque(&p1, delta);

    printf("\n--- Produto atualizado ---\n");
    exibeProduto(p1);

    return 0;
}
