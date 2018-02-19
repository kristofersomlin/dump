#include "Tweeter.h"
#include "Person.h"
#include <iostream>
using namespace std;
Tweeter::Tweeter(string first,
      string last,
      int arbitrary,
      string handle) :
      Person(first,last,arbitrary),
      twitterhandle(handle)
{
  cout <<"Constructing tweeter" <<
            twitterhandle << endl;


}

Tweeter::~Tweeter(void)
{
  cout <<"Destructing tweeter" <<
            twitterhandle << endl;

}
