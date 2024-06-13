#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void RegisterUser(char *name);
int checkIfNewUser(char *name, char *pass);
void checkPassword(char *name, char *pass);


// Use SQL instead of file
int main(){
    char name[50];
    char pass[50];

    //Get name
    printf("Enter your name: ");
    scanf("%s", name);

    // Open file
    FILE *file = fopen("./password.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    //Check if new user
    int state = checkIfNewUser(name, pass);


    // Old user
    if (state == 0 ) {
        // CheckPassword
        checkPassword(name, pass);
        return 0;
    }

    // New user
    RegisterUser(name);


    fclose(file);
    return 0;
}

void RegisterUser(char *name) {
    FILE *file = fopen("./password.txt", "a");

    char pass[50];
    printf("Welcome new user\n Enter your password: ");
    scanf("%s", pass);

    fprintf(file, "%s %s\n", name, pass);

}

int checkIfNewUser(char *name, char *pass) {
    FILE *file = fopen("./password.txt", "r");
    char tempName[50];

    while (fscanf(file, "%s%s", tempName, pass) != EOF) {
        if (strcmp(name, tempName) == 0) {
            strcpy(name, tempName);
            return 0;
        }
    }

    return 1;

}

void checkPassword(char *name, char *pass) {
        char tempPass[50];

        int i = 3;
        printf("Welcome back %s \n Enter your password: ", name);

        while (i >= 1)
        {
            scanf("%s", tempPass);

            if (strcmp(pass, tempPass) == 0) {
                printf("Logged In, enjoy the service");
                return;
            }
            i--;
            printf("You have entered the wrong password\n Re enter your password\n You have %d attempts left: ", i);
        }
        printf("\nYou are logged out of the portal");
}