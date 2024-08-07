#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

// Class to store student information
class Student {
private:
    // Member variables to store student details
    string name;
    int rollNumber;
    string className;
    char division;
    string dateOfBirth;
    string bloodGroup;
    string contactAddress;
    string telephoneNumber;
    string drivingLicenseNumber;
    string otherInfo;

    // Static member variable to keep track of the number of students
    static int studentCount;

public:
    // Default constructor
    Student() : name("Unknown"), rollNumber(0), className("Unknown"), division(' '), dateOfBirth("Unknown"),
                bloodGroup("Unknown"), contactAddress("Unknown"), telephoneNumber("Unknown"),
                drivingLicenseNumber("Unknown"), otherInfo("Unknown") {
        ++studentCount;
    }

    // Parameterized constructor
    Student(string name, int rollNumber, string className, char division, string dateOfBirth,
            string bloodGroup, string contactAddress, string telephoneNumber, 
            string drivingLicenseNumber, string otherInfo) :
            name(name), rollNumber(rollNumber), className(className), division(division),
            dateOfBirth(dateOfBirth), bloodGroup(bloodGroup), contactAddress(contactAddress),
            telephoneNumber(telephoneNumber), drivingLicenseNumber(drivingLicenseNumber), otherInfo(otherInfo) {
        ++studentCount;
    }

    // Copy constructor
    Student(const Student &other) {
        this->name = other.name;
        this->rollNumber = other.rollNumber;
        this->className = other.className;
        this->division = other.division;
        this->dateOfBirth = other.dateOfBirth;
        this->bloodGroup = other.bloodGroup;
        this->contactAddress = other.contactAddress;
        this->telephoneNumber = other.telephoneNumber;
        this->drivingLicenseNumber = other.drivingLicenseNumber;
        this->otherInfo = other.otherInfo;
        ++studentCount;
    }

    // Destructor
    ~Student() {
        --studentCount;
    }

    // Static member function to get the current student count
    static int getStudentCount() {
        return studentCount;
    }

    // Inline function to display student details
    inline void display() const {
        cout << "Name: " << name << "\nRoll Number: " << rollNumber << "\nClass: " << className
             << "\nDivision: " << division << "\nDate of Birth: " << dateOfBirth << "\nBlood Group: "
             << bloodGroup << "\nContact Address: " << contactAddress << "\nTelephone Number: "
             << telephoneNumber << "\nDriving License Number: " << drivingLicenseNumber << "\nOther Info: "
             << otherInfo << endl;
    }

    // Function to update student details
    void updateDetails(string name, int rollNumber, string className, char division, string dateOfBirth,
                       string bloodGroup, string contactAddress, string telephoneNumber, 
                       string drivingLicenseNumber, string otherInfo) {
        this->name = name;
        this->rollNumber = rollNumber;
        this->className = className;
        this->division = division;
        this->dateOfBirth = dateOfBirth;
        this->bloodGroup = bloodGroup;
        this->contactAddress = contactAddress;
        this->telephoneNumber = telephoneNumber;
        this->drivingLicenseNumber = drivingLicenseNumber;
        this->otherInfo = otherInfo;
    }
};

// Initialize static member variable
int Student::studentCount = 0;

int main() {
    try {
        // Create students using default and parameterized constructors
        Student student1;   // Default constructor
        Student student2("Lalit Kumar", 21, "2nd B.E", 'B', "07/06/2004", "B+", "Baldev, Mathura", "9389560922", "DL12345", "N/A"); // Parameterized constructor

        // Display student details
        cout << "Student 1 details (using default constructor):" << endl;
        student1.display();
        cout << "------------------" << endl;

        cout << "Lalit details (student 2, using parameterized constructor):" << endl;
        student2.display();
        cout << "------------------" << endl;

        // Update student 1 details
        student1.updateDetails("Dushyant", 23, "12th", 'A', "01/01/2003", "O+", "Badmoss of Bharatpur", "1234567890", "DL67890", "N/A");
        
        // Display updated student 1 details
        cout << "Updated Student 1 details:" << endl;
        student1.display();
        cout << "------------------" << endl;

        // Display the student count
        cout << "Total Students: " << Student::getStudentCount() << endl;

    } catch (const exception &e) {
        // Handle any exceptions that may occur
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}
