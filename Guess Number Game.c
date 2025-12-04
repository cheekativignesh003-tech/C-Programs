#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

  int number, guess ,attempts = 0;

  srand(time(0));
  number = rand()% 100 +1;
  printf("Welcome to the Number Guessing Game \n");
  printf("I have chosen a number between 1 and 100. \n");
  printf("\nCan You guess it ? \n");
  do
    {
    	printf("Enter Your Guess Number");
			scanf("%d",&guess);
			attempts ++;
			if(guess>number){
					printf("Too high Guess Try Again \n");
				}
			else if (guess<number){
				printf("Too Low Guess Try Again \n");
			}
			else{
        prinf("Congratus you guess correct in attempt %d",attempts);
      }
			
			
        
    } while (guess != number);
    
    return 0;
}