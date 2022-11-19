#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
  string F_Name;
  string L_Name;
  int year;
  double wage;

  cout << "Name: ";
  cin >> F_Name >> L_Name;

  cout << "Birth Year: ";
  cin >> year;

  cout << "Hourly Wage($): ";
  cin >> wage;
  int age=2018-year;

  cout << fixed << setprecision(2);

  cout << F_Name << " " << L_Name << " is " << age << " years old and requests an hourly wage of $" << wage << "." << endl;

  return 0;
}
