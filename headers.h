//
// Created by me on 13/01/2023.
//

#ifndef FINANCE_MANAGER_HEADERS_H
#define FINANCE_MANAGER_HEADERS_H

typedef struct money{
    char account[50];
    char concept[100];
}MONEY;

void add_account (MONEY *finances, int n){
    fflush(stdin);
    printf("Enter the account number: ");
    gets(finances[n].account);
    printf("Enter account concept: ");
    gets(finances[n].concept);
    printf("Account number: %s\nDescription: %s\n", finances[n].account, finances[n].concept);
}

void print_account (MONEY *finances, int n){
    int i;
    fflush(stdin);
    if(!n){
        printf("No accounts in file");
    }
    else
        for(i=0;i<n;i++){
           printf("%s\n%s\n----\n", finances[i].account, finances[i].concept);
        }
}

void add_transaction(MONEY *finances);
void print_transaction(MONEY *finances);

#endif //FINANCE_MANAGER_HEADERS_H
