// pointer arrays checkng for duplicates 
#include <iostream>

using namespace std;

typedef int* IntPtr;//declearing all IntPtr variables pointers

void sort(int arr[], int size);//declearing the sorting function

int main()
{
  //p1[0]==*p1
  //p1[1]==*(p1+1)
  IntPtr p1;//user input array
  IntPtr countArray;//counts the valus of the user input
  int size;//array elements
  int counter=0;
  cout << "Enter the size" << endl;
  cin >> size;//user chooses the size of array
  p1 = new int[size];//dymanic array for user input
  countArray = new int[size];//dynamic array for the amount of times in p1 array
  cout << "Enter the intergers" << endl;//user enters the intergers
  for (int i=0;i<size;i++)
  {
    cin >> p1[i];
  }
  cout << endl;

  for (int i=0;i<size;i++)//this counts the amount of times the intergers
  {//the user entres shows
    for (int j=0;j<size;j++)
    {
      sort(p1, size);//sorting function
      if (p1[i] == p1[j])
      {
        counter++;
      }
    }
    countArray[i] = counter;//converts it to an array
    counter=0;//initializes it back to 0
  }
  for (int i=0;i<size;i++)//loop checks for duplicates
  {
    bool isDuplicate = false;
    for (int j=i+1;j<size;j++)
    {
      if (p1[i] == p1[j])
      {
        isDuplicate = true;
      }
    }
    if (!isDuplicate)//goes to this if there are no duplicates
    {
      if (countArray[i]>=2)//double digits for times
      {
        cout << p1[i] << " -> " << countArray[i] << " times" << endl;
      }
      else//single digit for time
      {
        cout << p1[i] << " -> " << countArray[i] << " time" << endl;
      }
    }
  }
  delete [] p1;
  delete [] countArray;
}
void sort(int arr[], int size)//defining the sorting function
{
  int tempHolder;
  for (int i=0;i<size;i++)
  {
    for (int j=0;j<size;j++)
    {
      if (arr[i]<arr[j])
      {
        tempHolder=arr[i];
        arr[i]=arr[j];
        arr[j]=tempHolder;
      }
    }
  }
}
