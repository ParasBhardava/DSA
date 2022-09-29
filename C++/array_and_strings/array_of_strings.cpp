#include <iostream>
#include <vector>
#include <array>
#include <string>

int main()
{
    // 1. Using Pointers : 
    /* These strings are constants and their contents cannot be changed. Because string literals (literally, the quoted strings) exist in a read-only area of memory, we must specify “const” here to prevent unwanted accesses that may crash the program.*/
    const char *colour1[4] = { "Blue", "Red", "Orange", "Yellow" };
 
    for (int i = 0; i < 4; i++)
        std::cout << colour1[i] << " ";
    std::cout<<"\n";

    // 2. Using 2D array :
    char colour2[4][10] = { "Blue", "Red", "Orange","Yellow" };
    for (int i = 0; i < 4; i++)
        std::cout << colour2[i] << " ";
    std::cout<<"\n";

    // 3. Using the string class:
    std::string colour3[4] = { "Blue", "Red", "Orange", "Yellow" };
    for (int i = 0; i < 4; i++)
        std::cout << colour3[i] << " ";
    std::cout<<"\n";

    // 4. Using the vector class(Best Method):
    std::vector<std::string> colour4 {"Blue", "Red", "Orange"};
    colour4.push_back("Yellow");
    for (int i = 0; i < colour4.size(); i++)
        std::cout << colour4[i] << " ";
    std::cout<<"\n";

    // 5. Using the array class:
    std::array<std::string, 4> colour5 { "Blue", "Red", "Orange", "Yellow" };
    for (int i = 0; i < 4; i++)
        std::cout << colour5[i] << " ";
    std::cout<<"\n";
 
    return 0;
}