#include <stdio.h>

struct Ponto2D {
    float x, y;
};

struct Ponto2D criaPonto(float x, float y) {
    struct Ponto2D p;
    p.x = x;
    p.y = y;
    return p;
}

void movePonto(struct Ponto2D *p, float dx, float dy) {
    p->x = p->x + dx;
    p->y = p->y + dy;
}

float raiz(float n) {
    float x = n;
    float erro = 0.0001;

    while ((x * x - n) > erro || (n - x * x) > erro) {
        x = (x + n / x) / 2;
    }

    return x;
}

float distanciaEntrePontos(struct Ponto2D p1, struct Ponto2D p2) {
    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;
    return raiz(dx * dx + dy * dy);
}

int main() {
    struct Ponto2D p1, p2;
    float dx, dy;

    printf("Digite x e y do ponto 1: ");
    scanf("%f %f", &p1.x, &p1.y);

    printf("Digite x e y do ponto 2: ");
    scanf("%f %f", &p2.x, &p2.y);

    float dist = distanciaEntrePontos(p1, p2);
    printf("Distancia: %.2f\n", dist);

    printf("Digite dx e dy para mover o ponto 1: ");
    scanf("%f %f", &dx, &dy);

    movePonto(&p1, dx, dy);

    printf("Novo ponto 1: (%.2f, %.2f)\n", p1.x, p1.y);

    return 0;
}
