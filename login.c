#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// int searchUserName(char name[]);
void putPassword(char name[], char password[], FILE *file);

// Use SQL instead of file
int main(){
    // Variables
    char name[30];
    char password[30];

    //Get name
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);

    // Open file
    FILE *file = fopen("./password.txt", "a+");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // char line[30];
    // int n = 0;
    // while (fgets(line, sizeof(line), file)) {
    //     // Remove the newline character from the line
    //     line[strcspn(line, "\n")] = '\0';

    //     if (strcmp(line, name) == 0) {
    //         strcpy(name, "Found");
    //         break;
    //     }
    //     n++;
    // }

    // puts(name);
    // printf("%d", n);

    putPassword(name, password, file);

    // printf("Welcome Mr.");
    // puts(name);

    fclose(file);
    return 0;
}

int searchUserName(char name[]) {

}

void putPassword(char name[], char password[], FILE *file) {
    // New user
    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);

    //  string complementry span
    // Replace the newline character with empty
    name[strcspn(name, "\n")] = " ";
    strcat(name, " ");
    fputs(name, file);
    fputs(password, file);
}