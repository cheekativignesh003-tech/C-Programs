# include<stdio.h>
void Function(int x, int y){
     int w = x;
     x = y;
     y = w;
     printf("In the Function \n x = %d \n y = %d \n", x, y);
}    

int main(){
    int a=10, b=20;
    Function(a,b);
    printf("In the Caller \n a = %d \n b = %d \n", a, b);
    return 0; 
}