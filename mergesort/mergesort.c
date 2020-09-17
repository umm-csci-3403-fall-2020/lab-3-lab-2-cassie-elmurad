#include "mergesort.h"
#include<stdlib.h>

void mergeRanges(int values[], int size, int startIndex, int midPoint, int endIndex){
  int rangeSize = endIndex - startIndex;
  int* destination;
  destination = (int*) calloc(size+1, sizeof(int));
  int firstIndex = startIndex;
  int secondIndex = midPoint;
  int copyIndex = 0;
  while(firstIndex < midPoint && secondIndex < endIndex){
    if(values[firstIndex] < values[secondIndex]){
      destination[copyIndex] = values[firstIndex];
      firstIndex++;		   
    }else {
      destination[copyIndex] = values[secondIndex];  
      secondIndex++;
    }  
    copyIndex++;
  }
  while(firstIndex < midPoint) {
    destination[copyIndex] = values[firstIndex];
    copyIndex++;
    firstIndex++;
  }
  while(secondIndex < endIndex) {
    destination[copyIndex] = values[secondIndex];
    copyIndex++;
    secondIndex++;
  }
  for(int i =0; i< rangeSize; i++){
    values[i + startIndex] = destination[i];
  }
}

void bool needsSorting(int rangeSize){
  if(rangeSize >= 2){
    return True; 
  }else {
    return False;	  
  } 
   
}


void mergeSortRange(int values[], int startIndex, int endIndex){                                                    int rangeSize = endIndex - startIndex;
    if (needsSorting(rangeSize)) {
      int midPoint = (startIndex + endIndex) / 2;
      mergeSortRange(values, startIndex, midPoint);
      mergeSortRange(values,midPoint, endIndex);
      mergeRanges(values, startIndex, midPoint, endIndex);
    }
}


void mergesort(int size , int values[]) {
  mergeSortRange(values, 0, size); 
}
