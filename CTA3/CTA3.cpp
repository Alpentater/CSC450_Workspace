//an inclusion package.
#include <iostream>

using namespace std;

//Main function / main entry point.
int main() {
    //Defining some variables to store user inputting ints.
    int numberOne = 0;
    int numberTwo = 0;
    int numberThree = 0;

    /* Here, we ask the user in the console for three integers and store them
    * in the variables we declared above.*/
    cout << "Enter the first integer: ";
    cin >> numberOne;
    cout << "Enter the second integer: ";
    cin >> numberTwo;
    cout << "Enter the third integer: ";
    cin >> numberThree;

    //Defining some pointers for the integers we populated.
    int* numOnePointer = new int(numberOne);
    int* numTwoPointer = new int(numberTwo);
    int* numThreePointer = new int(numberThree);

    //Printing memory addresses and their associated ingeter values.
    cout << "\nMemory address for first integer: " << numOnePointer << " | It's integer value was: " << numberOne;
    cout << "\nMemory address for second integer: " << numTwoPointer << " | It's integer value was: " << numberTwo;
    cout << "\nMemory address for three integer: " << numThreePointer << " | It's integer value was: " << numberThree;


    //Deleting and freeing up that memory!
    delete numOnePointer;
    delete numTwoPointer;
    delete numThreePointer;

    //Waiting for input as to not immediately close the console.
    cin.get();

    //Main function return statement.
    return 0;
}

