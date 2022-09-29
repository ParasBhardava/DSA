#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    int passengers;
    float mileage, price_of_diesel_per_liter, length_of_route, ticket_of_passenger;
    
    scanf("%f", &mileage);
    scanf("%f", &price_of_diesel_per_liter);
    scanf("%f", &length_of_route);
    scanf("%d", &passengers);
    scanf("%f", &ticket_of_passenger);
    
    float liter_of_diesel = length_of_route/mileage;
    int profit = (passengers*ticket_of_passenger) -(liter_of_diesel*price_of_diesel_per_liter);
    
    printf("%d", profit);
                                   
    return 0;
}