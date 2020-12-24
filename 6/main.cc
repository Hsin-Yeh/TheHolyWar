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
      s = "\nThe rain in Taipei will last for one month\n";
      break;
    case 1:
      s = "\nHahaha, you will take 10 years to graduate\n";
      break;
    case 2:
      s = "\nMeetings will NOT be cancelled tommorrow! \nNo Christmas for you!!\nWork!!!!!\n";
  }
  return s;
}

string blessings(int i){
  string s;
   switch(i) {
     case 0:
       s = "It will be a sunny day tomorrow!";
       break;
     case 1:
       s = "Congratulations to Page and Lao!";
       break;
     case 2:
       s = "No meetings tomorrow~~~~~~~~~~~ Merry Christmas!";
   }
   return s;
}

int Get_some_Chocolate(){
  return 100;
}

int Pour_a_glass_of_wine(){
  return 100;
}

int Prepare_Christmas_gifts(){
  return 100;
}

bool Trial(int a, int b, int c){
  bool trial;
  if(a+b+c == 300) trial = 1;
  else trial = 0;
  return trial;
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
