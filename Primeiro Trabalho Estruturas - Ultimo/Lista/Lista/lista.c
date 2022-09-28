#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include <locale.h>


struct lista  {
    int info;
    Lista *prox;

};

Lista* lst_cria() {

  return NULL;

}

int lst_vazia(Lista *l){
    return (l==NULL);
}

Lista* lst_insere(Lista *l, int info){
    Lista* ln = (Lista*)malloc(sizeof(Lista));
    ln->info = info;
    ln->prox = l;
    return ln;
}

Lista* lst_busca(Lista *l, int info){
    Lista* laux = l;
    while(laux!=NULL){
        if(laux->info == info){
            return laux;
        }
        laux = laux->prox;
    }
    return NULL;
}

void lst_imprime(Lista *l){
    Lista* laux = l;
    while(laux!=NULL){
        printf(" Info = %d  ",laux->info);
        laux = laux->prox;
    }
}

Lista* lst_remove(Lista *l, int info){
    if(l!=NULL){
        Lista* laux = l->prox;
        if(l->info == info){
            free(l);
            return laux;
        } else {
            Lista* lant = l;
            while(laux!=NULL){
                if(laux->info == info){
                    lant->prox = laux->prox;
                    free(laux);
                    break;
                } else {
                    lant = laux;
                    laux = laux->prox;
                }
            }
        }

    }
    return l;
}

void lst_libera(Lista *l){
    Lista* lprox;
    while(l!=NULL){
        lprox = l->prox;
        free(l);
        l = lprox;
    }
}

Lista* lst_insere_ordenado(Lista *l , int info){
    Lista *lnew = (Lista*)malloc(sizeof(Lista));
    lnew->info = info;
    if(l==NULL){
        lnew->prox = NULL;
        return lnew;
    } else if(l->info >= info){
        lnew->prox = l;
        return lnew;
    } else {
        Lista *lant = l;
        Lista *lprox = l->prox;
        while(lprox!=NULL && lprox->info < info){
            lant = lprox;
            lprox = lprox->prox;
        }
        lant->prox = lnew;
        lnew->prox = lprox;

        return l;
    }

}

//FUNCOES RECURSIVAS

void lst_imprime_rec(Lista *l){
    if(lst_vazia(l)){
        return;
    } else {
        printf(" info: %d  ",l->info);
        lst_imprime_rec(l->prox);
    }

}

void lst_imprime_invertida_rec(Lista *l){
    if(lst_vazia(l)){
        return;
    } else {
        lst_imprime_invertida_rec(l->prox);
        printf(" info: %d  ",l->info);

    }
}

Lista* lst_remove_rec(Lista *l, int info){
    if(!lst_vazia(l)){
        if(l->info == info){
            Lista* laux = l;
            l = l->prox;
            free(laux);
        } else {
            l->prox = lst_remove_rec(l->prox,info);
        }
    }
    return l;
}

void lst_libera_rec(Lista *l){
    if(!lst_vazia(l)){
        lst_libera_rec(l->prox);
        free(l);
    }
}

int lst_igual_rec(Lista *l1, Lista *l2){
    if(lst_vazia(l1) && lst_vazia(l2)){
        return 1;
    } else if (lst_vazia(l1) || lst_vazia(l2)){
        return 0;
    } else {
        return(l1->info == l2->info && lst_igual_rec(l1->prox,l2->prox));

    }
}

Lista* lst_inverte(Lista *l){
    if(lst_vazia(l)){
        return l;
    } else {
     Lista *laux1 = l;
     Lista* lnew = lst_cria();
    int a;
    while(laux1!=NULL){
        a = laux1->info;
        lnew= lst_insere(lnew,a);
        laux1 = laux1->prox;
    }
return lnew;
    }
}

//FUNCOES TRABALHO


// retorna os valores menores que n

int menores(Lista* l, int n){
    int cont=0;
    Lista* laux = l;
    if(lst_vazia(l)){

        return cont;

    } else {
        while(laux!=NULL){
            if(laux->info < n){
                cont++;
            }
        laux = laux->prox;


    }
    return cont;
}
}

// função soma

int soma(Lista* l){
    int soma=0;
    Lista* laux = l;
    if(lst_vazia(l)){

        return soma;

    }else{
        while(laux!=NULL){
            soma = soma + laux->info;
            laux = laux->prox;

        }
        return soma;
    }
}

//divisiveis positivos

int num_ndivp(Lista* l, int n){
    Lista* lAux = l;
    int i = 1;
    int total1=0;
    int total2=0;
    int resto;
    while(lAux!=NULL){
      for(i=1;i<=lAux->info;i++){
          resto=lAux->info%i;
          if(resto==0){
            total1++; 
          }
      }
      if(total1==n){
             total2=total2+1;
            }
      total1=0;
      lAux = lAux->prox;
    }
    return total2;
}

//concatena lista

Lista* lst_conc(Lista* l1,Lista* l2){

    Lista *laux1 = l1;
    Lista *laux2 = l2;
    Lista* lnew = lst_cria();// nova fila
    int a;
    if(lst_vazia(l1)|| lst_vazia(l2)){
        return l1;
    } else {
    while(laux1!=NULL){
        a = laux1->info;
        lnew= lst_insere(lnew,a);
        laux1 = laux1->prox;
    }

     while(laux2!=NULL){
            a = laux2->info;
            lnew = lst_insere(lnew,a);
            laux2 = laux2->prox;
    }

    lnew = lst_inverte(lnew); // colocando os valores invertidos"posições originais"
return lnew;
    }
}

// diferença entre duas lista(excluir de l1 elementos em comum com l2)

Lista* lst_diferenca(Lista* l1, Lista* l2){

   Lista* laux2 = l2;
   if(lst_vazia(l1)|| lst_vazia(l2)){
     return l1;
   } else {

   while(laux2!=NULL){
         Lista* laux1 = l1->prox;
         Lista* lant = l1;
      if(lant->info == laux2->info) // teste caso os primeiros elementos sejam iguais
        {
            l1 = lant->prox;
            free(lant);
            lant = l1; // atualiza o valor de lant e laux para prosseguir o código
            laux1 = l1->prox;

        }
     while(laux1!=NULL){
         if(laux1->info == laux2->info){
             lant->prox= laux1->prox;
             free(laux1);
             laux1= lant->prox;
           } else {
            laux1 = laux1->prox;
            lant = lant->prox;
        }
    }
  laux2 = laux2->prox;
   }
return l1;
   }
}





















