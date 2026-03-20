#include <stdio.h>

struct Veiculo {
    char marca[50];
    char modelo[50];
    int ano;
    float preco;
};

void preencheVeiculo(struct Veiculo *v) {
    printf("Marca: ");
    scanf("%s", v->marca);

    printf("Modelo: ");
    scanf("%s", v->modelo);

    printf("Ano: ");
    scanf("%d", &v->ano);

    printf("Preco: ");
    scanf("%f", &v->preco);
}

void atualizaPreco(struct Veiculo *v, float novoPreco) {
    v->preco = novoPreco;
}

int main() {
    struct Veiculo v;

    printf("--- Cadastro do Veiculo ---\n");
    preencheVeiculo(&v);

    printf("\n--- Dados do Veiculo ---\n");
    printf("Marca: %s\n", v.marca);
    printf("Modelo: %s\n", v.modelo);
    printf("Ano: %d\n", v.ano);
    printf("Preco: %.2f\n", v.preco);

    float novoPreco;
    printf("\nDigite o novo preco: ");
    scanf("%f", &novoPreco);

    atualizaPreco(&v, novoPreco);

    printf("\n--- Preco Atualizado ---\n");
    printf("Preco: %.2f\n", v.preco);

    return 0;
}
