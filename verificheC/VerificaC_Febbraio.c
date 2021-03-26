/*
Author: Seimandi Alessandro
es: Verifica
*/

typedef struct el{  //Struttura che indica le caratteristiche della carta
    char seme;  //seme della carta
    int n;  //numero della carta da 1 a 13
    struct el *next;
}El;

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

int isEmpty(El *head){  //funzione per verificare che la pila abbia ancora degli elementi o sia già vuota
    if(head == NULL)
        return 1;
    else
        return 0;   
}

El *pop(El **head){ //funzione che serve per aggiungere le carte al mazzo, quindi aggiungere gli elementi alla pila
    El *ret = *head;

    if(isEmpty(*head)){
        return NULL;
    }else{
        *head = ret->next;
    }
    return ret;
}

void push(El **head, El *element){  //funzione che serve per togliere le carte dal mazzo, quindi togliere gli elementi dalla pila
    if(isEmpty(*head)){     //= if(isEmpty(*head) == 0)
        *head = element;
        element->next = NULL;
    }else{
        element->next = *head;
        *head = element;
    }
}

int main(){
    //dichiaro tutte le 3 pile. Una del mazzo principale, una del mazzo di Alice e una del mazzo di Bob
    El* head = NULL;
    El* element = NULL;
    El* headAlice = NULL;
    El* elementAlice = NULL;
    El* headBob = NULL;
    El* elementBob = NULL;
    int turno=0;    //variabile per stabilire di chi è il turno per distribuire le carte

    //riempio la pila con tutte le carte di cuori
    for(int k=1; k<14; k++){
        element = (El*) malloc(sizeof(El));
        element->seme = 'C';
        element->n = k;
        push(&head, element);
    }

    //continuo a riempire la pila con tutte le carte di picche
    for(int k=1; k<14; k++){
        element = (El*) malloc(sizeof(El));
        element->seme = 'P';
        element->n = k;
        push(&head, element);
    }

    //continuo a riempire la pila con tutte le carte di denari
    for(int k=1; k<14; k++){
        element = (El*) malloc(sizeof(El));
        element->seme = 'D';
        element->n = k;
        push(&head, element);
    }

    //continuo a riempire la pila con tutte le carte di fiori
    for(int k=1; k<14; k++){
        element = (El*) malloc(sizeof(El));
        element->seme = 'F';
        element->n = k;
        push(&head, element);
    }

    //svuoto il mazzo di carte principale con la pop e riempio i mazzi dei giocatori con la push
    while(!isEmpty(head)){
        turno = rand()%2;   //decido il turno con la formula random
        if(turno == 0){     //se tocca prima ad Alice
            elementAlice = pop(&head);  //dealloco il mazzo
            push(&headAlice, elementAlice); //riempio la pila di Alice

            elementBob = pop(&head);    //dealloco il mazzo
            push(&headBob, elementBob); //riempio la pila di Bob
        }
        if(turno == 1){     //se tocca prima a Bob
            elementBob = pop(&head);    //dealloco il mazzo
            push(&headBob, elementBob); //riempio la pila di Bob

            elementAlice = pop(&head);  //dealloco il mazzo
            push(&headAlice, elementAlice); //riempio la pila di Alice
        }
    }

    El* appoggioAlice;

    printf("Carte di Alice: \n");

    //Stampa le carte di Alice e dealloco la pila di Alice con la Pop
    while(!isEmpty(headAlice)){
        appoggioAlice = pop(&headAlice);    //dealloco la pila di Alice
        printf("%d ", appoggioAlice->n);    //stampo numero carta
        printf("%c , ", appoggioAlice->seme); //stampo seme carta
        free(appoggioAlice);
    }

    El* appoggioBob;

    printf("\nCarte di Bob: \n");

    //Stampa le carte di Bob e dealloco la pila di Bob con la Pop
    while(!isEmpty(headBob)){
        appoggioBob = pop(&headBob);    //dealloco pila di Bob
        printf("%d ", appoggioBob->n);  //stampo numero carta
        printf("%c , ", appoggioBob->seme);   //stampo seme carta
        free(appoggioBob);
    }


}

//wifi, b loutheut, wimax, livello internet, fino a ind ipvr4 speciali