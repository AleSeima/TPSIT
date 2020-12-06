#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct canzone{
    int numero;
    char autore[100];
    char nome[100];
    int val;
    struct canzone* next;
}Canzone;

void leggiFile(Canzone* playlist, FILE* fp, int *cnt){ //metto le canzoni del file nella lista
    char* riga = (char *) malloc(sizeof(char) * 200);
    Canzone* temp = playlist;   //variabile di appoggio per ogni canzone, qui punta alla prima canzone
    while(fgets(riga, 200, fp)){
        temp->numero = atoi(strtok(riga, ",")); //primo giro: prende il numero della prima canzone, poi dal giro 2 prende la seconda e così via
        strcpy(temp->autore, (strtok(NULL, ",")));
        strcpy(temp->nome, strtok(NULL, ","));
        temp->next = (Canzone*) malloc(sizeof(Canzone));    //essendo next un puntatore a canzoni, alloco in memoria e assegno l'indirizzo a next l'indizzo della struttura della seconda canzone
        temp->val = rand() % 10000000 ;//assegna un numero random al val di ogni canzone 
        temp = (temp->next);    //puntatore che puntava alla prima struttura fallo puntare alla seconda struttura il cui indirizzo è salvato in next
        *cnt += 1; //contatore canzoni
        free(riga); //cancello quello che è contenuto in riga
        riga = (char *)malloc(sizeof(char)*200); //rialloco una nuova riga  
    }
    free(temp);
    return;
}


Canzone* accediCanzone(Canzone* playlist, int numero){//prendo la conzone 
    Canzone* temp = playlist;//puntatore di canzone alla prima canzone
    for(int i = 0; i < numero; i++){//gli dico di puntare alla canzone numero all'ultimo giro del for
        temp=temp->next;//gli dico di puntare alla canzone successiva
    }
    return temp;//retruna il puntatore che punta a canzone numero(che gli passo)
}


void canzoniRandom(Canzone* playlist, int cnt){
    int max, posMax ;
    Canzone* temp;//variabile di appoggio che scorre tutte le canzoni della lista cnt volte
    for(int j = 0; j < cnt; j++){
        temp = playlist ;//temp punta alla prima canzone
        posMax = 0 ;//tutte le volte dalla prima canzone
        max = temp->val;//valore massimo = al val della prima canzone
        for(int x = 0; x < cnt; x++){
            if(max < temp->val){    //se max è minore del numero random della canzone attuale
                max = temp->val;    //se così a max assegno il valore di val della canzone attuale
                posMax = x ;//il numero della canzone con valore attuale massimo lo assegno a posMax, ad esempio al terzo giro gli assegno 3
            }
            temp = temp->next;//tempo ogni giro di ciclo punta alla prossima canzone
        }
        temp = accediCanzone(playlist, posMax); //temp puntava all' ultima canzone, ma adesso grazie alla funzione accedicanzone punta alla posizione massima ovvero ad esmpio nel terzo giro punta alla 3 canzone
        //accediCanzone: serve per accedere alla canzone con posMax = x e con valore di random(VAL) = al massimo per poi stampare la canzone, e devo fa5re un for essendo una lista in cui devo scorrere tutta la lista per accedere alla cxanzone che mi interessa
        printf ("%d %s %s\n",temp->numero, temp->nome, temp->autore);   
        temp->val = -100-posMax ;   //alla canzone che ho trovato assegno al suo val un numero negativo di modo che non lo riprenda più nei prossimi cicli
    }
    return ;
}


void main(){
    FILE *fp;
    if((fp = fopen("Canzoni.txt","r")) == NULL){
        printf("Il file non esiste");
    }else{
        int cnt = 0 ;
        Canzone* playlist = (Canzone *) malloc(sizeof(Canzone));
        leggiFile(playlist,fp,&cnt);
        
        fclose(fp);
        canzoniRandom(playlist, cnt);//passo la prima canzone contenuta in playlist e il cnt
        Canzone* temp = playlist;//variabile di appoggio che scorre tutte le canzoni della lista cnt volte
        Canzone* a = playlist;
        for(int k=0; k<cnt; k++){
            a = temp;
            temp = temp->next;
            free(a);
        }
    }
    return;
}

/*void freeStruttura(Canzone* playlist){
    if(playlist->next != NULL){
        freeStruttura(playlist->next);
        free(playlist);
    }
    return;
}
*/
