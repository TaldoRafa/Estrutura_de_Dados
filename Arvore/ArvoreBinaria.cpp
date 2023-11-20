#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <stddef.h>

using namespace std;

struct No
{
    int valor;
    No *direita;
    No *esquerda;
};

class ArvoreBinariadeBusca
{
private:
    No *raiz;

public:
    ArvoreBinariadeBusca();
    ~ArvoreBinariadeBusca();
    void deletarArvore(No *NoAtual);
    No *obterRaiz();
    bool estaVazio();
    bool estaCheio();
    void inserir(int item);
    void remover(int item);
    void removerBusca(int item, No *&NoAtual);
    void deletarNo(No *&NoAtual);
    void obterSucessor(int &itemSucessor, No *temp);
    void buscar(int &item, bool &busca);
    void imprimirPreOrdem(No *NoAtual);
    void imprimirOrdem(No *NoAtual);
    void imprimirPosOrdem(No *NoAtual);
};

int menuOpcao()
{
    system("cls");
    int opcao;

    puts("=============================");
    puts("       MENU DE OPCOES        ");
    puts("=============================");
    puts("");
    puts("1 - Adicionar Item");
    puts("2 - Remover Item");
    puts("3 - Buscar Item");
    puts("4 - Imprimir Arvore Pre Ordem");
    puts("5 - Imprimir Arvore Em Ordem");
    puts("6 - Imprimir Arvore Pos Ordem");
    puts("7 - Sair");
    puts("");
    puts("=============================");
    puts("");

    printf("Escolha 1 opcao: ");
    scanf("%d", &opcao);

    return opcao;
}

void Intro()
{
    system("cls");
    puts("=================================");
    puts("     TRABALHO ÁRVORE BINARIA     ");
    puts("=================================");
    puts("           ---[10]----           ");
    puts("           |         |           ");
    puts("        --[08]--    [12]         ");
    puts("        |      |                 ");
    puts("       [06]   [09]               ");
    puts("                                 ");
    puts("=================================");
    getch();
}

int main()
{
    Intro();

    ArvoreBinariadeBusca ArvoreDeInteiros;
    int num, opcao;

    bool sair = false;

    while (!sair)
    {
        opcao = menuOpcao();
        system("cls");

        switch (opcao)
        {
        case 1:
            if (ArvoreDeInteiros.estaCheio())
            {
                puts("ERRO! A Arvore esta cheia!");
                puts("Não é possivel inserir mais elementos!");
                getch();
            }
            else
            {
                printf("Qual valor inteiro deseja adicionar: ");
                scanf("%d", &num);

                ArvoreDeInteiros.inserir(num);
            }

            break;
        case 2:
            if (ArvoreDeInteiros.estaVazio())
            {
                puts("ERRO! A Arvore esta vazia!");
                getch();
            }
            else
            {
                printf("Qual valor inteiro valido deseja remover: ");
                scanf("%d", &num);

                bool busca;

                ArvoreDeInteiros.buscar(num, busca);

                if (busca)
                {
                    system("cls");
                    ArvoreDeInteiros.remover(num);
                    printf("O valor %d foi removido com sucesso!", num);
                }
                else
                {
                    system("cls");
                    puts("ERRO! O valor inserido não existe na arvore!");
                    getch();
                }
            }

            break;
        case 3:
            bool busca;

            printf("Qual valor inteiro deseja buscar: ");
            scanf("%d", &num);

            ArvoreDeInteiros.buscar(num, busca);

            system("cls");

            if (busca)
            {
                printf("Sucesso! O valor %d foi encontrado!", num);
                getch();
            }
            else
            {
                printf("O valor %d não foi encontrado na arvore!", num);
                getch();
            }

            break;
        case 4:
            ArvoreDeInteiros.imprimirPreOrdem(ArvoreDeInteiros.obterRaiz());

            puts("");
            getch();
            break;
        case 5:
            ArvoreDeInteiros.imprimirOrdem(ArvoreDeInteiros.obterRaiz());

            puts("");
            getch();
            break;
        case 6:
            ArvoreDeInteiros.imprimirPosOrdem(ArvoreDeInteiros.obterRaiz());

            puts("");
            getch();
            break;
        case 7:
            system("cls");

            sair = true;
            break;

        default:
            system("cls");
            printf("Erro! Opcao invalida, precione qualquer tecla para continuar! ");
            getch();
            break;
        }
    }

    return 0;
}

ArvoreBinariadeBusca::ArvoreBinariadeBusca() // construtora
{
    raiz = NULL;
}

ArvoreBinariadeBusca::~ArvoreBinariadeBusca() // destrutor
{
    deletarArvore(raiz);
}

