// Copyright (c) 2021 Layla Michel All rights reserved.
//
// Created by: Layla Michel
// Date: June 9, 2021
// This program takes a decimal number and rounds it to the number of decimals
// specified by the user

#include <iostream>
#include <string>
#include <cmath>

void round(float &number, int decimals) {
    // This function takes a number and the number of decimal places and then
    // rounds it to that number of places
    if (number < 0) {
        // does this if the number is negative
        number = number * pow(10, decimals) - 0.5;
        int numberCast = static_cast<int>(number);
        number = numberCast / pow(10, decimals);
    } else {
        // does this if the number is positive
        number = number * pow(10, decimals) + 0.5;
        int numberCast = static_cast<float>(number);
        number = numberCast / pow(10, decimals);
    }
}


int main() {
    // declare local variables
    std::string userNumString, userDecPlacesString;
    float userNumFloat, userDecPlacesFloat;
    int userDecPlacesInt;

    //  greet user
    std::cout << "This program rounds a decimal number to a number ";
    std::cout << "of places entered.\n";

    while (true) {
        // get the decimal number
        std::cout << "Enter a decimal number: ";
        std::cin >> userNumString;

        try {
            // convert from string to float
            userNumFloat = std::stof(userNumString);
            break;
        } catch (std::invalid_argument) {
            // error message of the input is not a number
            std::cout << userNumString << "  is not a number, try again.\n";
        }
    }
    std::cout << "\n";

    while (true) {
        // gets the number of decimal places to round to
        std::cout << "How many decimal places do you want to ";
        std::cout << "round the number to? ";
        std::cin >> userDecPlacesString;

        try {
            // convert from string to int
            userDecPlacesInt = std::stoi(userDecPlacesString);
            // convert from string to float
            userDecPlacesFloat = std::stof(userDecPlacesString);
            if (userDecPlacesInt == userDecPlacesFloat) {
                // check if input is an integer
                if (userDecPlacesInt < 0) {
                    // check if input is negative
                    std::cout << userDecPlacesInt << " is a negative ";
                    std::cout << "number, try again.\n";
                } else {
                    break;
                }
            } else {
                // error message if input is not an integer
                std::cout <<  userDecPlacesString;
                std::cout << "  is not a valid number, try again.\n";
            }
        } catch (std::invalid_argument) {
            // error message if the input is not an integer
            std::cout << userDecPlacesString << "  is not a valid number, ";
            std::cout << "try again.\n";
        }
    }
    std::cout << "\n";

    // call round() to round the number
    round(userNumFloat, userDecPlacesInt);

    // display rounded number
    std::cout << "The number rounded is: " << userNumFloat;
}
