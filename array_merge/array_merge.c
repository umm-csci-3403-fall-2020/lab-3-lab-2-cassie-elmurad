#include "array_merge.h"
#include "mergesort.h"
#include "mergesort.c"
#include<stdlib.h>
#include<cstdio>
int countUnique(int* arr, int size){
  int index =0;
  int count = 0; 
  // While number exist continue to check for repeat values
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
  return count;
}// end count Unique
int* catArray(int num_arrays, int* sizes, int** values){
  int length = 0;
  for(int i=0; i < num_arrays; i++){
	length += sizes[i];
  } 
  int* catArr = (int*) calloc(length +1, sizeof(int)); 
  int index = 1;
  catArr[0] = length+1;
  while(num_arrays >= 0){
     int arrSize = sizes[num_arrays];
     for(int i =0; i< arrSize-1; i++){
       catArr[index]= values[num_arrays][i];
       index++;
     }
     num_arrays--;  
  }
 return catArr;
}// end cat method

int* removeRepeats(int* arr, int size, int resultSize){
  int* result = (int*) calloc(resultSize+1, sizeof(int));
  mergesort(size, arr);
  int index =0;
  for(int i=1; i< size-1; i++){
    int curr = arr[i]; 
    int next = arr[i+1];
    if(curr!=next){
     result[index] = arr[i];
     index++;
    }
  }
  return result;
}
int* array_merge(int num_arrays, int* sizes, int** values) {
  int* catArr = catArray(num_arrays, sizes, values);
  int size = catArr[0]; 
  int unique = countUnique(catArr, size);
  int* result = removeRepeats(catArr, size, unique);
     return result;
 }
