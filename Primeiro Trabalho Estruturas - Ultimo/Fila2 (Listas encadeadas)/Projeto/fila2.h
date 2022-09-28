typedef struct fila Fila;
typedef struct pilha Pilha;

Fila* fila_cria(void); // fun��o que cria uma fila

int fila_vazia(Fila *f); // testa se uma fila est� vazia

void fila_insere(Fila *f, int info); // insere um elemento em uma fila

int fila_remove(Fila *f); // fun��o que remove um elemento da fila

void fila_imprime(Fila *f); // imprime na tela os elkementos da fila

void fila_libera(Fila *f);// libera espa�o alocado por uma fila

void fila_insere_inver(Fila* f, int info); // insere um elemento em uma fila

int pilha_pop(Pilha *p1); // remove um elemento do topo da pilha

int pilha_vazia(Pilha *p); // testa se uma pilha � vazia

void pilha_push(Pilha *p , int info); // adiciona um elemento ao topo de uma pilha

Pilha* pilha_cria(void); // fun��o que cria uma pilha

//FUN��ES TRABALHO

int qtd_primos(Fila* f); //retorna o n�mero de elementos da fila com valor primo

Fila* inverte_fila(Fila* f); // fun�ao que inverte uma fila;


