#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef struct node{
    int info;
    struct node *left, *right;

}Node;
Node *init(){
    return NULL;
}

Node * inicializaNode(int info){
    Node *novo = (Node*)malloc(sizeof(Node));
    novo->left = novo->right = NULL;
    novo->info = info;
    return novo;
}

Node *insere(Node *raiz, int info){
    if(!(raiz)){
        Node *novo = inicializaNode(info);
        raiz = novo;
    }
    else{
        if(raiz->info>=info){
            raiz->left = insere(raiz->left, info);
        }
        else{
            raiz->right = insere(raiz->right, info);
        }
    }
    return raiz;
}

Node *remover(Node *raiz, int info){
    if((!raiz)) return raiz;
    if(info<raiz->info)
        raiz->left = remover(raiz->left, info);
    else if(info>raiz->info)
        raiz->right = remover(raiz->right, info);
    else{
        if((!raiz->right) && (!raiz->left)){
            free(raiz);
            return NULL;
        }
        else if((!raiz->right) || (!raiz->left)){
            Node *aux = raiz;
            if(!raiz->right){
                raiz = raiz->left;
            }
            else raiz = raiz->right;
            free(aux);
        }
        else{
            Node *aux = raiz;
            while(aux->left){
                aux = aux->left;
            }
            raiz->info = aux->info;
            aux->info = info;
            raiz->right = remover(raiz->right, info);
            free(aux);
        }

    }
    return raiz;
}

void imprime(Node *raiz){
    if(!(raiz)) return;
    imprime(raiz->left);
    printf("%d ", raiz->info);
    imprime(raiz->right);

}

void tela(Node *raiz){

    printf("\n1 - Inserir elemento na avere:\n");
    printf("2 - Deletar elemento da avere:\n");
    printf("3 - Mostrar a avere:\n");
    printf("4 - Sair\n");
}

int main()
{
    Node *raiz = init();
    while(true){
        int input;
        tela(raiz);
        scanf("%d", &input);
        if(input == 1){
            int info;
            system("clear");
            printf("Digite um valor:\n");
            scanf("%d", &info);
            raiz = insere(raiz, info);
        }
        else if(input == 2){
            imprime(raiz);
            printf("Digite o valor que deseja apagar:\n");
            int info;
            scanf("%d", &info);
            raiz = remover(raiz, info);
        }
        else if(input == 3){
            system("clear");
            imprime(raiz);
            printf("\nPressione uma tecla para continuar:\n");
            getchar();
        }
        else return false;
    }
}
