#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void vaciarMapaBuscaminas(char buscaminas[6][6]){
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            buscaminas[i][j] = ' ';
        }
    }
}

void llenarMapaBuscaminas(char buscaminas[6][6]){
    vaciarMapaBuscaminas(buscaminas);
    for (int i = 0; i < 8; ++i) {
            int rand1 = rand() %6;
            int rand2 = rand() %6;
            if (buscaminas[rand1][rand2] != '*'){
                buscaminas[rand1][rand2] = '*';
            } else{
                i--;
            }
    }
}

void imprimirBuscaMinas(char buscaminas[6][6]){
    printf("   ");
    for (int i = 0; i < 6; ++i) {
        printf("%d ", i);
    }
    printf("\n");
    printf(" +-------------------+\n");
    for (int i = 0; i < 6; ++i) {
        printf("%d |",i);
        for (int j = 0; j < 6; ++j) {
            if(buscaminas[i][j] == '*'){
                printf("  ");
            } else {
                printf("%c ", buscaminas[i][j]);
            }
        }
        printf("\n");
    }
    printf("  +-------------------+\n");
}

void impresionMuerte(char buscaminas[6][6]){
    printf("   ");
    for (int i = 0; i < 6; ++i) {
        printf("%d ", i);
    }
    printf("\n");
    printf(" +-------------------+\n");
    for (int i = 0; i < 6; ++i) {
        printf("%d |",i);
        for (int j = 0; j < 6; ++j) {
            printf("%c ", buscaminas[i][j]);
        }
        printf("\n");
    }
    printf("  +-------------------+\n");
}

bool verificacionMina(char buscaminas[6][6], int x, int y){
    return buscaminas[x][y] == '*';
}

bool contarMinas(char buscaminas[6][6], int x, int y, bool *muerte){
    int contador = 0;
    if(verificacionMina(buscaminas, x, y)){
        *muerte = true;
    } else {
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                int validacionX = x + i;
                int validacionY = y + j;
                if(validacionX >= 0 && validacionX < 6 && validacionY >= 0 && validacionY < 6){
                    if (verificacionMina(buscaminas, validacionX, validacionY)){
                        contador++;
                    }
                }
            }
        }
        buscaminas[x][y] = '0' + contador;
        return *muerte;
    }
}

void impresionTitulo(){
    printf("    *****************\n");
    printf("    *               *\n");
    printf("    *   BUSCAMINAS  *\n");
    printf("    *               *\n");
    printf("    *****************\n");
    printf("\n");
}

int main() {
    srand(time(NULL));
    char buscaminas[6][6];
    bool muerte = false;
    int x, y;
    impresionTitulo();
    llenarMapaBuscaminas(buscaminas);
    while (!muerte){
        imprimirBuscaMinas(buscaminas);
        printf("Ingrese coordenada de X & coordenada de Y seguidamente\n");
        scanf("%d" "%d", &x, &y);
        if(contarMinas(buscaminas, x, y, &muerte)){
            impresionMuerte(buscaminas);
            printf("USTED HA MUERTO X.X");
        }
    }
    return 0;
}