#include <stdio.h>
#include <stdlib.h>
#include "fila1.h"


#define N 5
typedef struct fila{
	int n;
	int ini;
	int v[N];
}Fila;


Fila* fila_cria(void){
	Fila *f = (Fila*)malloc(sizeof(Fila));
	if(f==NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	f->n = 0;
	f->ini = 0;
	return f;
}


void fila_insere(Fila *f, int info){
	int fim;
	if(f->n == N){
		printf("Capacidade da Fila Estourou!!!\n");
		exit(1);
	}
	fim = (f->ini + f->n) % N;
	f->v[fim] = info;
	f->n++;
}


int fila_vazia(Fila *f){
	return f->n == 0;
}


int fila_remove(Fila *f){
	int a;
	if(fila_vazia(f)){
		printf("Fila Vazia!!!\n");
		exit(1);
	}
	a = f->v[f->ini];
	f->ini = (f->ini+1) % N;
	f->n--;
	return a;
}


void fila_imprime(Fila *f){
	int i; int k;
	for(i = 0; i < f->n; i++){
		k = (f->ini+i) % N;
		printf("%d\n",f->v[k]);
	}
}
	
	
void fila_libera(Fila *f){
	free(f);
}

// função para inverter uma fila

Fila* inverte_fila(Fila* f){
    int i,k=0;
    Fila *f1 = fila_cria();
     if(fila_vazia(f)){
 printf("Fila Vazia!!!\n");
 exit(1);
 } else {
    for(i = f->n-1; i>=0;i--){
    k = (f->ini+i) % N;
     fila_insere(f1,f->v[k]);
 }
 return f1;
 }

}

int qtd_primos(Fila *f)
{
	int i;
	int j;
	int k;
	int cont;
	int total = 0;

	for (i = 0; i < f->n; i++)
	{
		k = (f->ini + i) % N;
		cont = 0;
		for (j = 2; j <= f->v[k] / 2; j++)
		{
			if (f->v[k] % j == 0)
			{
				cont++;
				break;
			}
		}
		if (cont == 0)
			total++;
	}
	return total;
}
