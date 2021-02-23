//Scrivere una funzione che inverta una coda, ovvero produca una coda invertendo l’ordine
//degli elementi della coda di partenza. Suggerimento: utilizzare una pila.

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

typedef struct  el{
    char n;
    struct el *next;
}El;

int isEmpty(El *head){
    if(head == NULL)
        return 1;
    else
        return 0;
}

void enqueue(El **head, El **tail, El *element){

    if(isEmpty(*head))
        *head = element;
    else
        (*tail)->next = element;

    *tail = element;
    element->next = NULL;
}

El* dequeue(El **head, El **tail){
    El *ret = *head;

    if(isEmpty(*head))
        return NULL;
    else
        *head = ret->next;

    if(head == NULL)
        *tail = NULL;

    return ret;
}

El *pop(El **head){
    El *ret = *head;

    if(isEmpty(*head)){
        return NULL;
    }else{
        *head = ret->next;
    }
    return ret;
}

void push(El **head, El *element){
    if(isEmpty(*head)){     //= if(isEmpty(*head) == 0)
        *head = element;
        element->next = NULL;
    }else{
        element->next = *head;
        *head = element;
    }
}

int main(){
    //coda
    El* headCoda;
    El* tailCoda;
    El* elementCoda;
    headCoda = NULL;
    tailCoda = NULL;

    //pila
    char numero[100];
    El *headPila = NULL;
    El *elementPila = NULL;

    printf("Inserisci i numeri: ");
    fflush(stdin);
    scanf("%s", numero);

    for(int k = 0; numero[k] != '\0'; k++){
        //riempio la coda
        elementCoda = (El*) malloc(sizeof(El));
        elementCoda->n = numero[k];
        enqueue(&headCoda, &tailCoda, elementCoda);

        //riempio la pila
        elementPila = (El*) malloc(sizeof(El)); //alloco in memoria l'elemento della pila
        elementPila->n = numero[k];    //assegna al valore della cella il numero che ha letto
        push(&headPila, elementPila);       //inserisce il valore nella pila
    }

    printf("Stmpa coda in ordine:\n");

    El* appoggio;

    //dealloco la coda

    while(!isEmpty(headCoda)){
        appoggio = dequeue(&headCoda, &tailCoda);
        printf("%c ", appoggio->n);
        free(appoggio);
    }

    headCoda = NULL;
    tailCoda = NULL;

    //inserisco nella coda la pila e dealloco la pila
    while(!isEmpty(headPila)){
        appoggio = pop(&headPila);
        enqueue(&headCoda, &tailCoda, appoggio);
    }

    printf("\nStmpa coda invertita:\n");
    
    //stampa la coda finale, e la dealloca
    while(!isEmpty(headCoda)){
        appoggio = dequeue(&headCoda, &tailCoda);
        printf("%c ", appoggio->n);
        free(appoggio);
    }

}