#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct nodo{
    char val;
    struct nodo* next;
}Nodo;

int isEmpty(Nodo *head){
    if(head == NULL)
        return 1;
    else
        return 0;   
} 

void push(Nodo **head, Nodo *element){  //mette il valore in cima alla pila
    if(isEmpty(*head)){     //= if(isEmpty(*head) == 0)
        *head = element;
        element->next = NULL;
    }else{
        element->next = *head;  //l'elemento precedente dalla prima posizione passa alla prima
        *head = element;    //la testa diventa il nuovo elemnto che gli è stato appena passtao
    }
}

Nodo *pop(Nodo **head){
    Nodo *ret = *head;

    if(isEmpty(*head)){
        return NULL;
    }else{
        *head = ret->next;
    }
    return ret;
}

void leggiFile(Canzone playlist[],FILE *fp,int *cnt){//*cnt il numero di canzoni
    char song[100]; // stringa che legge nel file tutta la riga
    int k=0; // indice che serve a capire qiale riga sto leggendo
    while(fgets(song, LUNGHEZZARIGA, fp)!=NULL){//legge canzone
        strcpy(playlist[k].val, strtok(NULL, ","));
        k++;
    }
    printf("\nElenco canzoni in ordine\n");
    for(int k=0; k<N_CANZONI; k++){
        printf("\n%d %s %s",playlist[k].numero,playlist[k].nome,playlist[k].autore);
    }
    return;
}

int main(){
    Nodo* pila;
    Nodo* element;
    char* stringa;
    printf("inserisci una stringa: ");
    scanf("%s", stringa);

    for(int i = 0; i < strlen(stringa); i++){
        element = (Nodo*) malloc(sizeof(Nodo));
        element->val = stringa[i];
        push(pila, element);
    }
    char* stringa2;
    int i = 0;
    while(isEmpty(pila)){
        stringa[i] = pop(pila)->val;
        i++;
    }

    return 0;
}

