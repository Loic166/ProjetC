#include <stdio.h>
#include <signal.h>
#include "lib_prime.h"

int main(){

    signal(SIGINT, my_handler);

    printf("Pour arrèter le programme faites CTRL+C\n");
    while(1){
        int n;
        printf("Insérez un nombre entier: ");

        if(scanf("%d", &n) !=1){
            printf("Entré invalide !\n");

            //Vider le  buffer du stdin
            int buf;
            while((buf = getchar()) != '\n' && buf != EOF);
            continue;
        }
        is_prime(n);
    }
}