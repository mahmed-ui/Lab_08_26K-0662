#include <stdio.h>

void printRoutes(){
    printf("Welcome to NUCES Bus Service\n");
    printf("------BUS ROUTES------\n");
    printf("Route 1: Karachi to Hyderabad for Rs.800/=\n");
    printf("Route 2: Karachi to Sukhur for Rs.2200/=\n");
    printf("Route 3: Karachi to Multan for Rs.3500/=\n");
}

int getRouteNum(void){
    int routeNum;
    printf("Enter route number: ");
    scanf("%d",&routeNum);
    return routeNum;
}

int getNumSeats(void){
    int numOfSeats;
    printf("Enter number of seats: ");
    scanf("%d",&numOfSeats);
    return numOfSeats;
}

