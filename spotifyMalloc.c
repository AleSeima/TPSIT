/*Author: Seimandi
Date: 21/10/2019

es:
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#define N_CANZONI 10
#define LUNG 20
#define LUNGHEZZARIGA 100

typedef struct canzone{
    int numero;
    char autore[100];
    char nome[100];
    int val;
}Canzone;

void leggiFile(Canzone *playlist,FILE *fp){//*cnt il numero di canzoni
    char *song = (char*)malloc(sizeof(char)*100); // stringa che legge nel file tutta la riga
    int k=0; // indice che serve a capire qiale riga sto leggendo
    while(fgets(song, LUNGHEZZARIGA, fp)!=NULL){//legge canzone
        (playlist+k)->numero = atoi(strtok(song, ",\n"));
        strcpy((playlist+k)->autore, strtok(NULL, ",\n"));
        strcpy((playlist+k)->nome, strtok(NULL, ",\n"));
        k++;
    }
    printf("\nElenco canzoni in ordine\n");
    for(int k=0; k<N_CANZONI; k++){
        printf("\n%d %s %s",(playlist+k)->numero,(playlist+k)->nome,(playlist+k)->autore);
    }
    free(song);
    return;
}

void canzoniRandom(Canzone *tab, int n){
    bool ok= false;
    int canzone;
    printf("\n");
    printf("\nElelnco canzoni random:\n");
    for(int k=0; k<n; k++){
        while(ok == false){
            canzone = (rand()%10);
            if((tab+canzone)->val == 0){
                printf("\n%d %s %s", (tab+canzone)->numero, (tab+canzone)->nome, (tab+canzone)->autore);
                ok = true;
                (tab+canzone)->val = 1;
            }
        }
        ok = false;
    }
}

int contaCanzoni(FILE *fp){
    int cnt=0;
    char *riga;
    riga = (char*)malloc(200*sizeof(char));
    while(fgets(riga, 100, fp)){
        cnt++;
    }
    free(riga);
    return cnt;
}


void main(){
    Canzone *fo;
    int cnt=0;
    FILE *fp;
    if((fp=fopen("Canzoni.txt","r"))==NULL){
        printf("il file non esiste");
    }else{
        cnt = contaCanzoni(fp);
        fo = (Canzone*)malloc(sizeof(Canzone)*cnt);
        fclose(fp);
        fopen("Canzoni.txt", "r");
        leggiFile(fo,fp);
        canzoniRandom(fo,cnt);
        free(fo);
    }
    return;
}
