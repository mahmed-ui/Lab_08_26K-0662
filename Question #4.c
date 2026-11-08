#include <stdio.h>

void fareRules(void){
    printf("\n-------NUCES TAXI SERVICE------\n");
    printf("Base Fare Rs.150 will always be added.\n");
    printf("Rs.60 per KM for first 10 KM.\n");
    printf("Rs.45 per KM after that.\n");
    printf("Waiting: first 5 min free, then Rs.10 per min.\n");
    printf("Night trips (10 PM to 6 AM): extra 25%%.\n");
}

int getDistance(void){
    int distance;
    printf("Enter distance in KM (1-200): ");
    scanf("%d", &distance);
    return distance;
}

int getWaitingTime(void){
    int waitingTime;
    printf("Enter waiting time in minutes (0-120): ");
    scanf("%d", &waitingTime);
    return waitingTime;
}

int getHour(void){
    int hour;
    printf("Enter hour of the trip (0-23): ");
    scanf("%d", &hour);
    return hour;
}

int findDistanceCharge(int distance){
    if(distance > 10){
        return 150 + (10 * 60) + ((distance - 10) * 45);
    }else{
        return 150 + (distance * 60);
    }
}

int findWaitingCharge(int waitingTime){
    if(waitingTime <= 5){
        return 0;
    }else{
        return (waitingTime - 5) * 10;
    }
}

double nightCharge(double fare, int hour){
    if(hour >= 22 || hour < 6){
        return fare + 0.25 * fare;
    }
    return fare;
}

void printReceipt(int distance, int waitingTime, double finalFare){
    printf("\n------TRIP RECEIPT------\n");
    printf("Distance   : %d km\n", distance);
    printf("Waiting    : %d min\n", waitingTime);
    printf("Final Fare : Rs.%.2f\n", finalFare);
    printf("------------------------\n");
}

int main(){
    int i, distance, waitingTime, hour;
    double fare, finalFare;
    double totalEarnings = 0, highestFare = 0;

    fareRules();

    for(i = 1; i <= 3; i++){
        printf("\nTrip %d\n", i);

        do{
            distance = getDistance();
        } while(distance < 1 || distance > 200);

        do{
            waitingTime = getWaitingTime();
        } while(waitingTime < 0 || waitingTime > 120);

        do{
            hour = getHour();
        } while(hour < 0 || hour > 23);

        fare = findDistanceCharge(distance) + findWaitingCharge(waitingTime);
        finalFare = nightCharge(fare, hour);

        printReceipt(distance, waitingTime, finalFare);

        totalEarnings += finalFare;
        if(finalFare > highestFare)
            highestFare = finalFare;
    }

    printf("\nTotal earnings: Rs.%.2f\n", totalEarnings);
    printf("Highest fare  : Rs.%.2f\n", highestFare);
    return 0;
}