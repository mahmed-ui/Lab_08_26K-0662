#include <stdio.h>

void printRoomOpt(void){
    printf("Welcome to NUCES Hospital\n");
    printf("------ROOM TYPES------\n");
    printf("1. General Ward  Rs.1500/day\n");
    printf("2. Semi-Private  Rs.3500/day\n");
    printf("3. Private       Rs.6000/day\n");
}

int getRoomType(void){
    int roomType;
    printf("Enter room type (1-3): ");
    scanf("%d", &roomType);
    return roomType;
}

int getNumOfDays(void){
    int days;
    printf("Enter number of days stayed (1-30): ");
    scanf("%d", &days);
    return days;
}

int getRoomCharges(int roomType, int days){
    switch(roomType){
        case 1: return 1500 * days;
        case 2: return 3500 * days;
        case 3: return 6000 * days;
        default: return 0;
    }
}

double getMedicineCharges(void){
    double medicineBill;
    printf("Enter medicine bill amount: ");
    scanf("%lf", &medicineBill);
    return medicineBill + medicineBill * 0.05;
}

double getFinalAmount(double total, int days){
    if(days >= 7)
        return total - total * 0.08;
    return total;
}

void printFinalBill(int roomType, int days, int roomCharges,
                    double medicineCharges, double finalAmount){
    printf("\n------FINAL BILL------\n");
    switch(roomType){
        case 1: printf("Room Type       : General Ward\n"); break;
        case 2: printf("Room Type       : Semi-Private\n"); break;
        case 3: printf("Room Type       : Private\n");      break;
    }
    printf("Days Stayed     : %d\n", days);
    printf("Room Charges    : Rs.%d\n", roomCharges);
    printf("Medicine Charges: Rs.%.2f\n", medicineCharges);
    printf("Final Amount    : Rs.%.2f\n", finalAmount);
    printf("----------------------\n");
}

int main(){
    int roomType, days, roomCharges;
    double medicineCharges, total, finalAmount;
    char senior;

    printRoomOpt();

    do{
        roomType = getRoomType();
    } while(roomType < 1 || roomType > 3);

    do{
        days = getNumOfDays();
    } while(days < 1 || days > 30);

    roomCharges = getRoomCharges(roomType, days);
    medicineCharges = getMedicineCharges();

    total = roomCharges + medicineCharges;
    finalAmount = getFinalAmount(total, days);

    printf("Is the patient a senior citizen? (y/n): ");
    scanf(" %c", &senior);
    if(senior == 'y' || senior == 'Y'){
        finalAmount -= 1000;
        if(finalAmount < 0)
            finalAmount = 0;
    }

    printFinalBill(roomType, days, roomCharges, medicineCharges, finalAmount);
    return 0;
}