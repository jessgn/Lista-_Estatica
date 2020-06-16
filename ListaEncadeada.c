#include <stdio.h>
#include <stdlib.h>

 typedef struct Bloco {
 	int dado;
 	struct Bloco *prox;
} Nodo;

 void inicializa_lista(Nodo **N){//inicializa a lista
 	*N = NULL;
}

Nodo * Cria_Nodo(){ //aloca memória para o nodo
 	Nodo *p;
 	p = (Nodo *) malloc(sizeof(Nodo));
 	if(!p) {
 		printf("Problema de alocação");
		 exit(0);
 }
 	return p;
 }

 void insere_fim_lista(Nodo **N, int dado) {
	 Nodo *novo, * aux;
	 novo = Cria_Nodo( );
	 novo->dado = dado;
	 novo->prox = NULL;
	 if(*N == NULL)
	 	*N = novo;
	 else{
		 aux = *N;
		 while(aux->prox != NULL)
		 aux = aux->prox;
		 aux->prox = novo;
 }
}

 void insere_inicio_lista(Nodo **N, int dado) {
	 Nodo *novo;
	 novo = Cria_Nodo();
	 novo->dado = dado;
	 novo->prox = *N;
	 *N = novo;
}

int remove_inicio_lista(Nodo **N, int *dado){
	 Nodo *aux;
	 if(*N == NULL) //verifica se a lista está vazia
	 return 0;
	 else{
		 *dado = (*N)->dado;
		 aux = (*N)->prox;
		 free(*N);
		 *N = aux;
 }
 	return 1;
}

 void imprime_lista_ecandeada(Nodo *N){
	 Nodo *aux;
	 if(N == NULL)
		 printf("\n A lista está vazia!!");
		 else{
	 for(aux = N; aux != NULL; aux = aux->prox)
	 	printf("\n%d", aux->dado);
	}
}

int main() {
	 Nodo *MyList;
	 int menu, valor;
	 inicializa_lista(&MyList);
 do{
	 printf("\n1. Insere no fim da Lista");
	 printf("\n2. Insere no inicio da Lista");
	 printf("\n3. Exclui do inicio da Lista");
	 printf("\n4. Imprime Lista");
	 printf("\n5. sair\n");
	 scanf("%d", &menu);
	switch(menu){
 		case 1:
			 printf("\nInforme o valor a ser inserido no final da lista:");
			 scanf("%d", &valor);
			 insere_fim_lista(&MyList, valor);
 		break;
 		case 2:
			 printf("\nInforme o valor a ser inserido no inicio da lista:");
			 scanf("%d", &valor);
			 insere_inicio_lista(&MyList, valor);
		 break;
 		case 3:
			 if(remove_inicio_lista(&MyList, &valor) == 0)
		 		printf("\nA lista está vazia!!");
 			else
 				printf("\nO valor excluido do inicio da lista foi: %d", valor);
 		break;
 		case 4:
		 	imprime_lista_ecandeada(MyList);
		 break;
 		case 5:
			printf("\n\n\nSaindo do programa!");
 		break;
 		default:
 			printf("\nOpcao Invalida!!!");
 	}
 } 
 	while(menu != 5);
 return 0;
}
