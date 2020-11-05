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

typedef struct canzone{
    int numero;
    char autore[100];
    char nome[100];
    int val;
}Canzone;

void leggiFile(Canzone playlist[],FILE *fp,int *cnt){//*cnt è il numero di canzoni
    char lettera; // lettera che legge nel file (lettera per lettera)
    char parola[100]; //parola completa (successione di tutte le lettere prima della ',')
    int indice=0; // indice che serve a capire cosa sto leggendo
    while(fscanf(fp,"%c",&lettera)!=EOF){//legge lettera
        if(lettera==','){// se è arrivata alla fine della parola
            parola[strlen(parola)]='\0';//aggiunge alla fine della parola completa '0'
            /*
            INDICE:
            0-> numero della canzone
            1-> titolo della canzone
            2-> autore della canzone
            */
            switch (indice){
                case 0:
                    playlist[*cnt].numero=(*cnt)+1;
                    break;
                case 1:
                    strcpy(playlist[*cnt].nome,parola);
                break;
                case 2:
                    strcpy(playlist[*cnt].autore,parola);
                break;
            }
            indice=(indice+1)%3;//incremento indice
            memset(&parola[0],0,sizeof(parola));//azzera parola
            if(indice==0)//se ho finito di leggere la canzone
                *cnt = *cnt + 1;//incremento contatore canzone
        }else{
            parola[strlen(parola)]=lettera;//aggiunge alla fine della parola l'ultima lettera letta
        }
    }
    printf("\nElenco canzoni in ordine\n");
    for(int k=0; k<N_CANZONI; k++){
        printf("\n%d %s %s",playlist[k].numero,playlist[k].nome,playlist[k].autore);
    }
    return;
}

void canzoniRandom(Canzone tab[], int n){
    bool ok= false;
    int canzone;
    int quanti = 11;
    printf("\n");
    printf("\nElelnco canzoni random:\n");
    for(int k=0; k<n; k++){
        while(ok == false){
            canzone = (rand()%10);
            if(tab[canzone].val == 0){
                printf("\n%d %s %s", tab[canzone].numero, tab[canzone].nome, tab[canzone].autore);
                ok = true;
                tab[canzone].val = 1;
            }
        }
        ok = false;
    }
}


void main(){
    Canzone playlist[100];
    FILE *fp;
    if((fp=fopen("Canzoni.csv","r"))==NULL){
        printf("il file non esiste");
    }else{
        int cnt=0;
        leggiFile(playlist,fp,&cnt);
        canzoniRandom(playlist,N_CANZONI);
    }
    return;
}
