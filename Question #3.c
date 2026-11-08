#include <stdio.h>

void printRoutes(void){
    printf("\n------BUS ROUTES------\n");
    printf("Route 1: Karachi to Hyderabad - Rs.800\n");
    printf("Route 2: Karachi to Sukkur    - Rs.2200\n");
    printf("Route 3: Karachi to Multan    - Rs.3500\n");
}

int getRouteNum(void){
    int routeNum;
    printf("Enter route number (1-3): ");
    scanf("%d", &routeNum);
    return routeNum;
}

int getNumSeats(void){
    int numOfSeats;
    printf("Enter number of seats (1-6): ");
    scanf("%d", &numOfSeats);
    return numOfSeats;
}

int findFare(int routeNum){
    switch(routeNum){
        case 1: return 800;
        case 2: return 2200;
        case 3: return 3500;
        default: return 0;
    }
}

int findTotalFare(int seatFare, int numOfSeats){
    return seatFare * numOfSeats;
}

char getSeatType(void){
    char seatType;
    printf("Enter seat type (E for Economy, B for Business): ");
    scanf(" %c", &seatType);
    return seatType;
}

double addSeatCharge(double totalFare, char seatType){
    if(seatType == 'B' || seatType == 'b')
        return totalFare + totalFare * 0.30;
    return totalFare;
}

void printTicket(int routeNum, int numOfSeats, char seatType, double finalFare){
    printf("\n------YOUR TICKET------\n");
    switch(routeNum){
        case 1: printf("Route     : Karachi to Hyderabad\n"); break;
        case 2: printf("Route     : Karachi to Sukkur\n");    break;
        case 3: printf("Route     : Karachi to Multan\n");    break;
    }
    printf("Seats     : %d\n", numOfSeats);
    if(seatType == 'B' || seatType == 'b')
        printf("Seat Type : Business\n");
    else
        printf("Seat Type : Economy\n");
    printf("Final Fare: Rs.%.2f\n", finalFare);
    printf("-----------------------\n");
}

int main(){
    int routeNum, numOfSeats, seatFare, totalFare, i;
    char seatType;
    double finalFare, companyEarnings = 0.0;

    printf("Welcome to NUCES Bus Service\n");
    for(i = 1; i <= 2; i++){
        printf("\nPassenger %d\n", i);
        printRoutes();

        do{
            routeNum = getRouteNum();
        } while(routeNum < 1 || routeNum > 3);

        do{
            numOfSeats = getNumSeats();
        } while(numOfSeats < 1 || numOfSeats > 6);

        do{
            seatType = getSeatType();
        } while(seatType != 'E' && seatType != 'e' &&
                seatType != 'B' && seatType != 'b');

        seatFare = findFare(routeNum);
        totalFare = findTotalFare(seatFare, numOfSeats);
        finalFare = addSeatCharge(totalFare, seatType);

        printTicket(routeNum, numOfSeats, seatType, finalFare);
        companyEarnings += finalFare;
    }

    printf("\nTotal company earnings: Rs.%.2f\n", companyEarnings);
    return 0;
}