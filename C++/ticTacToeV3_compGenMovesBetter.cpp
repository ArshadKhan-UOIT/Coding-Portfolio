//TIC-TAC-TOE [game]
// making the computer generated moves better 

#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int SIZE = 3;

void displayBoard(string b[][SIZE]);
bool userFirst();
bool currentPlayerWon(string b[][SIZE], string symbol);
void generateComputerMove(string board[][SIZE], int &row, int &col);

int main()
{
  //construct board
  string board[SIZE][SIZE];

  int position_id = 1;
  for (int i=0; i< SIZE; i++)
  {
    for (int j=0; j < SIZE; j++)
    {
        board[i][j] = to_string(position_id);
      /*  stringstream ss;
        ss << position_id;
        board[i][j] = ss.str();
        */
        position_id++;
    }
  }

  //Initial game output
  cout << "Welcome to Tic-Tac-Toe" << endl;

  bool userTurn = userFirst();
  if (userTurn == true)
  {
    cout << "Player goes first!" << endl;
  } else {
    cout << "Computer goes first!" << endl;
  }

  //Loop for turn taking in game
  int positionsRemaining = SIZE * SIZE;
  bool userWon = false;
  bool computerWon = false;

  while ((positionsRemaining > 0)
        && (!userWon) && (!computerWon))
  {
      displayBoard(board);

      //User's turn
      if (userTurn)
      {
        bool validMove = false;
        while (!validMove)
        {
          int position_id;
          cout << "Enter a position: ";
          cin >> position_id;
          if ((position_id <= (SIZE*SIZE))
              && (position_id > 0))
          {
            int row = (position_id-1)/SIZE;
            int col = (position_id-1)%SIZE;
            //cout << "row = " << row << " col = " << col << endl;
            if ((board[row][col] != "X")
                && (board[row][col] != "O"))
            {
                  board[row][col] = "X";
                  validMove = true;
            }
            else
            {
              cout << "Position already used. Try again." << endl;
            }

          }
          else
          {
            cout << "Position invalid. Try again." << endl;
          }
        }
        positionsRemaining--;
        userWon = currentPlayerWon(board, "X");
        userTurn = false;
      }

      //Computer's turn
      else
      {
        //The row and col are both passed as call-by-reference
        int row, col;
        //call function to determine computer move
        generateComputerMove(board, row, col);
        //update board with new move
        board[row][col] = "O";
        positionsRemaining--;
        //check if computer has won
        computerWon = currentPlayerWon(board, "O");
        userTurn=true;


      }
  }

  //Display game result
  displayBoard(board);
  if (userWon)

  {
    cout << "Congratulations! You have won!" << endl;
  }
  else if (computerWon)
  {
    cout << "The computer has won. Try again." << endl;
  }
  else
  {
    cout << "Out of moves. Try again." << endl;
  }
  return 0;
}

void displayBoard(string b[][SIZE])
{
  cout << "Tic-tac-toe board:" << endl << endl;
  for (int i=0; i< SIZE; i++)
  {
    for (int j=0; j < SIZE; j++)
    {
        cout << b[i][j] << "\t";
    }
    cout << endl;
  }
  cout << endl;
}

bool userFirst()
{
  //set seed for random number generation
  srand(time(NULL));

  //generate a random number
  //0 for computer
  //1 for user
  int num = rand()%2;
  if (num == 0)
  {
    return false;
  }
  else
  {
    return true;
  }
}

