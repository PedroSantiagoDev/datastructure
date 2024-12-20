#include <stdio.h>
#include <stdbool.h>

#define MAX 50

typedef int TIPOCHAVE;

typedef struct {
  TIPOCHAVE chave;
} REGISTRO;

typedef struct {
  REGISTRO A[MAX];
  int nroElem;
} LISTA;

void inicializarLista(LISTA* l) {
  l->nroElem = 0;
}

int tamanho(LISTA* l) {
  return l->nroElem;
}

void exibirLista(LISTA* l) {
  int i;
  printf("Lista: \" ");
  for (i = 0; i < l->nroElem; i++) printf("%i ", l->A[i].chave);
  printf("\"\n");
}

int buscaSequencial(LISTA* l, TIPOCHAVE ch) {
  int i = 0;
  while (i < l->nroElem) {
    if (ch == l->A[i].chave) return i;
    else i++;
  }
  return -1;
}

bool inserirElemLista(LISTA* l, REGISTRO reg, int i) {
  int j;
  if ((l->nroElem == MAX) || (i < 0) || (i > l->nroElem)) 
    return false;
  for (j = l->nroElem; j > i; j--) l->A[j] = l->A[j - 1];
  l->A[i] = reg;
  l->nroElem++;
  return true;
}

bool excluirElemLista(TIPOCHAVE ch, LISTA* l) {
  int pos, j;
  pos = buscaSequencial(l, ch);
  if (pos == -1) return false;
  for (j = pos; j < l->nroElem - 1; j++) 
    l->A[j] = l->A[j + 1];
  l->nroElem--;
  return true;
}

void reiniciaLizarLista(LISTA* l) {
  l->nroElem = 0;
}

int main() {
  LISTA lista;
  inicializarLista(&lista);

  printf("Tamanho inicial da lista: %i\n", tamanho(&lista));

  REGISTRO reg1 = {10};
  REGISTRO reg2 = {20};
  inserirElemLista(&lista, reg1, 0);
  inserirElemLista(&lista, reg2, 1);

  exibirLista(&lista);

  int pos = buscaSequencial(&lista, 20);
  printf("Posição do elemento 20: %i\n", pos);

  if (excluirElemLista(10, &lista)) printf("Elemento 10 excluído com sucesso.\n");
  else printf("Elemento 10 não encontrado.\n");

  exibirLista(&lista);

  reiniciaLizarLista(&lista);
  printf("Tamanho após reinicializar: %i\n", tamanho(&lista));

  return 0;
}