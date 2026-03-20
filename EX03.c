#include <stdio.h>
#include <stdbool.h>

struct AlunoNota {
    int matricula;
    char nome[50];
    float n1, n2, n3;
    float media;
};

struct AlunoNota maiorPrimeiraProva(struct AlunoNota a[], int tam) {
    int i;
    struct AlunoNota maior = a[0];

    for (i = 1; i < tam; i++) {
        if (a[i].n1 > maior.n1) {
            maior = a[i];
        }
    }

    return maior;
}

void mediaGeral(struct AlunoNota *a) {
    a->media = (a->n1 + a->n2 + a->n3) / 3;
}

bool aprovado(struct AlunoNota a) {
    if (a.media >= 6) {
        return true;
    } else {
        return false;
    }
}

bool reprovado(struct AlunoNota a) {
    if (a.media < 6) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int i;
    struct AlunoNota alunos[3];

    for (i = 0; i < 3; i++) {
        printf("\nAluno %d\n", i + 1);

        printf("Matricula: ");
        scanf("%d", &alunos[i].matricula);

        printf("Nome: ");
        scanf("%s", alunos[i].nome);

        printf("Nota 1: ");
        scanf("%f", &alunos[i].n1);

        printf("Nota 2: ");
        scanf("%f", &alunos[i].n2);

        printf("Nota 3: ");
        scanf("%f", &alunos[i].n3);

        
        mediaGeral(&alunos[i]);
    }

    
    printf("\n--- RESULTADOS ---\n");

    for (i = 0; i < 3; i++) {
        printf("\nNome: %s\n", alunos[i].nome);
        printf("Media: %.2f\n", alunos[i].media);

        if (aprovado(alunos[i])) {
            printf("Aprovado\n");
        } else {
            printf("Reprovado\n");
        }
    }

  
    struct AlunoNota melhor = maiorPrimeiraProva(alunos, 3);

    printf("\nAluno com maior N1: %s\n", melhor.nome);
    printf("Nota N1: %.2f\n", melhor.n1);

    return 0;
}
