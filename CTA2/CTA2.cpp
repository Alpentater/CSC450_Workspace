#include<iostream>
#include<string>

//Standard namespace declaration
using namespace std;

//Main Function
int main() {

    string firstString = "";
    string secondString = "";
    string combinedString = "";

    //Since the assingment asked for this to be done 3 times, the for loop will run 3 times.
    for (int i = 0; i < 3; i++) {
        //Label for what loop we are on...
        cout << "Loop: " << (i + 1) << endl;

        //Asking the user to input their first of two strings and reading it from the console line...
        cout << "\nEnter your first string: " << endl;
        getline(cin, firstString);

        //Asking the user to input their second of two strings and reading it from the console line...
        cout << "\nEnter your second string: " << endl;
        getline(cin, secondString);

        //combine the strings!
        combinedString = firstString + secondString;

        //Display the string we just made:
        cout << "\nConcatenated string: " << combinedString << endl;
    }

    
    // Wait For Output Screen
    std::cin.get();

    //Main Function return Statement
    return 0;
}
