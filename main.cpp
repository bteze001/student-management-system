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

// void loading() {

// 	system("clear");
//     //std::cout << "\033[32;44m"; 
// 	system("color 9F");
	
// 	char a = 177, b = 219;

// 	std::cout<<"\n\n\n\n\n\t\t\t\t\tStudent's Data Management System";
// 	std::cout<<"\n\t\t\t\t\tProject By Beza Tezera";
// 	std::cout<<"\n\n\n\t\t\t\t\tLoading...\n";
// 	std::cout << std::endl;
// 	std::cout<<"\t\t\t\t\t";
	
// 	for(int i = 0; i < 26; i++)

// 	    std::cout << a;
    
// 	std::cout<<"\r";
// 	std::cout<<"\t\t\t\t\t";

// 	for(int i = 0; i < 26 ; i++){

// 		std::cout << b;
// 		std::this_thread::sleep_for(std::chrono::milliseconds(200));
// 	}
	
// }
