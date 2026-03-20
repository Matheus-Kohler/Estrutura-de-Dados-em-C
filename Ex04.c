#include <stdio.h>


struct Vetor3D {
    float x, y, z;
};

struct Vetor3D somaVetores(struct Vetor3D a, struct Vetor3D b) {
    struct Vetor3D resultado;

    resultado.x = a.x + b.x;
    resultado.y = a.y + b.y;
    resultado.z = a.z + b.z;

    return resultado;
}

void acumulaNoPrimeiro(struct Vetor3D *a, struct Vetor3D b) {
    a->x = a->x + b.x;
    a->y = a->y + b.y;
    a->z = a->z + b.z;
}

int main() {
    struct Vetor3D v1, v2, soma;

    printf("Digite o vetor 1 (x y z): ");
    scanf("%f %f %f", &v1.x, &v1.y, &v1.z);

    printf("Digite o vetor 2 (x y z): ");
    scanf("%f %f %f", &v2.x, &v2.y, &v2.z);

    soma = somaVetores(v1, v2);

    printf("\n--- Soma (novo vetor) ---\n");
    printf("Resultado: (%.2f, %.2f, %.2f)\n", soma.x, soma.y, soma.z);

    printf("\n--- Antes da acumulacao ---\n");
    printf("Vetor 1: (%.2f, %.2f, %.2f)\n", v1.x, v1.y, v1.z);

    acumulaNoPrimeiro(&v1, v2);

    printf("\n--- Depois da acumulacao ---\n");
    printf("Vetor 1: (%.2f, %.2f, %.2f)\n", v1.x, v1.y, v1.z);

    return 0;
}
