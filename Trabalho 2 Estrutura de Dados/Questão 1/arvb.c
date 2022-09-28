
#include<stdlib.h>
#include<stdio.h>
#include "arvb.h"




ArvB* arvb_cria_vazia(void){
 return NULL;
}


ArvB* arv_cria_no(char c, ArvB *sae, ArvB *sad){
 ArvB* a = (ArvB*) malloc( sizeof(ArvB) );
 a->info = c;
 a->esq = sae;
 a->dir = sad;
 return a;

}

int arvb_vazia(ArvB *a){ 

 return a==NULL;
}

void arvb_imprime(ArvB *a){
 if(!arvb_vazia(a)){
 printf("%c ",a->info);
 arvb_imprime(a->esq);
 arvb_imprime(a->dir);
 }
}

int arvb_pertence(ArvB *a,char c){
 if(arvb_vazia(a))
 return 0;
 else
return a->info ==c || arvb_pertence(a->esq,c)
 || arvb_pertence(a->dir,c);
}

void arvb_libera(ArvB *a){
 if(!arvb_vazia(a)){
 arvb_libera(a->esq);
 arvb_libera(a->dir);
 free(a);
 }
}

int arvb_altura(ArvB *a){
 if(arvb_vazia(a))
 return 0; // Apenas para fins deste trabalho. 
 else{
int hSAE = arvb_altura(a->esq);
int hSAD = arvb_altura(a->dir);
 if(hSAE > hSAD)
 return 1+hSAE;
 else
 return 1+hSAD;
 }
}

ArvB* arvb_busca(ArvB *a, int c){
 if(arvb_vazia(a))
return NULL;
 else if(a->info < c)
return arvb_busca(a->dir,c);
 else if(a->info > c)
return arvb_busca(a->esq,c);
 else //(a->info == c)
return a;
} 

ArvB* arvb_insere(ArvB *a, char c){
 if(arvb_vazia(a)){ 
     a = (ArvB*)malloc(sizeof(ArvB));
	 a->info = c;
	 a->esq = NULL;
	 a->dir = NULL; 
	}else if(a->info > c){
	 	a->esq = arvb_insere(a->esq,c);
	 }
	 else if (a->info < c){
	   a->dir = arvb_insere(a->dir,c);
	 }
	 else{
	 	printf("\nElemento Ja Pertence a Arvore");
	 }
    
    	
	 return a;
}

ArvB*  arvb_remove(ArvB *a, char c){ 
 if(!arvb_vazia(a)){
    if(a->info > c)
      a->esq = arvb_remove(a->esq,c);
    else if (a->info < c)
      a->dir = arvb_remove(a->dir,c);
 	else{
 	  ArvB* t;
 	if (a->esq == NULL){
 		t = a; a = a->dir;
 		free(t);
   }else if (a->dir == NULL){
 		t = a; a = a->esq;
 		free(t);
 	}else{
 		t = a->esq;
 		while(t->dir!=NULL)
		 t = t->dir;
 		 a->info = t->info; t->info = c;
 		 a->esq = arvb_remove(a->esq,c);
 	}
  }
}
return a; 
   	
}
int numero_primo(int numero){ 
 int i; 
 int div = 0;
 for (i = 1; i <= numero; i++) {
    if (numero % i == 0) { 
     div++;
    }
  }
  return div == 2;
}

int folhas_primo(ArvB* a){ 
  if(a == NULL){
  	 return 0;
  }
  
  return folhas_primo(a->dir) + folhas_primo(a->esq) +  numero_primo(a->info);
}

int subarvs_difnull(ArvB* a){
   if(a == NULL){
     return 0;
   } 	
   int qtd_difnull = 0;
   
   qtd_difnull = (a->esq != NULL) + (a->dir != NULL);
    
   return qtd_difnull +  subarvs_difnull(a->dir) +  subarvs_difnull(a->esq);
}

int subarvs_ig_alt(ArvB* a){
	if(a == NULL){
		return 0; // Se a arvore é inexistente logo sua altura é zero; 
	}
	int ig_alt = arvb_altura(a->dir) == arvb_altura(a->esq);
	return ig_alt + subarvs_ig_alt(a->dir) + subarvs_ig_alt(a->esq);
}

void impressao_arv_nivel(ArvB* a, int nivel, int nivel_atual){
    
    if(a != NULL){
      if(nivel_atual == nivel){
        printf("%i ",a->info);
	  
	  }else{ 
   	   nivel_atual++;
   	   impressao_arv_nivel(a->esq,nivel,nivel_atual);
	   impressao_arv_nivel(a->dir,nivel,nivel_atual);
	   
	 }	
	}
	 
}

void impressao_arv_niveis(ArvB* a){
   int alt_arv =  arvb_altura(a); 
  
   int x;
   for(x = 0; x < alt_arv; x++){ 
     impressao_arv_nivel(a,x,0);
     printf("- nivel %i\n",x);
   }
   
}

