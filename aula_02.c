#include <stdio.h>
#include <malloc.h>

#define alturaMaxima 255

typedef struct {
  int peso;
  int altura;
} PesoAltura;

int main() {
  PesoAltura* pessoa = (PesoAltura*) malloc(sizeof(PesoAltura));
  pessoa->peso = 80;
  pessoa->altura = 185;

  printf("Peso %i, Altura %i\n", pessoa->peso, pessoa->altura);

  if (pessoa->altura > alturaMaxima) printf("Altura acima da maxima.\n");
  else printf("Altura abaixo da maxima\n");
  return 0;
}
