#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct{
    unsigned day, month, year;
    char account[50];
    char concept[100];
    float price;
}MONEY;

/*int add_account (FILE *money, MONEY *finances){
    fflush(stdin);
    printf("Enter the account number: ");
    gets(finances->account);
    printf("Account number: %s", finances->account);
    fwrite(finances, sizeof(MONEY), 1, money);
}

int read_account (FILE *money, MONEY *finances){
    int i;
    char accounts[50];
    fflush(stdin);
    for(i=0;finances->account;i++){
        fgets(accounts, 1, money);
        printf("%s", accounts);
    }
}*/

int main() {
    MONEY finances[500];
    FILE *money;
    int ans, b, c, d;
    //Checks are run
    printf("Running checks...\n");
    if(!(money=fopen("money.dat", "ab"))){
        printf("Error al abrir el fichero");
        return 1;
    }
    printf("Done! Welcome\n");

    //Beginning of the program
    do {
        do {
            system("cls");
            printf("Menu:\n1. Add account\n2. New Transaction\n3. Read Accounts\n0. Exit\n");
            scanf("%i", &ans);
        } while (ans < 0 || ans > 4);
        switch (ans) {
            case 0:
                system("cls");
                printf("System Shutdown...\n");
                break;
            case 1:
                system("cls");
                printf("Add Account\n-----\n");
                //add_account(money, &finances);
                printf("N: ");
                getch();
                break;
            case 3:
                system("cls");
                printf("Read Account\n-----\n");
                //read_account(money, &finances);
                getch();
                break;
            default:0;
        }
    } while(ans);



}
