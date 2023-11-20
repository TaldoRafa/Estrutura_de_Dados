#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

// TODO: Criação do Tipo de dado Base da Fila
typedef struct _staticQueue
{
    int *data;
    long capacity;
    long size;
    long begin;
    long end;
} StaticQueue;

//? Criação da Fila
StaticQueue *StaticQueueCreate(long capacity)
{
    StaticQueue *Q = (StaticQueue *)calloc(1, sizeof(StaticQueue));

    Q->data = (int *)calloc(capacity, sizeof(int));

    Q->capacity = capacity;
    Q->size = 0;
    Q->begin = 0;
    Q->end = 0;

    return Q;
}

//? Desalocação da Fila
void StaticQueueDestroy(StaticQueue **qRef)
{
    StaticQueue *Q = *qRef;

    free(Q->data); //* Desaloca o Vetor
    free(Q);       //* Desaloca a var Base da Fila

    *qRef = NULL; //* Seta a var como NULL
                  //* Para a var não ficar com ref de nenhum local
}

void StaticQueueEnqueue(StaticQueue *Q)
{
    if (Q->size == Q->capacity)
    {
        system("cls");
        printf("ERRO! A Fila Esta Cheia!");
        getch();
    }
    else
    {
        int val = 0;

        system("cls");
        printf("Insirra o valor a ser inserido: ");
        scanf("%d", &val);

        Q->data[Q->end] = val;
        printf("Sucesso! %d inserido na posisão [%ld].", val, Q->fim);
        Q->end = (Q->end + 1) % Q->capacity;
        Q->size++;

        getch();
    }
}

void StaticQueueDequeue(StaticQueue *Q)
{
    if (Q->size == 0)
    {
        system("cls");
        printf("ERRO! A Fila Esta Vazia!");
        getch();
    }
    else
    {
        int val = Q->data[Q->begin];

        printf("\nSucesso! %d removido da posisão [%ld].", val, Q->inicio);

        Q->data[Q->begin] = 0;
        Q->begin = (Q->begin + 1) % Q->capacity;
        Q->size--;

        system("cls");
        getch();
    }
}

void StaticQueuePrint(const StaticQueue *Q)
{
    if (Q->size == 0)
    {
        system("cls");
        printf("ERRO! A Fila Esta Vazia!");
        getch();
    }
    else
    {

        system("cls");
        printf("Capacidade: %ld\n", Q->capacity);
        printf("Tamanho: %ld\n", Q->size);
        printf("Begin: %ld\n", Q->begin);
        printf("End: %ld\n", Q->end);
        puts("\n");

        int s, i;
        for (s = 0, i = Q->begin; s < Q->size; s++, i = (i + 1) % Q->capacity)
        {
            printf("[%ld] = %d \n", i, Q->data[i]);
        }
        printf("\n\nPressione qualquer tecla para continuar!");
        getch();
    }
}

int menuOpcao()
{
    system("cls");
    int opcao = 0;

    puts("=============================");
    puts("       MENU DE OPCOES        ");
    puts("=============================");
    puts("");
    puts("1 - Adicionar Item");
    puts("2 - Remover Item");
    puts("3 - Ver Lista");
    puts("4 - Sair");
    puts("");
    puts("=============================");
    puts("");

    printf("Escolha 1 opcao: ");
    scanf("%d", &opcao);

    return opcao;
}

int main()
{
    int opcao = 0;
    long capacicy = 0;
    bool sair = false;

    printf("Qual o tamanho da fila: ");
    scanf("%ld", &capacicy);

    StaticQueue *Q = StaticQueueCreate(capacicy);

    while (!sair)
    {
        opcao = menuOpcao();
        switch (opcao)
        {
        case 1:
            StaticQueueEnqueue(Q);
            break;
        case 2:
            StaticQueueDequeue(Q);
            break;
        case 3:
            StaticQueuePrint(Q);
            break;
        case 4:
            system("cls");
            StaticQueueDestroy(&Q);
            sair = true;
            break;

        default:
            system("cls");
            puts("Opção invalida! Por favor insira uma opção valida!");
            getch();
            break;
        }
    }

    return 0;
}