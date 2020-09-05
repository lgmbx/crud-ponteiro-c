#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    char nome[20];
    int idade;
    struct no *ptrNext;
}no;

struct no *ptrInicio = NULL, *ptr = NULL, *aux = NULL;

void input(){
    printf("Nome: ");
    fflush(stdin);
    gets(ptr->nome);
    fflush(stdin);
    printf("Idade: ");
    scanf("%d", &ptr->idade);
}

void cadastrar(){

    if(ptrInicio == NULL){
        ptrInicio = (no*)malloc(sizeof(no));
        ptr = ptrInicio;
        aux = ptr;
        input();
        ptr->ptrNext = NULL;
    }
    else{
        //sincroniza os ponteiros
        aux = ptrInicio;
        ptr = ptrInicio;

        while(ptr->ptrNext != NULL){
            ptr = ptr->ptrNext;
            aux = ptr;
        }

        ptr = (no*)malloc(sizeof(no));
        aux->ptrNext = ptr;
        aux = ptr;
        input();
        ptr->ptrNext = NULL;

    }
}

void exibir(){
    ptr = ptrInicio;
    while(ptr != NULL){
        printf("Nome: %s, Idade: %d\n", ptr->nome, ptr->idade);
        ptr = ptr->ptrNext;
    }
    if(ptrInicio == NULL){
        printf("Nenhum registro encontrado!");
    }
    system("pause");
}

void pesquisar(){

    char nomePesquisa[20];
    int achou = 0;
    fflush(stdin);
    printf("Digite um nome a ser pesquisado: ");
    scanf("%s", &nomePesquisa);

    ptr = ptrInicio;
    while (ptr != NULL){
        if(strcmp(nomePesquisa, ptr->nome) == 0){
            printf("Nome: %s, Idade: %d\n", ptr->nome, ptr->idade);
            achou = 1;
        }
        ptr = ptr->ptrNext;
    }
    if(achou == 0){
        printf("Nenhum registro encontrado! ");
    }
    system("pause");
}

void remover(){
    char nomePesquisa[20];
    int achou = 0;
    fflush(stdin);
    printf("Digite um nome a ser removido: ");
    scanf("%s", &nomePesquisa);

    ptr = ptrInicio;
    aux = ptrInicio;

    while(ptr != NULL){

        //Executa se for o primeiro registro da lista
        if(strcmp(nomePesquisa, ptrInicio->nome) == 0){
            //Executa se só houver 1 registro na lista
            if(ptrInicio->ptrNext == NULL){
                free(ptrInicio);
                ptrInicio = NULL;

            }
            else{
                ptrInicio = ptrInicio->ptrNext;
                free(ptr);
                ptr = ptrInicio;
            }

        }

        else if(strcmp(nomePesquisa, ptr->nome) == 0){
            aux->ptrNext = ptr->ptrNext;
            free(ptr);
            ptr = aux;
        }
        aux = ptr;
        ptr = ptr->ptrNext;
    }
}

int main(){
    int op = 0;

    while(op != 5){
        system("cls");
        printf("[1] Cadastrar...:");
        printf("\n[2] Exibir......:");
        printf("\n[3] Pesquisar...:");
        printf("\n[4] Remover.....:");
        printf("\n[5] Sair........:");
        printf("\n>> ");
        scanf("%d", &op);

        switch (op){
        case 1:
            cadastrar();
            break;

        case 2:
            exibir();
            break;

        case 3:
            pesquisar();
            break;

        case 4:
            remover();
            break;

        default:
            break;
        }
    }


    return  0;
}
