#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void RegisterUser(char *name);


// Use SQL instead of file
int main(){
    char name[50];
    char pass[50];

    //Get name
    printf("Enter your name: ");
    scanf("%s", name);

    // Open file
    FILE *file = fopen("./password.txt", "a+");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }


    //Check user
    char tempName[50];
    int state = 1;

    while (fscanf(file, "%s%s", tempName, pass) != EOF) {
        if (strcmp(name, tempName) == 0) {
            strcpy(name, tempName);
            state = 0;
            break;
        }
    }
    if (state == 0 ) {
        char tempPass[50];

        int i = 3;
        printf("Welcome back %s \n Enter your password: ", name);

        while (i >= 1)
        {
            scanf("%s", tempPass);

            if (strcmp(pass, tempPass) == 0) {
                printf("Logged In, enjoy the service");
                return 0;
            }

            i--;
            printf("You have entered the wrong password\n Re enter your password\n You have %d attempts left: ", i);
        }

        printf("\nYou are logged out of the portal");
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