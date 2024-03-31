#include <iostream>

// Define a function to be obfuscated
void secretFunction() {
    std::cout << "This is a secret function!\n";
}

// Main function
int main() {
    std::cout << "Welcome to the program!\n";

    // Call the secret function
    secretFunction();

    std::cout << "Program exiting...\n";
    return 0;
}