#include <iostream>

float volume(float d1)
{
    return d1 * d1 * d1;
}

float volume(float d1, float d2, float d3)
{
    return d1 * d2 * d3;
}

int main()
{
    char shape[10];
    double d1, d2, d3;

    std::cin >> shape;
    if ('e' == shape[3])
    {
        std::cin >> d1;
        std::cout << volume(d1);
    }
    
    else
    {
        std::cin >> d1 >> d2 >> d3;
        std::cout << volume(d1, d2, d3);
    }

    return 0;
}