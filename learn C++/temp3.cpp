#include <iostream>

using namespace std;

class Bus
{
    string bus_id;
    string fuel_type;
    double mileage_per_litre;
    int max_passengers;
    static double petrol_price_per_litre , diesel_price_per_litre;
    
    public:
    
    Bus(string bus_id, string fuel_type, double mileage_per_litre, int max_passengers)
    {
        this->bus_id = bus_id;
        this->fuel_type = fuel_type;
        this->mileage_per_litre =  mileage_per_litre;
        this->max_passengers = max_passengers;
    }
    
    static void change_petrol_price(double value)
    {
        petrol_price_per_litre = value;
    }
    
    static void change_diesel_price(double value)
    {
        diesel_price_per_litre = value;
    }
    
};

double Bus :: petrol_price_per_litre  = 80.88;
double Bus :: diesel_price_per_litre  = 75.77;

class Route
{
    string route_id;
    string source; 
    string destination;
    double distance;
    int fare_per_passenger;
    
    public:
    Route(string route_id; string source; string destination; double distance; int fare_per_passenger)
    {
        this->route_id = route_id;
        this->source = source; 
        this->destination = destination;
        this->distance = distance;
        this->fare_per_passenger = fare_per_passenger;
    }
};

double calculate_profit(Route R, Bus B)
{
       
}

int main()
{
    
    return 0;
}