#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "headers.h"

int main() {
    FILE *money;
    int ans, n, o, r;
    char username[50], user[50];
    //User Selection
    printf("Username: ");
    gets(username);
    strcpy(user, username);
    strcat(username, ".dat");
    getch();

    //Checks are run
    printf("Running checks...\n");
    if(!(money=fopen(username, "rb"))){
        money=fopen(username, "wb");
        n=0; o=0;
        fwrite(&n, sizeof(int), 1, money);
        fwrite(&o, sizeof(int), 1, money);
    }
    fread(&n, sizeof(int), 1, money);
    fread(&o, sizeof(int), 1, money);
    MONEY finances[50];
    TRANS transactions[500];
    fread(finances, sizeof(MONEY), n, money);
    fclose(money);
    printf("Done! Welcome %s\n", user);


    //Beginning of the program
    do {
        do {
            system("cls");
            printf("Welcome to the PLACEHOLDER %s\n-----\n", user);
            printf("Menu:\n1. Add account\n2. Print all accounts\n3. Add transaction\n4. Print all transactions\n0. Exit\n-----\nWARNING: Closing without using function 0 will result in data loss\n-----");
            printf("\nDEBUG:\nn: %i\no: %i\n-----\n", n, o);
            printf("Option: ");
            scanf("%i", &ans);
        } while (ans < 0 || ans > 5);
        switch (ans) {
            case 0: //Exit
                system("cls");
                printf("Writing data... Please wait\n");
                money = fopen(username, "wb");
                fwrite(&n, sizeof(int), 1, money);
                fwrite(&o, sizeof(int), 1, money);
                fwrite(finances, sizeof(MONEY), n, money);
                fclose(money);
                printf("Done!\n");
                break;
            case 1: //Add Account
                system("cls");
                printf("Add Account\n(Accounts in file: %i)\n-----\n", n);
                //printf("%i\n", n); //For debug purposes
                r=add_account(finances, n);
                switch (r) {
                    default:
                        n++;
                        break;
                    case 99:
                        break;
                }
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
                //add_transaction(transactions, o);
                o++;
                getch();
                break;
            case 4: //Print all transactions
                system("cls");
                printf("Print transactions\n-----\n");
                //print_transaction(transactions, o);
                getch();
                break;
            default: //Default (Just so CLion stops screaming at me)
                printf("Oops, you should definitely not be here!\nPlease contact you SysAdmin for more info\n");
                getch();
                break;
        }
    } while(ans);



}
