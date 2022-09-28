typedef struct arvb ArvB;

struct arvb{
  char info;
  ArvB *esq;
  ArvB *dir;
};



ArvB*  arvb_cria_vazia(void); 
ArvB*  arvb_cria_no(char c, ArvB *sae, ArvB *sad);
int    arvb_vazia(ArvB *a);
void   arvb_imprime(ArvB *a);
int    arvb_pertence(ArvB *a,char c);
void   arvb_libera(ArvB *a);
int    arvb_altura(ArvB *a);
ArvB*  arvb_busca(ArvB *a, char c);
ArvB*  arvb_insere(ArvB *a, char c);
ArvB*  arvb_remove(ArvB *a, char c);


int folhas_primo(ArvB* a);
int subarvs_difnull(ArvB* a);
int subarvs_ig_alt(ArvB* a);
void impressao_arv_niveis(ArvB* a);
