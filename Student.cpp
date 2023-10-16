#include "Student.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

studentRecord::studentRecord(){}

std::string studentRecord:: getName() {

    return studentName;
}

void studentRecord :: addData(std::string filename) {

    std::ofstream file(filename, std::ios::app);

    if(!file.is_open()) {

        throw std::runtime_error("File Not Opened!");
    }

    studentRecord record;

    record.inputData();
    file << record.studentName << " " << record.studentID << " " << record.studentGrade << std::endl;

    file.close();
    std::cout << "student added" << std:: endl;
}

void studentRecord :: deleteData(std::string name) {

    std::ifstream file ("data.csv");
    std::ofstream files ("temp.csv");

    if(!file.is_open() || !files.is_open()) {

        throw std::runtime_error("File not opened");
    }

    else {

        std::string line;
        bool studentFound = false;

        while(std::getline(file, line)) {

            std::string studentName;
            std::stringstream ss (line);

            std::getline(ss, studentName, ' ');

            if (name == studentName) {

                studentFound = true;
            }

            else {

                files << line << std::endl;
            }
        }

        file.close();
        files.close();

        if (studentFound) {

            if (remove("data.csv") != 0) {

                throw std:: runtime_error ("Error deleting the original file.");
        
            }

            if (rename("temp.csv", "data.csv") != 0) {

                throw std:: runtime_error ("Error renaming the temporary file.");
            }

            else {

                std::cout << "Student data deleted successfully." << std::endl;
            }
        }
        else {
            std::cout << "student not found." << std::endl;
            remove("temp.csv");
        }

    }
}

void studentRecord :: displayRecord(const std::string filename) const {

    std::ifstream file(filename);

    if (!file.is_open()) {

        throw std::runtime_error("File not found");
    }

    else {

        std::string line;

        while(std::getline (file, line)) {

            std::string name, ID, gradeStr;

            std::stringstream ss(line);

            std::getline(ss, name, ',');
            std::getline(ss, ID, ',');
            std::getline(ss, gradeStr, '.');

            std::cout << name << ID << gradeStr << std::endl;

        }
    }

    file.close();
}

void studentRecord :: inputData() {

    std:: cout << "Enter student's name: " << std::endl;
    std:: cin.ignore();
    std:: getline(std::cin, studentName);

    std:: cout << "Enter student's ID: " << std::endl;
    std:: getline(std::cin, studentID);

    std:: cout << "Enter grade: " << std::endl;
    std:: getline (std::cin, studentGrade);

} 

void studentRecord :: searchStudent(std::string name) const {

    std::ifstream file("data.csv");

    if (!file.is_open()) {

        throw std::runtime_error ("File not opened");
    }

    else {

        std::string line;
        while (std::getline(file, line)) {
            
            std::string studentName;
            std::stringstream ss(line);

            std::getline(ss, studentName, ' ');

            if (name == studentName) {

                studentRecord record;

                record.displayRecord("data.csv");
            }

            else {

                throw std::runtime_error ("Student not found");
            }
        }
              
    } 
    
}

void studentRecord :: updateInformation(std::string name) {

    std::ifstream file("data.csv");
    std::ofstream tempfile("temp.csv");

    if (!file.is_open() || !tempfile.is_open()) {

        throw std::runtime_error ("File not opened");
    }

    else {

        std::string line;
        bool studentFound = false;

        while (std::getline(file, line)) {
            
            std::string studentName, studentID, studentGrade;
            std::stringstream ss(line);

            std::getline(ss, studentName, ' ');
            std::getline(ss, studentID, ' ');
            std::getline(ss, studentGrade, ' ');

            if (name == studentName) {

                studentFound = true; 
                std::string newName, newID, newGrade;
                std::cout << "Enter updated name: " << std::endl;
                //std::cin.ignore();
                std::getline(std::cin, newName);
                std:: cout << "Enter updated ID: " << std::endl;
                std:: getline(std::cin, newID);
                std:: cout << "Enter updated grade: " << std::endl;
                std:: getline (std::cin, newGrade);

                tempfile << newName << " " << newID << " " << newGrade << "." << std::endl;
            }

            else {

                tempfile << line << std::endl;
            }
        }

        file.close();
        tempfile.close();

        if (studentFound) {

            if (remove("data.csv") != 0) {

                throw std:: runtime_error ("Error deleting the original file.");
        
            }

            if (rename("temp.csv", "data.csv") != 0) {

                throw std:: runtime_error ("Error renaming the temporary file.");
            }

            else {

                std::cout << "Student data updated successfully." << std::endl;
            }
        }
        else {
            std::cout << "student not found." << std::endl;
            remove("temp.csv");
        }

    }
}

