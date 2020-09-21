#include<stdio.h>
#include "array_merge.h"
int main( int argc, const char* argv[] ){
	int num_arrays = 1;
	  int sizes[] = { 1 };
	    int a0[] = { 5 };
	      int* a[] = { a0 };
	        
		  int* result;

		    result = array_merge(num_arrays, sizes, a);

}
