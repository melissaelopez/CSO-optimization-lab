/*
 * author: Melissa Lopez
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "proj3.h"

// Implement a C function called level_3_opt. It should perform the same 
// task as the implemented level_3 function. 
// In the comments for the function describe why your changes make the
// function more cache friendly. 
//
// Note: your function needs to compute the entire matrix C,
// not only its x entry. 

long level_3(long * B, long * A, int x){

	long * C = (long * ) calloc (N,sizeof(long) );
	if (!C) return 0; 
	
	// N = 3
	// c=0,r=0, c[0] = B[0] + A[0]
	// c=0,r=1, c[1] = B[3] + A[1]
	// c=0,r=2, c[2] = B[6] + A[2]

	// c=1,r=0, c[0] = B[1] + A[3]
	// c=1,r=1, c[1] = B[4] + A[4]
	// c=1,r=2, c[2] = B[7] + A[5]

    int c, r; 

    for(c = 0; c < N; c++)
        for(r = 0; r < N; r++)
            C[ r ] = B[ r*N + c ] + A[ c*N + r ] ;
	
	long ret = C[x];
	free (C); C = 0; 
    return ret;
}

// This is optimized by taking into account that we are constantly overwriting
// information in level_3, and it's completely unneccesary. In my version, we're
// only finding those values that we need to contruct our array, and only using

long level_3_opt(long * B, long * A, int x){

	long * C = (long * ) calloc (N,sizeof(long) );
	if (!C) return 0; 

	// long * D = (long * ) calloc (N,sizeof(long) );
	// if (!D) return 0; 

	// long * E = (long * ) calloc (N,sizeof(long) );
	// if (!E) return 0; 
	
	int c, r;

	for(r = 0; r < N; r++)
    	C[ r ] = B[ r*N + (N - 1) ]+ A[(N - 1)*N + r ];

    // for(c = 0; c < N; c++)
    //     for(r = 0; r < N; r++)
    //         D[ r ] = A[ c*N + r ];

    // for(r = 0; r < N; r++)
    //     for(c = 0; c < N; c++)
    //         E[ r ] = B[ r*N + c ];

    // for(r = 0; r < N; r++){
    // 	C[r] = D[r] + E[r];
    // }

	//DO NOT modify the rest of this function 
	long ret = C[x];
	free (C); C = 0; 
    return ret;
}
