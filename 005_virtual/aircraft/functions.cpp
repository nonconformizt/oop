#ifndef FUNCTIONS_CPP
#define FUNCTIONS_CPP

#include <iostream>
#include <queue>
#include "aircraft.cpp"




int user_prompt(int from, int to)
{
	int tmp = 0;
	do
	{
		std::cin >> tmp;
	}
	while (tmp < from || tmp > to);
	return tmp;
}


std::queue<oop::Flight*> 
getFlightQueue()
{
    int tmp;
    std::queue<oop::Flight*> queue;

    std::cout << "Insert flight data: ";

    while (true)
    {
        auto flight = new oop::Flight();
        queue.push(flight);

        std::cout << "Enter 0 to finish, any number to continue\n";
        std::cin >> tmp;
        if (tmp == 0) break;
    }

    return queue;
}


oop::Tree<queue<oop::Flight*>> *
getFlightTree(std::string filename)
{
    auto flighttree = new oop::Tree<queue<oop::Flight*>>();

    ifstream file(filename);

    int tmp_number;
    int tmp_time;
    string tmp_days;
    int iscontinue;

    while (true)
    {
        queue <oop::Flight*> tmp_queue;

        while (true)
        {
            file >> tmp_number;
            if (tmp_number == -1)
                break;
            file >> tmp_time;
            getline(file, tmp_days);
            getline(file, tmp_days);

            cout << tmp_number << endl;
            cout << tmp_time << endl;
            cout << tmp_days << endl;

            tmp_queue.push(new oop::Flight(tmp_number, tmp_time, tmp_days));
        }

        flighttree->insert(tmp_queue);

        if (file.eof()) break;
    }

    return flighttree;
}





#endif // FUNCTIONS_CPP