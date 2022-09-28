#include <stdio.h>
#include <stdlib.h>
#include "ordenacao.h"


int main(int argc, char** argv) { 
  unsigned int n6 = 1000000;
  printf("Ordenacao com 10^6  %lld \n",n6);
  processa_bubbleSort(n6);
  printf("\n");
  processa_insertionSort(n6);
  printf("\n");
  processa_quickSort(n6);
  printf("\n");
  processa_heapSort(n6);
  printf("\n\n\n");
  
  
  int n5 = 100000;
  printf("Ordenacao com 10^5 \n");
  processa_bubbleSort(n5);
  printf("\n");
  processa_insertionSort(n5);
  printf("\n");
  processa_quickSort(n5);
  printf("\n");
  processa_heapSort(n5);
  printf("\n\n\n");
  
  int n4 = 10000;
  printf("Ordenacao com 10^4 \n");
  processa_bubbleSort(n4);
  printf("\n");
  processa_insertionSort(n4);
  printf("\n");
  processa_quickSort(n4);
  printf("\n");
  processa_heapSort(n4);
  printf("\n\n\n");
  
  
  int n3 = 1000;
  printf("Ordenacao com 10^3\n");
  processa_bubbleSort(n3);
  printf("\n");
  processa_insertionSort(n3);
  printf("\n");
  processa_quickSort(n3);
  printf("\n");
  processa_heapSort(n3);
  printf("\n");
  system("PAUSE");
}
