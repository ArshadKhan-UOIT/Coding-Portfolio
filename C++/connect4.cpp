// connect 4 game 
#include <iostream>
#include <string>

using namespace std;

//Global variables for representing the game board
const int COLS = 7;
const int ROWS = 6;
char board[COLS][ROWS]; //2D array of 7x6

//Global constants for game pieces
const char EMP = '-';
const char P1 = 'X';
const char P2 = 'O';

//initializes a connect4 board to contain
//all empty cells
void initializeBoard();

//Display contents of the board
void displayBoard();

//Add one piece to the Board
bool addPiece(int c, bool isPlayer1);

//Checks if a given player has won
bool isWinner(bool isPlayer1);

int main() {
  //Initialize game play
  bool PlayerOne = true;
  bool gameWon = false;
  int totalMoves = 0;
  const int MAX_MOVES = ROWS * COLS;

  initializeBoard();
  displayBoard();

  //Create a game play loop
  while ((totalMoves < MAX_MOVES) && (!gameWon)) {
    bool validMove = false;
    int columnToPlay = 0;
    //ask current player for a column until a valid move
    //is chosen
    while (!validMove) {
      cout << "Player ";
      if (PlayerOne) {
        cout << "1";
      } else {
        cout << "2";
      }
      cout << " - Select a column (0-"
           << (COLS-1) << ") to play: ";
      cin >> columnToPlay;
      validMove = addPiece(columnToPlay, PlayerOne);
      if (!validMove) {
        cout << "Column full. Try again." << endl;
      }
    }
    totalMoves++;
    displayBoard();
    gameWon = isWinner(PlayerOne);
    //Switch Player
    if (!gameWon){
      PlayerOne = !PlayerOne;
    }
  }
  if (gameWon) {
    cout << "Congratulations Player ";
    if (PlayerOne) {
      cout << "1";
    } else {
      cout << "2";
    }
    cout << ". You've won Connect Four!!!!" << endl;
  }
  else if (totalMoves == MAX_MOVES) {
    cout << "Game over! No moves remaining." << endl;
  }
  return 0;
}

void initializeBoard() {
  for (int c = 0; c < COLS; c++) {
    for (int r = 0; r < ROWS; r++) {
        board[c][r] = EMP;
    }
  }
}

void displayBoard() {
  cout << endl <<  "Connect 4 Board:" << endl;
  //Display board one row at a time
  for (int r = 0; r < ROWS; r++) {
    //For each row display all of the columns
    for (int c = 0; c < COLS; c++) {
      cout << board[c][r] << " ";
    }
    //After each row output newline character
    cout << endl;
  }
  for (int c = 0; c < COLS; c++) {
      cout << c << " ";
  }
  cout << endl << endl;
}

bool addPiece(int c, bool isPlayer1) {
  //check if column c is full
  if (board[c][0] != EMP) {
    return false;
  } else {
    //add piece to lowest unoccupied slot in column c
    for (int r = (ROWS-1); r >= 0; r--) {
        if (board[c][r] == EMP) {
          if (isPlayer1) {
            board[c][r] = P1;
          }
          else {
            board[c][r] = P2;
          }
          break;
        }
    }
    return true;
  }
}

bool isWinner(bool isPlayer1) {
  char currTile;
  if (isPlayer1) {
    currTile = P1;
  } else {
    currTile = P2;
  }
  //Check if current player has 4 pieces horizontally
  for (int r = 0; r < ROWS; r++) {
    int counter = 0; //reset counter to zero for each row
    for (int c = 0; c < COLS; c++) {
      if(board[c][r] == currTile) {
        counter++;
      } else {
        counter = 0;
      }
      if (counter == 4) {
        return true; //game won!
      }
    }
  }
  //Check if current player has 4 pieces vertically
  for (int r = 0; r < ROWS; r++) {
    int counter = 0; //reset counter to zero for each row
    for (int c = 0; c < COLS; c++) {
      if(board[r][c] == currTile) {
        counter++;
      } else {
        counter = 0;
      }
      if (counter == 4) {
        return true; //game won!
      }
    }
  }


  //Check if current player has 4 pieces diagonally (both ways)
  //the left to right diagonal
  for (int r=0;r<ROWS;r++)
  {
    int counter = 0;//reset the counter to zero for each Column
    for (int c=0;c<COLS;c++)
    {
      if(board[c][r] == currTile)
      {
        counter++;
        //these if statements check for the left to right diagonals
        if(board[c-1][r+1] == currTile)
        {
          counter++;
          if (board[c-2][r+2] == currTile)
          {
            counter++;
            if (board[c-3][r+3] == currTile)
            {
              counter++;
            }
            else
            {
              counter=0;
            }
          }
          else
          {
            counter=0;
          }
        }
        else
        {
          counter=0;
        }
      }
      else
      {
        counter = 0;
      }
      if (counter == 4)
      {
        return true; //game won!
      }
    }
  }
  //the right to left diagonal
  for (int r=0;r<ROWS;r++)
  {
    int counter = 0;//reset the counter to zero for each Column
    for (int c=0;c<COLS;c++)
    {
      if(board[c][r] == currTile)
      {
        counter++;
        //these if statements check for the right to left diagonals
        if(board[c+1][r+1] == currTile)
        {
          counter++;
          if (board[c+2][r+2] == currTile)
          {
            counter++;
            if (board[c+3][r+3] == currTile)
            {
              counter++;
            }
            else
            {
              counter=0;
            }
          }
          else
          {
            counter=0;
          }
        }
        else
        {
          counter=0;
        }
      }
      else
      {
        counter = 0;
      }
      if (counter == 4)
      {
        return true; //game won!
      }
    }
  }

  return false;
}
