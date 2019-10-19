#include <iostream>
#include <memory>
#include <random>
#include <fstream>
#include <functional>

using namespace std;


double get_average(shared_ptr<int[]> arr, int n);
int user_prompt(int from, int to);

void fill_arr(shared_ptr<int[]> arr, int n);
void fill_keyboard(shared_ptr<int[]> arr, int n);
void fill_rand(shared_ptr<int[]> arr, int n);
void fill_file(shared_ptr<int[]> arr, int n);



int main()
{
    cout << "Enter array size: ";
    int n = user_prompt(1, 1024);
    shared_ptr<int[]> arr(new int[n]);
    fill_arr(arr, n);

    double avg = get_average(arr, n);

    cout << "Result: " << avg << endl;

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


double get_average(shared_ptr<int[]> arr, int n)
{
    double avg = 0.0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0 && i % 2 == 1 ) {
            avg += arr[i];
            count++;
        }
    }
    avg /= (double) count;

    return avg;
}


void fill_arr(shared_ptr<int[]> arr, int n)
{
    cout << "Read array from...\n"
         << "\t1. Keyboard\n"
         << "\t2. Random\n"
         << "\t3. File\n";

    int choice = user_prompt(1, 3);

    switch (choice)
    {
    case 1: 
        fill_keyboard(arr, n);
        break;
    case 2: 
        fill_rand(arr, n);
        break;
    case 3: 
        fill_file(arr, n);
        break;
    }
}


void fill_keyboard(shared_ptr<int[]> arr, int n)
{
    cout << "Enter array elements:\n";
    
    vector<float>::size_type i;

    for (i = 0; i < n; i++)
    {
        cout << "[" << i << "]= ";
        cin >> arr[i];  
    }
}


void fill_rand(shared_ptr<int[]> arr, int n)
{
    default_random_engine generator;
    uniform_int_distribution<int> distribution(-100, 100);
    auto dice = bind ( distribution, generator );
    
    vector<int>::size_type i;

    for (i = 0; i < n; i++)
        arr[i] = dice();
}


void fill_file(shared_ptr<int[]> arr, int n)
{
    string filename;
    ifstream file;

    cout << "Enter file name: ";
    cin >> filename;

    file.open(filename);

    if (!file) { 
        cout << "Unable to open file!\n";
        return;
    }

    cout << "Reading data from file...\n";

    for (int i = 0; i < n; i++)
        file >> arr[i];
    
    cout << "Complete.\n";

    file.close();
}