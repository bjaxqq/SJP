#include <iostream>

using namespace std;

int main()
{
  int even = 0;
  int odd = 0;

  srand(time(NULL));

  const int size = 25;
  int numbers[size];

  for(int i = 0; i < 25; i++)
  {
    numbers[i] = rand()%101;

    cout << "Number " << i+1 << " is: " << numbers[i] << endl;
  }

  cout << endl;

  for(int i = 0; i < 25; i++)
  {
    if(numbers[i]%2 == 0)
    {
      even++;
    }
    else
    {
      odd++;
    }
  }

  cout << endl;

  cout << "The number of even numbers is: " << even << endl;
  cout << "The number of odd numbers is: " << odd << endl;

  return 0;
}
