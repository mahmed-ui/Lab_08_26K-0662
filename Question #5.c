#include <stdio.h>

int main(){
    double costPrice,sellingPrice,quantity,totalCost,totalSales,profit;
    double *costPricePtr = &costPrice;
    double *sellingPricePtr = &sellingPrice;
    double *quantityPtr = &quantity;
    double *totalCostPtr = &totalCost;
    double *totalSalesPtr = &totalSales;
    double *profitPtr = &profit;


    printf("Enter the cost price: ");
    scanf("%lf", costPricePtr);
    printf("Enter the selling price: ");
    scanf("%lf", sellingPricePtr);
    printf("Enter the quantity: ");
    scanf("%lf", quantityPtr);
    *totalCostPtr = (*costPricePtr) * (*quantityPtr);
    *totalSalesPtr = (*sellingPricePtr) * (*quantityPtr);
    *profitPtr = (*totalSalesPtr) - (*totalCostPtr);

    if(*profitPtr > 0){
        printf("Made Profit\\n");
    }
    else if(*profitPtr < 0){
        printf("Made Loss");
    }
    else{
        printf("No profit, no loss.\n");
    }

    double profitPercent;
    double *profitPercentPtr = &profitPercent;

    if(*totalCostPtr != 0){
        *profitPercentPtr = (*profitPtr / *totalCostPtr) * 100;
        printf("Profit Percentage: %.2lf%%\n", *profitPercentPtr);
    }else{
        *profitPercentPtr = 0;
        printf("Profit Percentage: N/A (Total cost is zero)\n");
    }

    double *larger;
    const char *largerName;
    if(*costPricePtr > *sellingPricePtr){
        larger = costPricePtr;
        largerName = "costPrice";
    } else {
        larger = sellingPricePtr;
        largerName = "sellingPrice";
    }
    if(*costPricePtr == *sellingPricePtr)
        printf("\nCost price and selling price are equal: %.2f\n", *larger);
    else
        printf("\nLarger price: %s = %.2f\n", largerName, *larger);
    
    printf("\n%-16s %-20s %-20s\n", "Name", "Address of it", "Value stored (address)");
printf("---------------------------------------------------------\n");
printf("%-16s %-20p\n", "costPrice",     (void*)&costPrice);
printf("%-16s %-20p\n", "sellingPrice",  (void*)&sellingPrice);
printf("%-16s %-20p\n", "quantity",      (void*)&quantity);
printf("%-16s %-20p\n", "totalCost",     (void*)&totalCost);
printf("%-16s %-20p\n", "totalSales",    (void*)&totalSales);
printf("%-16s %-20p\n", "profit",        (void*)&profit);
printf("%-16s %-20p\n", "profitPercent", (void*)&profitPercent);
printf("---------------------------------------------------------\n");
printf("%-16s %-20p %-20p\n", "costPricePtr",     (void*)&costPricePtr,     (void*)costPricePtr);
printf("%-16s %-20p %-20p\n", "sellingPricePtr",  (void*)&sellingPricePtr,  (void*)sellingPricePtr);
printf("%-16s %-20p %-20p\n", "quantityPtr",      (void*)&quantityPtr,      (void*)quantityPtr);
printf("%-16s %-20p %-20p\n", "totalCostPtr",     (void*)&totalCostPtr,     (void*)totalCostPtr);
printf("%-16s %-20p %-20p\n", "totalSalesPtr",    (void*)&totalSalesPtr,    (void*)totalSalesPtr);
printf("%-16s %-20p %-20p\n", "profitPtr",        (void*)&profitPtr,        (void*)profitPtr);
printf("%-16s %-20p %-20p\n", "profitPercentPtr", (void*)&profitPercentPtr, (void*)profitPercentPtr);
printf("%-16s %-20p %-20p\n", "larger",           (void*)&larger,           (void*)larger);

return 0;


}