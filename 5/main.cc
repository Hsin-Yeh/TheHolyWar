#include <iostream>
#include <string>

using namespace std;

string curseWords(int i);
string blessings(int i);
int Get_some_Chocolate();
int Pour_a_glass_of_wine();
int Prepare_Christmas_gifts();
bool Trial(int a, int b, int c);

string curseWords(int i){
  string s;
  switch(i) {
    case 0:
      s = "The rain in Taipei will last for one month";
      break;
    case 1:
      s = "Hahaha, you will take 10 years to graduate";
      break;
    case 2:
      s = "Meetings will NOT be cancelled tommorrow! \nNo Christmas for you!!\nWork!!!!!";
  }
  return s;
}

string blessings(int i){
  return "tmp";
}

int Get_some_Chocolate(){
  return 100;
}

int Pour_a_glass_of_wine(){
  return 0;
}

int Prepare_Christmas_gifts(){
  return 0;
}

bool Trial(int a, int b, int c){
  return 0;
}

int main(int argc, char *argv[]) {

  bool theLittleXmas = 0; // 0 == devil littleXmas; 1 == angel littleXmas;

  int a = Get_some_Chocolate();
  int b = Pour_a_glass_of_wine();
  int c = Prepare_Christmas_gifts();

  theLittleXmas = Trial(a, b, c);

  if ( theLittleXmas == 0 ) {
    srand((unsigned) time(0));
    cout << curseWords(rand()%3) << endl;
  }
  else {
    srand((unsigned) time(0));
    cout << blessings(rand()%3) << endl;
  }

  return 0;
}
