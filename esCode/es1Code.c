//Implementare i metodi enqueue() e dequeue()  e creare un programma che permetta
//all’utente di riempire una coda di numeri interi di lunghezza arbitraria. Successivamente
//testare la funzione dequeue per svuotare la coda.

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

typedef struct  el{
    int n;
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

void stampaLista(El *head){
    while(!isEmpty(head)){
        printf("%d", head->n);
        *head = *head->next;
    }
}

int main(){
    El* head;
    El* tail;
    El* elementCoda;
    head = NULL;
    tail = NULL;
    char ancora;

    do{
        element = (El*) malloc(sizeof(El));
        printf("Inserire un numero naturale");
        fflush(stdin);
        scanf("%d", &elementCoda->n);
        enqueue(&head, &tail, elementCoda);
        printf("Vuoi inserire un,altro elemento?(S per si)");
        fflush(stdin);
        scanf("%c", &ancora);
    }while(ancora == 'S' || ancora == 's');

    printf("Stmpa lista piena:\n");
    
    while(!isEmpty(head)){
        El* appoggio;
        appoggio = dequeue(&head, &tail);
        printf("%d ", appoggio->n);
        free(appoggio);
    }
}