void ArvoreBinariadeBusca::deletarArvore(No *NoAtual)
{
    if (NoAtual != NULL)
    {

        deletarArvore(NoAtual->esquerda);

        deletarArvore(NoAtual->direita);

        delete NoAtual;
    }
}

No *ArvoreBinariadeBusca::obterRaiz()
{
    return raiz;
}

bool ArvoreBinariadeBusca::estaVazio()
{
    return (raiz == NULL);
}

bool ArvoreBinariadeBusca::estaCheio()
{
    try
    {
        No *temp = new No;
        delete temp;
        return false;
    }
    catch (std::bad_alloc &exception)
    {
        return true;
    }
}

void ArvoreBinariadeBusca::inserir(int item)
{
    if (estaCheio())
    {
        printf("A arvore esta cheia! Não foi possivel inserir este elemento!");
        getch();
    }
    else
    {
        No *NoNovo = new No;
        NoNovo->valor = item;
        NoNovo->direita = NULL;
        NoNovo->esquerda = NULL;

        if (raiz == NULL)
        {
            raiz = NoNovo;
        }
        else
        {
            No *temp = raiz;

            while (temp != NULL)
            {
                if (item < temp->valor)
                {
                    if (temp->esquerda == NULL)
                    {
                        temp->esquerda = NoNovo;
                        break;
                    }
                    else
                    {
                        temp = temp->esquerda;
                    }
                }
                else if (item > temp->valor)
                {
                    if (temp->direita == NULL)
                    {
                        temp->direita = NoNovo;
                        break;
                    }
                    else
                    {
                        temp = temp->direita;
                    }
                }
                else
                {
                    system("cls");
                    printf("ERRO! O valor inserido ja existe na arvore!");
                    getch();
                    break;
                }
            }
        }
    }
}

void ArvoreBinariadeBusca::remover(int item)
{
    removerBusca(item, raiz);
}

void ArvoreBinariadeBusca::removerBusca(int item, No *&NoAtual)
{
    if (item < NoAtual->valor)
    {
        removerBusca(item, NoAtual->esquerda);
    }
    else if (item > NoAtual->valor)
    {
        removerBusca(item, NoAtual->direita);
    }
    else if (item == NoAtual->valor)
    {
        deletarNo(NoAtual);
    }
}

void ArvoreBinariadeBusca::deletarNo(No *&NoAtual)
{
    No *temp = NoAtual;

    if (NoAtual->esquerda == NULL)
    {
        NoAtual = NoAtual->direita;
        delete temp;
    }
    else if (NoAtual->direita == NULL)
    {
        NoAtual = NoAtual->esquerda;
        delete temp;
    }
    else
    {
        int valorSucessor;
        obterSucessor(valorSucessor, NoAtual);

        NoAtual->valor = valorSucessor;

        removerBusca(valorSucessor, NoAtual->direita);
    }
}

void ArvoreBinariadeBusca::obterSucessor(int &itemSucessor, No *temp)
{
    temp = temp->direita;

    while (temp->esquerda != NULL)
    {
        temp = temp->esquerda;
    }

    itemSucessor = temp->valor;
}

void ArvoreBinariadeBusca::buscar(int &item, bool &busca)
{
    No *NoAtual = raiz;

    system("cls");

    while (NoAtual != NULL)
    {
        if (item < NoAtual->valor)
        {
            NoAtual = NoAtual->esquerda;
        }
        else if (item > NoAtual->valor)
        {
            NoAtual = NoAtual->direita;
        }
        else
        {
            busca = true;

            break;
        }
    }

    if (NoAtual == NULL)
    {
        busca = false;
    }
}

void ArvoreBinariadeBusca::imprimirPreOrdem(No *NoAtual)
{
    if (NoAtual != NULL)
    {
        printf("%d, ", NoAtual->valor);

        imprimirPreOrdem(NoAtual->esquerda);

        imprimirPreOrdem(NoAtual->direita);
    }
}

void ArvoreBinariadeBusca::imprimirOrdem(No *NoAtual)
{
    if (NoAtual != NULL)
    {
        imprimirOrdem(NoAtual->esquerda);

        printf("%d, ", NoAtual->valor);

        imprimirOrdem(NoAtual->direita);
    }
}

void ArvoreBinariadeBusca::imprimirPosOrdem(No *NoAtual)
{
    if (NoAtual != NULL)
    {
        imprimirPosOrdem(NoAtual->esquerda);

        imprimirPosOrdem(NoAtual->direita);

        printf("%d, ", NoAtual->valor);
    }
}