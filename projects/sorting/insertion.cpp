#include <iostream>
using namespace std;
inline void swap (int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}
void insertionsort (int arr[], int length) {
  for (int i = 1; i < length; i++) {
    int current = i;
    while (current >= 0) {
      if (arr[current] > arr[current - 1]) break;
      swap (arr[current], arr[current - 1]);
      current--;
    }
  }
}
int main() {
  int length;
  cin >> length;
  int arr[length];
  for (int i = 0; i < length; i++) {
    cin >> arr[i];
  }
  insertionsort(arr, length);
  for (int i = 0; i < length; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}
