#include <iostream>
using namespace std;

int main() {
  int dag_antal,dagpris;
  cout << "antal dagar? ";
  cin >> dag_antal;
  cout << "pris per dag? ";
  cin >> dagpris;
  cout << "totalt pris "
       << dag_antal * dagpris << endl;
}
