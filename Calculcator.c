#include <stdio.h>

int main() {
    char operator;
    int a, b, result;
    char choice;

    do {

        printf("Enter a number: \n");
        scanf("%d", &a);
        printf("a = %d",a);
        printf("Enter a number: \n");
        scanf("%d", &b);
        printf("b = %d",b);
        printf("\nEnter an operator (+, -, *, /): ");
        scanf(" %c", &operator);

        switch(operator) {
            case '+':
                result = a + b;
                printf("Result: %d\n", result);
                break;
            case '-':
                result = a - b;
                printf("Result: %d\n", result);
                break;
            case '*':
                result = a * b;
                printf("Result: %d\n", result);
                break;
            case '/':
                if (b != 0)
                    result = a / b;
                else {
                    printf("Error! Division by zero.\n");
                    break;
                }
                printf("Result: %d\n", result);
                break;
            default:
                printf("Invalid operator!\n");
        }

        printf("\nDo you want to perform another calculation? (y/n): ");
        scanf(" %c", &choice);

    } while(choice == 'y' || choice == 'Y');

    printf("\nCalculator exited.\n");

    return 0;
}
