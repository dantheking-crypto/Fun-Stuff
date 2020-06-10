#include <iostream>
using namespace std;
inline void swaptwo (int arr[], int first, int second) {
  int temp = arr[first];
  arr[first] = arr[second];
  arr[second] = temp;
}
void selectionsort(int arr[], int length) {
    for (int i = 0; i < length - 1; i++) {
        int least = i;
        for (int j = i + 1; j < length; j++) {
            if (arr[j] < arr[least]) least = j;
        }
        swaptwo(arr, i, least);
    }

}
int main() {
    int length;
    cin >> length;
    int arr[length];
    for (int i = 0; i < length; i++) {
        cin >> arr[i];
    }
    selectionsort(arr, length);
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