//Return true if player/computer with symbol (X or O) has won
bool currentPlayerWon(string b[][SIZE], string symbol)
{
  //Horizontal case
  //Loop through each row
  for (int i=0; i < SIZE; i++)
  {
    bool rowWinDetected = true;
    //Check all positions in row and see if they are the same symbol
    for (int j = 0; j < SIZE; j++)
    {
      if (b[i][j] != symbol)
      {
        rowWinDetected = false;
      }
    }
    if (rowWinDetected)
    {
      return true;
    }
  }

  //Vertical case
  //Loop through each column
  for (int i=0; i < SIZE; i++)
  {
    bool colWinDetected = true;
    //Check all positions in column and see if they are the same symbol
    for (int j = 0; j < SIZE; j++)
    {
      if (b[j][i] != symbol)
      {
        colWinDetected = false;
      }
    }
    if (colWinDetected)
    {
      return true;
    }
  }

  //Diagonal case #1
  bool diagonal1WinDetected = true;
  for (int i=0; i < SIZE; i++)
  {
    if (b[i][i] != symbol)
    {
      diagonal1WinDetected = false;
    }
  }
  if (diagonal1WinDetected)
  {
    return true;
  }

  //Diagonal case #2
  bool diagonal2WinDetected = true;
  for (int i=0; i < SIZE; i++)
  {
    if (b[(SIZE-1)-i][i] != symbol)
    {
      diagonal2WinDetected = false;
    }
  }
  if (diagonal2WinDetected)
  {
    return true;
  }

  //otherwise win not diagonal2WinDetected
  return false;

}

