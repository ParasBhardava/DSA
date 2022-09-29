#include <iostream>
#include <iomanip>

using namespace std;

class Route;

class Bus
{
    string bus_id;
    string fuel_type;
    double mileage_per_litre;
    int max_passengers;
    static double petrol_price_per_litre, diesel_price_per_litre;

public:
    Bus(string bus_id, string fuel_type, double mileage_per_litre, int max_passengers)
    {
        this->bus_id = bus_id;
        this->fuel_type = fuel_type;
        this->mileage_per_litre = mileage_per_litre;
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

    friend double calculate_profit(const Route &, const Bus &);
};

double Bus ::petrol_price_per_litre = 80.88;
double Bus ::diesel_price_per_litre = 75.77;

class Route
{
    string route_id;
    string source;
    string destination;
    double distance;
    int fare_per_passenger;

public:
    Route(string route_id, string source, string destination, double distance, int fare_per_passenger)
    {
        this->route_id = route_id;
        this->source = source;
        this->destination = destination;
        this->distance = distance;
        this->fare_per_passenger = fare_per_passenger;
    }

    friend double calculate_profit(const Route &, const Bus &);
};

double calculate_profit(const Route &R, const Bus &B)
{
    double fuel_price;
    if (B.fuel_type == "diesel")
        fuel_price = B.diesel_price_per_litre;
    else if (B.fuel_type == "petrol")
        fuel_price = B.petrol_price_per_litre;
    else
        return 0;

    return (R.fare_per_passenger * B.max_passengers) - (R.distance / B.mileage_per_litre * fuel_price);
}

int main()
{
    double new_price_petrol, new_price_diesel, mileage_per_litre, distance;
    string bus_id, fuel_type, route_id, destination, source;
    int max_passengers, fare_per_passenger;

    cin >> new_price_petrol >> new_price_diesel >> bus_id >> fuel_type >> mileage_per_litre >> max_passengers >> route_id >> source >> destination >> distance >> fare_per_passenger;

    Bus B(bus_id, fuel_type, mileage_per_litre, max_passengers);
    B.change_petrol_price(new_price_petrol);
    B.change_diesel_price(new_price_diesel);

    Route R(route_id, source, destination, distance, fare_per_passenger);

    cout << fixed << setprecision(2) << calculate_profit(R, B);

    return 0;
}