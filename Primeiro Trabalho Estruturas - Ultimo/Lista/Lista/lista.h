typedef struct lista Lista;


// cria lista vazia
Lista* lst_cria(); 

// testa se uma lista � vazia
int lst_vazia(Lista *l); 

// insere valores no inicio da lista
Lista* lst_insere(Lista *l, int info); 

// busca elementos na lista
Lista* lst_busca(Lista *l, int info); 

// imprime uma lista
void lst_imprime(Lista *l); 

// remove um elemento da lista
Lista* lst_remove(Lista *l, int info); 

// libera o espa�o alocado por uima lista
void lst_libera(Lista *l); 

// insere valores ordenadamente, para isso a lista deve est� ordenada
Lista* lst_insere_ordenado(Lista *l, int info);

//FUNCOES RECURSIVAS

// imprime uma lista recursivamente
void lst_imprime_rec(Lista *l); 

// imprime uma lista invertida recursivamente
void lst_imprime_invertida_rec(Lista *l); 

// remove n� da lista recursivamente
Lista* lst_remove_rec(Lista *l, int info); 

// libera espa�o de uma lista recursivamente
void lst_libera_rec(Lista *l);  

// verifica de duas lista s�o iguais
int lst_igual_rec(Lista *l1,Lista *l2); 

// inverte uma fila
Lista* lst_inverte(Lista *l); 

//FUN��ES ACRESCENTADAS TRABALHO


// retorna a quantidade de valores menores que n
int menores(Lista* l, int n); 

// calcula a soma de todos os campos info da lista;
int soma(Lista* l); 

// retorna numero de n�s com o campo n divisores positivos
int num_ndivp(Lista* l, int n); 

// concatena duas listas
Lista* lst_conc(Lista* l1, Lista* l2); 

// tira os elementos comuns entre duas lista
Lista* lst_diferenca(Lista* l1, Lista* l2); 

