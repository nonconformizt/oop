#include <bits/stdc++.h> 
using namespace std; 

#include "util.hpp"
#include "gauss.hpp"



#define K 4  // degree of the approximation polynome 


double ** getNormalSystem(double points[][2], int points_n, int k)
{
    double ** system = new double * [k + 1];
    double sum = 0;

    // TODO: optimization
    for(int i = 0; i <= k; i++) // loop through rows
    {
        system[i] = new double[k + 2];

        // fill LHS columns
        for (int j = 0; j <= k; j++)
        {
            sum = 0;
            // find sum of all x^(i+j)
            for (int p = 0; p < points_n; p++)
                sum += npow(points[p][0], i + j);

            system[i][j] = sum;
        }

        // fill RHS column
        sum = 0;
        // find sum of all y*(x^i)
        for (int p = 0; p < points_n; p++)
            sum += points[p][1] * npow(points[p][0], i);

        system[i][k + 1] = sum;

    }

    return system;
}


int main() 
{
    double points[9][2] = {
        {-1.00000, 3.41421},
        {-0.84776, 3.11069},
        {-0.41421, 2.41496},
        {0.23463, 1.87705},
        {1.00000, 1.91421},
        {1.76536, 2.32307},
        {2.41421, 2.80073},
        {2.84775, 3.15714},
        {3.00000, 3.28727}
    };

    double ** system = getNormalSystem(points, 9, K);

    cout << "Normal system: \n";
    printGauss(system, K + 1);

    // solve the system
    double * koefs = gauss(system, K + 1);

    printResult(koefs, K + 1);
    exportCVS(points, 9, koefs, K + 1);

}

