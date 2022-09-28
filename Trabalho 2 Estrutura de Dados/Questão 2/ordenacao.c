#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"



void bubbleSort(long long int n,  int *v){
    long long  int i, j;

    for(i=0; i<n-1; i++){
        for(j=i; j<n; j++){
            if(v[i]>v[j]){
                int aux = v[i];
                v[i]=v[j];
                v[j]=aux;
            }
        }
    }
}




void processa_bubbleSort(unsigned long int n) {
	
    long long int i;
         
    int *v_crescente = malloc(n * sizeof(int));
    int *v_descrecente  = malloc(n * sizeof(int));
    int *v_aleatorio = malloc(n * sizeof(int));;

    for(i=0; i<n; i++){
        v_aleatorio[i] = rand()%100;
        v_crescente[i] = i;
    }

    for( ; i > 0; i--){
       v_descrecente[n - i] = i;
    }

    printf("BubbleSort com vetor crescente:");
    srand(time(NULL));

    clock_t Ticks[2];

    Ticks[0] = clock();

     bubbleSort(n, v_crescente);

    Ticks[1] = clock();

    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("%g ms. \n", Tempo);


    printf("BubbleSort com vetor descrecente:");
    srand(time(NULL));


    Ticks[0] = clock();

    bubbleSort(n, v_descrecente);

    Ticks[1] = clock();

    Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("%g ms. \n", Tempo);



    printf("BubbleSort com vetor aleatorio:");
    srand(time(NULL));


    Ticks[0] = clock();

     bubbleSort(n, v_aleatorio);

    Ticks[1] = clock();

    Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("%g ms.", Tempo);

}
void insertionSort( long long int n,   int *v){
    long long int i;

	for (i = 1; i < n; i++){
		int j = i;
		while (j > 0 && v[j] < v[j-1]) {
			int aux = v[j];
			v[j] = v[j-1];
			v[j-1] = aux;
			j-=1;
		}

	}

}

void processa_insertionSort( long long int  n){
  
   long long  int i;
    int *v_crescente = malloc(n * sizeof(int));
    int *v_descrecente  = malloc(n * sizeof(int));
    int *v_aleatorio = malloc(n * sizeof(int));;
   
    for(i=0; i<n; i++){
        v_aleatorio[i] = rand()%100;
        v_crescente[i] = i;
    }

    for( ; i > 0; i--){
       v_descrecente[n - i] = i;
    }

    printf("InsertionSort com vetor crescente:");
    srand(time(NULL));
   
    clock_t Ticks[2];

    Ticks[0] = clock();

    insertionSort(n, v_crescente);

    Ticks[1] = clock();

    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("%g ms. \n", Tempo);


    printf("InsertionSort com vetor descrecente:");
    srand(time(NULL));


    Ticks[0] = clock();

    insertionSort(n, v_descrecente);

    Ticks[1] = clock();

    Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("%g ms. \n", Tempo);



    printf("InsertionSort com vetor aleatorio:");
    srand(time(NULL));


    Ticks[0] = clock();

    insertionSort(n, v_aleatorio);

    Ticks[1] = clock();

    Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("%g ms.", Tempo);

}
void quick_sort(long long int esquerda, long long int direita, int *v) {
  long long  int i, j, x, y;

    i = esquerda;
    j = direita;
    x = v[(esquerda + direita) / 2];

    while(i <= j) {
        while(v[i] < x && i < direita) {
            i++;
        }
        while(v[j] > x && j > esquerda) {
            j--;
        }
        if(i <= j) {
            y = v[i];
            v[i] = v[j];
            v[j] = y;
            i++;
            j--;
        }
    }

    if(j > esquerda) {
        quick_sort(esquerda, j,v);
    }
    if(i < direita) {
        quick_sort(i, direita,v);
    }
}

void processa_quickSort(long long int n){
  long long	int i;
  int *v_crescente = malloc(n * sizeof(int));
  int *v_descrecente  = malloc(n * sizeof(int));
  int *v_aleatorio = malloc(n * sizeof(int));;
  
    for(i=0; i<n; i++){
        v_aleatorio[i] = rand()%100;
        v_crescente[i] = i;
    }

    for( ; i > 0; i--){
       v_descrecente[n - i] = i;
    }

    printf("QuickSort com vetor crescente:");
    srand(time(NULL));

    clock_t Ticks[2];

    Ticks[0] = clock();
    quick_sort(0,n-1,v_crescente);

    Ticks[1] = clock();

    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("%g ms. \n", Tempo);


    printf("QuickSort com vetor descrecente:");
    srand(time(NULL));


    Ticks[0] = clock();

    quick_sort(0,n-1,v_descrecente);

    Ticks[1] = clock();

    Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("%g ms. \n", Tempo);


    printf("QuickSort com vetor aleatorio:");

    srand(time(NULL));

    Ticks[0] = clock();

    quick_sort(0,n-1,v_aleatorio);

    Ticks[1] = clock();

    Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("%g ms.", Tempo);
}

void heapsort(long long int n,  int *v) {
   long long int i = n / 2, pai, filho, t;
   while(1) {
      if (i > 0) {
          i--;
          t = v[i];
      } else {
          n--;
          if (n <= 0) return;
          t = v[n];
          v[n] = v[0];
      }
      pai = i;
      filho = i * 2 + 1;
      while (filho < n) {
          if ((filho + 1 < n)  &&  (v[filho + 1] > v[filho]))
              filho++;
          if (v[filho] > t) {
             v[pai] = v[filho];
             pai = filho;
             filho = pai * 2 + 1;
          } else {
             break;
          }
      }
      v[pai] = t;
   }
}


void processa_heapSort(long long int n){

	long long int i;
    int *v_crescente = malloc(n * sizeof(int));
    int *v_descrecente  = malloc(n * sizeof(int));
    int *v_aleatorio = malloc(n * sizeof(int));;

    for(i=0; i<n; i++){
        v_aleatorio[i] = rand()%100;
        v_crescente[i] = i;
    }

    for( ; i > 0; i--){
       v_descrecente[n - i] = i;
    }

    printf("HeapSort com vetor crescente:");
    srand(time(NULL));

    clock_t Ticks[2];

    Ticks[0] = clock();

    heapsort(n, v_crescente);

    Ticks[1] = clock();

    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("%g ms. \n", Tempo);


    printf("HeapSort com vetor descrecente:");
    srand(time(NULL));


    Ticks[0] = clock();

    heapsort(n, v_descrecente);

    Ticks[1] = clock();

    Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("%g ms. \n", Tempo);



    printf("HeapSort com vetor aleatorio:");
    srand(time(NULL));


    Ticks[0] = clock();

    heapsort(n, v_aleatorio);

    Ticks[1] = clock();

    Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("%g ms.", Tempo);


}
