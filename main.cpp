#include "Student.h"
#include <iostream>
#include <string>
#include <vector>

void Menu();

int main() {

    studentRecord record;

    Menu();

    int choice;
    std::cin >> choice;

    while(true) {

        if (choice == 6) {

            break;
        }

        else if (choice == 1) {

            studentRecord newData;

            newData.addData("data.csv");

            Menu();
            std::cin >> choice;
        }

        else if (choice == 2) {

            std::string studentName;

            std::cout << "Enter student's name to delete:" << std::endl;
            std:: cin.ignore();

            std:: getline(std::cin, studentName);

            record.deleteData(studentName);

            Menu();
            std::cin >> choice;

        }

        else if (choice == 3) {

            record.displayRecord("data.csv");

            Menu();
            std::cin >> choice;

        }

        else if (choice == 4) {

            std::cout << "Enter student name: " << std::endl;
            std::string studentName;
            std::cin.ignore();
            std::getline(std::cin, studentName);

            record.searchStudent(studentName);

            Menu();
            std::cin >> choice;
        }

        else if (choice == 5) {

            std::cout << "Enter student name to update: " << std::endl;
            std::string studentName;
            std::cin.ignore();
            std:: getline(std::cin, studentName);

            record.updateInformation(studentName);
            
            Menu();
            std::cin>>choice;
        }

    }

    
}

void Menu() {

    std:: cout << "1. Add data" << std::endl;
    std:: cout << "2. Delete data" << std::endl;
    std:: cout << "3. Display records" << std::endl;
    std:: cout << "4. Search student by name" << std::endl;
    std:: cout << "5. update information" << std::endl;
    std:: cout << "6. Quit" << std::endl;

}

