//Needed packages, algorithm will be used to reverse strings.
#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>

//Standard namespace declaration
using namespace std;

//Main Function, main entry point.
int main() {

    //Declaring some strings that hold filenames.
    string fileName = "CSC450_CT5_mod5.txt";
    string fileNameReversed = "CSC450-mod5-reverse.txt";

    //This part asks the user for some input to be appended to the file.
    //It stores their input into a string called "usersInput".
    cout << "Enter some text to add to the end of the file: ";
    string usersInput = "";
    getline(cin, usersInput);

    //Here, we take what the user entered and append it to the end of the text file.
    ofstream outFile(fileName, ios::app);
    outFile << usersInput << endl;
    outFile.close();

    //Just an output line to the terminal, some feedback to let us know things are happening!
    cout << "Data appended to " << fileName << endl;

    //A new ifstream called "infile" I like to think of these as a "Scanner" from Java.
    //It is necessary to read from a file.
    ifstream inFile(fileName);
    //Storing that text from the inFile ifstream reading from the source text and storing it into "fileText" string.
    string fileText((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());
    inFile.close();

    //Reverse the string, using the function "reverse" imported from algorithm package.
    reverse(fileText.begin(), fileText.end());

    //Write reversed string into new file
    ofstream outPutFile(fileNameReversed);
    outPutFile << fileText;
    outPutFile.close();

    //Just an output line to the terminal, some feedback to let us know things are happening!
    cout << "Reversed content written to: " << fileNameReversed << endl;

    // Wait For Output Screen
    std::cin.get();

    //Main Function return Statement
    return 0;
}
