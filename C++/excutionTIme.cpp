// testing the excution time of a program 
// time ./<cpp file name> 
/*output time for 10000 element array is
real    0m0.337s
user    0m0.281s
sys     0m0.016s
output time for 1000 element array is
real    0m0.029s
user    0m0.000s
sys     0m0.016s
*/
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>


using namespace std;

//declearing the swapper function
int swap(int& a, int& b);
//declearing the sorting function
int sorting(int array[], int& elements);

main()
{
    //so the randum number generates a different number each time
    srand(time(NULL));
    //variable declaration
    int highestIndex, noOfComparisons;
    //sorting an array with 1000 elements
    int sortArray[1000];
    //sorting an array with 10000 elements
    // int sortArray[10000];
    int Array_size;
    //finding the length of the array
    Array_size=sizeof(sortArray)/sizeof(sortArray[0]);
    // sortArray.length == sizeof(sortArray)/sizeof(sortArray[0]) in c++
    for (int i=0;i<Array_size;i++)
    {
      sortArray[i] = rand() % 100000;
    }
    //for getting the random values and let them go through the sorting function
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
