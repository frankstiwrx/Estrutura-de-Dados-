typedef struct fila Fila;
typedef struct pilha Pilha;

Fila* fila_cria(void); // função que cria uma fila

int fila_vazia(Fila *f); // testa se uma fila está vazia

void fila_insere(Fila *f, int info); // insere um elemento em uma fila

int fila_remove(Fila *f); // função que remove um elemento da fila

void fila_imprime(Fila *f); // imprime na tela os elkementos da fila

void fila_libera(Fila *f);// libera espaço alocado por uma fila

void fila_insere_inver(Fila* f, int info); // insere um elemento em uma fila

int pilha_pop(Pilha *p1); // remove um elemento do topo da pilha

int pilha_vazia(Pilha *p); // testa se uma pilha é vazia

void pilha_push(Pilha *p , int info); // adiciona um elemento ao topo de uma pilha

Pilha* pilha_cria(void); // função que cria uma pilha

//FUNÇÕES TRABALHO

int qtd_primos(Fila* f); //retorna o número de elementos da fila com valor primo

Fila* inverte_fila(Fila* f); // funçao que inverte uma fila;


