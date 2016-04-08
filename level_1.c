/*
 * author: 
 * 
 */
  
#include <stdlib.h>
#include <stdio.h>

#include "proj3.h"

// Implement a C function called level_1_opt. It should perform the same 
// task as the implemented level_1 function. 
// In the comments for the function describe why your changes make the
// function more cache friendly. 
//
// Note: your function needs to compute the entire matrix A,
// not only its x+y entry. 


double level_1(double * B, double * A, int x, int y )
{	
    int i, j; 

    for(i = 0; i < LARGE; i++)
        for(j = 0; j < SMALL; j++){
            A[ i ] = A[i] + B[  j*LARGE + i ] ;
		}

    return A[x+y];
}

double level_1_opt(double * B, double * A, int x, int y )
{	
	
	
	
	
	
	
	



	//DO NOT modify the rest of this function 
    return A[x+y];
}
