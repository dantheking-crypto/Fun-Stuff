#include <iostream>
using namespace std;
int left(int arr[], int index) {
 return arr[2 * index + 1];
}
int right(int arr[], int index) {
 return arr[2 * index + 2];
}
void maxheapify(int arr[], int index, int heapsize) {
  int l, r, greatestindex;
  greatestindex = index;
  l = left(arr, index);
  r = right(arr, index);
  if (l > arr[index] && 2 * index + 1 < heapsize) greatestindex = 2 * index + 1;
  if (r > arr[greatestindex] && 2 * index + 2 < heapsize) greatestindex = 2 * index + 2;
  if (greatestindex != index) {
    int temp;
    temp = arr[index];
    arr[index] = arr[greatestindex];
    arr[greatestindex] = temp;
    maxheapify(arr, greatestindex, heapsize);
  }
  
}
void buildmaxheap(int arr[], int length) {
  for (int i = length / 2 - 1; i >= 0; i--) {
    maxheapify(arr, i, length);
  }
}
void heapsort(int arr[], int arrsize) {
  buildmaxheap(arr, arrsize);
  for (int i = arrsize - 1; i > 0; i--) {
    int temp;
    temp = arr[i];
    arr[i] = arr[0];
    arr[0] = temp;
    maxheapify(arr, 0, i);
  }
}
int main() {
  int length;
  cin >> length;
  int arr[length];
  for (int i = 0; i < length; i++) {
    cin >> arr[i];
  }
  heapsort(arr, length);
  for (int i = 0; i < length; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}
