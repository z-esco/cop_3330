#include "a4.h"

int main(){

    Course courseList[5];

    int count, ind; 
    bool stop, valid;
    std::string courseName, courseCode, studentName, studentId;
    char studentClass;

    Course tempList[5];
    Student tempStud;
    stop = false;
    count = 0;

    while(!stop){
        switch(menuFunction()){
            case 'A':
                if(count >= 5)
                    std::cout << "You have reached the maximum course limit.\n";
                
                else{// get input for course name/code
                std::cout << "Input new course name: ";
                std::cin >> courseName;
                std::cout << "Input new course code: ";
                std::cin >> courseCode;

                //create course to be sent to new course list
                courseList[count].setName(courseName);
                courseList[count].setCode(courseCode);
                count++;
                }
                break;
            case 'B':
                //set ind to chosen index using getRemoveInd
                int ind;
                ind = getRemoveInd(courseList, count);
            std::cout << ind <<"lkj\n";
                std::cout << ind << " \n";
                for(int i = ind ; i< count -1; i++)
                courseList[i] = courseList[i+1];

                count--;
                break;
            case 'C':
                for(int i = 0; i<count; i++)
                    std::cout << courseList[i];
                break;
            case 'D':
                courseList[ind].addStudent();
                break;
            case 'E':
                std::cout << "What index is the class: ";
                std:: cin >> ind;
                courseList[ind].removeStudent();
                break; 
            case 'F':
                stop = true;
                break;
            default:
                stop = false;
                break;
        }             
    }
    return 0;
}