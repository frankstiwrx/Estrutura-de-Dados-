#include<stdio.h>
#include<stdlib.h>
#include"fila2.h"

typedef struct lista Lista;
typedef struct fila Fila;
typedef struct pilha Pilha;

struct lista{
    int info;
    Lista *prox;
};
struct fila{
    Lista *ini;
    Lista *fim;
};
struct pilha{
	Lista *prim;
};


Fila* fila_cria(void){
    Fila *f = (Fila*)malloc(sizeof(Fila));
    if(f==NULL){
        printf("Memoria insuficiente!");
        exit(1);
    }
    f->ini = NULL;
    f->fim = NULL;
    return f;
}

void fila_insere(Fila *f, int info){
    Lista *l = (Lista*)malloc(sizeof(Lista));
    if(l==NULL){
        printf("Memoria insuficiente !");
        exit(1);
    }
    l->info = info;
    l->prox = NULL;
    if(!fila_vazia(f)){
        f->fim->prox = l;
    }else{
        f->ini = l;
    }

    f->fim = l;

}


int fila_vazia(Fila *f){
    return f->ini == NULL;
}

int fila_remove(Fila *f){
    Lista *l;
    int a;
    if(fila_vazia(f)){
        printf("Fila vazia!");
        exit(1);
    }
    a = f->ini->info;
    l = f->ini;
    f->ini = f->ini->prox;
    free(l);
    if(fila_vazia(f)){
        f->fim = NULL;
    }
    return a;
}


void fila_imprime(Fila *f){
    Lista *laux;
    laux = f->ini;
    while(laux!=NULL){
        printf("%d\n",laux->info);
        laux = laux->prox;
    }
}

void fila_libera(Fila *f){
    Lista *l = f->ini;
    Lista *laux;
    while(l!=NULL){
        laux = l->prox;
        free(l);
        l = laux;
    }
    free(f);
}

//Pilha

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

int pilha_vazia(Pilha *p){
	return p->prim==NULL;
}

Pilha* pilha_cria(void){
	Pilha *p = (Pilha*)malloc(sizeof(Pilha));
	if (p==NULL){
		printf("Memória Insuficiente !");
		exit(1);
	}
	p->prim = NULL;
	return p;
}

void pilha_push(Pilha *p, int info){

	Lista *l = (Lista*)malloc(sizeof(Lista));
	if (l==NULL){
		printf("Memória Insuficiente !");
		exit(1);
	}

	l->info = info;
	l->prox = p->prim;
	p->prim = l;
}

//Trabalho

//Função quantidade primos

int qtd_primos(Fila* f){
    Lista* lAux = f->ini;
    int cont = 0; 
	int qtd = 0; 
	int total = 0;
    while(lAux!=NULL){
     	for(cont = 2; cont <= (lAux->info)/2; cont++) {
    		if(lAux->info % cont == 0) {
       			qtd++;
       			break;
    		}
 	}
		if(qtd == 0)
			total++;
        lAux = lAux->prox;
        qtd = 0;
    }
    return total;
}


//Função inverte fila

Fila* inverte_fila(Fila* f){

    Fila *faux = fila_cria();
    Lista* laux = f->ini;
    Pilha* p1 = pilha_cria();
    Fila* fnew = fila_cria();

    if(fila_vazia(f)){
        return f;
    } else {
    while(laux!=NULL){ 
        fila_insere(faux,laux->info);
        laux = laux->prox;

    }

  while( !fila_vazia(faux) )
{
  pilha_push( p1,fila_remove(faux) ); 
}

while( !pilha_vazia(p1) )
{
  fila_insere( fnew , pilha_pop(p1) ); 
  
return fnew;

}

}

}



