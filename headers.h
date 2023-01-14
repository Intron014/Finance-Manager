//
// Created by me on 13/01/2023.
//

#ifndef FINANCE_MANAGER_HEADERS_H
#define FINANCE_MANAGER_HEADERS_H
#define MAX_TRANS 500
#define MAX_ACC 50
typedef struct money{
    char account[50];
    char concept[100];
}MONEY;
typedef struct transactions{
    float amount;
    char merchant[50];

}TRANS;

int add_account (MONEY *finances, int n){
    char ans;
    if(n<MAX_ACC){
        fflush(stdin);
        printf("Enter the account number: ");
        gets(finances[n].account);
        printf("Enter account description: ");
        gets(finances[n].concept);
        printf("Are you sure? (y/n): ");
        scanf("%c", &ans);
        if(ans=='N'||ans=='n'){
            printf("Your data will not be saved");
            getch();
            return 99;
        }
    }
    else
        printf("You have reached the max number of accounts\nPlease remove or modify the accounts");
}

void print_account (MONEY *finances, int n){
    int i;
    fflush(stdin);
    if(!n){
        printf("No accounts in file");
    }
    else
        for(i=0;i<n;i++){
           printf("-[%i]--\nAccount: %s\nDescription: %s\n", i,finances[i].account, finances[i].concept);
        }
}

int add_transaction(TRANS *trans, int o){
    char ans;
    if(o<MAX_TRANS){
        fflush(stdin);
        printf("Enter the amount: ");
        scanf("%f", &trans[o].amount);
        fflush(stdin);
        printf("Concept: ");
        gets(trans[o].merchant);
        printf("Are you sure? (y/n): ");
        scanf("%c", &ans);
        if(ans=='N'||ans=='n'){
            printf("Your data will not be saved");
            getch();
            return 99;
        }
    }
    else
        printf("You have reached the max number of transactions\nPlease ask for more");
}
void print_transaction(TRANS *trans, int o){
    int i;
    fflush(stdin);
    if(!o){
        printf("No accounts in file");
    }
    else
        for(i=0;i<o;i++){
            printf("-[%i]--\nAmount: %f\nMerchant: %s\n", i,trans[i].amount, trans[i].merchant);
        }
}

#endif //FINANCE_MANAGER_HEADERS_H
