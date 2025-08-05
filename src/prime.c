#include "lib_prime.h"
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

void is_prime(int n){
    if(n <= 1){
        printf("%d n'est pas premier\n", n);
        return;
    }
    if(n == 2){
        printf("%d est premier\n",n);
        return;
    }
    for(int i=2; i<=n-1; i++){
        if(n%i == 0){
            printf("%d n'est pas premier\n", n);
            return;
        }
    }
    printf("%d est premier\n",n);
}



void my_handler(int sig) {
    if (sig == SIGINT) {
        printf("\nVoulez-vous vraiment fermer le programme (Y/N): ");
        int reponse = getchar();

        // Vider le buffer stdin jusqu'au '\n' ou EOF
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        if (reponse == 'Y' || reponse == 'y') {
            printf("Fermeture du programme...\n");
            exit(0);
        } else if (reponse == 'N' || reponse == 'n') {
            printf("Reprise du programme.\n");
            return;
        } else {
            // Appel récursif si la réponse est autre chose
            my_handler(sig);
        }
    }
}
