// Copyright (c) 2022 Yiyun Qin All rights reserved
//
// Created by Yiyun Qin
// Created in June 2022
// This is a math program, calculating the average of marks

#include <iostream>
#include <string>
#include <iomanip>
#include <list>


float Average(std::list<int> marks) {
    // This function calculates the average of marks

    // process & output
    float total = 0;
    float averageMark;
    for (int aMark : marks) {
        total = total + aMark;
    }
    averageMark = total / marks.size() * 1.00;
    return averageMark;
}


int main() {
    // This function does try and catch
    std::string aMarkString = "";
    int aMark;
    std::list<int> marks;
    float averageMark;
    float aMarkFloat;

    // input
    std::cout << "Please enter 1 mark at a time. Enter -1 to end." << std::endl;

    // process
    std::cout << "" << std::endl;
    while (aMarkString != "-1") {
        std::cout << "What is your mark? (as %): ";
        std::cin >> aMarkString;
        try {
            aMarkFloat = std::stof(aMarkString);
            aMark = std::stoi(aMarkString);
            if (aMarkFloat == aMark) {
                if (aMark >= 0 && aMark <= 100) {
                    marks.push_back(aMark);
                } else if (aMark == -1) {
                    aMarkString = std::to_string(aMark);
                    marks.push_back(aMark);
                    continue;
                } else {
                    std::cout << "Please enter a score between 0 and 100!"
                    << std::endl;
                }
                aMarkString = std::to_string(aMark);
            } else {
                std::cout << "Invalid number!" << std::endl;
            }
        } catch (std::invalid_argument) {
            std::cout << "Invalid number!" << std::endl;
        }
    }
    // remove the last thing in the list
    marks.pop_back();
    averageMark = Average(marks);
    std::cout << "\nThe average is " << std::fixed << std::setprecision(2)
    << std::setfill('0') << averageMark << "%" << std::endl;
    std::cout << "\nDone.";
}
