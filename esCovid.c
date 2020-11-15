#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#define N_REGIONI 21
#define LUNG 200
#define LUNGHEZZARIGA 200

typedef struct regione{
    char data[LUNG];
    char stato[LUNG];
    int codice_regione;
    char denominazione_regione[LUNG];
    float lat;
    float longit;
    int ricoverati_con_sintomi;
    int terapia_intensiva;
    int totale_ospedalizzati;
    int isolamento_domiciliare;
    int totale_positivi;
    int variazione_totale_positivi;
    int nuovi_positivi;
    int dimessi_guariti;
    int deceduti;
    int casi_da_sospetto_diagnostico;
    int casi_da_screening;
    int totale_casi;
    int tamponi;
    int casi_testati;
    bool preso;
}Regione;

int contaRegioni(FILE *fp){
    int cnt=0;
    char *riga;
    riga = (char*)malloc(200*sizeof(char));
    while(fgets(riga, 200, fp)){
        cnt++;
    }
    free(riga);
    return cnt;
}

void leggiFile(Regione *regioni, FILE *fp){
    char *riga = (char*)malloc(sizeof(char)*200);// stringa che legge nel file tutta la riga
    int k=0;
    while(fgets(riga, LUNGHEZZARIGA, fp)){
         (regioni+k)->preso = false;
        strcpy((regioni+k)->data, strtok(riga, ",\n"));
        strcpy((regioni+k)->stato, strtok(NULL, ",\n"));
        (regioni+k)->codice_regione = atoi(strtok(NULL, ",\n"));
        strcpy((regioni+k)->denominazione_regione, strtok(NULL, ",\n"));
        (regioni+k)->lat = atof(strtok(NULL, ",\n"));
        (regioni+k)->longit = atof(strtok(NULL, ",\n"));
        (regioni+k)->ricoverati_con_sintomi = atoi(strtok(NULL, ",\n"));
        (regioni+k)->terapia_intensiva = atoi(strtok(NULL, ",\n"));
        (regioni+k)->totale_ospedalizzati = atoi(strtok(NULL, ",\n"));
        (regioni+k)->isolamento_domiciliare = atoi(strtok(NULL, ",\n"));
        (regioni+k)->totale_positivi= atoi(strtok(NULL, ",\n"));
        (regioni+k)->variazione_totale_positivi = atoi(strtok(NULL, ",\n"));
        (regioni+k)->nuovi_positivi = atoi(strtok(NULL, ",\n"));
        (regioni+k)->dimessi_guariti = atoi(strtok(NULL, ",\n"));
        (regioni+k)->deceduti = atoi(strtok(NULL, ",\n"));
        (regioni+k)->casi_da_sospetto_diagnostico = atoi(strtok(NULL, ",\n"));
        (regioni+k)->casi_da_screening = atoi(strtok(NULL, ",\n"));
        (regioni+k)->totale_casi = atoi(strtok(NULL, ",\n"));
        (regioni+k)->tamponi = atoi(strtok(NULL, ",\n"));
        (regioni+k)->casi_testati = atoi(strtok(NULL, ",\n"));
        k++;
    }
    free(riga);
    return;
}

void ordina(Regione *regioni, int dim) { 			
    int k ; 
    int PosMax[3];
    int superiore ; 							
    for (superiore = 3; superiore > 0; superiore--) {
        PosMax[superiore]=0;           
        for (k = 0; k < dim; k++) {
 			if ((regioni+k)->terapia_intensiva > (regioni+PosMax[superiore])->terapia_intensiva) {
 				if((regioni+k)->preso == false){
                     PosMax[superiore] = k;
                 }
             }
        }
        (regioni+PosMax[superiore])->preso = true;
        printf(" %d %d", superiore, (regioni+PosMax[superiore])->terapia_intensiva);
    }
}

void contaTerapie(Regione *regioni, int dim) {
    int somma =0;
    for(int k=0; k<dim; k++){
        somma = somma + (regioni+k)->terapia_intensiva;
    }
    printf("\n%d", somma);
}

void ordinaMenoCasi(Regione *regioni, int dim) { 			
    int k ; 
    int PosMax[3];
    int superiore ; 							
    for (superiore = 3; superiore > 0; superiore--) {
        PosMax[superiore]=0;           
        for (k = 0; k < dim; k++) {
 			if ((regioni+k)->totale_positivi < (regioni+PosMax[superiore])->totale_positivi) {
 				if((regioni+k)->preso == false){
                     PosMax[superiore] = k;
                 }
             }
        }
        (regioni+PosMax[superiore])->preso = true;
        printf(" %d %d", superiore, (regioni+PosMax[superiore])->totale_positivi);
    }
}

int main(){
    Regione *fo;
    FILE *fp;
    int cnt=0;
    if((fp=fopen("covid.txt","r"))==NULL){
        printf("il file non esiste");
    }else{
        cnt = contaRegioni(fp);
        printf("Numero regioni%d", cnt);
        fo = (Regione*)malloc(sizeof(Regione)*cnt);
        fclose(fp);
        fopen("Covid.txt", "r");
        leggiFile(fo,fp);
        contaTerapie(fo, cnt);
        ordinaMenoCasi(fo, cnt);
        ordina(fo, cnt);
    }
}