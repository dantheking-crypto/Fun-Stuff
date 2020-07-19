#include <iostream>
#include <vector>
//Don't submit
using namespace std;
int main() {
  vector<char> string1;
  string number;
  cin >> number;
  for (int i = 0; i < number.length(); i++) {
    string1.push_back(number[i]);
  }
  cin >> number;
  vector<char> string2;
    for (int i = 0; i < number.length(); i++) {
    string2.push_back(number[i]);
  }
  vector<char>::iterator string1begin = string1.begin();
  string1begin = string1.insert(string1begin, '0');
    vector<char>::iterator string2begin = string2.begin();
  string2begin = string2.insert(string2begin, '0');
  while (string2.size() < string1.size()) {
    string2begin = string2.insert(string2begin, '0');
  }
  while (string2.size() > string1.size()) {
    string1begin = string1.insert(string1begin, '0');
  }
  int num1[string1.size()];
  for (int i = 0; i < string1.size(); i++) {
    num1[i] = (int)(string1[i])-'0';
  }
  int num2[string2.size()];
    for (int i = 0; i < string2.size(); i++) {
    num2[i] = (int)(string2[i])-'0';
  }

  int sum[string2.size()];
  int carry = 0;
  for (int i = 1; i <= string2.size(); i++) {
    int total = num1[string1.size() - i] + num2[string2.size() - i] + carry;
    sum[string2.size() - i] = total % 10;
    carry = (total/ 10) % 10;
  }
  if (sum[0] != 0) cout << sum[0];
  for (int i = 1; i < string2.size(); i++) {
    cout << sum[i];
  }
  return 0;
}
