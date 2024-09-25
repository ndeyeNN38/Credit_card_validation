#include <iostream>

using namespace std;

void swapCodes(int *code1, int *code2)
{
    // CHANGE_HERE Swap the values of the two secret codes. This function is used in the exercise below. 
    int temp = *code1;  
    *code1 = *code2;   
    *code2 = temp;
      
}

int main()
{
    /**
     * Pointer Declaration and Initialization (The Treasure Map)
     * You’ve just discovered an ancient map that points to the hidden treasure! Declare an integer variable treasureLocation and initialize it with the value 10 (the treasure’s coordinates).
     * Create a pointer mapPointer that points to treasureLocation.
     * Print the coordinates using both the variable and the pointer (you need to confirm the location with the ancient map).
     * Print the address of treasureLocation (the map’s reference code)
     */
    int treasureLocation = 10;
    int *mapPointer = &treasureLocation;

    std::cout << "Treasure Location: " << treasureLocation << std::endl;
    std::cout << "Treasure Location using mapPointer: " << *mapPointer << std::endl;
    std::cout << "Map Reference Code: " << &treasureLocation << std::endl;

    /**
     * Pointer Arithmetic (Navigating the Map)
     * The map reveals that there are five key locations you must visit before finding the treasure. These locations are marked as {1, 2, 3, 4, 5}.
     * Declare an array locations with these values and create a pointer navigator to help you move between locations.
     * Use pointer arithmetic to navigate through the locations and print them as you move forward.
     */
    int locations[5] = {1, 2, 3, 4, 5};
    int *navigator = locations;

    std::cout << "Key Locations on the Map:" << std::endl;
    for (int i = 0; i < 5; ++i)
    {
        std::cout << *(locations + i) << " ";
    }
    std::cout << std::endl;

    /**
     * Dynamic Memory Allocation (Avoiding Traps)
     * As you navigate, you encounter hidden traps that could prevent you from reaching the treasure. You need to dynamically allocate resources to bypass them!
     * Use the new keyword to dynamically allocate memory for an integer trapCounter (this keeps track of the number of traps).
     * Assign a value to trapCounter and print it (this shows how many traps you’ve avoided).
     * Free the allocated memory using delete (disarm the trap).
     */
    int *trapCounter = new int;
    *trapCounter = 20;

    std::cout << "Traps Avoided: " << *trapCounter << std::endl;

    delete trapCounter;

    /**
     * Dynamic Allocation of an Array (Crossing the Trap Fields)
     * You reach a field filled with traps! You must carefully step through it. Dynamically allocate memory for an array trapField to represent the traps in the field.
     * Assign values representing safe steps (e.g., {0, 0, 1, 0, 1} where 1 represents a trap) and print them using pointer arithmetic.
     * Deallocate the memory to safely cross the field.
     */
    int *trapField = new int;

    trapField[0] = 0;
    trapField[1] = 0;
    trapField[2] = 1;
    trapField[3] = 0;
    trapField[4] = 1;

    std::cout << "Crossing the Trap Field:" << std::endl;
    for (int i = 0; i < 5; ++i)
    {
        std::cout << trapField[i] << " ";
    }
    std::cout << std::endl;

    delete[] trapField;

    /**
     * Passing Pointers to Functions (Decoding the Treasure Lock)
     * You finally arrive at the treasure, but it’s locked! You need to swap the positions of two secret codes to unlock it.
     * Write a function swapCodes that takes two integer pointers and swaps their values (the secret codes).
     * In the main function, declare two variables for the secret codes, print them, use swapCodes to unlock the treasure, and print the codes again.
     */

    int codeA = 1234, codeB = 5678;
    std::cout << "Before swap: Code A = " << codeA << ", Code B = " << codeB << std::endl;

    swapCodes(&codeA, &codeB);

    std::cout << "After swap: Code A = " << codeA << ", Code B = " << codeB << std::endl;

    /**
     * Pointers to Pointers (Finding the Master Key)
     * The treasure chest requires a master key. You find a double-locked key mechanism. Use pointers to pointers to unlock it!
     * Declare a variable masterKey and initialize it with a value. Create a pointer keyPointer to masterKey and a pointer lockPointer to keyPointer.
     * Print the value of masterKey using lockPointer by dereferencing it twice (this will unlock the final lock).
     */
    int masterKey = 30;
    int *keyPointer = &masterKey;
    int **lockPointer = &keyPointer;

    std::cout << "Master Key Value: " << **lockPointer << std::endl;

    return 0;
}


