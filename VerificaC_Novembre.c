/*Author: Seimandi Alessandro   4A ROB
Date: 18/11/2020
Verifica TPSIT
es:
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#define LUNG 30
#define LUNGHEZZARIGA 200

typedef struct drone{
    int tempoVolo;
    int tempoAnomalia;
    float lat;
    float lon;
    char tipoAnomalia[];
}Drone;

int contaVolo(FILE *fp){
    int cnt=0;
    char *riga;
    riga = (char*)malloc(sizeof(char)*LUNG);
    while(fgets(riga, 200, fp)){
        cnt++;
    }
    free(riga);
    return cnt;
}

int contaAnomalie(FILE *fo){
    int cnt=0;
    char *riga;
    riga = (char*)malloc(sizeof(char)*LUNG);
    while(fgets(riga, 200, fo)){
        cnt++;
    }
    free(riga);
    return cnt;
}

void leggiFileVoli(Drone *droni, FILE *fp){
    char *riga = (char*)malloc(sizeof(char)*200);
    int k=0;
    fgets(riga, LUNGHEZZARIGA, fp);
    while(fgets(riga, LUNGHEZZARIGA, fp)){
        (droni+k)->tempoVolo = atoi(strtok(riga, ","));
        (droni+k)->lat = atof(strtok(NULL, ","));
        (droni+k)->lon = atof(strtok(NULL, ","));
        k++;
    }
    free(riga);
    return;
}

void leggiFileAnomalie(Drone *droni, FILE *fo){
    char *riga = (char*)malloc(sizeof(char)*200);
    int k=0;
    fgets(riga, LUNGHEZZARIGA, fo);
    while(fgets(riga, LUNGHEZZARIGA, fo)){
        (droni+k)->tempoAnomalia = atoi(strtok(riga, ","));
        strcpy((droni+k)->tipoAnomalia, strtok(NULL, ","));
        k++;
    }
    free(riga);
    return;
}

void verificaCoordinate(Drone *droni, int cntVolo, int cntAnomalie){
    for(int j=0; j<cntAnomalie; j++){
        for(int k=0; k<cntVolo; k++){
            if((droni+j)->tempoAnomalia == (droni+k)->tempoVolo){
                printf("\nerrore: latitudine: %f, longitudine: %f", (droni+k)->lat, (droni+k)->lon);
            }
    }
    }
}

void main(){
    Drone *droni;
    FILE *fp;
    FILE *fo;
    int cntVolo = 0;
    int cntAnomalie = 0;
    if((fp = fopen("Volo_drone.csv", "r")) == NULL){
        printf("Il file non esiste");
    }else{
        cntVolo = contaVolo(fp);
        fclose(fp);
        printf("%d", cntVolo);
        if((fo = fopen("Anomalie_drone.csv", "r")) == NULL){
            printf("Il file non esiste");
        }else{
            cntAnomalie = contaAnomalie(fo);
            fclose(fo);
            droni = (Drone*)malloc(sizeof(Drone)*cntVolo);
            fp = fopen("Volo_drone.csv", "r");
            leggiFileVoli(droni, fp);
            fo = fopen("Anomalie_drone.csv", "r");
            leggiFileAnomalie(droni, fo);
            verificaCoordinate(droni, cntVolo, cntAnomalie);
        }
    }
}