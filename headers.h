//
// Created by me on 13/01/2023.
//

#ifndef FINANCE_MANAGER_HEADERS_H
#define FINANCE_MANAGER_HEADERS_H

typedef struct{
    char account[50];
    char concept[100];
}MONEY;

int passthrough (MONEY *finances){
    FILE * money;
    int i;
    money=fopen("money.dat", "rb");
    for(i=0;fread(&finances[i].concept, sizeof(MONEY), 1, money);i++){
        printf("CON:%s\n%i\n\n", finances[i].concept, i);
    }
    rewind(money);
    for(i=0;fread(&finances[i].account, sizeof(MONEY), 1, money);i++){
        printf("AC:%s\n%i\n\n", finances[i].account, i);
    }
}

void add_account (MONEY *finances){
    FILE * money;
    money=fopen("money.dat", "ab");
    fflush(stdin);
    printf("Enter the account number: ");
    gets(finances[0].account);
    printf("Enter account concept: ");
    gets(finances[0].concept);
    printf("Account number: %s\nDescription: %s", finances[0].account, finances[0].concept);
    fwrite(finances, sizeof(MONEY), 1, money);
    fclose(money);
}

void print_account (MONEY *finances){
    FILE * money;
    money=fopen("money.dat", "rb");
    int i;
    char accounts[50];
    fflush(stdin);
    printf("%s\n%s\n----\n", finances->account, finances->concept);
    /*for(i=0;i<50;i++){
        printf("%s\n%s\n----\n", finances[i].account, finances[i].concept);
    }*/
    fclose(money);
}

void add_transaction(MONEY *finances);
void print_transaction(MONEY *finances);

#endif //FINANCE_MANAGER_HEADERS_H
