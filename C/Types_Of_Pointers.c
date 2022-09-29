//                ********** Types Of Pointers In C **********
// Pointer: Pointer is a variable which store address of other variable of same type.
// syntax: data_type *pointer_name

//               ------ Void Pointer -----
// A void pointer is a pinter that has no data type associated with it.
// A void pointer can be easily typecasted to ant pointertype.
// In simple language it is a general purpose pointer variable.
// In dynamic memory allocation, malloc() & calloc() return (void *) type pointer
// This allows these dynamic memory function to be used to allocate the memory of any data type. This is beccause 
// these pointers can be typecasted to any pointer type. 
// It is not possible to dereference void pointers.
// If we want to dereference void pointer then we can type cast it into datatype which pointed by it.
// Pointer arithmetic is not allowed in C standards with void pointers because there is no fixed datatype which is
// pointed by void pointer so scale factor is also not definded.
// Hence it is not recommended to use pointer arithmetic with void pointer.      
// syntex: void *pointer_name
/* Ex....     int var = 10;
              char ch = 'x';
              void *ptr = &var;  // void pointer stores address of int var
              *ptr = &ch;        // void pointer now holds address of char ch
*/              

//                           ------ Null Pointer ------
// Null pointer is a pointer which has a value reserved for indecatind=g that the pointer or reference does not 
// refer to a valid object.
// A null pointer is guranteed to compare unequal to any pointer taht points to a valid object.
// Dereferencing a null pointer in C, and a conforming implimentation is allowed to assume that any pointer 
// that is derefereced is not null.
// Null pointer is a specific pointer which is mentioned in C standards and it has specific purpose.
// Null pointer gives a functionality to c programer to check whether a pointer is legitimate or not.
// A null pointer is a pointer that points to NULL(nothing).
// A null pointer should not be dereferenced.
// A check must be run by the c programmer to know whether a pointer is null before dereferencing it.
// To intialize a pointer variable in cases where pointer variable has not been assigned any alid address yet.
// To heck for legitmate addresslocation before accessing any pointer variable.
// By doing so, we can perform error handling while using pointers with c.
// Example of such error handling can be: dereference pointer variable only it is not NULL.
// To passa a null pointer to a function argument when we don't want to pass an valid memory address.
// NULL macro is defind as ((void*)0) in header file of most of the C compiler implimentations.
// NULL pointer vs Unintilized pointer - An unintilized pointer contains anundefind value.
// A null pointer stores a defined value. which is the one decided by the envirnment to not be a valid memory 
// address for any object.
// NULL pointer vs Void pointer - Null pointer is value where as void pointer is a type 
// syntax: data_type *pointer_name = NULL;
/*         int x = 10;
           int *ptr = NULL;   // null pointer
           p = &x             // null pointer now holds address of int x and it can be dereferenced
*/

//                     ------ Dangling Pointer ------
// A pointer pointing to a freed memory location or the location whose content has been deleted is called 
// a dangling pointer.
// Dangling pointer arise during object destructiion when an object that has an incoming reference is deletrd or
// deallocated without modyfying the value of the pointer. So that the pointer still to the memory location of 
// the deallocated memory.
// Cause of Dangling Pointer :-
// -Deallocation of memory
// -Returning local variables in function calls 
// -Variable goiong out of scope
// Dangling pointer can introduce nasty bugs in our C programs.
// Dangling pointer bugs frequently become security holes at times.
// We can avois issues caused by dangling pointers by intializing pointer to NULL
// After de-allocating memory, pointer will m=no longer dangling.
// Assigning NULL value means pinter is a null pointer now.

//                      ------ Wild Pointer In C -------
// Uninialized pointes are known as wild pointer.
// These pointers point to some arbitrary location n memory and memeory may cause a program to crash or behave badly.
// Dereferencing wild pointers can cause nasty bugs.
// It is suggested to always intialize unused pointers to NULL.
/*  int a = 3;
    int *ptr;   // Wild pointer  
    ptr = &a    // ptr no longer wild pointer
*/










