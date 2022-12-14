#include "pilha.h"
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct pilha Pilha;
typedef struct lista Lista;

struct lista {
	int info;
	Lista *prox;
};

struct pilha{
	Lista *prim;
};

Pilha* pilha_cria(void){
	Pilha *p = (Pilha*)malloc(sizeof(Pilha));
	if (p==NULL){
		printf("Mem?ria Insuficiente !");
		exit(1);
	}
	p->prim = NULL;
	return p;
}

//insere um elemento no topo da pilha

void pilha_push(Pilha *p, int info){

	Lista *l = (Lista*)malloc(sizeof(Lista));
	if (l==NULL){
		printf("Mem?ria Insuficiente !");
		exit(1);
	}

	l->info = info;
	l->prox = p->prim;
	p->prim = l;
}

//testa se uma pilha ? vazia

int pilha_vazia(Pilha *p){
	return p->prim==NULL;
}

// remove um elemento do topo da pilha

int pilha_pop(Pilha *p){
	int a;
	Lista *l;
	if(pilha_vazia(p)){
		printf("Pilha vazia!");
		exit(1);
	}
	l = p->prim;
	a = l->info;
	p->prim = l->prox;
	free(l);
	return a;
}

// fun??o imprime elementos da pilha

void pilha_imprime(Pilha *p){
	Lista *laux = p->prim;
	while(laux!=NULL){
		printf("%d\n",laux->info);
		laux = laux->prox;
	}
}

//libera o espa?o alocado por uma pilha

void pilha_libera(Pilha *p){
	Lista* l = p->prim;
	Lista* laux;
	while(l!=NULL){
		laux = l->prox;
		free(l);
		l = laux;
	}
	free(p);
}

//empilha elementos comuns

Pilha* empilha_elem_comuns(Lista* l1, Lista* l2){

   Lista* laux2 = l2;
   Lista* igual = lst_cria();
   Pilha *pnew = pilha_cria();

   if(lst_vazia(l1)|| lst_vazia(l2)){
    return l1;
   } else {

   while(laux2!=NULL){
         Lista* laux1 = l1->prox;
         Lista* lant = l1;
      if(lant->info == laux2->info) // teste caso os primeiros elementos sejam iguais
        {
            l1 = lant->prox;
            igual = lst_insere_ordenado(igual,lant->info); // insere os elementos em comum em ordem crescente em uma nova lista;
            lant = l1; // atualiza o valor de lant e laux para prosseguir o c?digo
            laux1 = l1->prox;
        }
     while(laux1!=NULL){
         if(laux1->info == laux2->info){
             lant->prox= laux1->prox;
             igual = lst_insere_ordenado(igual,laux1->info);
             laux1= lant->prox;
           } else {
            laux1 = laux1->prox;
            lant = lant->prox;
        }
    }
  laux2 = laux2->prox;
   }

   while(!lst_vazia(igual)){ // copia os elementos da lista para uma nova pilha; empilhados em ordem crescente;
     pilha_push(pnew,igual->info);
     igual = igual->prox;
   }

return pnew;
   }

}

//Inverte os elementos de uma pilha

Pilha* inverte_pilha(Pilha *p){		
	
	Lista *lAux = p->prim;
	Pilha *pAux = pilha_cria();
	while(lAux!=NULL){ 
		pilha_push(pAux,lAux->info);
		lAux = lAux->prox;
	}
	return pAux;
}

