// Programming Technique II (SECJ1023)
// Semester 1, 2022/2023

// Exercise 5: Polymorphism and inheritance

// Write your name and your partner's name.
// Only one submission is required per pair
// Submit only the source code file.
// Use only one source code file for this exercise. However, class declaration and definition
//  must be separated within the same file.

//! Pair Programming - Members Names and Location
//! Name 1: Md Jubayer Islam (A23MJ4007)
//! Name 2: Zinut Ferdous (A23MJ4017)

#include <iostream>
#include <string>
using namespace std;

//-------------------------------------------------------------------------------------------------------------
// Class declarations >> Student, Mentor, Coach, Support and Mentee
//-------------------------------------------------------------------------------------------------------------
// Class Student is fully given. Do nothing on this class.

class Student
{
protected:
    string name;

public:
    Student(string n = "");
    string getName() const;
    void setName(string n);
};

// Task 1(a): Declare the class Mentor.
class Mentor : public Student
{
protected:
    double cpa;

public:
    Mentor();
    Mentor(string n, double c);
    virtual void edit();
    virtual void print();
};

// Task 1(b): Declare the class Coach.
class Coach : public Mentor
{
protected:
    string expertise;

public:
    Coach(string name, double cpa, string expertise);
    void getExpertise() const;
    void setExpertise(string expertise);
    void edit();
    void print();
};

// Task 1(c): Declare the class Support.
class Support : public Mentor
{
protected:
    string phone;

public:
    Support(string name, double cpa, string phone);
    void getPhone() const;
    void setPhone(string phone);
    void edit();
    void print();
};

// Task 1(d): Declare the class Mentee.
class Mentee : public Mentor
{
private:
    Mentor *mentor;

protected:
    int level;

public:
    Mentee(string name, int level);
    void assignMentor(Mentor *mentor);

    void displayInfo() const;
    void displayMentor();
};

//-------------------------------------------------------------------------------------------------------------
// Class definition >> Student
//-------------------------------------------------------------------------------------------------------------
// Class Student is given. Do nothing on this class.

Student::Student(string n) : name(n) {}
string Student::getName() const { return name; }
void Student::setName(string n) { name = n; }

//-------------------------------------------------------------------------------------------------------------
// Class definition >> Mentor
//-------------------------------------------------------------------------------------------------------------
// Task 2: Define all methods for the class Mentor.
Mentor::Mentor() {}
Mentor::Mentor(string n, double c)
{
    name = n;
    cpa = c;
}

void Mentor::edit()
{
    cout << "Enter new name: ";
    cin >> name;
    cout << "Enter new CPA: ";
    cin >> cpa;
}

void Mentor::print()
{
    cout << "Name: " << name << endl;
    cout << "CPA: " << cpa << endl;
}

//-------------------------------------------------------------------------------------------------------------
// Class definition >> Coach
//-------------------------------------------------------------------------------------------------------------
// Task 3:  Define all methods for the class Coach.
Coach::Coach(string name, double cpa, string expertise)
{
    this->name = name;
    this->cpa = cpa;
    this->expertise = expertise;
}

void Coach::getExpertise() const
{
    cout << "Expertise: " << expertise << endl;
}

void Coach::setExpertise(string expertise)
{
    this->expertise = expertise;
}

void Coach::edit()
{
    cout << "Enter new expertise: ";
    cin >> expertise;
}

void Coach::print()
{
    cout << "Name: " << name << endl;
    cout << "CPA: " << cpa << endl;
    cout << "Expertise: " << expertise << endl;
}

//-------------------------------------------------------------------------------------------------------------
// Class definition >> Support
//-------------------------------------------------------------------------------------------------------------
// Task 4: Define all methods for class Support.
Support::Support(string name, double cpa, string phone)
{
    this->name = name;
    this->cpa = cpa;
    this->phone = phone;
}

void Support::getPhone() const
{
    cout << "Phone: " << phone << endl;
}

void Support::setPhone(string phone)
{
    this->phone = phone;
}

void Support::edit()
{
    cout << "Enter new phone number: ";
    cin >> phone;
}

