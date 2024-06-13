#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;

    printf("Enter the number of names you want to add: ");
    scanf("%d", &n);

    // Consume the newline character left by scanf
    getchar();

    char names[200];

    for (int i = 1; i <= n; i++)
    {
        char name[20];
        printf("Enter the %d name: ", i);

        fgets(name, sizeof(name), stdin);

        // Remove the newline character if present
        name[strcspn(name, "\n")] = 0;

        strcat(names, name);
        strcat(names, " ");
    }

    FILE *file = fopen("file.txt", "w+");

    if(file == NULL) {
        exit(0);
    }

    
    fputs(names, file);

    rewind(file);

    char newNames[200];

    fgets(newNames, sizeof(newNames), file);

    puts(newNames);

    fclose(file);
    return 0;
}