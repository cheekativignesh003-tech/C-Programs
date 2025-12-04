# include<stdio.h>

static float balance = 0.0;

void deposit(float amount){
  if(amount>0){
    balance+=amount;
    printf("%.2f deposit sucessfully\n",amount);
  }
  else{
    printf("Invalid deposit Amount.\n");
  }
  
}
void withdraw(float amount){
  if(amount>0 &&amount<=balance){
    balance-=amount;
    printf("%.2f withdraw successfully\n",amount);
  }
  else if (amount>balance){
    printf("insufficient Balance.\n");
  }
  else{
    printf("Invalid withdrawal Amount.\n");
  }
}
void checkbalance(){
  printf("Balance is %.2f",balance);
}
int main(){
  int choice;
  float amount;
  while(1){
    printf("\n--- Simple Banking System ---\n");
    printf("1. Deposit\n");
    printf("2. Withdraw\n");
    printf("3. Check Balance\n");
    printf("4. Exit\n");
    printf("Enter Your Choice: ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
      printf("Enter Deposit Amount: ");
      scanf("%f",&amount);
      deposit(amount);
      break;

    case 2:
      printf("Enter Withdrawal Amount: ");
      scanf("%f",&amount);
      withdraw(amount);
      break;
    case 3:
      checkbalance();
      break;
    case 4:
      printf("Thank for using The Bank System");
      return 0;
    default:
      printf("Invaid Choice Please Try Again");
    }
  }
  return 0;
}