#include <stdio.h>
#include <stdbool.h>

enum Status { TO_DO, IN_PROGRESS, DONE, BLOCKED };
enum Prioridade { BAIXA, MEDIA, ALTA };

struct Task {
    int id;
    char nome[50];
    enum Status status;
    enum Prioridade prioridade;
};

struct Task criaTarefa(int id, char nome[], enum Status status, enum Prioridade prioridade) {
    struct Task t;
    t.id = id;
    int i = 0;
    while (nome[i] != '\0') {
        t.nome[i] = nome[i];
        i++;
    }
    t.nome[i] = '\0';
    t.status = status;
    t.prioridade = prioridade;
    return t;
}

void atualizaStatus(struct Task *t, enum Status novoStatus) {
    t->status = novoStatus;
}

bool tarefaUrgente(struct Task t) {
    if (t.prioridade == ALTA && t.status != DONE) {
        return true;
    }
    return false;
}

int main() {
    struct Task t1;

    t1 = criaTarefa(1, "Estudar C", TO_DO, ALTA);

    printf("Tarefa: %s\n", t1.nome);
    printf("Status inicial: %d\n", t1.status);
    printf("Prioridade: %d\n", t1.prioridade);

    if (tarefaUrgente(t1)) {
        printf("Esta tarefa e urgente!\n");
    } else {
        printf("Tarefa nao e urgente.\n");
    }

    atualizaStatus(&t1, IN_PROGRESS);

    printf("Status atualizado: %d\n", t1.status);

    return 0;
}
