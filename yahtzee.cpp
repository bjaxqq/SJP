#include <iostream>

using namespace std;

void swap(int &a, int &b); //the swap function

void insertion(int dice[]);//insertion function

bool trip(int dice1[]); // three of a kind

bool quad(int dice2[]); // four of a kind

bool full(int dice3[]); // full house

bool small(int dice4[]); // small straight

bool large(int dice5[]); // large straight

bool yahtzee(int dice6[]); // yahtzee function

int chance(int dice7[]); // chance function

int main()
{
	string player1; // player 1
	string player2; // player 2
	//these are the players points
	int pp1 = 0; // starts off with 0
	int pp2 = 0;
	char con;

	cout << endl << "	*********	*********" << endl;
	cout << "	* X   X *	* X   X *" << endl;
	cout << "	* X   X *	* X   X *" << endl;
	cout << "	* X   X *	* X   X *" << endl;
	cout << "	*********	*********" << endl;
	cout << endl << "                 YAHTZEE                 " << endl;
	cout << "-----------------------------------------" << endl;

	cout << "Enter in the first player's name: ";
	cin >> player1; //players name

	cout << "Enter in the second player's name: ";
	cin >> player2; // players name

	//loops this code 13 times for a full match of yahtzee
	for(int i = 0; i < 13; i++)
	{
		cout << endl << "It's " << player1 << "'s turn." << endl; // player 1's turn
		cout << "*dice roll*" << endl;

		srand(time(NULL));

		int roll1[5];

		cout << "Dice rolled: ";

		for(int i = 0; i < 5; i++) // randomizes (the player rolls) the dice
		{
			roll1[i] = rand()%6+1;

			cout << roll1[i] << " ";
		}

		cout << endl << "Dice sorted: ";

		insertion(roll1);

		for(int i = 0; i < 5; i++) // sorts the dice
		{
			cout << roll1[i] << " ";
		}

		cout << endl;
		/* this if statement is figuring out what the player has rolled, with the least
		common in front. Yahtzee has a three of a kind and a four of  kind so it needs
		to be checked first */
		if(yahtzee(roll1)== true)
		{
			cout << "You have rolled a YAHTZEE!" << endl;
			pp1 = pp1+50;
			cout << "50 points!" << endl;
		}
		else if(quad(roll1) == true)
		{
	    	cout << "You have rolled a 4 of a kind!" << endl;
			cout << chance(roll1) << " points!" << endl;
			pp1 = pp1 + chance(roll1);
	  	}
		else if(trip(roll1) ==true)
		{
	    	cout << "You have rolled a 3 of a kind!" << endl;
			cout << chance(roll1) << " points!" << endl;
			pp1 = pp1 + chance(roll1);
		}
	  	else if(large(roll1) == true)
	 	{
			cout << "You have rolled a large straight!" << endl;
			pp1 = 40 + pp1;
			cout << "40 points!" << endl;
		}
	  	else if(small(roll1) == true)
	  	{
	    	cout << "You have rolled a small straight!" << endl;
			pp1 = 30+pp1;
			cout << "30 points!" << endl;
	  	}
		else if(full(roll1) == true)
		{
			cout << "You have rolled a full house!" << endl;
			pp1 = pp1+25;
			cout << "25 points!" << endl;
		}
		else
		{
			cout << "You have rolled nothing." << endl;
			cout << chance(roll1) << " points." << endl;
			pp1 = pp1 + chance(roll1);
		}

		cout << endl << "Now it's " << player2 << "'s turn." << endl; // acknowledges that it's now player 2's turn
		cout << "*dice roll*" << endl;

		int roll2[5];

		cout << "Dice rolled: ";

		for(int i = 0; i < 5; i++) // randomizes (the player rolls) the dice
		{
			roll2[i] = rand()%6+1;

			cout << roll2[i] << " ";
		}

		cout << endl << "Dice sorted: ";

		insertion(roll2);

		for(int i = 0; i < 5; i++) // sorts the dice
		{
			cout << roll2[i] << " ";
		}

		cout << endl;
		/* this if statement is figuring out what the player has rolled, with the least
		common in front. Yahtzee has a three of a kind and a four of  kind so it needs
		to be checked first */
		if(yahtzee(roll2)== true)
		{
			cout << "You have rolled a YAHTZEE!" << endl;
			pp2 = pp2 + 50;
			cout << "50 points!" << endl;
		}
	  	else if(quad(roll2) == true)
	  	{
	    	cout << "You have rolled a 4 of a Kind." << endl;
			cout << chance(roll2) << " points!" << endl;
			pp2 = pp2 + chance(roll2);
	  	}
	  	else if(full(roll2) == true)
		{
			cout << "You have rolled a full house!" << endl;
			pp2 = pp2+25;
			cout << "25 points!" << endl;
		}
	  	else if(trip(roll2) == true)
	  	{
	    	cout << "You have rolled a 3 of a kind!" << endl;
			cout << chance(roll2) << " points!" << endl;
			pp2 = pp2 + chance(roll2);
	  	}
	  	else if(large(roll2) == true)
	  	{
			cout << "You have rolled a large straight!" << endl;
			pp2 = 40 + pp2;
			cout << "40 points!" << endl;
		}
	  	else if(small(roll2) == true)
	  	{
	    	cout << "You have rolled a small straight!" << endl;
			pp2 = 30+pp2;
			cout << "30 points!" << endl;
	  	}
		else
		{
			cout << "You have rolled nothing." << endl;
			cout << chance(roll2) << " points." << endl;
			pp2 = pp2 + chance(roll2);
		}

		cout << endl << player1 << " has " << pp1 << " points." << endl; // this is just saying who is winning
		cout << player2 << " has " << pp2 << " points." << endl << endl;
		/* We added this loop so the player could look at the two rolls by each player
		to make sure everything is correct. We did this so al of the code does not
		come all at once */
		cout << "Are you ready to play the next round? (y/n): ";
		cin >> con;
		while(con != 'y')
		{
			cout << "how about now: ";
			cin >> con;
		}
	}

	cout << endl;
	cout << "The game has ended." << endl;

	//this code is here to tell us who won or if they tied
	if(pp1 > pp2)
	{
		cout << player1 << " won with " << pp1 << " points!" << endl;
	}
	else if(pp1 < pp2)
	{
		cout << player2 << " won with " << pp2 << " points!" << endl;
	}
	else
	{
		cout << "Oh my goodness!" << player1 << " and " << player2 << " have tied with" << pp1 << " points!" << endl;
	}

	cout << "Thanks for playing!" << endl; // ends the game
	return 0;
}
 // all of our functions

