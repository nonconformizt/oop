
void exportCVS(double points[][2], int points_n, double * result, int k);
void printGauss(double ** mat, int n);
void printResult(double * vec, int n);
double polynome(double * a, int n, double x);
double npow(double x, int y);


void exportCVS(double points[][2], int points_n, double * result, int k)
{
    double x;
    ofstream output;
    output.open("result.csv");

    output << "x,y\n";

    for (int i = 0; i < points_n; i++)
    {
        x = points[i][0];
        output << x << "," << points[i][1] << endl;
    }

    output << "\n\n\n\n\nx,f(x)\n";

    double start = points[0][0];
    double end = points[points_n - 1][0];
    for (double j = start, step = (end-start)/100; j <= end; j += step)
    {
        output << j << "," << polynome(result, k, j) << endl;
    }


    output.close();
}



void printGauss(double ** mat, int n) 
{ 
    for (int i = 0; i < n; i++, printf("\n")) 
        for (int j = 0; j <= n; j++) 
            printf("%lf ", mat[i][j]); 

    printf("\n");
} 
  

double npow(double x, int y)
{
    double res = 1.0;
    for (int i = 0; i < y; i++)
        res *= x;
    return res;
}


double polynome(double * a, int n, double x)
{
    double y = 0.0;
    for (int i = 0; i < n; i++) 
        y += a[i] * npow(x, i);
    return y;
}


void printResult(double * vec, int n)
{
    cout << "Result: ";
    for (int i = 0; i < n; i++)
        cout << vec[i] << " ";
    cout << endl;
}