/*
#include <iostream>

using namespace std;

int main()
{
  srand(time(NULL));

  const int size = 21;
  int grades[size];

  for(int i = 0; i < size; i++)
  {
    grades[i] = rand()%101;

    cout << "Student " << i+1 << "'s grade is " << grades[i] << endl;
  }
  return 0;
}
*/

#include <iostream>

using namespace std;

int main()
{
  srand(time(NULL));

  string partyList[10];

  for(int i = 0; i < 10; i++)
  {
    cout << "Enter the person coming to the party: ";
    cin >> partyList[i];
  }

  cout << endl;

  cout << "The full party list: " << endl;
  for(int j = 0; j < 10; j++)
  {
    cout << partyList[j] << endl;
  }

  cout << endl;

  cout << "The VIP for this party is " << partyList[rand()%10] << endl;
}
