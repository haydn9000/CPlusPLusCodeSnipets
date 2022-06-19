#include <iostream>
using namespace std;

//================================== FUNCTION PROTOTYPES ==================================
int convertStrToInt(string asciiValue);

int charArraySize(char * charArray);

int pow(int baseNumber, int exponent);

//================================== MAIN FUNCTION ==================================
int main()
{
    string asciiValue = "012";
    int integerValue = convertStrToInt(asciiValue);


    cout << "The integer value of octal representation \"" << asciiValue << "\" is: " << integerValue <<  endl;
    return 0;
}

//================================== FUNCTION DEFINITIONS ==================================
int convertStrToInt(string asciiValue)
{
    /*
    This function takes as input an ascii string containing an octal representation
    of an unsigned integer and convert that string to an integer value.
    */

    int integerValue;
    int exponent = asciiValue.length() - 1;

    // Traverse the string
    for (int i = 0; i < asciiValue.length(); i++)
    {
        int d = asciiValue[i] - '0';  // Convert char to digit
        int p  = pow(8, exponent);    // Calculate the power
       
        integerValue += (d * p);      // Sum values to get integer value of multiplied digit with 8^n
        exponent--;
    }

    return integerValue;
}

int pow(int baseNumber, int exponent)
{
    /*
    This function takes two numbers, a base number and an exponent then calculates the power.
    */

    int result = 1;

    // Calculating the power (formula: baseNumber multipied by itself a number of times, times=exponent)
    while (exponent != 0)
    {
        result *= baseNumber;
        --exponent;
    }

    return result;
}