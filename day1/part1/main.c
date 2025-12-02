#include <stdio.h>
#include <stdlib.h>

int main(void){
    FILE *f = fopen("../input/input.txt", "r");
    if (f == NULL) {
        perror("Erreur ouverture");
        return 1;
    }
    char buffer[100];
    int dial = 50;
    int compteur = 0;

    while (fscanf(f, "%s", buffer) == 1) {
        if (buffer[0] == 'L')
            dial -= atoi(&buffer[1]);
        else if (buffer[0] == 'R')
            dial += atoi(&buffer[1]);
        dial = ((dial % 100) + 100) % 100;
        compteur += (dial == 0);
    }

    fclose(f);
    printf("%d\n", compteur);
    return 0;
}