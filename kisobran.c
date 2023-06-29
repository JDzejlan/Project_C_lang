#include <stdio.h>
#define CRVENA 176
#define SIVA 177
#define BIJELA 178
#define CRNA 32

void PrviDioMatrice(int matrica[8][12]){

    for(int x = 0; x < 8; x++){
        for(int y = 0; y < 12; y++){
            if(x < 4 && y <6){
                matrica[x][y] = BIJELA;
            }else if(x < 4 && y > 5){
                matrica[x][y] = SIVA;
            }else if(x > 3 && y < 6){
                matrica[x][y] = SIVA;
            }else if(x > 3 && y > 5){
                matrica[x][y] = BIJELA;
            }

            if((x+y<3) || (y-x>8) || (y>4 && y<7) ||(y+x>15)){
                matrica[x][y] = CRNA;
            }

            if(x-y==5 || x-y==6 || x-y==7){
                matrica[x][y] = CRNA;
            }
        }
    }
}


void ispis(int matrica[8][12]){

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 12; j++){
            printf("%c" , matrica[i][j]);
        }
        printf("\n");
    }
}



int suma(int matrica[8][12]){
    int rez = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 12; j++){
            if(matrica[i][j] > 32){
                rez += matrica[i][j];
            }
        }
    }
    return rez;
}



int main(){

    int kisobran[8][12];

    PrviDioMatrice(kisobran);
    ispis(kisobran);

    int suma_elemenata = suma(kisobran);
    putchar('\n');
    printf("Suma karaktera: %c\n", suma_elemenata);
}
