#include <stdio.h>

#define NUM_CASAS 4

// Define se no final deve-se contar a volta para a pizzaria ou não
#define VOLTAR_PARA_PIZZARIA 1

int distancias[NUM_CASAS * NUM_CASAS] = { -1, 12,   3,   5,
                                          12, -1,  11,  15, 
                                          3,  11,  -1,   5,  
                                          5,  15,   5,  -1,};
// Rotas esperadas:
// 1 => 4 => 3 => 5 => 2 => 1
// 1 => 4 => 3 => 2 => 5 => 1
//      3 +  17 + 12 + 6 + 11 = 49
//      3 +  17 + 12 + 6      = 38

// Essa função roda 1 vez para cada linha
// A linha que a função vai rodar fica na var linhaAtual
void printf_recursivo(int n_casas, int rota[]) {
  /* Essa função roda 1 vez para cada linha
   * ------------------
   * Argumentos:
   * n_casas: Define a quantidade de vezes que a função vai rodar. é o valor
   * máximo de linhaAtual rota[]: é um vetor com as rotas
   */

  // Uma variável static mantém o valor que já tava quando a função é chamada de
  // novo Sendo assim, podemos chamar a função várias vezes passando esse valor
  static int linhaAtual = 0;
  static int utilizados[NUM_CASAS];
  int escolhidas = 0; // Caso de parada: escolhidas = num_casas - 1
  int soma = 0;       // Soma final de todas as casas

  // Por padrão a primeira casa[0] é ignorada(já que ela é a pizzaria)
  int menor = 1; // Casa com menor distância

  // Descobre qual a próxima casa procurando o menor valor(que não seja -1)
  for (int i = 1; i < n_casas; i++) {

    // Caso especial: O menor == 1 e o valor dele é -1. Nesse caso, menor = 2
    if (menor == 1 && rota[n_casas * linhaAtual + menor] < 0) {
      menor++;
    }

    // Descobre a casa com menor distância entre todas
    if (utilizados[i] == 0 && rota[n_casas * linhaAtual + i] > 0) {
      if (rota[n_casas * linhaAtual + i] < rota[n_casas * linhaAtual + menor]) {
        menor = i;
      }
    }
  }

  // Grava qual a casa escolhida e bota ela para ser procurada
  utilizados[linhaAtual] = menor;
  linhaAtual = menor;

  // Caso de parada: Quando todas as casas forem passadas(n_casas -1)
  for (int i = 0; i < n_casas; i++) {
    if (utilizados[i] != 0) {
      escolhidas++;
    }
  }

  if (escolhidas == n_casas - 1) {
    // Última casa == -1
    utilizados[linhaAtual] = -1;

    /* Anda na rota toda até encontrar um "-1"
     * Explicação desse for:
     * Este laço vai pulando de casa em casa procurando a próxima (i =
     * utilizados[i]) Quando a última casa for encontrada ele para(utilizados[i]
     * != -1) 2 for são necessários para imprimir a rota e a soma
     */

    // Imprime a rota escolhida
    printf("Rota escolhida: 1,");
    for (int i = 0; utilizados[i] != -1; i = utilizados[i]) {

      /* Verifica se o próximo pulo já é o último
       * Serve só para retirar a "," no final. Pode ser substituído por
       * printf("%d,", utilizados[i]+1);
       * se você não liga para a "," no final
       */
      if (utilizados[utilizados[i]] != -1) {
        printf("%d,", utilizados[i] + 1);
      } else {
#if VOLTAR_PARA_PIZZARIA
        // Adiciona a volta pra pizzaria no final
        printf("%d,1\n", utilizados[i] + 1);
#else
        printf("%d\n", utilizados[i] + 1);
#endif
      }
    }

    // Imprime a soma
    printf("Soma:");
    for (int i = 0; utilizados[i] != -1; i = utilizados[i]) {

      if (utilizados[utilizados[i]] != -1) {
        printf("%d+", rota[n_casas * i + utilizados[i]]);
      } else {
#if VOLTAR_PARA_PIZZARIA
        // Imprime o valor das duas últimas rotas
        printf("%d+", rota[n_casas * i + utilizados[i]]);
        printf("%d", rota[n_casas * (n_casas - 1)]);

        // Adiciona a última rota na soma
        soma += rota[n_casas * (n_casas - 1)];
#else
        printf("%d", rota[n_casas * i + utilizados[i]]);
#endif
      }
      // Adiciona a rota atual na soma
      soma += rota[n_casas * i + utilizados[i]];
    }
    // Imprime a soma
    printf("=%d\n", soma);

    // Termina a recursão
    return;
  }

  // Repete a função na linha escolhida
  printf_recursivo(n_casas, rota);
}

int main(void) {
  printf_recursivo(NUM_CASAS, distancias);
  return 0;
}
