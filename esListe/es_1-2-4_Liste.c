//ES1 ES2

#include <stdio.h>
#include <stdlib.h>
struct El{
    int valore;
    struct El next;
};

void push(struct El* lista,int valore){
    if (lista == NULL){ /* se lista non punta a niente 
                // alloca una struct El in memoria, assegna l'indirizzo della struttura allocata a lista. Assegna poi a l'indirizzo puntato ada lista */

        lista = (struct El*)malloc(sizeof(struct El));
        lista ->valore = valore;    //inserisco il valore al primo elemnto della lista
        lista ->next = NULL;    //inizio lista
    }else{ // se la lista punta a qualcosa 
        while(lista->next != NULL){
            lista = lista->next;//incremento il puntatore
        }
        lista->next = (struct El )malloc(sizeof(struct El));
        lista->next->valore = valore;
        lista->next->next = NULL;   //lista di next = x    lista-> = null perche è l'ultimo
    }
    return;
}

void stampaLista(struct El l){
    while (l != NULL){
        printf("%d - %p \n", l->valore, l->next);
        l = l->next;  //fa puntare all'offset la prossima struttura 
    }
    return;
}
int main(){
    int n;
    struct El *lista;
    struct El l;
    lista = NULL; // svuota il contenuto di lista, quidi non punta a niente (punta alla cella 0000...) 

    do{
        printf("Inserisci un naturale o -1 per terminare\n");
        scanf("%d", &n);
        if (n >= 0){
                push(lista,l);
            }
            l->valore = n;  / il valore di "valore" della struttura corrente (l), viene assegnato n (preso in input) /
            l->next = NULL; / cancella il contenuto del puntatore alla prossima struttura (l->next) /
    } while (n >= 0);

    l = lista;  //fa puntare all'offset la prima struttura 
    printf("numeri inseriti: ");
    stampaLista(l);
    printf("\n");
    return 0;
}

//ES4
void freeStruttura(El* lista){
    if(lista->next != NULL){
        freeStruttura(lista->next);
        free(lista);
    }
    return;
}