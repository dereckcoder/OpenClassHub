#include <stdio.h>

// Tamanho da ram (GB) = Aprox. 1 bilhão de bytes - células de memória individuais
#define TAM_RAM 100

int main(){

    // Memorias ram - do you senior?
    int memoria_ram[TAM_RAM] = {0};

    // Memoria cache - validador/endereço/dado
    int cache_endereco = -1;
    int cache_dado = 0;
    
    // Entrada 
    int entrada_endereco = 0;


    // Metodo preguiça
    int i = 0;
    /*
    printf("preguiça: %d\n", );
    */

    // simulação entrada_endereco 
    entrada_endereco = 10;

    memoria_ram[10] = 20;
    memoria_ram[30] = 80;

    cache_endereco = 10;
    cache_dado = 20;

    printf("-----------------------------\n");
    printf(">> Tentando acessar o endereço: %d\n",entrada_endereco);
    printf("-----------------------------\n");

    // LD - inicia validação de endereço da cache 
    if (cache_endereco == entrada_endereco){

        // LD - inicia validação dos dados da cache
        if(cache_dado == memoria_ram[entrada_endereco]){
            
            printf(">> CACHE HIT\n");
            printf("LD ENDEREÇO CACHE: %d\n", cache_endereco);
            printf("LD CACHE: %d\n", cache_dado);
            printf("-----------------------------\n");
        
        // Dados na cache divergente, inicia SD
        }else{
            printf(">> MISS: ENDEREÇO está na CACHE mas os DADOS MUDOU.\n");
            
            // SD - Grava os dados RAM -> cache_dado
            printf(">> SD - Atualização -> CACHE DADOS\n");
            cache_dado = memoria_ram[entrada_endereco];
            
        
            printf("-----------------------------\n");
            printf(">> CACHE CARREGA -> SUCESSO\n");
            printf("LD ENDEREÇO CACHE: %d\n", cache_endereco);
            printf("LD CACHE: %d\n", cache_dado);
            printf("-----------------------------\n");
            
        }//else
    
    }else{
        printf(">> CACHE MISS: ENDEREÇO NÃO ESTÁ NA CACHE BUSCANDO RAM\n");
        printf("LD - BUSCANDO -> RAM\n");
        printf("-----------------------------\n");

        // LD RAM -> SD CACHE
        // SD CACHE -> ENDEREÇO
        cache_endereco = entrada_endereco;
        // SD CACHE -> DADOS
        cache_dado = memoria_ram[entrada_endereco];

        printf(">> CACHE CARREGA -> SUCESSO\n");
        printf("NOVO ENDEREÇO CACHE: %d | NOVO DADO CACHE: %d\n", cache_endereco, cache_dado);
        printf("-----------------------------\n");        

    }//fim else
    
    return 0;
} // fim main