/*
generateComputerMove(string board[][SIZE], int &row, int &col)

this function generates a computer move by counting th number of O's and X's
in each row, column and diagonal and depending on the number of each a move is
determined to either block or try to win.

string board[][SIZE] holds the board that was passed

int &row references the address of the passed parameter to hold the row of the
         new move

int &col references the address of the passed parameter to hold the column of
         the new move
*/
void generateComputerMove(string board[][SIZE], int &row, int &col)
{
  bool validMove = false;
  int counterO=0;
  int counterX=0;
  //loop until a valid move is determined
  while (!validMove)
  {

    //Horizontal case
    if (!validMove)
    {
      //Loop through each row
      for (int i=0; i < SIZE; i++)
      {
        int counter = 0;
        //Check all positions in the row and see if they are the are an "O"
        for (int j = 0; j < SIZE; j++)
        {
          if (board[i][j] == "O")
          {
            //if the checked postition is an "O" add 1 to the counter
            counterO+=1;
          }
          else if (board[i][j] == "X")
          {
            //if the checked postition is an "X" add 1 to the counter
            counterX+=1;
          }
        }
        //check how many of each symbol are in the row to determine move
        if (counterX==2 && counterO==0)
        {

          for (int j = 0; j < SIZE; j++)
          {
            if ((board[i][j] != "X") && (board[i][j] != "O"))
            {
              //set the row and column of the new move
              row=i;
              col=j;

              validMove = true;

            }
          }
        }
        else if (counterX==0 && counterO==2)
        {

          for (int j = 0; j < SIZE; j++)
          {
            if ((board[i][j] != "X") && (board[i][j] != "O"))
            {
              //set the row and column of the new move
              row=i;
              col=j;

              validMove = true;

            }
          }
        }
        else if (counterX==0 && counterO>=1)
        {

          for (int j = 0; j < SIZE; j++)
          {
            if ((board[i][j] != "X") && (board[i][j] != "O"))
            {
              //set the row and column of the new move
              row=i;
              col=j;

              validMove = true;

            }
          }
        }
      }
    }

    //Vertical case
    if (!validMove)
    {
      //Loop through each column
      for (int i=0; i < SIZE; i++)
      {
        int counter = 0;
        //Check all positions in column and see if they are the same symbol
        for (int j = 0; j < SIZE; j++)
        {
          if (board[j][i] == "O")
          {
            //if the checked postition is an "O" add 1 to the counter
            counterO+=1;
          }
          else if (board[j][i] == "X")
          {
            //if the checked postition is an "X" add 1 to the counter
            counterX+=1;
          }
        }
        //check how many of each symbol are in the column to determine move
        if (counterX==2 && counterO==0)
        {
          for (int j = 0; j < SIZE; j++)
          {
            if ((board[j][i] != "X") && (board[j][i] != "O"))
            {
              //set the row and column of the new move
              row=j;
              col=i;

              validMove = true;

            }
          }
        }
        else if (counterX==0 && counterO==2)
        {

          for (int j = 0; j < SIZE; j++)
          {
            if ((board[j][i] != "X") && (board[j][i] != "O"))
            {
              //set the row and column of the new move
              row=j;
              col=i;

              validMove = true;

            }
          }
        }
        else if (counterX==0 && counterO>=1)
        {
          for (int j = 0; j < SIZE; j++)
          {
            if ((board[j][i] != "X") && (board[j][i] != "O"))
            {
              //set the row and column of the new move
              row=j;
              col=i;

              validMove = true;

            }
          }
        }
      }
    }

    //Diagonal case #1
    if (!validMove)
    {
      for (int i=0; i < SIZE; i++)
      {
        int counter = 0;
        if (board[i][i] == "O")
        {
          //if the checked postition is an "O" add 1 to the counter
          counterO+=1;
        }
        else if (board[i][i] == "X")
        {
          //if the checked postition is an "X" add 1 to the counter
          counterX+=1;
        }
      }
      //check how many of each symbol are in the diagonal to determine move
      if (counterX==2 && counterO==0)
      {
        for (int j = 0; j < SIZE; j++)
        {

          if ((board[j][j] != "X") && (board[j][j] != "O"))
          {
            //set the row and column of the new move
            row=j;
            col=j;

            validMove = true;

          }
        }
      }
      else if (counterX==0 && counterO==2)
      {

        for (int j = 0; j < SIZE; j++)
        {
          if ((board[j][j] != "X") && (board[j][j] != "O"))
          {
            //set the row and column of the new move
            row=j;
            col=j;

            validMove = true;

          }
        }
      }
      else if (counterX==0 && counterO>=1)
      {
        for (int j = 0; j < SIZE; j++)
        {
          if ((board[j][j] != "X") && (board[j][j] != "O"))
          {
            //set the row and column of the new move
            row=j;
            col=j;

            validMove = true;

          }
        }
      }
    }

    //Diagonal case #2
    if (!validMove)
    {
      for (int i=0; i < SIZE; i++)
      {
        int counter = 0;
        if (board[(SIZE-1)-i][i] == "O")
        {
          //if the checked postition is an "O" add 1 to the counter
          counterO+=1;
        }
        else if (board[(SIZE-1)-i][i] == "X")
        {
          //if the checked postition is an "X" add 1 to the counter
          counterX+1;
        }
      }
      //check how many of each symbol are in the diagonal to determine move
      if (counterX==2 && counterO==0)
      {
        for (int j = 0; j < SIZE; j++)
        {
          if ((board[(SIZE-1)-j][j] != "X") && (board[(SIZE-1)-j][j] != "O"))
          {
            //set the row and column of the new move
            row=(SIZE-1)-j;
            col=j;

            validMove = true;

          }
        }
      }
      else if (counterX==0 && counterO==2)
      {

        for (int j = 0; j < SIZE; j++)
        {
          if ((board[(SIZE-1)-j][j] != "X") && (board[(SIZE-1)-j][j] != "O"))
          {
            //set the row and column of the new move
            row=(SIZE-1)-j;
            col=j;

            validMove = true;

          }
        }
      }
      else if (counterX==0 && counterO>=1)
      {
        for (int j = 0; j < SIZE; j++)
        {
          if ((board[(SIZE-1)-j][j] != "X") && (board[(SIZE-1)-j][j] != "O"))
          {
            //set the row and column of the new move
            row=(SIZE-1)-j;
            col=j;

            validMove = true;

          }
        }
      }
    }

    //if none of the previous moves were made, the new move will be randomly
    //generated instead
    if (!validMove)
    {
      int r = rand()%SIZE;
      int c = rand()%SIZE;
      if ((board[r][c] != "X") && (board[r][c] != "O"))
      {
        row = r;
        col = c;

        validMove = true;

      }



    }
  }

}
