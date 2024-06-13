#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void RegisterUser(char *name);
int isUserPresent(char *name, char *pass);
void checkPassword(char *name, char *pass);


// Use SQL instead of file
int main(){
    char name[50];
    char pass[50];

    int inp;
    printf("Welcome to the App\nare you a\n 1)Existing user\n 2)New user\n");
    scanf("%d", &inp);

    // Open file
    FILE *file = fopen("./password.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    switch (inp){
        // existing user
        case 1:
            printf("Enter your username: ");
            scanf("%s", name);
            int state = isUserPresent(name, pass);
            switch (state) {
                case 1:
                    checkPassword(name, pass);
                    break;
                case 0:
                    printf("User name not present, try again");
                    exit(1);
            }
            break;

        // New user
        case 2:
            int i = 0;
            printf("Enter your username: ");
            while (i == 0)
            {
                scanf("%s", name);
                int state = isUserPresent(name, pass);
                if (state == 0) {
                    i = 1;
                    break;
                } else if (state == 1){
                    printf("User already exist, reenter your username: ");
                }
                
            }
            RegisterUser(name);
            break;

        default:
            printf("Unsuccesful login attempt");
            exit(1);
    }

    fclose(file);
    return 0;
}

void handleExistingUser(char *name, char *pass) {
    printf("Enter your username: ");
    scanf("%s", name);
    int state = isUserPresent(name, pass);
    switch (state) {
        case 1:
            checkPassword(name, pass);
            break;
        case 0:
            printf("User name not present, try again");
            exit(1);
    }
}

void RegisterUser(char *name) {
    FILE *file = fopen("./password.txt", "a");

    char pass[50];
    printf("Welcome new user\n Enter your password: ");
    scanf("%s", pass);

    fprintf(file, "%s %s\n", name, pass);

    printf("You are succesfully registered!");
}

int isUserPresent(char *name, char *pass) {
    FILE *file = fopen("./password.txt", "r");
    char tempName[50];

    while (fscanf(file, "%s%s", tempName, pass) != EOF) {
        if (strcmp(name, tempName) == 0) {
            strcpy(name, tempName);
            return 1;
        }
    }

    return 0;

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
        exit(1);
}