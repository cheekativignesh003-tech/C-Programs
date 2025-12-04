#include<stdio.h>
#include<string.h>
struct car
{
    char name[50];
    char model[50];
    int year;
};

int main(){
struct car c1;
c1.year = 2023;
strcpy(c1.name ,"BMW");
strcpy(c1.model ,"X3");
struct car c2 = {"Audi", "A6", 2022};

printf("Name: %s, Model: %s, Year: %d\n", c1.name, c1.model, c1.year);
printf("Name: %s\nYear: %d\nModel: %s\n", c2.name, c2.year, c2.model);
return 0;
}