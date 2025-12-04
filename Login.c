#include <stdio.h>
#include <string.h>

int main() 

{
    char username[50];
    char password[50];
    const char correct_username[] = "Vignesh";
    const char correct_password[] = "V@9908$C";

    printf("Enter Your Username: ");
    scanf("%s", username);

    printf("Enter Your Password: ");
    scanf("%s", password);

    if (strcmp(username, correct_username) == 0 && strcmp(password, correct_password) == 0)
    {    printf("\nLogin successful!\n");
        printf("Thank you Boss\n");
    } else {
        printf("\nLogin failed. Invalid username or password.\n");
    }

    return 0;
}