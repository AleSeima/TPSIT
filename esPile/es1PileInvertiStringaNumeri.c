/*
Author: Seimandi Alessandro
es: invertire una stringa di numeri utilizzando le pile
*/

typedef struct nodo{
    char valore;
    struct nodo *next;
}Nodo;

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

int isEmpty(Nodo *head){
    if(head == NULL)
        return 1;
    else
        return 0;   
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

void push(Nodo **head, Nodo *element){
    if(isEmpty(*head)){     //= if(isEmpty(*head) == 0)
        *head = element;
        element->next = NULL;
    }else{
        element->next = *head;
        *head = element;
    }
}

void stampa(Nodo **head){
    Nodo *appoggio;
    
    while(appoggio != NULL){
        appoggio = pop(head);   //toglie dalla lista, e ad appoggio assegna la testa della pila
        printf("%c ", appoggio->valore);
        free(appoggio);
    }
}

int main(){
    char numero[100];
    Nodo *head = NULL;
    Nodo *element = NULL;

    printf("Inserisci i numeri: ");
    fflush(stdin);
    scanf("%s", numero);

    for(int k = 0; numero[k] != '\0'; k++){
        element = (Nodo*) malloc(sizeof(Nodo)); //alloco in memoria l'elemento della pila
        element->valore = numero[k];    //assegna al valore della cella il numero che ha letto
        push(&head, element);       //inserisce il valore nella pila
    }

    stampa(&head);
    return;
}