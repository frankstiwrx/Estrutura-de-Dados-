typedef struct pilha Pilha;
typedef struct lista Lista;

//PILHAS

Pilha* pilha_cria(); // funçõa que cria uma  pilha

int pilha_vazia(Pilha *p); // testa se uma pilha é vazia

void pilha_push(Pilha *p, int info); // função que adiciona um elemento ao topo de uma pilha;

int pilha_pop(Pilha *p); // função que remove um elemento do topo da pilha

void pilha_imprime(Pilha *p); // imprime os elementos de uma pilha

void pilha_libera(Pilha *p); // libera o espaço alocado por uma pilha;

//TRABALHO

Pilha* empilha_elem_comuns(Lista* l1, Lista* l2); // verifica os elementos em comum e emplilha os mesmos em uma nova lista em ordem crescente
 
Pilha* inverte_pilha(Pilha* p); // inverte os elementos de uma pilha
