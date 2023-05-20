#include <iostream>

using namespace std;

int factorial(int num);

int main()
{
  int n;

  cout << endl;
  cout << "Enter a number to get its factorial: ";
  cin >> n;

  cout << n << "! = " << factorial(n);
  cout << endl;

  return 0;
}

int factorial(int num)
{
  if(num == 0)
  {
    return 1;
  }
  return num*factorial(num-1);
}
