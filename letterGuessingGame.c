#include <stdio.h>
#include <string.h>

int main() {
    char toBeGuessed[] = "p";

    char guess[2];

    int returner = 1;

    while (returner == 1) {
        printf("Guess a lower case letter: \n");
        fgets(guess, sizeof(guess), stdin);

        int result = strcmp(guess, toBeGuessed);

        if (result == 0) {
            printf("You win");
            returner = 0;
        } else if (result > 0) {
            printf("Your guess is higher\n");
        } else {
            printf("Your guess is lower\n");
        }
    }

    return returner;
}