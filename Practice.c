#include<stdio.h>


int main()
{
/*// Q.no:1    
int side;

printf("Enter Side of sqaure:");            //print function to display output on screen
scanf("%d",& side);                         //& is address of operator to locate variable
                                            //%d is format specifier for int
                                            //scanf is used to take input from uset
printf("Area of sqaure: %d", side * side);

//Q.no:2
float radius;

printf("Enter radius of cricle: ");
scanf("%f", & radius);                              //%f is format specifier for float
printf("Area of circle: %f", 3.14*radius*radius);

//Q.no:3
int a = 5+2 / 2*3;

printf("Enter a Operation: ");
//scanf("%f", &a);
printf("a is %d \n",a);                             // \n is new line character

//Q.no:4
int x;
printf("Enter any number:");
scanf("%d",&x);
printf("%d",x % 2==0);

//Q.no:5
int isSunday = 1;
int isShowing = 1;
printf("%d \n", isSunday && isShowing);

//Q.no:6
int isMonday = 1;
int isRaining = 1;
printf("%d \n", isMonday && isRaining);

//Q.no:7
int x;
printf("Enter any number: ");
scanf("%d",&x);
printf("%d", x>9 && x<100);

//Q.no:8
int age;
printf("Enter Your Age: ");
scanf("%d",&age);
if(age>=18)
{   
    printf("Adult");
}
else
{
    printf("Not Adult");

}
//switch case
//Q.no:9
int day;
printf("Enter day(1-7): ");
scanf("%d",&day);
switch (day)
{
case 1:
    printf("Monday");
    break;

case 2:
    printf("Tuesday");
    break;

case 3:
    printf("Wednsday");
    break;

case 4:
    printf("Thursday");
    break;

case 5:
    printf("Friday");
    break;

case 6:
    printf("Saturday");
    break;
    
case 7:
    printf("Sunday");
    break;
default:
    printf("Wrong input");
    break;
}

//Q.no:10
int marks;
printf("Enter Marks(0-100): ");
scanf("%d",&marks);
if (marks >30 && marks<=100)
{
    printf("You Passed");
}
else if (marks<=0 && marks<=30)
{
    printf("You Failed");
}

else
{
    printf("Wrong Input");
}
//if, else if, else condition
Q.no:11
int marks;
printf("Enter Your Marks(0-100): ");
scanf("%d",&marks);
if (marks>=0 && marks<28)
{
    printf("You Failed");
}

else if (marks>=28 && marks<35)
{
    printf("Grade is: C");
}
else if (marks<=35 && marks<70)
{
    printf("Grade is: B");
}
else if (marks<=70 && marks<90)
{
    printf("Grade is: A");
}
else if (marks<90 && marks<=100)
{
    printf("Grade is: A+");
}
else
{
    printf("Wrong input");
}
//Q.no:12
char ch;                            //char is a data type to store single character
printf("Enter your Character: ");
scanf("%c",&ch);                    //%c is format specifier for character
if (ch >='A' && ch <='Z')
{
    printf("It's an Uppercass Letter");
}
else if (ch >= 'a' && ch <= 'z')
{
    printf("It's a Lowercass Letter");
}
else
{
    printf("Not English Letter");
}
//Q.no:13
//for loop
for ( int i=0; i<4; i++)                  // for loop syntax
{
    printf("%d \n",i);
}

//increment and decrement operator
//increment operator
//++i;    //pre-increment   use,then increase
//i++;    //post-increment  increase,then use
int i = 1;
printf("%d \n", i++);          //post-increment
printf("%d \n", i);
printf("%d \n", ++i);          //pre-increment
printf("%d \n", i);
//decrement operator
//--i;    //pre-decrement   use,then decrease
//i--;    //post-decrement  decrease,then use 
int i = 5;
printf("%d \n", i--);          //post-decrement             
printf("%d \n", i);
printf("%d \n", --i);          //pre-decrement
printf("%d \n", i);*
//Q.no:14
//while loop
int n;
printf("Enter any number: ");
scanf("%d",&n);
//int i=0;
int i=10; 
while(i >= n)                  //while loop syntax
{
    printf("%d \n",i);
    i++;
}
//do Whileloop
int i = 0;
do
{
    printf("%d \n",i);
    i++;
}While (i <= 10);

int n;
printf("Enter any number: ");
scanf("%d",&n);
int sum = 0;
for(int i=1;i<=n;i++)
{
    sum =sum + i;                            //sum+=1 or sum = sum+i
}

printf("Sum is: %d \n",sum);

int age = 17;
int* ptr = &age;
printf("%d \n", age);
printf("%p \n",ptr);
printf("%d \n",*ptr);
ptr++;
printf("%p \n",ptr);
printf("%d \n",*ptr); 
(*ptr)++;
printf("%p \n",ptr);
printf("%d \n",*ptr);

*/


int num[5] = {2,3,5,7,11};
printf("%d",num[3]);


return 0;                                   //return 0 means program ended successfully   
}