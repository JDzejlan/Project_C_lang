#include <stdio.h>
#include <string.h>
#define SEZONA 82

typedef struct{
    char ime[30];
    float PPG;
    float RPG;
    float APG;
    int game_no;
}igrac;
float pF(int gaame_no){
    int Koraci = 0;
    int suma = 0;
    float prosjek;
    for ( int i = 0; i < gaame_no; i++){
        int temp = 15 + rand() % (35 - 15);
        suma += temp;
        Koraci++;
    }
    prosjek =(float) suma / (float)Koraci;
    return prosjek;
}
float rF(int gaame_no){
    int Koraci = 0;
    int suma = 0;
    float prosjek;
    for ( int i = 0; i < gaame_no; i++){
        int temp = 5 + rand() % (15 - 5);
        suma += temp;
        Koraci++;
    }
    prosjek =(float) suma / (float)Koraci;
    return prosjek;
}
float aF(int gaame_no){
    int Koraci = 0;
    int suma = 0;
    float prosjek;
    for ( int i = 0; i < gaame_no; i++){
        int temp = 3 + rand() % (17 - 3);
        suma += temp;
        Koraci++;
    }
    prosjek =(float) suma / (float)Koraci;
    return prosjek;
}
int main()
{
printf("Unesite broj kosarkasa koliko zelite da budu u programu\n");
int temp;
scanf("%d", &temp);
igrac nets[temp];
char ime_igraca[30];
for (int i = 0; i < temp; i++){
    printf("Ime igraca- ");
    scanf("%s",&ime_igraca);
    strcpy(nets[i].ime, ime_igraca);
    nets[i].game_no = (int)(33 + rand() % (SEZONA - 33));
    nets[i].PPG = pF(nets[i].game_no);
    nets[i].RPG = rF(nets[i].game_no);
    nets[i].APG = aF(nets[i].game_no);
}
for (int i = 0; i < temp; i++){
    printf("\n %s\t%d \t%f \t%f \t%f \n", nets[i].ime , nets[i].game_no, nets[i].PPG, nets[i].RPG , nets[i].APG );
}
char tempchar [8];
char naziv_datoteke[25];
for (int i = 0; i < temp; i++){
    for(int j = 0; j < 4; j++){
            tempchar[j] = nets[i].ime[j];
    }
    strcat(naziv_datoteke, tempchar);
}
strcat(naziv_datoteke, ".txt");
FILE *file = fopen(naziv_datoteke, "a+");
fprintf(file, "ime igrca\tbroj utakmica\t PPG\t\t\t RPG\t\t\t APG\n");
for(int i = 0; i< temp; i++){
    fprintf(file, "%s\t\t%d\t\t%f\t\t%f\t\t%f\n", nets[i].ime , nets[i].game_no, nets[i].PPG, nets[i].RPG , nets[i].APG );
}
fclose(file);
}
