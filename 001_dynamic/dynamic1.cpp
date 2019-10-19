#include <iostream>
#include <fstream>
#include <functional>
#include <random>
#include <unistd.h>
#include <bits/stdc++.h>
using namespace std;


void fill_arr(float * arr, int n);
void fill_rand(float * arr, int n);
void fill_keyboard(float * arr, int n);
void fill_file(float * arr, int n);
   
void sort_arr(float * arr, int n);
void show_arr(float * arr, int n);
void save_arr(float * arr, int n);

bool menu(float ** arr, int * n);

void action1(float * arr, int * n);
void action2(float * arr, int * n);
void action3(float * arr, int * n);
void action4(float ** arr, int * n);

void remove_arr(float * arr, int * n, int start, int end);
bool print_array_tofile(float* arr, int n, string filename);

int main()
{
    int n;
    cout << "Enter number of elements: ";
    do 
        cin >> n;
    while (n <= 0);

    float * arr = new float[n]();

    fill_arr(arr, n);
    show_arr(arr, n);

    while (menu(&arr, &n))
        ;

    delete arr; 
    return 0;
}


bool menu(float ** arr, int * n)
{
    int choice;

    cout << "Choose action: \n"
        << "\t1. Elements not greater than 1 in absolute value first, then others.\n"
        << "\t2. Replace with zero element with greatest fractional part.\n"
        << "\t3. Delete the longest sequence of positive numbers\n"
        << "\t4. Insert the average value after the smallest element\n"
        << "\t5. Sort array\n"
        << "\t0. Exit\n";

    cin >> choice;

    switch (choice)
    {
    case 0:
        save_arr(*arr, *n);
        return false;
        break;
    case 1:
        action1(*arr, n);
        break;
    case 2:
        action2(*arr, n);
        break;
    case 3:
        action3(*arr, n);
        break;
    case 4:
        action4(arr, n);
        break;
    case 5:
        sort_arr(*arr, *n);
        break;
    }

    cout << "Result: \n";
    show_arr(*arr, *n);

    return true;
}


void action1(float * arr, int * n)
{
    int last = 0;
    float t;

    for (int i = 0, last = 0; i < *n; i++)
    {
        if (abs(arr[i]) <= 1) {
            t = arr[i];
            arr[i] = arr[last];
            arr[last] = t;
            last++;
        }
    }

}


void action2(float * arr, int * n)
{
    float max_fract = 0.0, temp, fract;
    int max_i = 0;

    for (int i = 0; i < *n; i++)
    {
        fract = abs(modf(arr[i], &temp));
        if (fract > max_fract) {
            max_fract = fract;
            max_i = i;
        }
    }

    arr[max_i] = 0.0;
}


void action3(float * arr, int * n)
{

    int max_seq_start = 0, max_seq_len = 0, seq_len = 0, seq_start = 0; 
  
    for (int k = 0; k < *n; k++) { 
        if (arr[k] > 0) { 
            seq_len++; 
  
            // new sequence, store beginning index. 
            if (seq_len == 1)  
                seq_start = k;             
        } 
        else { 
            if (seq_len > max_seq_len) { 
                max_seq_len = seq_len; 
                max_seq_start = seq_start; 
            } 
            seq_len  = 0; 
        } 
    }

    if (seq_len > max_seq_len) { 
        max_seq_len = seq_len; 
        max_seq_start = seq_start; 
    }

    cout << "Longest sequence of positive elements: start=" << max_seq_start << " end=" << max_seq_start + max_seq_len << endl;

    remove_arr(arr, n, max_seq_start, max_seq_start + max_seq_len - 1);
}


void action4(float ** arr, int * n)
{
    // find average element 
    // and smallest element index

    float avg = 0;
    float min = MAXFLOAT;
    int min_i, temp;


    for (int i = 0; i < *n; i++)
    {
        avg += (*arr)[i];
        if ((*arr)[i] < min) {
            min = (*arr)[i];
            min_i = i;
        }
    }
    avg /= (float) *n;

    // expand array

    *n  = *n + 1;
    (*arr) = (float*) realloc((*arr), sizeof(float) * *n);

    // insert average after smallest element

    for (int i = *n - 1; i > min_i + 1; i--)
        (*arr)[i] = (*arr)[i-1];
    
    (*arr)[min_i + 1] = avg;
}


void fill_arr(float * arr, int n)
{
    cout << "Read array from...\n"
         << "\t1. Keyboard\n"
         << "\t2. Random\n"
         << "\t3. File\n";

    int choice;

    do 
        cin >> choice;
    while (choice < 0 || choice > 3);

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


void fill_rand(float * arr, int n)
{
    default_random_engine generator;
    uniform_int_distribution<int> distribution(-100,100);
    auto dice = bind ( distribution, generator );

    for (int i = 0; i < n; i++)
        arr[i] = dice();   
}


void fill_keyboard(float * arr, int n)
{
    cout << "Вводите элементы массива:\n";
    for (int i = 0; i < n; i++) {
        cout << "[" << i << "]= ";
        cin >> arr[i];
    }
}


void fill_file(float * arr, int n)
{
    string filename;
    ifstream file;

    // считать имя файла
    cout << "Enter file name: ";
    cin >> filename;

    // считать данные из файла
    file.open(filename);

    if (!file) { 
        cout << "Unable to open file!\n";
        return;
    }

    float num;
    int i = 0;
    printf("Reading data from file...\n");
    while (file >> num && i < n) 
    {
        arr[i] = num;
        i++;
    }
    cout << "Complete.\n";


    file.close();
}


void show_arr(float * arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}


void sort_arr(float * arr, int n)
{
    int i, j, smallest_i;
    float smallest;

    cout << "Sorting...\n";

    for (i = 0; i < n - 1; i++)
    {
        smallest = arr[i];
        smallest_i = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < smallest) {
                smallest = arr[j];
                smallest_i = j;
            }
        }
        arr[smallest_i] = arr[i];
        arr[i] = smallest;
    }


    cout << "Result: ";
}


void remove_arr(float * arr, int * n, int start, int end)
{
    int length = end - start + 1;
    *n = *n - length;
    for (int i = start; i <= end; i++)
        arr[i] = arr[i + length];
}


bool print_array_tofile(float * arr, int n, string filename)
{
	ofstream output;
	output.open(filename);
    
	if (output.is_open()) {
        cout << "File opened\n";
		for (int i = 0; i < n; ++i)
			output << arr[i] << " ";
        output << endl;
    }
    else {
        cout << "Cannot open file!";
        return false;
    }

	output.close();
    return true;
}

void save_arr(float * arr, int n)
{
    char choice;
    cout << "Export results to file? (y/n)\n";
    cin >> choice;
    
    if (choice != 'y')
        return;

    string filename;
    bool result;

    do {
        cout << "File name: ";
        cin >> filename;
        result = print_array_tofile(arr, n, filename);
    }
    while (!result);

    cout << "File written successfully! Bye.\n";
}