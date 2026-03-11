/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

typedef struct {
    char nome[30];
    int idade;
    char endereco[30];
} Pessoa;

void prenchePessoa(Pessoa *p){
    printf("\nDigite seu Nome: ");
    scanf("%s", &p->nome);
    
    printf("\nDigite sua idade: ");
    scanf("%d", &p->idade);
    
    printf("\nDigite seu Endereço: ");
    fflush(stdin);
    scanf(" %[^\n]s", &p->endereco);
}


void exibePessoa(Pessoa p){
    printf("\n %s", p.nome);
    
    printf("\n %d", p.idade);
    
    printf("\n %s", p.endereco);
}

int main()
{
    Pessoa pessoa1;
    
    prenchePessoa(&pessoa1);
    
    exibePessoa(pessoa1);
    

    return 0;
}
