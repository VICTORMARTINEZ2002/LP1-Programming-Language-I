#include <stdio.h>

// Descobrir quem conecta com + pontos
// Retirar os pontos utilizados da lista
// Se sobrar somente 1, ele é botado na lista de escolhidos
// Se sobrar + de 1, procurar o que tem + pontos conectados no total e botar ele na lista de escolhidos

#define TAMANHO 6

int M[TAMANHO][TAMANHO] = { {0, 1, 0, 1, 1, 1},  // 0 conecta com 1
                            {1, 0, 1, 0, 0, 0},  // 1 conecta com 0 e 2
                            {0, 1, 0, 1, 1, 1},  // 2 conecta com 1, 3, 4 e 5 
                            {1, 0, 1, 0, 0, 0},  // 3 conecta com 2 
                            {1, 0, 1, 0, 0, 0},  // 4 conecta com 2
                            {1, 0, 1, 0, 0, 0}}; // 5 conecta com 2


int printf_recursivo(int n_pontos, int pontos[]) {
    static int utilizados[TAMANHO];
    static int quantidade[TAMANHO], iter = 0;
    static int selecionados[TAMANHO], disponiveis = -1;
    int soma, maior;

    // Verifica quantos números estão disponíveis
    if (disponiveis == 1) {
        maior = 0;
        for (int i = 0; i < n_pontos; i++) {
            if (utilizados[i] == 0) {
                maior = i;
            }
        }
        selecionados[iter] = maior;

        // Imprime no final bonitinho
        printf("Para monitorar todos os pontos, deve-se utilizar %d câmeras, nos pontos ", iter+1);
        if (iter > 0) {
            for (int i = 0; i < iter-1; i++) {
                printf("%d,", selecionados[i]);
            }
            printf("%d e %d", selecionados[iter-1], selecionados[iter]);
        } else {
            printf("%d", selecionados[0]);
        }
        return 0;
    }
    
    // Procura a quantidade de vezes que cada um é chamado
    if (disponiveis == -1) {
        disponiveis = n_pontos;
        // Zera o vetor de utilizados
        for (int i = 0; i < n_pontos; i++) {
            soma = 0;
            for (int j = 0; j < n_pontos; j++) {
                soma += pontos[i * n_pontos + j];
            }
            quantidade[i] = soma;
            utilizados[i] = 0;
            selecionados[i] = -1; // -1 = ninguém selecionado
        }

    } 

    // Pega o não utilizado mais chamado
    maior = 0;
    for (int i = 0; i < n_pontos; i++) {
        if (utilizados[i] == 0 && quantidade[i] > quantidade[maior]) {
            maior = i;
        }
    }

    // Inutiliza todos os conectados a ele
    for (int j = 0; j < n_pontos; j++) {
        if (pontos[maior * n_pontos + j] && utilizados[j] == 0) {
            utilizados[j] = 1;
            disponiveis--;
        }
    }
    // Inutiliza ele no final
    utilizados[maior] = 1;
    disponiveis--;
    selecionados[iter] = maior;
    iter++;

    return printf_recursivo(n_pontos, pontos);
}

int main() {
    printf_recursivo(TAMANHO, *M); // ignorar tipo de ponteiro incompatível 
    return 0;
}