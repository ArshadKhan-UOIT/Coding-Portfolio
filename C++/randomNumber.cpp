//testing random number generator 


#include <iostream> //basic input and output services
#include <cstdlib>  //for the random number servies
#include <ctime>  //helps to generate a different number
#include <cmath> //used for the power function


using namespace std; //for cout and cin

int main()
{
    srand(time(NULL));
    //pseudop random number generator generates result when the rand is called
    int i=0;
    //for the number of rounds
    int num=0;
    // for controling the amount in the equation
    // for the Less_Than and Rand_Num function
    int choice=0;
    //user input
    int tries=5;
    // for the number of tries
    bool loop=true;
    //for creating the while loop
    cout << "-----------------------------------" << endl;
    cout << "Welcome to Guess That Number!" << endl;
    cout << "-----------------------------------" << endl;

    while(loop) //while loop [first]
    {
        i++;
        int Rand_Num = rand() % 5*pow(2, num);
        //so the random number generator generates 5 different numbers thats
        //less than 5 for round 1 and 10 different numbers thats less than
        //10 and round 3 etc
        cout << "\nRound " << i << endl;
        //shows which is the current round
        int Less_Than = 5*pow(2, num);
        //this is the function that tells the user that they have to enter
        //a value that is less than a certain number and this doubles every
        //round becasue of the num=num+1 (num++) so if num=0
        //user has to enter a value thats less than 5 then 10, 20 and so on each
        //time the second loop finiehes and theres a new round
        //5(2)^0=5(1)=5 - 5(2)^1=5(2)=10
        num++;
        //this makes num increase by 1 each time it goes through the
        //first loop
        while(loop)
        //while loop [second] this is where all the if else if statement are
        //used
        {
          tries--;
          //this makes the amout of tries one less once the user enters an
          //value that doesnt match the Rand_Num variable
          // so when it goes back to the beginning of the loop is goes
          //straight back to the beginning
          cout << "Guess a number less than " << Less_Than << ": ";
          cin >> choice;
          /*this is where the user input is entered
          */
          if (choice != Rand_Num)
          /*this is the if else statement. if the number the user enters
          does not equal the Rand_Num that was generated then it goes through
          a different set of if else statements
          */
          {
            /*this is where the incorrent set of values that the user enters
            goes through these if and else statements
            */
            if (tries ==0)
            /*if the user enters a value that is not equal to Rand_Num
            and the number of tries left is equal to 0 then the game is over
            and the program ends
            */
            {
              cout << "Incorrect! out of guesses :(\nGame Over!!!";
              loop=false;
              /*this is the output when the user and no more tries left and
              the variable that ends the program just and the loop false so it
              does not excute anymore
              */
            }
            else
            {
              cout << "\nIncorrect! try again (" << tries << " tries remaining)" << endl;
              /*this is the else statement that if the user's value does not
              match up with the Rand_Num and there is not 0 tries left then it
              goes to this else statement with outputs the amout of tries left
              */
            }
          }
          else if (choice == Rand_Num)
          //this else if statement is if the user input is equal to the Rand_Num
          {
            cout << "Correct! The Number was " << choice << "\n";
            tries=5;
            break;
            /*this is the output if the user guesses correctly and it
            resets the tries back to 5 before breaking the second while loop to
            go back to the first loop to a new round
            */
          }
        }
      }

  return 0;
 }