void swap(int &a, int &b) // this swaps the two numbers so insertion can work
{
	int temp = a;
	a = b;
	b = temp;
}

void insertion(int dice[]) // this function will order the dice from greatest to least
{
	for(int i = 1; i < 5; i++)
	{
		int j = i;

		while((j > 0) && (dice[j-1] < dice[j]))
		{
			swap(dice[j],dice[j-1]);
			j = j - 1;
		}
	}
}

bool trip(int dice1[]) // this is for the three of a kind function
{
	if((dice1[0]==dice1[2]) || (dice1[1] == dice1[3]) || (dice1[2] == dice1[4]))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool quad(int dice2[]) //this is the four of a kind function
{
	if(dice2[0]==dice2[3] || dice2[1] == dice2[4])
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool full(int dice3[]) // this is for the full
{
	if((dice3[0]==dice3[2] && dice3[3]==dice3[4]) || (dice3[0]==dice3[1] && dice3[2]==dice3[4]))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool small(int dice4[]) // this code is for the small straight
{
	int n1 = 0;
	int n2 = 0;
	int n3 = 0;
	int n4 = 0;
	int n5 = 0;
	int n6 = 0;
	for (int i =0; i < 5; i++)
	{
		if (dice4[i] ==6)
		{
			n1++;
		}
		else if (dice4[i] ==5)
		{
			n2++;
		}
		else if (dice4[i] ==4)
		{
			n3++;
		}
		else if (dice4[i] ==3)
		{
			n4++;
		}
		else if (dice4[i] ==2)
		{
			n5++;
		}
		else if (dice4[i] ==1)
		{
			n6++;
		}
	}
	if(n1 >= 1 && n2 >=1 && n3 >=1 && n4 >=1)
	{
		return true;
	}
	else if(n2 >= 1 && n3 >=1 && n4 >=1 && n5 >=1)
	{
		return true;
	}
	else if(n3 >= 1 && n4 >=1 && n5 >=1 && n6 >=1)
	{
		return true;
	}

	return false;
}

bool large(int dice5[]) // this is for a large straight
{
	if(dice5[0] == dice5[1]+1 && dice5[1] == dice5[2]+1 && dice5[2] == dice5[3]+1 && dice5[3] == dice5[4]+1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool yahtzee(int dice6[])// this function is for yahtzee
{
	if(dice6[0]==dice6[4])
	{
		return true;
	}
	else
	{
		return false;
	}
}

int chance(int dice7[]) // this is the chance function
{
	int tot = 0;
	for (int i = 0; i < 5; i++)
	{
		tot = tot + dice7[i];
	}
	return tot;
}


/*
*********
*       *
*   X   *
*       *
*********

*********
* X   X *
* X   X *
* X   X *
*********
*/
