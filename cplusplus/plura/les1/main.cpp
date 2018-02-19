#include <iostream>
#include "Person.h"
#include "Tweeter.h"

using std::cout;
using std::endl;
int main()  {

  Person p1("Kristofer","Somlin",123);
  {
  //p1.arbitrarynumber = 124;
  Tweeter t1("Anders","Andersson",456,"@whaattaa");
  }

  cout << "after innermost block" << endl;
  //p2.arbitrarynumber = 457;

  cout<<"###############################"<<endl;
  return 0;
}
