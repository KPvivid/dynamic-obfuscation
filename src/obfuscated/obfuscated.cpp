#include <iostream>

// Define obfuscated function
void secretFunction() {
    std::cout << "This is a secret function!\n";
}

// Define function pointer type
typedef void (*FunctionPtr)();

int main() {
    std::cout << "Welcome to the program!\n";

    // Initialize function pointer
    FunctionPtr ptr = &secretFunction;

    // Call the obfuscated function using the function pointer
    ptr();

    std::cout << "Program exiting...\n";
    return 0;
}