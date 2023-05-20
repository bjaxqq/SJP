#include <iostream>
#include <unistd.h>

using namespace std;

const int col = 20; // sets collumn size to 20
const int row = 20; // sets row size to 20

void gridIn(string a[][col]); // creates the initial blank grid
void gridOut(string a[][col]); // outputs the initial blank grid
void coords(string a[][col]); // allows the user to input x and y coordinates
void survive(string a[][col], string b[][col]); // checks if cell will live or die
int surrounding(string a[][col], int x, int y); // checks the cells arround the original cell
void change(string a[][col], string b[][col]); // changes the status of each cell to either dead or alive
void empty(string a[][col], int& x); // stops the program if everything is empty

int main()
{
  string grid[row][col]; // outputting the grid
  string temp[row][col]; // future grid
  int t = 0; // sets an infinite loop
  int buffer; // duration of time for each "day"

  gridIn(grid); // creates the grid

  cout << "Seconds per day: ";
  cin >> buffer; // inputting the duration

  coords(grid); // grabs coords

  while(t < 1) // runs the code in an infinite loop
  {
    gridOut(grid); // outputs the grid
    cout << endl;

    empty(grid,t); // checks if the board is empty

    survive(grid,temp); // checks which cells survive

    sleep(buffer); // what speed the code wants to run at
  }

  return 0;
}

void gridIn(string a[][col]) // function to create the initial grid
{
  for(int i = 0; i < row; i++)
  {
    for(int j = 0; j < col; j++)
    {
    a[i][j] = "⬜"; // sets each cell to a white cell emoji
    }
  }
}

void gridOut(string a[][col]) // function to output the grid for the user
{
  for(int i = 0; i < row; i++)
  {
    for(int j = 0; j < col; j++)
    {
      cout << a[i][j];
    }
    cout << endl;
  }
}

void coords(string a[][col]) // function that asks what coords are to be used
{
  char choice = 'y';

  while(choice == 'y' || choice == 'Y')
  {
    int x,y;

    cout << "The grid is currently " << col << "x" << col << " cells." << endl;

    cout << "Enter the x-coordinate of the cell: ";
    cin >> x; // input x coord

    cout << "Enter the y-coordinate of the cell: ";
    cin >> y; // input y coord

    a[y - 1][x - 1] = "⬛"; // formatting

    cout << "Would you like to add another cell? (y/n) ";
    cin >> choice; // input whether or not another cell should be created
}

}

void survive(string a[][col], string b[][col]) // function that checks all cells to see alive or dead status
{
  for(int i = 0; i < row; i++)
  {
    for(int j = 0; j < col; j++)
    {
      if(a[i][j] == "⬜")
      {
        if(surrounding(a,i,j) == 3)
        {
          b[i][j] = "⬛";
        }
        else
        {
          b[i][j] = "⬜";
        }
      }
      else if(a[i][j] == "⬛")
      {
        if(surrounding(a,i,j) == 2 || surrounding(a,i,j) == 3)
        {
          b[i][j] = "⬛";
        }
        else
        {
          b[i][j] = "⬜";
        }
      }
    }
  }
  change(a,b); // changes the board to a new one with the changed cells
}

int surrounding(string a[][col], int x, int y) // checks for all of the surrounding cells
{
  int scout = 0;

  if(x != 0 && y != 0)
  {
    if(a[x-1][y-1] == "⬛")
    {
      scout++;
    }
  }
  if(y != 0)
  {
    if(a[x][y-1] == "⬛")
    {
      scout++;
    }
  }
  if(x != col - 1 && y != 0)
  {
    if(a[x+1][y-1] == "⬛")
    {
      scout++;
    }
  }
  if(x != 0)
  {
    if(a[x-1][y] == "⬛")
    {
      scout++;
    }
  }
  if(x != col - 1)
  {
    if(a[x+1][y] == "⬛")
    {
      scout++;
    }
  }
  if(x != 0 && y != col - 1)
  {
    if(a[x-1][y+1] == "⬛")
    {
      scout++;
    }
  }
  if(y != col - 1)
  {
    if(a[x][y+1] == "⬛")
    {
      scout++;
    }
  }
  if(x != col - 1 && y != col - 1)
  {
    if(a[x+1][y+1] == "⬛")
    {
      scout++;
    }
  }
  return scout; // takes the number of surrounding cells
}

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
