#include <iostream>
using namespace std;
void mergetwosorted(int arr1[], int arr2[], int len1, int len2, int newarr[]) {
  
  int aindex = 0;
  int bindex = 0;
  int least1 = arr1[aindex];
  int least2 = arr2[bindex];
  for (int i = 0; i < len1 + len2; i++) {
    if (least1 < least2) {
      newarr[i] = least1;
      if (aindex < len1 - 1) {
        aindex++;
        least1 = arr1[aindex];
      } 
      else least1 = arr2[len2 - 1];
    }
    else {
      newarr[i] = least2;
      if (bindex < len2 - 1) {
        bindex++;
        least2 = arr2[bindex];
      } 
      else least2 = arr1[len1 - 1];
    }
  }
}
void mergesort(int arr[], int length) {
  if (length == 1) return;
  int arr1[length / 2];
  for (int i = 0; i < length / 2; i++) {
    arr1[i] = arr[i];
  }
  int arr2[length - length / 2];
  for (int i = length / 2; i < length; i++) {
    arr2[i - length / 2] = arr[i];
  }
  mergesort(arr1, length / 2);
  mergesort(arr2, length - length / 2);
  mergetwosorted(arr1, arr2, length / 2, length - length / 2, arr);
}
int main() {
  int len;
  cin >> len;
  int arr[len];
  for (int i = 0; i < len; i++) {
    cin >> arr[i];
  }
  mergesort(arr, len);
  for (int i = 0; i < len; i++) {
    cout << arr[i] << " ";
  }
  return 0; 
}
