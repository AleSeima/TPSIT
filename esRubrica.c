#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_CONTATTI 1024

struct contatto{
    int id;
    char nome[64];
    char numero[16];
};

struct rubrica{
    int num_inseriti;
    struct contatto db[MAX_NUM_CONTATTI];  
};

int inserisci(struct rubrica *r, char *nome, char *numero){
    struct contatto *p;
    if(r->num_inseriti == MAX_NUM_CONTATTI){
        printf("Rubrica piena");
        return -1;                              //errore
    }
    p = &r->db[r->num_inseriti];    //punta all'area di memoria disponibile

    strcpy(p->nome, nome);          //copia il nome
    strcpy(p->numero, numero);      //copia il numero
    p->id = r->num_inseriti;        //assegno indice
    r->num_inseriti++;              //incremento numero contatti
    return 0;                       //tutto OK
}

char *trova_numero_da_nome(struct rubrica *r, char *nome){
    int i;
    struct contatto *p;
    for(i = 0; i < MAX_NUM_CONTATTI; i++){
        if(i == r->num_inseriti){
            break;                      //STOP se abbiamo raggiunto l'ultimo contatto
        }
        p = &r->db[i];                  //punto l'i-esimp contatto

        if (strcmp(p->nome, nome) == 0){
            return p->numero;             //ritorno il numero se i nomi coincidono
        }    
    }
    return NULL;
}

void stampa_rubrica(struct rubrica *r){
    int i;
    struct contatto *p;

    printf("\nStampa rubrica: %d contatti\n", r->num_inseriti);

    for(i = 0; i < MAX_NUM_CONTATTI; i++){
        if(i == r->num_inseriti){
            break;              //STOP se abbiamo raggiunto l'ultimo contatto
        }
        p = &r->db[i];          //punto l'i-esimo contatto

        printf("%s, %s,\n", p->nome, p->numero);
    }
}
