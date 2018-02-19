#include <iostream>
#include <stdio.h>
#include <cstdio>
using namespace std;




class smallobj {
  private:
    int somedata;
  public:
    void setdata(int d) {
      somedata=d;
    }
    void showdata() {
      cout << "THE DATA IS " << somedata << endl;
    }
};


namespace first_space {
  void func() {
    printf("Inside first_space\n");
  }
}
namespace second_space {
  void func() {
    printf("Inside second_space\n");
  }
}
int main() {

smallobj mackes_snopp, joels_snopp;




mackes_snopp.setdata(3);
joels_snopp.setdata(2);


mackes_snopp.showdata();
joels_snopp.showdata();



  first_space::func();
  second_space::func();
  return 1337;
}
