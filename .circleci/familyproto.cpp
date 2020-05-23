#include <iostream>
using namespace std;
class Family {
  
  private:
    int age;
    string name;
    string Top3Hobbies[3];
    bool isFriend = false;  
  public:
    
    Family(string GetName = "John", int GetAge = 20) {
      name = GetName;
      age = GetAge;
    }
    int getAge() {
      return age;
    }
    void changeAge(int newage) {
      age = newage;
    }
    string getName() {
      return name;
    }
    void changeName(string newname) {
      name = newname;
    }
    string getHobby(int index) {
      return Top3Hobbies[index];
    }
    bool friendOrNot() {
      return isFriend;
    }
    void changeFriend(bool change) {
      isFriend = change;
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
      cout << "If you are a family member who hasn't entered his or her data yet, please come to the screen. \n";
      int getage;
      string getname;
      cout << "Enter your name: ";
      cin >> getname;
      cout << "Enter your age: ";
      cin >> getage;
      changeAge(getage);
      changeName(getname);
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
        Closest3Friends[i].changeFriend(true);
        Closest3Friends[i].Hobbies();
      }
    }
    void IntroduceFriends() {
      for (int i = 0; i < 3; i++) {
        cout << Closest3Friends[i].getName() << " is " << Closest3Friends[i].getAge() << " years old." << endl;
        cout << "His top 3 hobbies are: ";
        for (int j = 0; j < 3; j++) {
            cout << Closest3Friends[i].getHobby(i) << " ";
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