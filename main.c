#include <stdio.h>

#define alturaMaxima 255

typedef struct {
  int peso;
  int altura;
} PesoAltura;

int main() {
  PesoAltura pessoa;
  pessoa.peso = 80;
  pessoa.altura = 185;

  printf("Peso %i, Altura %i\n", pessoa.peso, pessoa.altura);
  return 0;
}
