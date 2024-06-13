#include <stdio.h>

int main(void) {
    // default values for failsafe
    int length = 1;
    int breath = 1;
    printf("what is the configuration you need: ");
    scanf("%d %d", &length, &breath);

    for (int i = 0; i < length; i++) {
        for (int i = 0; i < breath; i++) {
            printf("O");
        }
        printf("\n");
    }
}