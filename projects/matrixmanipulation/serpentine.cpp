#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  int s[n][n];
  int counter = 1;
  int currentrow = 0;
  int currentcol = 0;
  int rownum = 1;
  int dir = 1;
  bool right = true;
  bool descending = false;
  while (counter <= n * n) {
    for (int i = 0; i < rownum; i++) {
      s[currentrow][currentcol] = counter;
      counter++;
      if (i != rownum - 1) {
        currentrow -= dir;
        currentcol += dir;
    }
    }
    dir *= -1;
    if (right) currentcol++;
    else currentrow++;
    if (rownum == n) descending = true;
    if (descending) right = !right;
    else if (rownum != n - 1) right = !right;
    if (descending) rownum--;
    else rownum++;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << s[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
  

}
