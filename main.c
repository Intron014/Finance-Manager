#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "headers.h"

int main() {
    FILE *money;
    int ans, n, o;
    //Checks are run
    printf("Running checks...\n");
    if(!(money=fopen("money.dat", "rb"))){
        money=fopen("money.dat", "wb");
        n=0;
        fwrite(&n, sizeof(int), 1, money);
    }
    fread(&n, sizeof(int), 1, money);
    fread(&o, sizeof(int), 1, money);
    MONEY finances[50];
    TRANS transactions[500];
    fread(finances, sizeof(MONEY), n, money);
    fclose(money);
    printf("Done! Welcome\n");


    //Beginning of the program
    do {
        do {
            system("cls");
            printf("Menu:\n1. Add account\n2. Print all accounts\n3. Add transaction\n4. Print all transactions\n0. Exit\n-----\nWARNING: Closing without using function 0 will result in data loss\n-----\nOption: ");
            scanf("%i", &ans);
        } while (ans < 0 || ans > 5);
        switch (ans) {
            case 0: //Exit
                system("cls");
                printf("Writing data... Please wait\n");
                money = fopen("money.dat", "wb");
                fwrite(&n, sizeof(int), 1, money);
                fwrite(finances, sizeof(MONEY), n, money);
                fclose(money);
                printf("Done!\n");
                break;
            case 1: //Add Account
                system("cls");
                printf("Add Account\n-----\n");
                //printf("%i\n", n); //For debug purposes
                add_account(finances, n);
                n++;
                //printf("\n%i", n); //For debug purposes
                getch();
                break;
            case 2: //Print all accounts
                system("cls");
                printf("Print Accounts\n-----\n");
                print_account(finances, n);
                getch();
                break;
            case 3: //Add transaction
                system("cls");
                printf("Add transaction\n-----\n");
                //add_transaction();
                getch();
                break;
            case 4: //Print all transactions
                system("cls");
                printf("Print transactions\n-----\n");
                //print_transaction();
                getch();
                break;
            default: //Default (Just so CLion stops screaming at me)
                printf("Oops, you should definitely not be here!\nPlease contact you SysAdmin for more info\n");
                getch();
                break;
        }
    } while(ans);



}
