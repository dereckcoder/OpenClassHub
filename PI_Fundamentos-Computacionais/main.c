/*
Batalha Naval
Cada jogador tem duas grades, uma para esconder seus próprios navios, outra para atirar nos navios do oponente.
A grade tem o tamanho 10x10, as linhas são identificadas por numeros (1-10) e as colunas por letras (A-J)
Antes do jogo começar, os jogadores posicionam seus navios na grade

Regras:
Os navios só podem ser colocados na horizontal ou vertical

Como jogar:
Os jogadores revezam dando tiros escolhendo uma coordenada na grade (uma letra e um numero, ex: "C5")
O oponente verifica sua grade e responde de acordo com o resultado
    Água: O tiro não acertou e é marcado um "X" na grade
    Fogo: O tiro acertou o pedaço de um navio e é marcado com outro simbolo
    Afundou: O tiro acertou o ultimo pedaço restante de um navio inteiro
O turno passa para o proximo jogador independente de ter acertado ou não

Navios:
Existe uma frota padrão e cada navio ocupa um numero exato de espaços na grade. 
Essa frota é composta por 5 navios:
    1 porta-aviões: ocupa 5 espaços
    1 navio de guerra: ocupa 4 espaços
    1 fragata: ocupa 3 espaços
    1 submarino: ocupa 3 espaços
    1 destroier: ocupa 2 espaços

Uma vez posicionado, não pode mudar. Não pode sobrepor outro navio, pode ou não ter um espaço entre um navio e outro (opcional)
*/

#include <stdio.h>
#include <stdbool.h>
#include <regex.h>
#include <string.h>

// Estrutura de um navio
struct Navio {
    char nome[50];
    int tamanho;
    int qtd;
    int direcao; /* 0 = horizontal, 1 = vertical*/
    char coordenada[5];
};

void criar_grade(int linha, int coluna) {
    printf("     ");
    for(int i = 0; i < coluna; i++) {
        printf("%c ", 65 + i);
    }
    
    printf("\n");
    for (int i = 0; i < linha; i++){
        printf("%02d - ", i + 1);
        for (int j = 0; j < coluna; j++) {
            printf("# ");
        }
        printf("\n");
    }
}

int main(int argc, char *argv) {


    // Verificar se o nome dos jogadores foi informado
    // if(argc < 2) {
    //     printf("Informe o nome dos jogadores\nUso: ./main.c Jogador1 Jogador2\n");
    //     return 1;
    // }

    // Frota jogador 1
    struct Navio frota_j1[5] = {
        {"Porta-Aviões", 5, 1, false, "0"},
        {"Navio de Guerra", 4, 1, false, "0"},
        {"Caravela", 3, 1, false, "0"},
        {"Submarino", 3, 1, false, "0"},
        {"Destróier", 2, 1, false, "0"}
    };

    // Frota jogador 2
    struct Navio frota_j2[5] = {
        {"Porta-Aviões", 5, 1, false, "0"},
        {"Navio de Guerra", 4, 1, false, "0"},
        {"Caravela", 3, 1, false, "0"},
        {"Submarino", 3, 1, false, "0"},
        {"Destróier", 2, 1, false, "0"}
    };

    criar_grade(10, 10);

    printf("\n");
    printf("Jogador 1 posicione os navios\n\n");
    printf("Navio\t\tQtd\n");

    for(int i = 0; i < 5; i++) {
        printf("%s\t%d\n", frota_j1[i].nome, frota_j1[i].qtd);
    }

    printf("\n");

    char *padrao_coordenada = "^[A-J]([1-9]|10)$";
    regex_t regex;
    regcomp(&regex, padrao_coordenada, REG_EXTENDED | REG_ICASE);

    int num_navios = 5;
    for(int i = 0; i < 5; i++) {

        do {
        printf("Direção do %s (0 = Horizontal, 1 = Vertical): ", frota_j1[i].nome);
        scanf("%d", &frota_j1[i].direcao);
        int c;
        while ((c - getchar() != '\n' && c- EOF))

        printf("Coordenada do %s (ocupa %d espaços): ", frota_j1[i].nome, frota_j1[i].tamanho);
        fgets(frota_j1[i].coordenada, sizeof(frota_j1[i].coordenada), stdin);
        frota_j1[i].coordenada[strcspn(frota_j1[i].coordenada, "\n")] = '\0';

        if(regexec(&regex, frota_j1[i].coordenada, 0, NULL, 0) == REG_NOMATCH) {
            printf("Coordenada invalida. Forneça uma coordenada entre A1 e J10\n");
        }
        
        printf("\n");

        } while(regexec(&regex, frota_j1[i].coordenada, 0, NULL, 0) == 1);
    }
}




