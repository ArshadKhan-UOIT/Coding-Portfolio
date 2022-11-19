/* making a command line calender
References:

how to find the first day of the month in c++ http://www.cplusplus.com/forum/general/174165/
Eample from website...
unsigned day_of_week( unsigned year, unsigned month, unsigned day )
  {
  unsigned a, y, m;
  a = (14 - month) / 12;
  y = year - a;
  m = month + (12 * a) - 2;
  // Gregorian:
  return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
  }

  0 sunday
  1 monday
  2 Tuesday
  3 Wednesday
  4 thursday
  5 friday
  6 saturday

How to set the width of something in c++ http://www.cplusplus.com/reference/iomanip/setw/

i had some troubles formatting the output for the variable daysPer so i used this for
some help http://truelogic.org/wordpress/2015/09/12/generate-yearly-calendar-in-c/
// print days

int daysPrinted = 0;
for (int j = 1; j <= mDays[i]; j++) {
// move display head to the correct day of week for 1st
if (j == 1) {
int dow = firstDayOfMonth(i, mYear);
for (int spaces=0; spaces < dow; spaces++) {
  cout << setw(5) << " " << setw(2) << "   ";
    daysPrinted ++;
}
}

cout << setw(5) << j << setw(2) << "   ";
            daysPrinted ++;
            if (daysPrinted % 7 == 0) {
                cout << endl;
                daysPrinted = 0;
            }
        }
        cout << endl << setw(35) << "----------------------------------------------------------------" << endl;
    }
}



*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>


using namespace std;
//declearing the print month function
int printMonth(int& month, int& year);
//declearing the print year function
int printYear(int& year);

main()
{
  //declearing variables
  int year, month, choice;
  //main menu
  cout << "\nThis is a calender: "
       << "\nWhich calender do you perfer:\n1) Year\n2) Month\n3) Quit" << endl;
  cin >> choice;
  //choice 3 ends the loop and the program
  while (choice !=3)
  {
    //if user chooses the year calender
    if (choice==1)
    {
      //user chooses the year and puts it into the printYear function
      cout << "You choose the year calender: " << endl;
      cout << "Input the year: " << endl;
      cin >> year;
      printYear(year);
    }
    //if user chooses the month calender
    else if (choice==2)
    {
      //user enters the month and year and it goes into the printMonth function
      cout << "You choose the month calender: " << endl;
      cout << "Input the month:"
           << "\nEx. if you want Janurary please enter 1, Feburary is 2, etc"
           << "\nYour options should be between (1-12)"
           << endl;
      cin >> month;
      //this makes sure the user enters a valid month, otherwise program ends
      if (month <1 || month >12)
      {
        cout << "You Choose an Invalid Option!\n";
        cout << "Calender Ended!\n";
        break;
      }
      cout << "\nInput the year: " << endl;
      cin >> year;
      printMonth(month, year);
    }
    //if user chooses the quit option
    else if (choice==3)
    {
      cout << "Calender Ended!\n";
    }
    //if user enters an invalid option from the main menu
    else
    {
      cout << "Invalid Option\nTry again!";
    }
    /*brings the user back to the main menu when the print month, print year,
    and invalid option is finish excuting
    */
    cout << "\nThis is a calender: "
         << "\nWhich calender do you perfer:\n1) Year\n2) Month\n3) Quit" << endl;
    cin >> choice;
  }
  return 0;
}
//defining the printMonth function
int printMonth(int& month, int& year)
{
  /*i just reused the code from the print year option and changed some of the
  variables such as monthsOfYear and daysOfMonth to be the element of the actual
  user input of the month, since i worked on the print year first

  */
  int i=0;
  bool loop=true;
  int y=year;
  int m=month;
  string dayOfWeek[7];
  string monthsOfYear[13];
  int daysOfMonth[13];

  //array for daysOfMonth
  dayOfWeek[0]="S";
  dayOfWeek[1]="M";
  dayOfWeek[2]="Tu";
  dayOfWeek[3]="W";
  dayOfWeek[4]="Th";
  dayOfWeek[5]="F";
  dayOfWeek[6]="S";

  //array for the monthsOfYear
  monthsOfYear[1]="JANUARY";
  monthsOfYear[2]="FEBRUARY";
  monthsOfYear[3]="MARCH";
  monthsOfYear[4]="APRIL";
  monthsOfYear[5]="MAY";
  monthsOfYear[6]="JUNE";
  monthsOfYear[7]="JULY";
  monthsOfYear[8]="AUGUST";
  monthsOfYear[9]="SEPTEMBER";
  monthsOfYear[10]="OCTOBER";
  monthsOfYear[11]="NOVEMBER";
  monthsOfYear[12]="DECEMBER";

  //this is the amount of days per month
  daysOfMonth[1]=31;
  daysOfMonth[2]=28;
  daysOfMonth[3]=31;
  daysOfMonth[4]=30;
  daysOfMonth[5]=31;
  daysOfMonth[6]=30;
  daysOfMonth[7]=31;
  daysOfMonth[8]=31;
  daysOfMonth[9]=30;
  daysOfMonth[10]=31;
  daysOfMonth[11]=30;
  daysOfMonth[12]=31;
  /*daysOfMonth[2]=28
  if it goes through this to determine to see if theres a leep year
  [copied from CSCI 1060U - Laboratory #4.pdf]
  Years that are evenly divisible by 4 [remainder 0] are leap
  years except when the year is also evenly divisible by 100
  [when remmainder is not equal to 0].
  There is also an exception to this rule since
  years that are evenly divisible by 100 but
  also evenly divisible by 400 [remainder 0] [i just decided to use just the
  400]
  are considered leap years
  */
  if (y %400==0 || y %4==0 && y %100 !=0)
  {
    //if it is a leap year the daysOfMonth[2] is equal to 29
    daysOfMonth[2]=29;
  }
  //loop for the entire output of the calender
  while(loop)
  {
    //how to set the width of something http://www.cplusplus.com/reference/iomanip/setw/
    i++;
    //outputs the month
    cout << "\n" << setw(1) << monthsOfYear[m] << " " << y << "\n";
    //for loop for the dayOfWeek
    for (int j=0; j<8;j++)
    {
      cout << setw(2) << dayOfWeek[j] << " ";
    }
    cout << "\n";
    int daysPer=0;
    //this forloop formats the output for the days per month
    /*used this for some help formatting the output for the daysPer
    //http://truelogic.org/wordpress/2015/09/12/generate-yearly-calendar-in-c/
    */
    for (int k=1;k<=daysOfMonth[m];k++)
    {
      /*
      these are the values of what f_Day is equal to once it calculates the
      first day of the month
      0 sunday
      1 monday
      2 Tuesday
      3 Wednesday
      4 thursday
      5 friday
      6 saturday
      */
      //for the first row of the days of the month
      if (k==1)
      {
        //this is a formula from http://www.cplusplus.com/forum/general/174165/
        //it calclutes the first day of the month
        int a = (14 - m) / 12;
        int y_ = y - a;
        int d = m + (12 * a) - 2;
        int f_Day=(1 + y_ + (y_ / 4) - (y_ / 100) + (y_ / 400) + ((31 * d) / 12)) % 7;
        //formats the output for the first row of the days of the month
        for (int g=0;g<f_Day;g++)
        {
          cout << setw(3) << " " << setw(2);
          daysPer++;
        }
      }
      //outputs the rest after the the first row
      cout << setw(2) << k << " " << setw(2);
      daysPer++;
      //makes the new line once the 7th element of excuted
      if (daysPer %7==0)
      {
        cout << endl;
        daysPer=0;
      }
    }
    cout << "\n" << endl;
    //stops the while loop once the first month is finished excuting
    //this is not need for printMonth but i did for the printYear function
    //and i just copied it over and changed a few things so it only output one
    //month of which the user enters
    if (i==1)
    {
      // loop=false;
      break;
    }
  }
}
//defining the printYear function
int printYear(int& year)
{
  //this function of the same as the printMonth just a few changes so
  //it output the whole year to which the user enters
  int i=0;
  bool loop=true;
  int y=year;
  string dayOfWeek[7];
  string monthsOfYear[13];
  int daysOfMonth[13];

  //array for daysOfMonth
  dayOfWeek[0]="S";
  dayOfWeek[1]="M";
  dayOfWeek[2]="Tu";
  dayOfWeek[3]="W";
  dayOfWeek[4]="Th";
  dayOfWeek[5]="F";
  dayOfWeek[6]="S";

  monthsOfYear[1]="JANUARY";
  monthsOfYear[2]="FEBRUARY";
  monthsOfYear[3]="MARCH";
  monthsOfYear[4]="APRIL";
  monthsOfYear[5]="MAY";
  monthsOfYear[6]="JUNE";
  monthsOfYear[7]="JULY";
  monthsOfYear[8]="AUGUST";
  monthsOfYear[9]="SEPTEMBER";
  monthsOfYear[10]="OCTOBER";
  monthsOfYear[11]="NOVEMBER";
  monthsOfYear[12]="DECEMBER";
  // monthsOfYear[13]="Janurary";
  // monthsOfYear[14]="Feburary";

  daysOfMonth[1]=31;
  daysOfMonth[2]=28;
  daysOfMonth[3]=31;
  daysOfMonth[4]=30;
  daysOfMonth[5]=31;
  daysOfMonth[6]=30;
  daysOfMonth[7]=31;
  daysOfMonth[8]=31;
  daysOfMonth[9]=30;
  daysOfMonth[10]=31;
  daysOfMonth[11]=30;
  daysOfMonth[12]=31;

  /*daysOfMonth[2]=28
  if it goes through this to determine to see if theres a leep year
  [copied from CSCI 1060U - Laboratory #4.pdf]
  Years that are evenly divisible by 4 [remainder 0] are leap
  years except when the year is also evenly divisible by 100
  [when remmainder is not equal to 0].
  There is also an exception to this rule since
  years that are evenly divisible by 100 but
  also evenly divisible by 400 [remainder 0] [i just decided to use just the
  400]
  are considered leap years
  */
  if (y %400==0 || y %4==0 && y %100 !=0)
  {
    daysOfMonth[2]=29;
    //if it is a leap year the daysOfMonth[2] is equal to 29
  }
  //initializes the m so the f_Day formula can repeat finding the first day of
  //every month
  int m=1;

  while(loop)
  {
    //how to set the width of something http://www.cplusplus.com/reference/iomanip/setw/
    i++;//couter for the monthsOfYear
    //for the month
    cout << "\n" << setw(1) << monthsOfYear[i] << " " << y << "\n";
    for (int j=0; j<8;j++)
    {
      cout << setw(2) << dayOfWeek[j] << " ";
    }
    cout << "\n";
    /*used this for some help formatting the output for the daysPer
     http://truelogic.org/wordpress/2015/09/12/generate-yearly-calendar-in-c/
    */
    int daysPer=0;
    //outputs the days
    for (int k=1;k<=daysOfMonth[i];k++)
    {
      /*
      these are the values of what f_Day is equal to once it calculates the
      first day of the month. whatever the remainder 7 equals to the
      number corresponds to this day
      0 sunday
      1 monday
      2 Tuesday
      3 Wednesday
      4 thursday
      5 friday
      6 saturday
      4
      */
      //this shifts the first row that so it matches the day, f_Day is equal to
      if (k==1)
      {
        //this is a formula from http://www.cplusplus.com/forum/general/174165/
        int a = (14 - m) / 12;
        int y_ = y - a;
        int d = m + (12 * a) - 2;
        int f_Day=(1 + y_ + (y_ / 4) - (y_ / 100) + (y_ / 400) + ((31 * d) / 12)) % 7;
        //indenting the first row
        for (int g=0;g<f_Day;g++)
        {
          //i played around with the set width numbers so it matched with the day
          cout << setw(3) << " " << setw(2);
          daysPer++;
        }
      }
      //outputs the rest after the the first row
      cout << setw(2) << k << " " << setw(2);
      daysPer++;
        //makes the new line once the 7th element of excuted
      if (daysPer %7==0)
      {
        cout << endl;
        daysPer=0;
      }
    }
    m++;//adds 1 to the month to help for the calculation of the f_Day
    cout << "\n" << endl;
    if (i==12)//if i = december
    {
      //stops the loop once it reaches 12 which is december
      // loop=false;
      break;
    }
  }
}
