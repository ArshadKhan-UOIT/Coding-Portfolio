// testing nested functions 
#include <iostream>
#include <cmath>

using namespace std;

const int kSIZE = 3;//size of the array const

//declearing the ProductionData function
void ProductionData(int valueOf[], int plant);

//declearing the function
void OnePer(int ProData[], int unit);

//declearing the display function
void Display(const int valueOf[], int plant);

//declearing the amount function
void Amount(int& sum);

//declearing the function
int Round(double number);

//declearing the Graph function
void Graph(int unitsInThousands);


int main()
{
    int production[kSIZE];//initializing the array
    cout << "This program displays a graph showing\n"
         << "production for each factory in the company.\n";
    //each time the production and kSIZE goes into a function and
    //comes out it then takes that production and data from the
    //from the previous function that was excuted
    ProductionData(production, kSIZE);
    OnePer(production, kSIZE);
    Display(production, kSIZE);
    return 0;
}
//defining the ProductionData function
void ProductionData(int valueOf[], int plant)
{
    // this function loops 3 time for the plant number
    //but eact time it loops it has to forefill the Amount functions
    //conditions
    for (int loop = 1;loop <= plant; loop++)
    {
        cout << endl
             << "Enter production data for plant number "
             << loop
             << endl;
        Amount(valueOf[loop - 1]);
        //this is where the the the Amount is called for the
        //units to be inputted for whatever plant number
        //is currently being excuted
    }
}
//defining the Amount function
void Amount(int& sum)
{
    //this asks for the amount for the production and then sums it up
    cout << "Enter number of units produced by each department.\n"
         << "Append a negative number to the end of the list.\n";
    sum = 0;
    int next;
    cin >> next;
    //you can keep entering a amount of units until you enter a negative number
    while (next >= 0)
    {
        sum = sum + next;
        cin >> next;
        //sums up the user input
    }
    //once the user enters a negative then the loop stop and
    //then the sum is outputted after that it goes back to the
    //ProductionData for the next 2 plant units to get the userinput
    cout << "Total = " << sum << endl;
}
//defininf the OnePer function
void OnePer(int ProData[], int unit)
{
    //the each of the plant unit numbers are then divided by 1000
    //and then the Round function then takes that value each time the
    //loop has been run
    for (int rounding_Loop = 0; rounding_Loop < unit; rounding_Loop++)
    {
      ProData[rounding_Loop] = Round(ProData[rounding_Loop]/1000.0);
    }
}
//defining the round function
int Round(double number)
{
    //this returns a round down number each time the loop
    //from the OnePer function is excuted so
    //it can get a whole number(interger)
    return static_cast<int>(floor(number + 0.5));
}
//defining the Display function
void Display(const int valueOf[], int plant)
{
    //the display then takes that number from the OnePer
    //function
    cout << "\nUnits produced in thousands of units:\n";
    //the display function displays a graph by
    //showing the factory number each time the loop is excuted and
    //it also calls the graph function
    for (int loop = 1; loop <= plant; loop++)
    {
        cout << "Factory #" << loop << " ";
        Graph(valueOf[loop - 1]);
        //this is where the graph is called and
        //takes the value from the OnePer
        //then gives it to the graph function
        //each time the loop is excuted
        cout << endl;
    }
}
//defining the Graph function
void Graph(int unitsInThousands)
{
    //the graph then loops 3 times like the other for loops in this program
    //the outputs asterisk based on the value(a value of 1 represents 1000)
    //for the valueOf[loop-1] in the doisplay fuction
    //that got that value from the OnePer function
    for (int PerFactory = 1; PerFactory <= unitsInThousands; PerFactory++)
    {
        cout << "*";
        //once it outs the whatever amount of asterisk from the
        //value that is based in thousands it goes back into the display
        //function so it can then output the next set of asterisk for the
        //next factory
        //1 asterisk represents 1000 units in production
    }
}
