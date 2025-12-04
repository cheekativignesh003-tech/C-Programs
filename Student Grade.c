# include <stdio.h>

int main()
{
int marks;
printf("Enter Your Marks(0-100): ");
scanf("%d",&marks);
if (marks>=0 && marks<28)
{
    printf("You Failed\n");
}

else if (marks>=28 && marks<35)
{
    printf("Grade is: C\n");
}
else if (marks<=35 && marks<70)
{
    printf("Grade is: B\n");
}
else if (marks<=70 && marks<90)
{
    printf("Grade is: A\n");
}
else if (marks>90 && marks<=100)
{
    printf("Grade is: A+\n");
}
else
{
    printf("Wrong input\n");
}
return 0;
}
