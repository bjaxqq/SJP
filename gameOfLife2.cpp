#include<iostream>
#include <unistd.h> // sleep()

using namespace std;
// made the grid 50 by 50
const int col = 50;
const int row = col; // the row is the same as the collum

void create(string a[][col]); // creates a blank grid
void output(string a[][col]); // this outputs the grid
void input(string a[][col]); // this function is where the user manually inputs the coordinates

void ggCreate(string a[][col]); // this function is for the glider gun

void statusCheck(string a[][col], string b[][col]); //checks to see if it's going to die or if it's giong to live the next day
int neighborCount(string a[][col], int x, int y); //counts how many living cells neighbor that coordinate
void replace(string a[][col], string b[][col]); // changes the dead to a living or the other way around depending on the surrounding cells

void emptyCheck(string a[][col], int& x); // if the whole grid is empty, it stops the programming by increasing the 't' value which controls the while loop

int main()
{
string grid[row][col];// getting outputted
string temp[row][col];// one 'day' in the future which will replace the present grid
int t = 0; // used in an infinite loop. Increases when the grid is empty
char ggAsk = 'n'; // asks the user if they want to run the glider gun function
int buffer; // how many seconds the user wants each day to last

create(grid);// creates the grid

cout << "Would you like to automatically generate a Gosper Glider Gun? (y/n)" << endl << "(If you say no, manual coordinate entry will begin)" << endl;
cin >> ggAsk; // asks the user if they want to run the glider gun

cout << "How many seconds would you like per day? (0 for no buffer, integer inputs only) ";
cin >> buffer; // how many seconds each day will last

if(ggAsk == 'y' || ggAsk == 'Y')//creates the glider gun grid
{
ggCreate(grid);
}
else
{
input(grid); // this runs the manually inputted grid where the user inputs the coordinates for the cells
}

while(t < 1) // this whole while loop runs the code infinitely until the grid is empty
{
output(grid); // outputs the grid
cout << endl;

emptyCheck(grid, t); // checks if it's empty

statusCheck(grid, temp); // checks if it's going to live or die

sleep(buffer); // how slow the user wants the code ot run
}

return 0;
}

void create(string a[][col]) // this creates the blank grid
{
for(int i = 0; i < row; i++)
{
for(int j = 0; j < col; j++)
{
a[i][j] = "⬜"; // white squares for each coordinate

}
}
}

void output(string a[][col]) // this outputs the grid for the user
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

void input(string a[][col])
{
char choice = 'y'; // originally yes so this while loop can run

while(choice == 'y' || choice == 'Y') // if yes, then this code asks the user for another coordinate
{
int x,y;

cout << "The grid is currently " << col << "x" << col << " cells." << endl;

cout << "Enter the x-coordinate of the cell: ";
cin >> x; // x coordinate

cout << "Enter the y-coordinate of the cell: ";
cin >> y; // goes down positively just because

a[y - 1][x - 1] = "⬛"; // have to minus one because of the way arrays are set up


cout << "Would you like to add another cell? (y/n) "; // asks if the user wants to add another coordinate
cin >> choice;
}

}

void statusCheck(string a[][col], string b[][col]) // this code checks to see if it should be living or if it should die and changes the cell
{
for(int i = 0; i < row; i++)
{
for(int j = 0; j < col; j++)
{
if(a[i][j] == "⬜")
{
if(neighborCount(a, i, j) == 3)
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
if(neighborCount(a, i, j) == 2 || neighborCount(a, i, j) == 3) // uses another function
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

replace(a, b); // replaces the grid with the changed grid
}

int neighborCount(string a[][col], int x, int y) // this whole function checks every neighbor for every coordinate
{
int nCount = 0; // variable that counts number of neighbors

if(x != 0 && y != 0)
{
if(a[x-1][y-1] == "⬛")
{
nCount++;
}
}
if(y != 0)
{
if(a[x][y-1] == "⬛")
{
nCount++;
}
}
if(x != col - 1 && y != 0)
{
if(a[x+1][y-1] == "⬛")
{
nCount++;
}
}
if(x != 0)
{
if(a[x-1][y] == "⬛")
{
nCount++;
}
}
if(x != col - 1)
{
if(a[x+1][y] == "⬛")
{
nCount++;
}
}
if(x != 0 && y != col - 1)
{
if(a[x-1][y+1] == "⬛")
{
nCount++;
}
}
if(y != col - 1)
{
if(a[x][y+1] == "⬛")
{
nCount++;
}
}
if(x != col - 1 && y != col - 1)
{
if(a[x+1][y+1] == "⬛")
{
nCount++;
}
}

return nCount; // returns the number of neighbors
}

void replace(string a[][col], string b[][col]) // this function replaces the original grid with the new day grid
{
for(int i = 0; i < row; i++)
{
for(int j = 0; j < col; j++)
{
a[i][j] = b[i][j]; // you can see it on this line

}
}
}

void emptyCheck(string a[][col], int& x) // this checks to see if the whole grid is empty
{
int count = 0; //variable that is used to count the number of living cells

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

if(count == 0) // if the grid has no living cells, it adds one to x which stops the whole code
{
x++;
}
}
