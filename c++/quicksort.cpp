#include<iostream>
using namespace std;



void swap(char* a, char* b){
        char temp;
        temp = *a;
        *a =*b;
        *b = temp;
    }

void swap(int* a,int* b){
  int temp;
  temp = *a;
  *a = *b;
  *b =temp;
}
int partition(string array,int low,int high){
  int pivot = array[high];

  int i=(low-1);
  for(int j=low;j<high;j++){
    if(array[j] <= pivot){
      i++;
      swap(&array[i],&array[j]);
    }
  }
  //swap pivot and greater element
  swap(&array[i+1],&array[high]);
  return (i+1);
}

void quicksort(string  array,int low,int high){
  if(low<high){
    int p = partition(array,low,high);
    quicksort(array,low,p-1);
    quicksort(array,p+1,high);
  }
  
}
void printArray(string array, int size) {
  int i;
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}
int main(){
  int data[] = {8, 7, 6, 1, 0, 9, 2};
  int n = sizeof(data) / sizeof(data[0]);
  cout<<"Unsorted: ";
  printArray(data,n);
  quicksort(data,0,n-1);
  printArray(data,n);

  return 0;
  
}
