#include <stdio.h>

int main(){
    int n, i;
    int hotDays = 0;
    double temp[10];
    double *ptr;
    double hottest, coldest;

    printf("How many days of temperature to store (1-10): ");
    scanf("%d", &n);
    while(n < 1 || n > 10){
        printf("Invalid. Enter a number from 1 to 10: ");
        scanf("%d", &n);
    }

    for(i = 0; i < n; i++){
        printf("Enter temperature for day %d: ", i + 1);
        scanf("%lf", &temp[i]);
        while(temp[i] < -10 || temp[i] > 55){
            printf("Invalid. Enter a value from -10 to 55: ");
            scanf("%lf", &temp[i]);
        }
    }

    printf("\n");
    for(i = 0; i < n; i++){
        printf("Day %d: %.1f at address %p\n", i + 1, temp[i], (void*)&temp[i]);
    }

    ptr = temp;
    hottest = *ptr;
    coldest = *ptr;

    for(i = 0; i < n; i++){
        if(*ptr > hottest){
            hottest = *ptr;
        }
        if(*ptr < coldest){
            coldest = *ptr;
        }
        if(*ptr > 40){
            hotDays++;
        }
        ptr++;
    }

    printf("\nHottest temperature : %.1f\n", hottest);
    printf("Coldest temperature : %.1f\n", coldest);
    printf("Days hotter than 40 : %d\n", hotDays);

    return 0;
}