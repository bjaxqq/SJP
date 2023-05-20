#include <iostream>
#include <unistd.h>
#include <iomanip>
#include <string>

using namespace std;

const int col = 10;
const int row = col;

void ocean(string a[][col]); // creates the initial blank grid
void oceanOut(string a[][col]); // outputs the initial blank grid
void oceanIn(string a[][col]); // allows the user to input x and y coordinates
void change(string a[][col], string b[][col]); // changes the status of each cell to either dead or alive
void empty(string a[][col], int& x); // stops the program if everything is empty

int main()
{
  string grid[row][col];
  string temp[row][col];
  int t = 0;
  int buffer;

  ocean(grid);

  cout << "Seconds per day: ";
  cin >> buffer;

  oceanIn(grid);

  while(t < 1)
  {
    oceanOut(grid);
    cout << endl;

    empty(grid,t);

    sleep(buffer);
  }

  return 0;
}


void ocean(string a[][col]) // function to create the initial grid
{
  for(int i = 0; i < row; i++)
  {
    for(int j = 0; j < col; j++)
    {
        a[i][j] = "🟦";
    }
  }
}

void oceanOut(string a[][col]) // function to output the grid for the user
{
  char r = 'A';

  cout << " 1 2 3 4 5 6 7 8 9 10" << endl;

  for(int i = 0; i < row; i++)
  {
    cout << r;
    r++;

    for(int j = 0; j < col; j++)
    {
      cout << a[i][j];
    }
    cout << endl;
  }
}

/*
void oceanIn(string a[][col]) // function that asks what coords are to be used
{
  char choice = 'y';

  while(choice == 'y' || choice == 'Y')
  {
    int x,y;

    cout << "The grid is currently " << col << "x" << col << " cells." << endl;

    cout << "Enter the x-coordinate of the ";
    cin >> x; // input x coord

    cout << "Enter the y-coordinate of the cell: ";
    cin >> y; // input y coord

    a[y - 1][x - 1] = "⬛"; // formatting

    cout << "Would you like to add another cell? (y/n) ";
    cin >> choice; // input whether or not another cell should be created
  }
}
*/

/*
void change(string a[][col], string b[][col]) // function that swaps the boards
{
  for(int i = 0; i < row; i++)
  {
    for(int j = 0; j < col; j++)
    {
      a[i][j] = b[i][j];
    }
  }
}
*/

/*
void empty(string a[][col], int& x) // function that checks if it is empty
{
  int count = 0;

  for(int i = 0; i < row; i++)
  {
    for(int j = 0; j < col; j++)
    {
      if(a[i][j] == "⬛")
      {
        count++;
      }
    }
  }

  if(count == 0)
  {
    x++; // if the board is empty, it terminates the program
  }
}
*/
