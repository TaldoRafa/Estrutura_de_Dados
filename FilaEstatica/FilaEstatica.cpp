#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

#define TAM 10

//? Criação do Tipo de dado fila
typedef struct _FILA
{
    int data[TAM];
    long capacidade;
    long tamanho;
    long inicio;
    long fim;
} FILA;

//? Criação da Fila
FILA CriarFila(long capacidade)
{
    FILA Q;

    Q.capacidade = capacidade;
    Q.tamanho = 0;
    Q.inicio = 0;
    Q.fim = 0;

    return Q;
}

void Enfileirar(FILA *Q)
{
    if (Q->tamanho == Q->capacidade)
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
        system("cls");

        Q->data[Q->fim] = val;

        printf("Sucesso! %d inserido na posisão [%ld].", val, Q->fim);

        Q->fim = (Q->fim + 1) % Q->capacidade;
        Q->tamanho++;

        getch();
    }
}

void Desenfileirar(FILA *Q)
{
    if (Q->tamanho == 0)
    {
        system("cls");
        printf("ERRO! A Fila Esta Vazia!");
        getch();
    }
    else
    {
        system("cls");

        int val = Q->data[Q->inicio];

        printf("\nSucesso! %d removido da posisão [%ld].", val, Q->inicio);

        Q->data[Q->inicio] = 0;
        Q->inicio = (Q->inicio + 1) % Q->capacidade;
        Q->tamanho--;

        getch();
    }
}

void PrintFila(const FILA Q)
{
    if (Q.tamanho == 0)
    {
        system("cls");
        printf("ERRO! A Fila Esta Vazia!");
        getch();
    }
    else
    {
        system("cls");
        printf("Capacidade: %ld\n", Q.capacidade);
        printf("Tamanho: %ld\n", Q.tamanho);
        printf("inicio: %ld\n", Q.inicio);
        printf("fim: %ld\n", Q.fim);
        puts("\n");

        long s, i;
        for (s = 0, i = Q.inicio; s < Q.tamanho; s++, i = (i + 1) % Q.capacidade)
        {
            printf("[%ld] = %d \n", i, Q.data[i]);
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
    puts("3 - Ver Fila");
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
    bool sair = false;

    FILA Q = CriarFila(TAM);

    while (!sair)
    {
        opcao = menuOpcao();
        switch (opcao)
        {
        case 1:
            Enfileirar(&Q);
            break;
        case 2:
            Desenfileirar(&Q);
            break;
        case 3:
            PrintFila(Q);
            break;
        case 4:
            system("cls");
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