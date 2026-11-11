#include <stdio.h>
#include <stdlib.h>


int getStartSize(void){
    int n;
    printf("Enter starting number of items (3-8): ");
    scanf("%d", &n);
    while(n<3 || n>8){
        printf("Invalid. Enter a number from 3 to 8: ");
        scanf("%d",&n);
    }
    return n;
}

void readStock(int *stock, int n){
    int i;
    for(i = 0; i < n; i++){
        printf("Enter stock of item %d: ", i + 1);
        scanf("%d", stock + i);
    }
}

void showMenu(void){
    printf("\n------ GROCERY STOCK MENU ------\n");
    printf("1. Display stock\n");
    printf("2. Update stock of one item\n");
    printf("3. Insert a new item\n");
    printf("4. Delete an item\n");
    printf("5. Sort stock\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

void printSummary(int *stock, int n){
    int i;
    int total = 0;
    int lowest = *stock;
    int lowestPos = 1;

    for(i = 0; i < n; i++){
        total = total + *(stock + i);
        if(*(stock + i) < lowest){
            lowest = *(stock + i);
            lowestPos = i + 1;
        }
    }
    printf("Total stock : %d\n", total);
    printf("Lowest stock: %d (item %d)\n", lowest, lowestPos);
}


void displayStock(int *stock, int n){
    int i;
    printf("\n");
    for(i = 0; i < n; i++){
        printf("Item %d: %d\n", i + 1, *(stock + i));
    }
}

void updateStock(int *stock, int n){
    int pos, value;
    printf("Enter position to update (1-%d): ", n);
    scanf("%d", &pos);
    if(pos < 1 || pos > n){
        printf("Invalid position.\n");
        return;
    }
    printf("Enter new stock value: ");
    scanf("%d", &value);
    *(stock + pos - 1) = value;
    printf("Stock updated.\n");
    printSummary(stock, n);
}

int *insertItem(int *stock, int *n){
    int i, pos, value;
    int *newStock;

    printf("Enter position to insert at (1-%d): ", *n + 1);
    scanf("%d", &pos);
    if(pos < 1 || pos > *n + 1){
        printf("Invalid position.\n");
        return stock;
    }
    printf("Enter stock value of the new item: ");
    scanf("%d", &value);

    newStock = (int*)malloc((*n + 1) * sizeof(int));
    if(newStock == NULL){
        printf("Memory could not be allocated.\n");
        return stock;
    }

    for(i = 0; i < pos - 1; i++){
        newStock[i] = stock[i];
    }

    newStock[pos - 1] = value;

    for(i = pos - 1; i < *n; i++){
        newStock[i + 1] = stock[i];
    }

    free(stock);
    *n = *n + 1;

    printf("Item inserted.\n");
    printSummary(newStock, *n);
    return newStock;
}


int* deleteItem(int *stock, int *n){
    int i, j, pos;
    int *newStock;

    if(*n == 1){
        printf("Cannot delete the last item.\n");
        return stock;
    }
    printf("Enter position to delete (1-%d): ", *n);
    scanf("%d", &pos);
    if(pos < 1 || pos > *n){
        printf("Invalid position.\n");
        return stock;
    }

    newStock = (int*)malloc((*n - 1) * sizeof(int));
    if(newStock == NULL){
        printf("Memory could not be allocated.\n");
        return stock;
    }

    j = 0;
    for(i = 0; i < *n; i++){
        if(i != pos - 1){
            newStock[j] = stock[i];
            j++;
        }
    }

    free(stock);
    *n = *n - 1;

    printf("Item deleted.\n");
    printSummary(newStock, *n);
    return newStock;
}

void sortStock(int *stock, int n){
    int i, j, temp;
    for(i = 0; i < n - 1; i++){
        for(j = 0; j < n - 1 - i; j++){
            if(*(stock + j) > *(stock + j + 1)){
                temp = *(stock + j);
                *(stock + j) = *(stock + j + 1);
                *(stock + j + 1) = temp;
            }
        }
    }
    printf("Stock sorted in ascending order.\n");
    printSummary(stock, n);
}


int main(){
    int n, choice;
    int *stock;

    n = getStartSize();

    stock = (int*)malloc(n * sizeof(int));
    if(stock == NULL){
        printf("Memory could not be allocated.\n");
        return 1;
    }

    readStock(stock, n);

    do{
        showMenu();
        scanf("%d", &choice);

        if(choice == 1)
            displayStock(stock, n);
        else if(choice == 2)
            updateStock(stock, n);
        else if(choice == 3)
            stock = insertItem(stock, &n);
        else if(choice == 4)
            stock = deleteItem(stock, &n);
        else if(choice == 5)
            sortStock(stock, n);
        else if(choice == 6)
            printf("Exiting program.\n");
        else
            printf("Invalid choice. Try again.\n");

    } while(choice != 6);

    free(stock);
    stock = NULL;
    printf("Memory has been released.\n");

    return 0;
}