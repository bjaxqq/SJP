#include <iostream>

using namespace std;

void multiplier(int a[], int x);

int main()
{
  int m;
  srand(time(NULL));

  const int size = 10;
  int num[size];

  cout << "Original Array:" << endl;

  for(int i = 0; i < 10; i++)
  {
    num[i] = rand()%101;

    cout << num[i] << endl;
  }

  cout << "Enter the multiplier: ";
  cin >> m;

  multiplier(num, m);

  cout << "New Array:" << endl;

  for(int i = 0; i < 10; i++)
  {
    cout << num[i] << endl;
  }
  return 0;
}
void multiplier(int a[], int x)
{
  for(int i = 0; i < 10; i++)
  {
    a[i] = a[i] * x;
  }
}
