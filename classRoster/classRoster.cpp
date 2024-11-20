#include "classRoster.h"

char menuFunction()
{
    char sel;

    std::cout << "Please select one of the following options:\n"
              << "(A) Create a course\n(B) Remove a Course\n(C) List all "
              << "courses\n(D) Enroll a student in a course\n(E) Remove "
              << "a student from a course\n(F) Exit Course Creator\nSelection: ";
        
    std::cin >> sel;
    sel = toupper(sel);
    
    return sel;
}

// Student function definitiond
// default constructor
Student::Student()
{
    name = " ";
    ID = " ";
    classification = ' ';
}

Student::Student(std::string n, std::string id, char year){
    name = n;
    ID = id;
    classification = year;
}
// getters
std::string const Student::getName()
{
    return name;
}

std::string const Student::getID()
{
    return ID;
}

char const Student::getClassification()
{
    return classification;
}

// setters
void Student::setName(std::string n)
{
    name = n;
}

void Student::setID(std::string id)
{
    ID = id;
}

void Student::setClassification(char c)
{
    classification = c;
}

// Roster function definitions
// default constructor
Roster::Roster()
{
    capacity = 5;
    size = 0;
    contents = new Student[capacity];
}

// destructor with delete operator
Roster::~Roster()
{
    delete[] contents;
}

//Add student Fuction
void Roster::addStudent(const Student& s){
    if(size == capacity){
        Student* temp;
        capacity += 5;
        temp = new Student[capacity];
        for(int i = 0; i< size; i++)
            temp[i] = contents[i];
        contents = temp;
        delete [] temp;
    }    
    contents[size] = s;
    size++;
}

void Roster::removeStudent(){
    std::string n;
    bool valid;
    int index;

    std::cout << "Input name of the student you want to remove: ";
    while(!valid){
        std::cin >> n;

        for (int i = 0; i < size; i++){
                if (n == contents[i].getName()){
                    index = i;
                    valid = true;
                }
        }

        if (!valid)
            std::cout << "Invalid input. Try again\n";
    }
        for(int i=index; i < size -1; i++)
            contents[index] = contents[index+1];
}

// getters
Student* const Roster::getContents()
{
    return contents;
}

int const Roster::getSize()
{
    return size;
}

int const Roster::getCapacity()
{
    return capacity;
}

// setters
void Roster::setContents(Student *s)
{
    contents = s;
}

void Roster::setSize(int n)
{
    size = n;
}

void Roster::setCapacity(int n)
{
    capacity = n;
}

Roster Roster::operator=(Roster &changeTo)
{
    Roster r;
    r.setContents(changeTo.contents);

    return r;
}

// Course class defintions
// friend defintions
int getRemoveInd(Course list[], int count)
{
    // declare necessary variable
    std::string n;
    int ind;
    bool valid = false;

    while (!valid)
    {
        std::cout << "Input name of course you want to delete: ";
        std::cin >> n;

        for (int i = 0; i < count; i++)
        {
            if (n == list[i].getName())
            {
                ind = i;
                valid = true;
            }
        }

        if (!valid)
            std::cout << "Invalid input. Try again\n";
    }
    return ind;
}

// default consstructor
Course::Course()
{
}

// Parameterized constructor
Course::Course(std::string name, std::string code)
{
    this->name = name;
    this->code = code;
}

// getters
std::string const Course::getName()
{
    return name;
}

std::string const Course::getCode()
{
    return code;
}

Roster const Course::getRoster()
{
    return roster;
}

// setters
void Course::setName(std::string s)
{
    name = s;
}

void Course::setCode(std::string c)
{
    code = c;
}

void Course::addStudent(){
    std::string courseName, studentName, studentId;
    char studentClass;
    int ind;
    
    std::cout << "What is the Students name: ";
    std::cin >> studentName;
    std::cout << "What is the students ID: ";
    std::cin >> studentId;
    std::cout << "What year is the student: ";
    std::cin >> studentClass;
    
    std::cout << "What is the index of the class to add them to: ";
    std::cin >> ind;

    Student tempStud(studentName, studentId, studentClass);
    

    roster.addStudent(tempStud);
}

void Course::removeStudent(){
    roster.removeStudent();
}

void Course::setRoster(Roster r)
{
    roster = r;
}

Course Course::operator=(Course changeTo)
{
    Course c;
    c.setName(changeTo.name);
    c.setCode(changeTo.code);

    return c;
}

std::ostream &operator<<(std::ostream &o, Course &c)
{
    return std::cout << "Name: " << c.getName() << "\t\tCode: " << c.getCode() << std::endl;
}
std::ostream& operator<<(std::ostream& o, Roster& r){
    return std :: cout << r.getContents();
}

std:: ostream& operator<< (std::ostream& o, Student& s){
    return std::cout << s.getName() << "\t\t" << s.getID() << "\t\t" << s.getClassification() << std::endl;
}
