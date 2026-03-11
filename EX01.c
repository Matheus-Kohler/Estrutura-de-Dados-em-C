
#include <stdio.h>

typedef struct {
    int hora;
    int minuto;
    int segundo;
}Horario;

typedef struct{
    int ano;
    int mes;
    int dia;
}Data;


typedef struct{
    Horario horarioCompromisso;
    Data dataCompromisso;
    char descricao[50];
}Compromisso;


void imprimir(Compromisso *ponteiro){
    printf("\n");
    printf("\nAno: %d", ponteiro->dataCompromisso.ano);
    printf("\nMês: %d", ponteiro->dataCompromisso.mes);
    printf("\nDia: %d", ponteiro->dataCompromisso.dia);
    printf("\n");
    printf("\nHora: %d", ponteiro->horarioCompromisso.hora);
    printf("\nMinuto: %d", ponteiro->horarioCompromisso.minuto);
    printf("\nSegundo: %d", ponteiro->horarioCompromisso.segundo);
    printf("\n");
    printf("\nDescrição do Compromisso: %s", ponteiro->descricao);
}


void criaCompromisso(Compromisso *ponteiro) {
    
    
    printf("\nDigite o ano, mês e dia(nessa ordem): ");
    scanf("\n %d", &ponteiro->dataCompromisso.ano);
    scanf("\n %d", &ponteiro->dataCompromisso.mes);
    scanf("\n %d", &ponteiro->dataCompromisso.dia);
    
    printf("\nDigite a hora, minuto e segundo(nessa ordem): ");
    scanf("\n\n %d", &ponteiro->horarioCompromisso.hora);
    scanf("\n %d", &ponteiro->horarioCompromisso.minuto);
    scanf("\n %d", &ponteiro->horarioCompromisso.segundo);
    
    printf("\nDigite a descrição: ");
    scanf("\n \n %s", &ponteiro->descricao);
    
    /* validação */ 
    
    if (&ponteiro->horarioCompromisso.segundo > 59){
        &ponteiro->horarioCompromisso.minuto +=1;
    }
    else if (&ponteiro->horarioCompromisso.minuto > 59){
        &ponteiro->horarioCompromisso.hora +=1;
    }
    else if (&ponteiro->horarioCompromisso.hora > 59){
        &ponteiro->dataCompromisso.dia +=1;
    }
    else if (&ponteiro->dataCompromisso.dia > 30){
        &ponteiro->dataCompromisso.mes +=1;
    }
    else if (&ponteiro->dataCompromisso.dia > 12){
        &ponteiro->dataCompromisso.ano +=1;
    }
}


int main()
{
    // Teste da função de impressão
    // Compromisso aula = {{13,30,0},{2026,6,20},{"Aula Jotair"}};
    // imprimir(&aula);
    
    printf("\n\n===============================\n");
    Compromisso trabalho;
    
    criaCompromisso(&trabalho);
    imprimir(&trabalho);
    
    return 0;
}
