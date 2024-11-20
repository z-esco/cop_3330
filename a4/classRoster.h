#include <string>
#include <iostream>

//Student class declaratiom
class Student{
    friend std::ostream& operator <<(std::ostream o, Student& s);
    
    private: 
        std::string name;
        std::string ID;
        char classification;

    public:
        //default constructor
        Student();

        Student(std:: string n, std::string c, char year);

        //getters
        std::string const getName();
        std::string const getID();
        char const getClassification();

        //setters
        void setName(std::string n);
        void setID(std::string id);
        void setClassification(char c);
};

//Roster class declaration
class Roster{
    int const SIZE = 5;
    friend std::ostream& operator << (std::ostream& o, Roster& r);
    private:
        Student* contents;
        int size;
        int capacity;

    public:
        //default constructor
        Roster();

        //destructor
        ~Roster();

        void addStudent(const Student& s);
        void removeStudent();

        //getters
        Student* const getContents();
        int const getSize();
        int const getCapacity();

        //setters
        void setContents(Student* s);
        void setSize(int n);
        void setCapacity(int n);

        //operator overloads
        Roster operator=(Roster& changeTo);

};

//Course class declaration
class Course{
    private:
        std::string name;
        std::string code;
        Roster roster;

    public:
        //default Constructor
        Course();

        //parameterized constructor
        Course(std::string name, std::string code);

        void addStudent();
        void removeStudent();

        //getters
        std::string  const getName();
        std::string const getCode();
        Roster const getRoster();

        //setters
        void setName(std::string s);
        void setCode(std::string c);
        void setRoster(Roster r);
        
        //operator overloads
        Course operator=(Course changeTo);


};

//Misc Funcitons
char menuFunction();
int getRemoveInd(Course list[], int count);
std::ostream& operator<<(std::ostream& o, Course& c);
