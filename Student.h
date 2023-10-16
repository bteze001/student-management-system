#ifndef _Student_H_
#define _Student_H_

#include <iostream>
#include <vector> 

class studentRecord {

    private:

        std::string studentName;
        std::string studentID;
        std::string studentGrade;

    public:

        studentRecord();
        studentRecord(std::string name, std::string ID, std::string grade): studentName(name), 
                                                                    studentID(ID), studentGrade(grade){}
        std::string getName();
        void addData(std::string filename); 
        void deleteData(std::string name);
        void displayRecord (const std::string filename) const;
        void inputData();
        void searchStudent(std::string name) const; 
        void updateInformation(std::string name);  

};
#endif