// Storage Classes in C
// Syntax:-
// storage class_data type_variable name
// Declaration: Telling te compiler about the variable (No space reserved)
// Defination: Declaration + space reservation

//          ---------- 1.Automatic Variable: Auto Storage Class ----------
// Scope: Local to the function body they are defind in
// Default Value: arbage Value
// Lifetime: Till the end of the function block they are defind in
// A variable defind without any storage class specification is by default an automatic variable 
// int a and auto int a are same

//          ---------- 2. Extern Variables: Extern Storage Classes ---------
// They are same as global variables
// Scope:GLbal to the program they are defind in
// Default Value: 0
// Lifetime: These variables are declaredoutside any function. They are available throughout the lfetime of the program.
// A global variable can be changed by any function in the proram.
// int a written outside any function will tell compiler that a is a global variable.
// It is recommended to minimize the use of unnecessary global variables in a program.
// extern keyword is used to inform our c compiler that a given variable is declared somewhere else.
// Using extern will not allocate space for the variable.

//         ---------- 3. Static Variables: Static Storage Class ----------
// Scope: Local to the block they are defind in 
// Default Value: 0
// Lifetime: They are available throught the lifetime of the program.
// A static variable remains under existence for use within the function for entire program run.
// They preserve their value from the previous scope andare not intialized again
// In C, static variables can only be intialized using constant literals 
//  static int a = 10; ---> valid
//  static int a = function() ---> Not valid
// static int a wriitten in any function will tell compiler that a is a static variable.
// It is recommended to minimize the use of unnecessary static variables in a program.  

//         ---------- 4. Register Variables: Register Storage Class
// Scope: Local to the function they are defind in
// Defaut value: Garbage
// Lifetime: They availablr till the end of the function block, in which the variable is defind.
// Register Vriable request the compiler to store the variable in the CPU register instead of storing into the memory 
// to have faster access.
// enerally this is done for the variables which are being used frequently.