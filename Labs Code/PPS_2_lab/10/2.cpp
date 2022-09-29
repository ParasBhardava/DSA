#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class MemoryAllocationFailed : public std::exception
{
    virtual const char *what() const throw()
    {
        return "MemoryAllocationFailed";
    }
};

void *allocate_memory(long size)
{
    void *temp = NULL;
    temp = malloc(size * sizeof(long));
    if (temp == NULL)
        throw MemoryAllocationFailed();
    return temp;
}

int main()
{
    void *vptr;
    try
    {
        vptr = allocate_memory(100);
        free(vptr);
        vptr = allocate_memory(100000000000000);
        free(vptr);
    }
    
    catch (std::exception &e)
    {
        cout << e.what();
    }

    return 0;
}