#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <functional> // for  bind()
#include <bits/stdc++.h> // for sort()

using namespace std;


bool menu(vector<float> * arr);

void action1(vector<float> * arr);
void action2(vector<float> * arr);
void action3(vector<float> * arr);
void action4(vector<float> * arr);

void show_arr(vector<float> arr);
void fill_arr(vector<float> * arr);
void sort_arr(vector<float> * arr);
void save_arr(vector<float> arr);
void fill_keyboard(vector<float> * arr);
void fill_rand(vector<float> * arr);
void fill_file(vector<float> * arr);

int user_prompt(int from, int to);
bool print_array_tofile(vector<float> arr, string filename);





int main() 
{
    cout << "Enter number of elements: ";
    int n = user_prompt(1, 1024);

    vector<float> arr(n);

    fill_arr(&arr);
    show_arr(arr);

    while (menu(&arr))
        ;


    save_arr(arr);

}



bool menu(vector<float> * arr)
{
    cout << "Choose action: \n"
        << "\t1. Elements not greater than 1 in absolute value first, then others.\n"
        << "\t2. Replace with zero element with greatest fractional part.\n"
        << "\t3. Delete the longest sequence of positive numbers\n"
        << "\t4. Insert the average value after the smallest element\n"
        << "\t5. Sort array\n"
        << "\t0. Exit\n";

    int choice = user_prompt(0, 5);

    switch (choice)
    {
    case 0:
        // save_arr(*arr, *n);
        return false;
        break;
    case 1:
        action1(arr);
        break;
    case 2:
        action2(arr);
        break;
    case 3:
        action3(arr);
        break;
    case 4:
        action4(arr);    
        break;
    case 5:
        sort_arr(arr);
        break;
    }

    cout << "Result: \n";
    show_arr(*arr);

    return true;
}


void action1(vector<float> * arr)
{
    int last = 0;
    float t;

    for (int i = 0, last = 0; i < (*arr).size(); i++)
    {
        if (abs((*arr)[i]) <= 1) {
            t = (*arr)[i];
            (*arr)[i] = (*arr)[last];
            (*arr)[last] = t;
            last++;
        }
    }

}


void action2(vector<float> * arr)
{
    float max_fract = 0.0, temp, fract;
    int max_i = 0;

    for (int i = 0; i < (*arr).size(); i++)
    {
        fract = abs(modf((*arr)[i], &temp));
        if (fract > max_fract) {
            max_fract = fract;
            max_i = i;
        }
    }

    (*arr)[max_i] = 0.0;
}


void action3(vector<float> * arr)
{

    int max_seq_start = 0, max_seq_len = 0, seq_len = 0, seq_start = 0; 
  
    for (int k = 0; k < arr->size(); k++) { 
        if ((*arr)[k] > 0) { 
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
            seq_len = 0; 
        } 
    }

    if (seq_len > max_seq_len) { 
        max_seq_len = seq_len; 
        max_seq_start = seq_start; 
    }

    cout << "Longest sequence of positive elements: start=" 
         << max_seq_start 
         << " end=" << max_seq_start + max_seq_len << endl;

    arr->erase(arr->begin() + max_seq_start, arr->begin() + max_seq_start + max_seq_len);
}


void action4(vector<float> * arr)
{
    // find average element 
    // and smallest element index

    float avg = 0;
    float min = MAXFLOAT;
    int min_i;


    for (int i = 0; i < arr->size(); i++)
    {
        avg += (*arr)[i];
        if ((*arr)[i] < min) {
            min = (*arr)[i];
            min_i = i;
        }
    }
    avg /= (float) arr->size();

    // insert average after smallest element

    arr->insert(arr->begin() + min_i + 1, avg);
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


void show_arr(vector<float> arr) 
{
    vector<float>::const_iterator i;

    for (i = arr.begin(); i != arr.end(); i++)
        cout << *i << " ";
    cout << endl;
}


void fill_arr(vector<float> * arr)
{
    cout << "Read array from...\n"
         << "\t1. Keyboard\n"
         << "\t2. Random\n"
         << "\t3. File\n";

    int choice = user_prompt(1, 3);

    switch (choice)
    {
    case 1: 
        fill_keyboard(arr);
        break;
    case 2: 
        fill_rand(arr);
        break;
    case 3: 
        fill_file(arr);
        break;
    }
}


void fill_keyboard(vector<float> * arr)
{
    cout << "Enter array elements:\n";
    
    vector<float>::size_type i;

    for (i = 0; i != (*arr).size(); i++)
    {
        cout << "[" << i << "]= ";
        cin >> (*arr)[i];  
    }
}


void fill_rand(vector<float> * arr)
{
    default_random_engine generator;
    uniform_real_distribution<float> distribution(-100.0, 100.0);
    auto dice = bind ( distribution, generator );

    
    vector<float>::size_type i;

    for (i = 0; i != (*arr).size(); i++)
        (*arr)[i] = dice();
}


void fill_file(vector<float> * arr)
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

    for(auto & value: *arr)
        file >> value;
    
    cout << "Complete.\n";


    file.close();
}

void sort_arr(vector<float> * arr)
{
    cout << "Sorting...\n";

    float * A = arr->data();
    int i, j, smallest_i;
    float smallest;


    for (i = 0; i < arr->size() - 1; i++)
    {
        smallest = A[i];
        smallest_i = i;
        for (j = i + 1; j < arr->size(); j++)
        {
            if (A[j] < smallest) {
                smallest = A[j];
                smallest_i = j;
            }
        }
        A[smallest_i] = A[i];
        A[i] = smallest;
    }


    cout << "Result: ";
}


void save_arr(vector<float> arr)
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
        result = print_array_tofile(arr, filename);
    }
    while (!result);

    cout << "File written successfully! Bye.\n";
}


bool print_array_tofile(vector<float> arr, string filename)
{
	ofstream output;
	output.open(filename);
    
	if (output.is_open()) {
        cout << "File opened\n";
        for(auto el : arr)
            output << el << " ";
        output << endl;
    }
    else {
        cout << "Cannot open file!\n";
        return false;
    }

	output.close();
    return true;
}