// testing functions and arrays 
#include <iostream>
#include <cstdlib>
#include <string>


using namespace std;

//declearing the swapper function
int swap(int& a, int& b);
//declearing the sorting function
int sorting(int array[], int& elements);

main()
{
    //variable declaration
    int sortArray[5];
    int Array_size;
    //finding the length of the array
    Array_size=sizeof(sortArray)/sizeof(sortArray[0]);
    // sortArray.length == sizeof(sortArray)/sizeof(sortArray[0]) in c++
    //user input
    cout << "Enter 5 intergers: ";
    for (int i=0;i<Array_size;i++)
    {
      cin >> sortArray[i];
    }
    //for getting the user input and let them go through the sorting function
    //along with the number of elements
    for (int i=0; i < Array_size; i++)
    {
      sorting(sortArray, Array_size);
    }
    //outputting the intergers in ascending order from max to min
		cout << "The array of integers sorted in ascending order is:\n";
    for (int i=0;i<Array_size;i++)
		{
			cout << sortArray[i] <<  " ";
		}
    cout << "\n" << endl;
  return 0;
}
//defining the sorting function
int sorting(int array[], int& elements)
{
  int highestIndex, noOfComparisons;
  highestIndex=elements-1;
  noOfComparisons=highestIndex;
  /*for loops are used to help sort and compare the values of each
  element of the array
  */
  for (int i=0;i<highestIndex;i++)
  {
    for (int j=0;j<noOfComparisons;j++)
    {
      /*if the one before is greater than the one after then is goes through
      this if statement to switch "swap" the numbers
      */
      if (array[j]>array[j+1])
      {
        // tempHolder=sortArray[j];
        // sortArray[j]=sortArray[j+1];
        // sortArray[j+1]=tempHolder;
        //this goes to the defining of the swapping function
        swap(array[j], array[j+1]);
      }
    }
    /*now that we have sorted one set we don't need to go
     through the entire array
    */
    noOfComparisons--;
  }
}
//defining the swapper function
int swap(int& a, int& b)
{
//switching the values of a and b
  int tempHolder;
  tempHolder=a; //storing the value of variable a into tempHolder
  a=b;  //the value of a is now the value of b
  b=tempHolder; //the value of b is now the original value of a
}
