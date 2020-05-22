#include <iostream>
using namespace std;
class Family {
  
    
  public:
    int age;
    string name;
    string Top3Hobbies[3];
    bool isFriend = false;
    Family(string GetName = "John", int GetAge = 20) {
      name = GetName;
      age = GetAge;
    }
    void Hobbies() {
      if (isFriend) cout << "Enter his or her top 3 hobbies: ";
      else cout << "Enter your top 3 hobbies: ";
      for (int i = 0; i < 3; i++) {
        cin >> Top3Hobbies[i];
      }
    }
    void IntroduceSelf() {
      cout << "Hi, I'm " << name << " and am " << age << " years old. My top three hobbies are: ";
      for (int i = 0; i < 3; i++) {
        cout << Top3Hobbies[i] << " ";
      }
      cout << endl;
      
    }
};
class Friends: public Family {
  private:
    Family Closest3Friends[3];
  public:
    Friends() {
      int getage;
      string getname;
      cout << "Enter your name: ";
      cin >> getname;
      cout << "Enter your age: ";
      cin >> getage;
      
      age = getage;
      name = getname;
      Hobbies();
      IntroduceSelf();
      DeclareFriends();
      IntroduceFriends();
    }
    void DeclareFriends() {
      cout << "Time to introduce your 3 best friends!" << endl;
      for (int i = 0; i < 3; i++) {
        string friendname;
        int friendage;
        cout << "Friend " << i + 1 << ": " << endl;
        cout << "Enter name: ";
        cin >> friendname;
        cout << "Enter age: ";
        cin >> friendage;
        Closest3Friends[i] = Family(friendname, friendage);
        Closest3Friends[i].isFriend = true;
        Closest3Friends[i].Hobbies();
      }
    }
    void IntroduceFriends() {
      for (int i = 0; i < 3; i++) {
        cout << Closest3Friends[i].name << " is " << Closest3Friends[i].age << " years old." << endl;
        cout << "His top 3 hobbies are: ";
        for (int j = 0; j < 3; j++) {
            cout << Closest3Friends[i].Top3Hobbies[j] << " ";
        }
        cout << endl;
      }
    }
};

int main() {
  cout << "How many family members do you have? ";
  int membernum;
  cin >> membernum;
  Friends family[membernum];
  
  
  return 0;
}