#include <stdio.h>


int findMax(int *marks, int n){
    int max=*marks;
    int i;
    for(i=1;i<n;i++){
        marks++;
        if(*marks > max){
            max=*marks;
        }
    }
    return max;
}

int findMin(int *marks, int n){
    int min=*marks;
    int i;
    for(i=1;i<n;i++){
        marks++;
        if(*marks<min){
            min=*marks;
        }
    }
    return min;
}

double findAverage(int *marks, int n){
    int total=0;
    int i;
    for(i=0;i<n;i++){
        total+=*marks;
        marks++;
    }
    return (double)total/n;
}

int countAboveAverage(int *marks, int n, double average){
    int i,count=0;
    for(i=0;i<n;i++){
        if(*marks>average){
            count++;
        }
        *marks++;
    }
    return count;
}

void reverseArray(int *marks, int n){
    int i,temp;
    for(i=0;i<n/2;i++){
        temp=*(marks+i);
        *(marks+i)=*(marks+n-1-i);
        *(marks+n-1-i)=temp;
    }
}

int searchMark(int *marks, int n,int key){
    int i;
    for(i=0;i<n;i++){
        if(*marks==key){
            return i+1;
        }
        marks++;
    }
    return -1;
}

int main(){
    int marks[10]={45,69,74,72,92,59,84,73,98,81};
    int i;

    printf("Maximum marks: %d\n",findMax(marks,10));
    printf("Minimum marks: %d\n",findMin(marks,10));
    printf("Average marks: %.2f\n",findAverage(marks,10));
    printf("Number of students above average: %d\n",countAboveAverage(marks,10,findAverage(marks,10)));

    printf("\nOriginal Array:\n");
    for(i=0;i<10;i++){
        printf("%d\t",marks[i]);
    }

    reverseArray(marks,10);
    printf("\n\nReversed Array:\n");
    for(i=0;i<10;i++){
        printf("%d\t",marks[i]);
    }

    printf("\n");
    int key,position;
    printf("Enter specific marks to search in array: ");
    scanf("%d",&key);
    position=searchMark(marks,10,key);
    if(position==-1){
        printf("Marks not found.\n");
    }else{
        printf("Marks found at Position %d\n",position);
    }

}