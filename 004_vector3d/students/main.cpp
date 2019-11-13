#include <iostream>
#include <list>
using namespace std;

class Student {

public: 
    string firstName, 
           fatherName, 
           lastName;
    
    Student(string last, string first, string father) 
    {
        firstName = first;
        fatherName = father;
        lastName = last;
    }
};


void countStudentsByFathername(list<Student*> * students)
{
    string fathername;
    cout << "Введите отчество:\n";
    cin >> fathername;
    auto count = 0;

    for (auto const & student : *students) 
        if(student->fatherName == fathername)
            count++;

    cout << "В базе " << count << " стдентов с отчеством " << fathername << endl;
}



int main ()
{
    list<Student*> students;

    {
        students.push_back(new Student("Иванов", "Иван", "Иванович"));
        students.push_back(new Student("Корж", "Богдан", "Андреевич"));
        students.push_back(new Student("Дудлин", "Андрей", "Дудлин"));
        students.push_back(new Student("Кургуз", "Михаил", "Андреевич"));
        students.push_back(new Student("Павловский", "Антон", "Евгеньевич"));
        students.push_back(new Student("Зубенко", "Михаил", "Петрович"));
        students.push_back(new Student("Рыбников", "Юрий", "Степанович"));
    }


    countStudentsByFathername(&students);

}