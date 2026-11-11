#include <stdio.h>
#include <string.h>


void readMarks(int *m1, int *m2, int *m3){
    printf("Enter mark 1 (0-100): ");
    scanf("%d", m1);
    while(*m1 < 0 || *m1 > 100){
        printf("Invalid. Enter mark 1 (0-100): ");
        scanf("%d", m1);
    }

    printf("Enter mark 2 (0-100): ");
    scanf("%d", m2);
    while(*m2 < 0 || *m2 > 100){
        printf("Invalid. Enter mark 2 (0-100): ");
        scanf("%d", m2);
    }

    printf("Enter mark 3 (0-100): ");
    scanf("%d", m3);
    while(*m3 < 0 || *m3 > 100){
        printf("Invalid. Enter mark 3 (0-100): ");
        scanf("%d", m3);
    }
}

void swapMarks(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortMarks(int *m1, int *m2, int *m3){
    if(*m1 < *m2)
        swapMarks(m1, m2);
    if(*m2 < *m3)
        swapMarks(m2, m3);
    if(*m1 < *m2)
        swapMarks(m1, m2);
}

void addGraceMarks(int *mark, int grace){
    int needed;
    if(*mark >= 35 && *mark <= 39){
        needed = 40 - *mark;
        if(grace >= needed)
            *mark = *mark + needed;
        else
            *mark = *mark + grace;
    }
}


void calculateStats(int m1, int m2, int m3,
                    int *total, double *average, int *highest, int *lowest){
    *total = m1 + m2 + m3;
    *average = *total / 3.0;

    *highest = m1;
    if(m2 > *highest) *highest = m2;
    if(m3 > *highest) *highest = m3;

    *lowest = m1;
    if(m2 < *lowest) *lowest = m2;
    if(m3 < *lowest) *lowest = m3;
}

void findGrade(double avg, char *grade, char *remarks){
    if(avg >= 80){
        *grade = 'A';
        strcpy(remarks, "Excellent");
    }
    else if(avg >= 60){
        *grade = 'B';
        strcpy(remarks, "Good");
    }
    else{
        *grade = 'C';
        strcpy(remarks, "Needs Improvement");
    }
}


void incrementByValue(int x){
    x = x + 1;
}

void incrementByReference(int *x){
    *x = *x + 1;
}

int main(){
    int i;
    int m1, m2, m3;
    int total, highest, lowest;
    double average;
    char grade;
    char remarks[20];
    int grace = 5;

    int totals[5];
    double averages[5];
    char grades[5];
    char allRemarks[5][20];

    for(i = 0; i < 5; i++){
        printf("\n--- Student %d ---\n", i + 1);
        readMarks(&m1, &m2, &m3);

        addGraceMarks(&m1, grace);
        addGraceMarks(&m2, grace);
        addGraceMarks(&m3, grace);

        sortMarks(&m1, &m2, &m3);
        printf("Marks (highest to lowest): %d %d %d\n", m1, m2, m3);

        calculateStats(m1, m2, m3, &total, &average, &highest, &lowest);
        printf("Highest: %d, Lowest: %d\n", highest, lowest);

        findGrade(average, &grade, remarks);

        totals[i] = total;
        averages[i] = average;
        grades[i] = grade;
        strcpy(allRemarks[i], remarks);
    }


    printf("\n%-10s %-8s %-10s %-7s %-20s\n",
           "Student", "Total", "Average", "Grade", "Remarks");
    printf("----------------------------------------------------------\n");
    for(i = 0; i < 5; i++){
        printf("%-10d %-8d %-10.2f %-7c %-20s\n",
               i + 1, totals[i], averages[i], grades[i], allRemarks[i]);
    }


    int num = 10;
    printf("\nBefore: num = %d\n", num);
    incrementByValue(num);
    printf("After incrementByValue    : num = %d\n", num);
    incrementByReference(&num);
    printf("After incrementByReference: num = %d\n", num);

    return 0;
}