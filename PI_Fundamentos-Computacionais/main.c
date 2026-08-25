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

Uma vez posicionado, não pode mudar. Não pode sobrepor outro navio, pode ou não ter um espaço entre um navio e outro
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

struct Coordenada {
    int x;
    int y;
};


// Verifica se coordenada está no padrao LetraNumero
bool validar_coordenada(char *coordenadas) {
    // Expressão regular para verificar se o usuário digitou coordenadas válidas
    char *padrao_coordenada = "^[A-J]([1-9]|10)$";
    regex_t regex;
    regcomp(&regex, padrao_coordenada, REG_EXTENDED | REG_ICASE);

    if(regexec(&regex, coordenadas, 0, NULL, 0) == REG_NOMATCH) {
        regfree(&regex);
        return false;
    } else {
        regfree(&regex);
        return true;
    }

}

// Cria a grade com letras, numeros e #
void criar_grade(int x, int y, struct Coordenada grade[x][y]) {
    printf("     ");
    for(int i = 0; i < x; i++) {
        printf("%c ", 65 + i);
    }
    
    printf("\n");
    for (int i = 0; i < y; i++){
        printf("%02d - ", i + 1);
        for (int j = 0; j < x; j++) {
            printf("~ ");
            grade[i][j].x = j + 1;
            grade[i][j].y = i + 1;
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

// Função para receber 
void receber_direcao_e_coordenadas_dos_navios(struct Navio navio[], char *jogador) {

    printf("\n%s posicione os seus navios\n\n", jogador);
    printf("Navio\t\tQtd\n");

    // Imprime a frota do jogador
    for(int i = 0; i < 5; i++) {
        printf("%s\t%d\n", navio[i].nome, navio[i].qtd);
    }

    printf("\n");

    // Loop para receber a direção e coordenadas de cada navio
    for(int i = 0; i < 5; i++) {

        // Recebe direção e valida se está correta
        do {
            printf("Direção do(a) %s (0 = Horizontal, 1 = Vertical): ", navio[i].nome);
            scanf("%d", &navio[i].direcao);
            int c;
            while ((c = getchar()) != '\n' && c != EOF);

            if(navio[i].direcao > 1 || navio[i].direcao < 0)
            {
                printf("***Direção incorreta. Informe 0 ou 1***\n");
            }

        } while (navio[i].direcao > 1 || navio[i].direcao < 0);    
        
        char coordenadas[5] = "";
        
        // Recebe coordenadas e valida se está correta
        do {
            printf("Coordenadas do(a) %s (ocupa %d espaços): ", navio[i].nome, navio[i].tamanho);
            scanf("%s", coordenadas);
            int c;
            while ((c = getchar()) != '\n' && c != EOF);                

            bool coordenada_valida = validar_coordenada(coordenadas);

            if(coordenada_valida == false) {
                printf("***Coordenada invalida. Forneça uma coordenada entre A1 e J10***\n");
            }

            // printf("Fora:\nx: %d\ny: %d\n", navio[i].x, navio[i]->y);

        } while (validar_coordenada(coordenadas) == false);
        tratar_coordenadas(coordenadas, &navio[i]);
        printf("\n\n");
    }
}

void limpar_tela() {
    printf("\e[1J\e[H"); 
}

//TO-DO: Função para validar se é possivel posicionar o navio na coordenada escolhida (se está dentro da grade ou se está encima de outro navio)


//TO-DO: Função para disparar os tiros


//TO-DO: Função para verificar se acertou ou não um navio ou se o jogador tentou atirar em algum lugar onde já existe um tiro


//TO-DO: Função para atualizar a grade para posicionar os navios e tiros


//TO-DO: Função para definir o ganhador


int main(int argc, char *argv[]) {


    // Verificar se o nome dos jogadores foi informado
    if(argc < 3) {
        printf("Informe o nome dos jogadores\nUso: ./main.c Jogador1 Jogador2\n");
        return 1;
    }

    int tamanho_grade = 10;

    char *j1 = argv[1];
    char *j2 = argv[2];

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

    // Inicializa frota do jogador 1
    struct Coordenada grade_j1[tamanho_grade][tamanho_grade];
    criar_grade(tamanho_grade, tamanho_grade, grade_j1);
    receber_direcao_e_coordenadas_dos_navios(frota_j1, j1);
    
    limpar_tela();

    // Inicializa frota do jogador 2
    struct Coordenada grade_j2[tamanho_grade][tamanho_grade];
    criar_grade(tamanho_grade, tamanho_grade, grade_j2);
    receber_direcao_e_coordenadas_dos_navios(frota_j2, j2);

}  