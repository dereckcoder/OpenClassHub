#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char matricula_aluno[999][50]; // vetor matricula
    char nome_alunos[999][50]; // vetor name aluno
    float notas_alunos[999][4]; // matriz notas 
    
    // variaveis de apoio
    int opcao = 0;
    int contador_nota = 0;
    int TOTAL_ALUNOS = 0;
    int i,j;
    
    float somador_de_notas = 0;
    float resultado = 0;

    while (1){
        //você pode usar sequências de escape ANSI - > limpa tela
        printf("\033[H\033[J"); 

        printf("\n------- MENU SISTEMA -------\n");
        printf("1. Cadastrar Aluno\n");
        printf("2. Ranking\n");
        printf("3. Visualizar Alunos no banco Dados\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);      
        
        // opcao 4 break -> encerra o programa 
        if (opcao == 4){
            printf("----- SISTEMA ENCERRADO É HORA DA PIZZA! ------\n"
            "░░░░░░░░░░░░░░░░░░░░░░░░░░░░▄▄▄░░░░░░░░░\n"
            "░░░░░░░░░░░░░░▄▄▄▄▄▄▄▄░░░░░░█████▄░░░░░░\n"
            "░░░░░░░░░▄▄█████████████▀░░▄░░▀████▄░░░░\n"
            "░░░░░░▄▄███▀▀░░▄▄▄▄▄▄░░▀░░████▄░▀████░░░\n"
            "░░░░▄███▀░▄▄██████▀▀███░░▄█▀▀░▀▀▄░▀███▄░\n"
            "░░░▄██▀░▄███▀▀▀███▄▄██░░▄██░░░░░█▄░▀███░\n"
            "░░███░▄██████████████▀░░███▄░░░▄██▄░████\n"
            "░███░▄████░█████░▀██▀░░█████████▀▀▀░░░░░\n"
            "▄██░░██████▀▀███████░░▀▀▀▀▀░░░░░░░░░░░░░\n"
            "███░██████░░░░█████░░░░░░░░░▄▄▄▄░░██░░░░\n"
            "██░░██████▄░░▄█████▄▄▄█████▀▀███░░██░░░░\n"
            "███░███▄░▀█████▀▀███████████████░░██░░░░\n"
            "███░▀██████▀████▄▄█████▄▄███▀███░▄██░░░░\n"
            "░██▄░██████▄▄██████▀▀▀█████▄▄██░░██▀░░░░\n"
            "░▀██▄░▀█▀▀████████░░░░░███████░░██▀░░░░░\n"
            "░░▀██▄░▀███████████▄░▄▄█████▀░▄██▀░░░░░░\n"
            "░░░░▀██▄░░▀███▄▄▄████████▀▀░▄███▀░░░░░░░\n"
            "░░░░░░▀███▄░░▀▀▀▀▀▀▀▀▀▀░░▄▄███▀░░░░░░░░░\n"
            "░░░░░░░░▀▀████▄▄▄▄▄▄▄▄█████▀░░░░░░░░░░░░\n"
            "░░░░░░░░░░░░░▀▀▀▀▀▀▀▀▀▀░░░░░░░░░░░░░░░░░\n"
            "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n"
            "░░░░░░░█████████████████████████░░░░░░░░\n"
            "░░░░░░░█────█───█────█────█────█░░░░░░░░\n"
            "░░░░░░░█─██─██─████──███──█─██─█░░░░░░░░\n"
            "░░░░░░░█────██─███──███──██────█░░░░░░░░\n"
            "░░░░░░░█─█████─██──███──███─██─█░░░░░░░░\n"
            "░░░░░░░█─████───█────█────█─██─█░░░░░░░░\n"
            "░░░░░░░█████████████████████████░░░░░░░░\n"
            "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
            break;
        }if (opcao == 1){
            // matriz lista_alunos
            for (i = 0; i < 999; i++){
                
                printf("\033[H\033[J");

                printf("---------------Cadastro---------------\n");
                printf("Cadastro do aluno nome: ");
                scanf("%s", nome_alunos[i]);

                printf("Cadastro do ID: ");
                scanf("%s", matricula_aluno[i]);
    
                printf("\n---------------Registro NOTAS---------------\n");
                contador_nota = 1;
                
                for (j = 0; j < 3; j++){
    
                    printf("NOTA (%d): ",contador_nota);

                    scanf("%f",&notas_alunos[i][j]); // i -> guarda o primeiro aluno j -> VAI ANDANDO 0,1,2
    
                    somador_de_notas += notas_alunos[i][j];
                    ++contador_nota;    
                }
                notas_alunos[i][3] = somador_de_notas / 3;
                somador_de_notas = 0;              
                ++TOTAL_ALUNOS;// contador
    
                printf("Cadastrar outro aluno? [1] Sim | [0] Voltar: ");
                scanf("%d", &opcao);
                
                if(opcao == 0){
                break;
                }//if -> break o registro notas
            }//loop
        }else if(opcao == 2){
            // ------------------ ESTATÍSTICAS / RANKING ------------------
            printf("\033[H\033[J");

            printf("\n=== RANKING DE ALUNOS (MAIOR PARA MENOR MÉDIA) ===\n");

            if(TOTAL_ALUNOS == 0){
                printf("Nao ha alunos cadastrados ainda!\n");
            }else{
            // Criamos vetores temporários para ordenar sem mexer na ordem original do banco
                char temp_nomes[999][50];
                char temp_matricula[999][50];
                float temp_medias[999];

                // Copia os dados atuais para as variaveis temporarias
                for (i = 0; i < TOTAL_ALUNOS; i++) {
                    strcpy(temp_nomes[i], nome_alunos[i]);
                    strcpy(temp_matricula[i], matricula_aluno[i]);
                    temp_medias[i] = notas_alunos[i][3];
                }//loop

                // Algoritmo Bubble Sort para ordenar do maior para o menor
                for (i = 0; i < TOTAL_ALUNOS - 1; i++) {
                    for (j = 0; j < TOTAL_ALUNOS - i - 1; j++) {
                        if (temp_medias[j] < temp_medias[j + 1]) {
                            // Troca as medias
                            float aux_media = temp_medias[j];
                            temp_medias[j] = temp_medias[j + 1];
                            temp_medias[j + 1] = aux_media;

                            // Troca os nomes correspondentes
                            char aux_nome[50];
                            strcpy(aux_nome, temp_nomes[j]);
                            strcpy(temp_nomes[j], temp_nomes[j + 1]);
                            strcpy(temp_nomes[j + 1], aux_nome);

                            // Troca as matrículas correspondentes
                            char aux_mat[50];
                            strcpy(aux_mat, temp_matricula[j]);
                            strcpy(temp_matricula[j], temp_matricula[j + 1]);
                            strcpy(temp_matricula[j + 1], aux_mat);
                        }//if
                    }//loop
                }//loop
                // Exibe o Ranking ordenado
                for (i = 0; i < TOTAL_ALUNOS; i++){

                    printf("%dº Lugar | Nome: %s | Matricula: %s | Media: %.1f\n",i + 1, temp_nomes[i], temp_matricula[i], temp_medias[i]);
                }//loop
            }//else

            printf("Voltar para o MENU DIGITE -> [0,1...]: ");
            scanf("%d", &opcao);
        }else if (opcao == 3){
        //------------------ Exibi dados cadastro/notas/media - alunos ------------------ 
        printf("\033[H\033[J");

                printf("\n=== EXIBINDO BANCO/DADOS ALUNOS SALVOS ===\n");
                // Exibe oque esta, matricula_aluno[i], nome_alunos[i]
                    for (i = 0; i < TOTAL_ALUNOS; i++){         
                    
                        printf("Matricula: %s\nNome: %s\n", matricula_aluno[i], nome_alunos[i]);

                        // Exibe oque esta Matrix, notas_alunos[i][j] contador simples, varivavel mutavel...
                        contador_nota = 1; 

                        for (j = 0; j < 3; j++){
                            
                            printf("Nota(%d): %1.f\n",contador_nota, notas_alunos[i][j]);
                            
                            contador_nota++;//adiciona 1
                        }
                        // Condições para verificar se foi: reprovado/recuperação/aprovado
                        if(notas_alunos[i][3] <= 59){
                        // notas_alunos[i][3] coluna refente ao laço, pega sempre a ultima linha
                            printf("MEDIA_ALUNO: %1.f -> 'REPROVADO'\n", notas_alunos[i][3]); 
                            printf("=================================\n");
                        }
                        else if(notas_alunos[i][3] <= 69){
                            printf("MEDIA_ALUNO: %1.f -> 'RECUPERAÇÃO'\n", notas_alunos[i][3]);
                            printf("=================================\n");
                        }
                        else if(notas_alunos[i][3] >= 70){
                            printf("MEDIA_ALUNO: %1.f -> 'APROVADO'\n", notas_alunos[i][3]);
                            printf("=================================\n");    
                        }
                        
                    }//loop
                    printf("Voltar para o MENU DIGITE -> [0,1...]: ");
                    scanf("%d", &opcao);                           
        }//else
    }//loop 
   return 0;
}//main     
