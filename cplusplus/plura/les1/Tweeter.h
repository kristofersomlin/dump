#include "Person.h"
#include <string>
#ifndef _Tweeter_H
#define _Tweeter_H
class Tweeter : public Person
{
  private:
    std::string twitterhandle;

  public:
    Tweeter(std::string first,
          std::string last,
          int arbitrary,
          std::string handle);
    ~Tweeter(void);
};
#endif
