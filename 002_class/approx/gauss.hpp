

double * gauss(double ** mat, int n);
double * backSub(double ** mat, int n);
void forwardElim(double ** mat, int n);
void swapRow(double ** mat, int n, int i, int j);



double * gauss(double ** mat, int n) 
{ 
    /* reduction into r.e.f. */
    forwardElim(mat, n); 
  
    /* get solution to system using backward substitution */
    return backSub(mat, n); 
} 


// function for elementary operation of swapping two rows 
void swapRow(double ** mat, int n, int i, int j) 
{   
    for (int k = 0; k <= n; k++) 
    { 
        double temp = mat[i][k]; 
        mat[i][k] = mat[j][k]; 
        mat[j][k] = temp; 
    } 
} 


// function to reduce matrix to r.e.f. 
void forwardElim(double ** mat, int n) 
{
    for (int k = 0; k < n; k++) 
    { 
        // Initialize maximum value and index for pivot 
        int i_max = k;
        int v_max = mat[i_max][k];
  
        /* find greater amplitude for pivot if any */
        for (int i = k+1; i < n; i++)
            if (abs(mat[i][k]) > v_max)
                v_max = mat[i][k], i_max = i; 
  
        /* singularity check */
        /*if (!mat[k][i_max])
            return k; */
  
        /* Swap the greatest value row with current row */
        if (i_max != k) 
            swapRow(mat, n, k, i_max); 
  
  
        for (int i = k + 1; i < n; i++) 
        { 
            /* factor f to set current row kth element to 0, 
             * and subsequently remaining kth column to 0 */
            double f = mat[i][k] / mat[k][k]; 
  
            /* subtract fth multiple of corresponding kth 
               row element*/
            for (int j = k + 1; j <= n; j++) 
                mat[i][j] -= mat[k][j] * f; 
  
            /* filling lower triangular matrix with zeros*/
            mat[i][k] = 0; 
        } 
    } 
} 

  
// function to calculate the values of the unknowns 
// returns pointer to array of length n
double * backSub(double ** mat, int n)
{ 
    double * x = new double[n];  // An array to store solution 
  
    /* Start calculating from last equation up to the 
       first */
    for (int i = n - 1; i >= 0; i--) 
    { 
        /* start with the RHS of the equation */
        x[i] = mat[i][n]; 
  
        /* Initialize j to i+1 since matrix is upper 
           triangular*/
        for (int j = i + 1; j < n; j++) 
        { 
            /* subtract all the lhs values 
             * except the coefficient of the variable 
             * whose value is being calculated */
            x[i] -= mat[i][j] * x[j]; 
        } 

        /* divide the RHS by the coefficient of the 
           unknown being calculated */
        x[i] = x[i] / mat[i][i]; 
    } 

    return x;
} 
