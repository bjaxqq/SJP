#include <iostream>
#include <iomanip>

using namespace std;

void output(string a[][5]);

const int row = 5;
const int col = 5;

int main()
{
  srand(time(NULL));

  string prizes[row][col];
  string pen[row][col];
  int car = 0;
  int pret = 0;
  int guit = 0;
  int bask = 0;
  int test = 0;

  //this code places a blue square on every spot in the 5 y 5 double array
  for(int i = 0; i < row; i++)
  {
    for(int j = 0; j < col; j++)
    {
    prizes[i][j] = "🟦";
    }
  }

  /*this for loops checks to see if there is a blue square open on that spot and
  if there is it places a car */
  for(int i = 0; i < 3; i++)
  {
    int b = rand()%5;
    int c = rand()%5;

    if(prizes[b][c] == "🟦")
    {
      prizes[b][c] = "🚗";
    }
    else
    {
      i--;
    }
  }

  /*this for loops checks to see if there is a blue square open on that spot and
  if there is it places a pretzel */
  for(int i = 0; i < 3; i++)
  {
    int b = rand()%5;
    int c = rand()%5;

    if(prizes[b][c] == "🟦")
    {
      prizes[b][c] = "🥨";
    }
    else
    {
      i--;
    }
  }

  /*this for loops checks to see if there is a blue square open on that spot and
  if there is it places a guitar */
  for(int i = 0; i < 3; i++)
  {
    int b = rand()%5;
    int c = rand()%5;

    if(prizes[b][c] == "🟦")
    {
      prizes[b][c] = "🎸";
    }
    else
    {
      i--;
    }
  }

  /*this for loops checks to see if there is a blue square open on that spot and
  if there is it places a basketball */
  for(int i = 0; i < 3; i++)
  {
    int b = rand()%5;
    int c = rand()%5;

    if(prizes[b][c] == "🟦")
    {
      prizes[b][c] = "🏀";
    }
    else
    {
      i--;
    }
  }

  /*this for loops checks to see if there is a blue square open on that spot and
  if there is it places a test tube */
  for(int i = 0; i < 3; i++)
  {
    int b = rand()%5;
    int c = rand()%5;

    if(prizes[b][c] == "🟦")
    {
      prizes[b][c] = "🧪";
    }
    else
    {
      i--;
    }
  }

  //outputs the prize board
  cout << "Prize Board:" << endl;

  output(prizes);

  cout << endl;

  //the for loop to make the penny board
  for(int i = 0; i < row; i++)
  {
    for(int j = 0; j < col; j++)
    {
      pen[i][j] = "-";
    }
  }

  for(int i = 0; i < 10; i++)
  {
    pen[rand()%5][rand()%5] = "P";
  }

  //outputs the penny board
  cout << "Penny Board:" << endl;

  output(pen);

  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      // if the is a car and there is a P, then it adds one
      // if there is three then you win the prize
      if(prizes[i][j] == "🚗" && pen[i][j] == "P")
      {
        car++;
      }
      else if(prizes[i][j] == "🥨" && pen[i][j] == "P")
      {
        pret++;
      }
      else if(prizes[i][j] == "🎸" && pen[i][j] == "P")
      {
        guit++;
      }
      else if(prizes[i][j] == "🏀" && pen[i][j] == "P")
      {
        bask++;
      }
      else if(prizes[i][j] == "🧪" && pen[i][j] == "P")
      {
        test++;
      }
    }
  }

  // checks to see if you won something
  if(car == 3)
  {
    cout << "You have won a car" << endl;
  }
  if(pret == 3)
  {
    cout << "You have won a pretzel" << endl;
  }
  if(guit == 3)
  {
    cout << "You have won a a guitar" << endl;
  }
  if(bask == 3)
  {
    cout << "You have won a basketball" << endl;
  }
  if(test == 3)
  {
    cout << "You have won a test tube" << endl;
  }
  if(car != 3 && pret != 3 && guit != 3 && bask != 3 && test != 3)
  {
    cout << "You won nothing" << endl;
  }

  return 0;
}

// code to output the 5 by 5 graphs
void output(string a[][5])
{
  for(int i = 0; i < row; i++)
  {
    for(int j = 0; j < col; j++)
    {
      cout << setw(2) << a[i][j];
    }
    cout << endl;
  }
}
