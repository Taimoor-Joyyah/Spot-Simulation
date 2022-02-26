#include <stdio.h>
#include <stdlib.h>

void getfloat(float *floatdata); //getfloat(&data); Enter float without newline. press space or + to complete.

void main()
{
    float USDBalance, CoinPrice, CoinBalance, TotalBalance;
    USDBalance = CoinPrice = CoinBalance = TotalBalance = 0;
    float Amount, OldPrice;
    char Key;

    printf("This Program is a Spot Market Simulator\n");
    printf("Enter Starting Data\n\n");
    printf("Balance    : ");
    getfloat(&USDBalance);
    printf("\nCoin Price : ");
    getfloat(&CoinPrice);

    printf("\n\nPress 1.Buy 2.Sell 3.ChangePrice 4.Exit");
    printf("\n______________________________________________________________________________________________\n");
    printf("Function\t\t\tCoinPrice\tCoinBalance\tUSDBalance\tTotalBalance\n\n\t\t");

    do {
        TotalBalance = USDBalance + CoinBalance;
        printf("\t%c%14.2f %c%14.2f %c%14.2f%c %14.2f %c\n", 179, CoinPrice, 179, CoinBalance, 179, USDBalance, 179, TotalBalance, 179);

        switch(Key = getch()) {
            case '1':
                printf("BuyAmount  : ");
                getfloat(&Amount);
                CoinBalance += Amount;
                USDBalance -= Amount;
                break;
            case '2':
                printf("SellAmount : ");
                getfloat(&Amount);
                CoinBalance -= Amount;
                USDBalance += Amount;
                break;
            case '3':
                OldPrice = CoinPrice;
                printf("NewPrice   : ");
                getfloat(&CoinPrice);
                if(OldPrice != 0)
                    CoinBalance *= CoinPrice / OldPrice;
                else
                    CoinBalance = 0;
                break;
            default:
                printf("\t\t");
        }
    } while(Key != '4');

    printf("\n\nPress any Key to Exit...");
    getch();
    return;
}

void getfloat(float *floatdata) {
    char num[16] = {0};
    int i, j;
    for(i = 0; num[i-1] != 13 && num[i-1] != ' '; i++) {
        num[i] = getch();
        if(num[i] == '\b') {
            printf("\b%c\b", 0);
            i-=2;
        }
        else if(num[i] != 13)
            printf("%c", num[i]);
    }
    for(j = 0; j < 16-i-6; j++) printf(" ");
    *floatdata = atof(num);
}
