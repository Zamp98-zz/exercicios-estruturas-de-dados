#include <stdlib.h>
#include <stdio.h>
#define true 1
#define false 0

TG *init(void){
	return NULL;
}

typedef struct grafo{
	int info;
	struct grafo *prox;
	struct grafo *viz;
}TG;

void tela(void){
	printf("1 - Criar um elemento:\n");
	printf("2 - Mostrar elementos:\n");
	printf("else - Sair\n");

}

TG *inicializaNo(int info){
	TG *novo = malloc(sizeof(TG));
	novo->info = info;
	novo->prox  = novo->viz = init();
	return novo;
}

TG *criaNo(TG *ref, int info){
	if(!ref){
		TG *novo = inicializaNo(info);
		return novo;
	}
	else{
		buscaNo(ref, info);
	}
}

int main(void){
	TG *ref = init();
	while(true){
		tela();
		int op;
		scanf("%d", &op);
		if(op == 1){
			int info;
			scanf("%d", &info);
			ref = criaNo();
		}
		else if(op == 2){
			
		}
		else{
			return false;
		}
	}
}
