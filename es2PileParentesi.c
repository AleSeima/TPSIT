/*
Author: Michele Alladio
es: verificare se, in una stringa, l'ordine delle parentesi è corretto. Utilizzando le pile.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

typedef struct nodo{
    char valore;
    struct nodo *next;
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

int main(){
    char stringa[100];
    Nodo *head = NULL;  //testa della pila
    Nodo *pila = NULL;  //coda della pila
    Nodo *appoggio = NULL;  //var di appoggio
    bool ok = true; 

    printf("inserisci una stringa con parentesi graffe tonde e quandre al suo interno: ");
    scanf("%s", stringa);

    for(int k = 0; stringa[k] != '\0' && ok == true; k++){ //carucamento stringa nella pila
        pila = (Nodo*) malloc(sizeof(Nodo));    //cre lo spazio in memoria per la pila
        pila->valore = stringa[k];  //assegna alla cella della pila il carattere corrisponente

        if(stringa[k] == '(' || stringa[k] == '[' || stringa[k] == '{'){    //se è una parentesi aperta
            push(&head, pila);  //metto il valore sopra a tutti gli altri valori della pila
            
        }else if(stringa[k] == ')'){    //se è una parentesi chiusa
            appoggio = pop(&head);  //annulla la push, prende da dentro la pila
            if(appoggio != NULL){
                if(appoggio->valore != '('){ //se il valore della struttura di appoggio è (
                    ok = false;
                    break;
                }
            }else{
                ok = false;
                break;
            }
            free(appoggio);
        }else if(stringa[k] == ']'){
            appoggio = pop(&head); //ad appoggio assegna la testa della pila
            if(appoggio != NULL){
                if(appoggio->valore != '['){
                    ok = false;
                    break;
                }
            }else{
                ok = false;
                break;
            }
            free(appoggio);
        }else if(stringa[k] == '}'){
            appoggio = pop(&head);
            if(appoggio != NULL){
                if(appoggio->valore != '{')
                    ok = false;
            }else{
                ok = false;
                break;
            }  
            free(appoggio);
        }
    }

    if(ok == true)
        printf("Ordine parentesi corretto");
    else
        printf("Ordine parentesi errato");

    return 0;
}
