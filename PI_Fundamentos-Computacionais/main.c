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
#include <ctype.h>


// Estrutura de um navio
struct Navio {
    char nome[50];
    int tamanho;
    int qtd;
    int direcao; /* 0 = horizontal, 1 = vertical*/
    int x; /* letra */
    int y; /* numero */
};

// Cria a grade com letras, numeros e #
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

// Transforma as coordenadas do tipo LetraNumero para X e Y (ex: A1 -> x=1 y=1, J10 -> x=10 y=10)
void tratar_coordenadas(char *coordenada, struct Navio *navio) {

    navio->x = toupper(coordenada[0]) - 64;

    if(strlen(coordenada) == 2) {
        navio->y = coordenada[1] - 48;
    } else {
        navio->y = 10;
    }
}

int main(int argc, char *argv[]) {


    // Verificar se o nome dos jogadores foi informado
    if(argc < 3) {
        printf("Informe o nome dos jogadores\nUso: ./main.c Jogador1 Jogador2\n");
        return 1;
    }

    // Frota jogador 1
    struct Navio frota_j1[5] = {
        {"Porta-Aviões", 5, 1, 0, 0, 0},
        {"Navio de Guerra", 4, 1, 0, 0, 0},
        {"Caravela", 3, 1, 0, 0, 0},
        {"Submarino", 3, 1, 0, 0, 0},
        {"Destróier", 2, 1, 0, 0, 0}
    };

    // Frota jogador 2
    struct Navio frota_j2[5] = {
        {"Porta-Aviões", 5, 1, 0, 0, 0},
        {"Navio de Guerra", 4, 1, 0, 0, 0},
        {"Caravela", 3, 1, 0, 0, 0},
        {"Submarino", 3, 1, 0, 0, 0},
        {"Destróier", 2, 1, 0, 0, 0}
    };

    // Cria a grade inicial
    criar_grade(10, 10);

    printf("\n");
    printf("%s posicione os seus navios\n\n", argv[1]);
    printf("Navio\t\tQtd\n");

    // Imprime a frota do jogador 1
    for(int i = 0; i < 5; i++) {
        printf("%s\t%d\n", frota_j1[i].nome, frota_j1[i].qtd);
    }

    printf("\n");

    // Expressão regular para verificar se o usuário digitou coordenadas válidas
    char *padrao_coordenada = "^[A-J]([1-9]|10)$";
    regex_t regex;
    regcomp(&regex, padrao_coordenada, REG_EXTENDED | REG_ICASE);

    // Loop para receber a direção e coordenadas de cada navio
    for(int i = 0; i < 5; i++) {

        // Recebe direção e valida se está correta
        do {
            printf("Direção do(a) %s (0 = Horizontal, 1 = Vertical): ", frota_j1[i].nome);
            scanf("%d", &frota_j1[i].direcao);
            while (getchar() != '\n' && getchar() != EOF);

            if(frota_j1[i].direcao > 1 || frota_j1[i].direcao < 0)
            {
                printf("***Direção incorreta. Informe 0 ou 1***\n");
            }

        } while (frota_j1[i].direcao > 1 || frota_j1[i].direcao < 0);    
        
        char coordenadas[5] = "";
        
        // Recebe coordenadas e valida se está correta
        do {
            printf("Coordenadas do(a) %s (ocupa %d espaços): ", frota_j1[i].nome, frota_j1[i].tamanho);
            scanf("%s", coordenadas);
            while (getchar() != '\n' && getchar() != EOF);
            
            if(regexec(&regex, coordenadas, 0, NULL, 0) == REG_NOMATCH) {
                printf("***Coordenada invalida. Forneça uma coordenada entre A1 e J10***\n");
            }

            // printf("Fora:\nx: %d\ny: %d\n", frota_j1[i].x, frota_j1[i].y);

        } while (regexec(&regex, coordenadas, 0, NULL, 0) == REG_NOMATCH);
        tratar_coordenadas(coordenadas, &frota_j1[i]);
        printf("\n\n");
    }
}
