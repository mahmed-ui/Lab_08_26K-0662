#include <stdio.h>

void printPackages(){
    printf("----------Recharge Packages---------\n");
    printf("(3-Days)--------Press 1 for Rs.100\n");
    printf("(Weekly-Prime)--Press 2 for Rs.200\n");
    printf("(15-Days)-------Press 3 for Rs.500\n");
    printf("(Monthly-Prime)-Press 4 for Rs.1000\n");
}

int getPackNumber(void){
    int pack;
    printf("Enter package number: \n");
    scanf("%d",&pack);
    return pack;
}

long long getMobile(void){
    long long mobile;
    printf("Enter your mobile number (11-Digits) : \n");
    scanf("%lld",&mobile);
    return mobile;
}

int getAmount(int pack){
    switch(pack){
        case 1: return 100;
        case 2: return 200;
        case 3: return 500;
        case 4: return 1000;
        default: return 0;
    }
}

double addTax(double amount){
    return amount + amount * 0.15;
}

double getBonus(double amount){
    if(amount>=500){
        return amount*0.10;
    }
    return 0;
}

void printSlip(long long mobile, double amount, double tax, double totalBalance){
    printf("\n------Recharge Slip------\n");
    printf("Mobile Number : %011lld\n", mobile);
    printf("Amount        : Rs.%.2f\n", amount);
    printf("Tax (15%%)     : Rs.%.2f\n", tax);
    printf("Total Balance : Rs.%.2f\n", totalBalance);
    printf("-------------------------\n\n");
}

int main(){
    int amount,i,pack;
    long long mobile;
    double withTax,tax,bonus,totalBalance;
    double totalSpent=0;

    for(i=1;i<=3;i++){
        printPackages();
        pack=getPackNumber();
        amount=getAmount(pack);
        if(amount==0){
            printf("Invalid pack number, try again.\n");
            i--;
            continue;
        }
        mobile=getMobile();
        withTax=addTax(amount);
        tax=withTax-amount;
        bonus=getBonus(amount);
        totalBalance=bonus+amount;

        printSlip(mobile,amount,tax,totalBalance);
        totalSpent+=withTax;

    }
    printf("Total money spent: Rs.%.2f\n", totalSpent);
    return 0;

}