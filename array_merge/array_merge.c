#include "array_merge.h"
#include "mergesort.h"
#include "mergesort.c"
#include<stdlib.h>
#include<cstdio>
int countUnique(int* arr, int size){
  int index =0;
  int count = 0; 
  // While number exist continue to check for repeat values
  if(size == 1){
    return count=1;

  }
  while( index < size-1 ){
    int curr = arr[index];
    int next = arr[index+1]; 
    if(curr == next ){
       index++;
    }
    else{
    count++;
    index++;
    }
  }
  if(size > 1){
    count++;

  } 
  
  return count;
}// end count Unique
int* catArray(int num_arrays, int* sizes, int** values){
  int length = 0;
  for(int i=0; i < num_arrays; i++){
	length += sizes[i];
  } 
  int* catArr = (int*) calloc(length +1, sizeof(int)); 
  int index = 0;
  while(num_arrays > 0){
     int arrSize = sizes[num_arrays-1];
     for(int i = 0; i< arrSize; i++){
       catArr[index]= values[num_arrays-1][i];
       index++;
     }
     num_arrays--;  
  }
 return catArr;
}// end cat method

int* removeRepeats(int* arr, int size, int resultSize){
  int* result = (int*) calloc(resultSize+2, sizeof(int));
    if(resultSize>0){
	 result[0] = resultSize;
    }
    else{
	result[0] = 0;
	
    }
 
  int index =1;
  for(int i=1; i< size; i++){
    int curr = arr[i]; 
    int next = arr[i+1];
    if(curr!=next && size > 1){
     result[index] = arr[i];
     index++;
    }
  
  }

  if(size == 1){
    result[1] = arr[0];
  }
  free(arr);
  return result;
}
int* array_merge(int num_arrays, int* sizes, int** values) {
  int* catArr = catArray(num_arrays, sizes, values);
  int size = 0;
  for(int i=0; i< num_arrays; i++){
	 size+= sizes[i];
  }
  mergesort(size, catArr);  
  int unique = countUnique(catArr, size);
  int* result = removeRepeats(catArr, size, unique);
     return result;
 }
