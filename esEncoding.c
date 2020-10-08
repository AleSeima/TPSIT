/*Author: Seimandi
Date: 21/10/2019

es:
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define LUNG 20

void encoding(char vect[]){
    int cnt=1;
    for(int k=0; vect[k] != '\0'; k++){
            if(vect[k] == vect[k+1]){
                cnt++;
            }else{
                if(cnt == 1){
                     printf("%c", vect[k]);
                }else{
                     printf("%d%c", cnt, vect[k]);
                     cnt = 1;
                }
            }
    }
}

void decoding(char vect[]){
    int cnt = 1;
    printf("\n");
    for(int k=0; vect[k] != '\0'; k++){
        if(vect[k] >= '0' && vect[k] <= '9'){
            for(int j=1; j < vect[k]-48; j++){
                printf("%c", vect[k+1]);
            }
        }else{
            printf("%c", vect[k]);
        }
    }

}

void main(){
    char vect[LUNG];

    printf("Inserire la frase: ");
    fflush(stdin);
    scanf("%s", vect);

    encoding(vect);

    decoding(vect);
}
