# include<stdio.h>
# include<stdlib.h>

int main() {
    int n, *ptr;
    

     printf("Enter the number of elements: ");
     scanf("%d", &n);

    ptr = (int *)calloc(n ,sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("%d", ptr[i]);

    }
    printf("\n ji \n");

    ptr = realloc(ptr,(n+2) * sizeof(int));
    for (int i = 0; i < n+2; i++) {
        printf("%d", ptr[i]);
    }

    free(ptr);
    return 0;
} 