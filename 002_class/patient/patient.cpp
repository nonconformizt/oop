#include <iostream>
#include <vector>
#include <time.h>
#include <limits.h>
using namespace std;


class Patient {

private:
    string firstName, lastName, fatherName;
    string address;
    int year;
    int number;
    string diagnosis;

public:
    Patient() {};

    Patient(string first, string last, string father, string diagn, int b_year, int num)
    {
        firstName = first;
        lastName = last;
        fatherName = father;
        diagnosis = diagn;
        year = b_year;
        number = num;
    }

    void print()
    {
        cout << this->lastName << " " << this->firstName << " " << this->fatherName << endl;
        cout << "Год рождения: " << this->year << endl; 
        cout << "Номер карты: " << this->number << endl; 
        cout << "Диагноз: " << this->diagnosis << endl; 
    }

    bool is_year_interval (int from, int to)
    {
        return (year >= from && year <= to);
    }

    bool is_diagnosis (string diagn)
    {
        return diagnosis == diagn;
    }

    bool is_number_interval (int from, int to)
    {
        return (number >= from && number <= to);
    }

};


struct NotFoundException : public exception {
   const char * what () const throw () {
      return "Ошибка: диагноз не найден!\n";
   }
};

struct IncorrectDataException : public exception {
   const char * what () const throw () {
      return "Ошибка: неверные вхоные данные!\n";
   }
};



int user_prompt(int from, int to);
void find_diagnosis(vector<Patient> people);
void find_number_in_interval(vector<Patient> people);
void find_year_in_interval(vector<Patient> people);
void fill(vector<Patient> * people);



int main ()
{
    vector<Patient> people;

    fill(&people);


    do {
        cout << "\nВыберите действие:\n"
             << "1. Список пациентов, имеющих данный диагноз\n"
             << "2. Список пациентов, номер медицинской карты которых находится в заданном интервале\n"
             << "3. Количество пациентов, год рождения которых находится в заданном интервале\n"
             << "4. Выход\n";

        int choice = user_prompt(1, 4);

        switch (choice)
        {
        case 1:
            try
            {
                find_diagnosis(people);
            }
            catch(const NotFoundException& e)
            {
                std::cout << e.what();
            }
            break;

        case 2:
            try
            {
                find_number_in_interval(people);
            }
            catch(const IncorrectDataException& e)
            {
                std::cout << e.what();
            }
            break;
        
        case 3:
            try
            {
                find_year_in_interval(people);
            }
            catch(const IncorrectDataException& e)
            {
                std::cout << e.what();
            }
            break;

        default:
            return 0;
            break;
        }

    } while (true);

}


int user_prompt(int from, int to)
{
	int tmp = 0;
	do
	{
		cin >> tmp;
	}
	while (tmp < from || tmp > to);
	return tmp;
}


void find_diagnosis(vector<Patient> people)
{
    bool found = false;
    string diagn;
    cout << "Введите диагноз (от а до е): ";
    cin >> diagn;

    cout << "Результаты поиска:\n";

    for (auto p : people)
    {
        if (p.is_diagnosis(diagn)) {
            found = true;
            p.print();
        }
    }
    
    if (!found)
        throw NotFoundException();
}


void find_number_in_interval(vector<Patient> people)
{
    int start, end;

    cout << "Введите начало интервала:\n";
    start = user_prompt(0, INT_MAX);
    cout << "Введите конец интервала:\n";
    end = user_prompt(0, INT_MAX);

    if (start > end)
        throw IncorrectDataException();
    else 
        for (auto p : people)
            if (p.is_number_interval(start, end))
                p.print();

}


void find_year_in_interval(vector<Patient> people)
{
    int start, end;

    cout << "Введите год начала интервала:\n";
    start = user_prompt(0, INT_MAX);
    cout << "Введите год конца интервала:\n";
    end = user_prompt(0, INT_MAX);

    if (start > end)
        throw IncorrectDataException();
    else
        for (auto p: people)
            if (p.is_year_interval(start, end))
                p.print();
}


void fill(vector<Patient> * people)
{
    string last_names[10] = {"Иванов", "Смирнов", "Кузнецов", "Попов", "Васильев", "Петров", "Соколов", "Михайлов", "Новиков", "Фёдоров"};
    string fisrt_names[10] = {"Андрей", "Сергей", "Дмитрий", "Юрий", "Ярослав", "Денис", "Иван", "Михаил", "Алексей", "Александр"};
    string father_names[10] = {"Андреевич", "Сергеевич", "Дмитриевич", "Юриьевич", "Ярославович", "Денисович", "Иванович", "Михайлович", "Алексеевич", "Александрович"};
    string diag[5] = {"a", "b", "c", "d", "e"};

    srand(time(nullptr));

    for (int i = 0; i < 10; i++)
    {
        people->push_back(Patient(
            fisrt_names[rand() % 10],
            last_names[rand() % 10],
            father_names[rand() % 10],
            diag[rand() % 5],
            rand() % 60 + 1950, 
            rand() % 10000
        ));
    }
}