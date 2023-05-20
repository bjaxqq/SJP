#include <iostream>

using namespace std;

int main()
{
  srand(time(NULL));

  const int size = 20;
  int num[size];

  cout << "Original Array:" << endl;

  for(int i = 0; i < 10; i++)
  {
    num[i] = rand()%101;

    cout << num[i] << endl;
  }

  cout << "Sorted Array:" << endl;
  return 0;
}
