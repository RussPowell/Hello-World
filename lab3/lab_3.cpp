/*
 * Naplayer1        : lab_3.cpp
 * Author      : Russell Powell
 * Description : Using branching statements, looping statements and string and
 *               character functions complete the functions
 */

#include "lab_3.h"

/*
 * Tell the story of Goldilocks. For example, if item is "bed" and number is 1,
 * the story will say "This bed is too soft". "item" parameter will be passed
 * in as all lowercase characters
 * Cases:
 * -item: "porridge", number: 1, return "This porridge is too hot"
 * -item: "porridge", number: 2, return "This porridge is too cold"
 * -item: "porridge", number: 3, return "This porridge is just right"
 * -item: "chair", number: 1, return "This chair is too big"
 * -item: "chair", number: 2, return "This chair is too small"
 * -item: "chair", number: 3, return "This chair is just right"
 * -item: "bed", number: 1, return "This bed is too hard"
 * -item: "bed", number: 2, return "This bed is too soft"
 * -item: "bed", number: 3, return "This bed is just right"
 * @param string item - Represents the item in the story ("porridge", "chair",
 *                      and "bed" are the only legal values -- will default to
 *                      "bed" on invalid arguplayer1nt)
 * @param int number - which item (1, 2, and 3 are the only legal values -- will
 *                     default to 3 on invalid arguplayer1nt)
 * @return string - The output string specified in the docuplayer1ntation above
 */
string Goldilocks(string item, int number) {
  // CODE HERE
  string story;
  if (item == "porridge"){
  	switch (number){
  		case 1:
  		story = "This porridge is too hot.";
  		break;
  		case 2:
  		story = "This porridge is too cold.";
  		break;
  		case 3:
  		story = "This porridge is just right!";
  	}
  }
  else if (item == "chair"){
  	switch (number){
  	    case 1:
  		story = "This chair is too big.";
  		break;
  		case 2:
  		story = "This chair is too small.";
  		break;
  		case 3:
  		story = "This chair is just right!";
  	}
  }
  else if (item == "bed"){
  	switch (number){
  		case 1:
  		story = "This bed is too hard.";
  		break;
  		case 2:
  		story = "This bed is too soft.";
  		break;
  		case 3:
  		story = "This bed is just right!";
  	}
  }
  //cout<< story<<"\n";//I am missing something as I cannot 'return'
  return story;    // story using the return command.  'Cout' works.
}

/*
 * Compute the outcome of a round of a rock-scissor-paper game. Lowercase or
 * uppercase values for player_one and player_two arguments are acceptable.
 * Possible inputs: 'R' rock, 'S' scissor, 'P' paper
 * Conditions
 * -rocks beats scissors
 * -scissors beats paper
 * -paper beats rock
 ****************************I added lizard and spock
 
 * @param char player_one - Represents player one's "play" ('R', 'S', or 'P')
 * @param char player_two - Represents player two's "play" ('R', 'S', or 'P')
 * @return int - 1 if player one wins, 2 if player two wins, 3 on a draw,
 *               0 if invalid inputs
 */
int RockScissorPaper(char player_one, char player_two) 
{
  // player2 MUST USE A SWITCH IN THIS FUNCTION
  // CODE HERE
  const int Player1Winner = 1;
  const int Player2Winner = 2;
  const int PlayesTie = 3;
  const int BadInput = 0;
		switch (player_one)
		{
		case 'r':
			if (player_two == player_one)
			{
				return BadInput;
			}
			else if (player_two == 'p')
			{
				return Player2Winner;
			}
			else if (player_two == 'v')
			{
				return Player2Winner;
			}
			else if (player_two == 'l')
			{
				return Player1Winner;
			}
			else if (player_two == 's')
			{
				return Player1Winner;
			}
			else
			{
				return BadInput;
			}
			break;
		case 'p':
		case 'P':
			if (player_one == player_two)
			{
				return PlayesTie;
			}
			else if (player_two == 's')
			{
				return Player2Winner;
			}
			else if (player_two == 'l')
			{
				return Player2Winner;
			}
			else if (player_two == 'r')
			{
				return Player1Winner;
			}
			else if (player_two == 'v')
			{
				return Player1Winner;
			}
			else
			{
				return BadInput;
			}
			break;
			
		case 's':
		case 'S':
			if (player_one == player_two)
			{
				return 3;
			}
			else if (player_two == 'r')
			{
				return 2;
			}
			else if (player_two == 'v')
			{
				return 2; 
			}
            else if (player_two == 'l')
			{
				return 1;

			}
			else if (player_two == 's')
			{
				return 1;
			}
			break;
		case 'l':
		case 'L':
			if (player_one == player_two)
			{
				return 3;
			}
			else if (player_two == 'r')
			{
				return 2;
			}
			else if (player_two == 's')
			{
				return 2;
			}
			else if (player_two == 'p')
			{
				return 1;
			}
			else if (player_two == 'v')
			{
				return 1;
			}
			else
			{
				return BadInput;
			}
			break;
		case 'v':
		case 'V':
			if (player_one == player_two)
			{
				return 3;
			}
			else if (player_two == 'l')
			{
				return 2;
			}
			else if (player_two == 'p')
			{
				return 2;
			}
			else if (player_two == 'r')
			{
				return 1;
			}
			else if(player_two == 's')
			{
				return 1;
			}
			else
			{
				return BadInput;
			}
			break;
		}
	return 0;
}		 
//as I gather, return is for error checking; return 0 if it works, return 1 if 
	     //it does not.  I cannot get a return of, well anything.


/*
 * Return the input string with all characters converted to lowercase.
 * @param string input - The string that will be converted to all lowercase
 * @return string - a string containing the converted input string
 */
string ToLower(string input) 
{
  // CODE HERE
  for (int i = 0; i<input.length(); i++)
  {
  input[i] = tolower(input[i]);
  }
  return input;
}

/*
 * Return the input string with all characters converted to uppercase.
 * @param string input - The string that will be converted to all uppercase
 * @return string - a string containing the converted input string
 *
string ToUpper(string input) {
  // CODE HERE
*/  
int main(){
    string item;
    int number;
    
    cout << "This is the story of Goldilocks, as told by you.\n";  
    cout << "You choose the item, \'pooridge\', \'chair\' or\n";
    cout << "\'bed\', and the number of that item, \'1\' ,\'2\'\n";
    cout << "or \'3\', and I will tell the story.  Are you ready?\n";
    cout << "Let's begin: \n";
    cout << "Which item? ";
    cin >> item;
    if ( item != "chair" && item != "porridge" && item != "bed"){
        item = "bed";}
    cout <<"\n And number? ";
    cin >> number;
    if (number < 1 || number > 3){
        number = 3;}
    cout << Goldilocks(item, number) << "\n";
    
    char PlayerOne, PlayerTwo;
    cout << "Let's play 'Rock, Paper, Scissors \n";
	cout << "Lizard, Spock!!\n";
	cout << "R =Rock, P = Paper, S = Scissors \n";
	cout << "L = Lizard and V = Spock (Vulcan) \n";
	cout << "Ready??  " << endl;
	
	cout << "Player one, choose your tool: ";
	cin >> PlayerOne;
	cout << "Player Two, choose your tool: ";
	cin >>PlayerTwo;
	char first = tolower(PlayerOne);
	char second = tolower(PlayerTwo);
	cout << RockScissorPaper(first, second) <<"\n";
	string send = "The Quick Brown Fox...";
    cout << ToLower(send)<< "\n";
    return 0;
}