void Support::print()
{
    cout << "Name: " << name << endl;
    cout << "CPA: " << cpa << endl;
    cout << "Phone: " << phone << endl;
}

//-------------------------------------------------------------------------------------------------------------
// Class definition >> Mentee
//-------------------------------------------------------------------------------------------------------------
// Task 5: Define all methods for the class Mentee.
Mentee::Mentee(string name, int level)
{
    this->name = name;
    this->level = level;
}

void Mentee::assignMentor(Mentor *mentor)
{
    this->mentor = mentor;
}

void Mentee::displayInfo() const
{
    cout << "Name: " << name << endl;
    cout << "Level: " << level << endl;
}

void Mentee::displayMentor()
{
    cout << "Mentor: ";

    if (mentor == NULL)
    {
        cout << "No mentor assigned" << endl;
    }
    else
    {
        mentor->print();
    }
}
//-------------------------------------------------------------------------------------------------------------
// The menu function is given
int menu()
{
    cout << endl;
    cout << "========== Menu ==========" << endl;
    cout << "1. Select first mentor" << endl;
    cout << "2. Select second mentor" << endl;
    cout << "3. Display selected mentor" << endl;
    cout << "4. Edit selected mentor" << endl;
    cout << "5. Assign selected mentor to mentee" << endl;
    cout << "6. Unassign mentor from mentee" << endl;
    cout << "7. Display all mentees" << endl;
    cout << "9. Exit" << endl;
    cout << endl;

    int choice;
    cout << "Choose an operation [1-7, or 9] => ";
    cin >> choice;

    cin.ignore();
    cout << endl;

    return choice;
}

//-------------------------------------------------------------------------------------------------------------
// The Main Function
//-------------------------------------------------------------------------------------------------------------

int main()
{
    // Given an array of mentees.
    Mentee mentees[3] = {Mentee("Abdul Samad", 2),
                         Mentee("Nurdiana", 1),
                         Mentee("Nurazlan", 2)};
    int index; // the index of mentee that the user wants to work on. To be used in case 5 and case 6

    // Given two mentors

    Coach mentor1("Ahmad Kamal", 3.87, "Programming");
    Support mentor2("Siti Aminah", 3.98, "0123456789");

    // Task 6(a): Declare a pointer to be used for pointing to a coach-mentor or a support-mentor.
    //            Initialize this pointer to point to any of the mentors (mentor1 or mentor2).

    Mentor *mentorPtr = &mentor1;

    int operation; // menu operation chosen by the user

    operation = menu();

    while (operation != 9)
    {
        switch (operation)
        {
        case 1: // Task 6(b): Select the first mentor (mentor1), as the current mentor.
            mentorPtr = &mentor1;

            cout << "First mentor is selected" << endl;
            break;

        case 2: // Task 6(c): Select the second mentor (mentor2), as the current mentor.
            mentorPtr = &mentor2;
            cout << "Second mentor is selected" << endl;
            break;

        case 3: // Task 6(d): Display the name of the selected mentor.

            cout << "Current selected mentor: ";
            mentorPtr->print();
            cout << endl;
            break;

        case 4: // Task 6(e): Edit the selected mentor.
            mentorPtr->edit();

            break;

        case 5: // Task 6(f): Assign the selected mentor to a mentee.
            cout << "Enter the index of mentee to assign with the current mentor => ";
            cin >> index;
            mentees[index].assignMentor(mentorPtr);

            break;

        case 6: // Task 6(g): Unassign the mentor from a mentee.
            cout << "Enter the index of mentee to remove its mentor => ";
            cin >> index;
            cout << "Mentor is removed from the mentee" << endl;
            break;

        case 7: // Task 6(h): Display the info for each of the mentees.
            cout << "List of mentees:" << endl;
            for (int i = 0; i < 3; i++)
            {
                int j = i + 1;
                cout << "Mentee " << j << endl;
                mentees[i].displayInfo();
                cout << endl;
                mentees[i].displayMentor();
            }

            break;

        } // switch

        operation = menu();

    } // while

    system("pause"); // You may want to comment out this line (system("pause")) if you are using Dev C++
    return 0;
}
