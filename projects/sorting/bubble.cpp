#include <iostream>
using namespace std;
inline void swaptwo (int arr[], int first, int second) {
  int temp = arr[first];
  arr[first] = arr[second];
  arr[second] = temp;
}
void bubblesort(int arr[], int length) {
  for (int i = 0; i < length - 1; i++) {
    bool sorted = true;
    for (int j = 0; j < length - 1 - i; j++) {
      if (arr[j] > arr[j + 1]) {
        swaptwo(arr, j, j + 1);
        sorted = false;
      }
    }
    if (sorted) break;
  }
}
int main() {
  int length;
  cin >> length;
  int arr[length];
  for (int i = 0; i < length; i++) {
    cin >> arr[i];
  }
  bubblesort(arr, length);
  for (int i = 0; i < length; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}
