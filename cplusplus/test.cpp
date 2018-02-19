#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string.h>
using namespace std;
int wal_stricmp(const char *a, const char *b) {
  int ca, cb;
  do {
     ca = (unsigned char) *a++;
     cb = (unsigned char) *b++;
     ca = tolower(toupper(ca));
     cb = tolower(toupper(cb));
   } while (ca == cb && ca != '\0');
   return ca - cb;
}
// NameDataSet : Store nae and credit card
//               information
class NameDataSet
{
public:
  char firstName[128];
  char lastName[128];
  int creditCard;
};

bool getData(NameDataSet& nds);
void displayData(NameDataSet& nds);

int main(){
  const int MAX = 25;
  NameDataSet nds[MAX];

  cout << "Read name/credit card information\n"
       << "Enter 'exit' to quit"
       << endl;
  int index = 0;
  while (getData(nds[index]) && index < MAX)
    {
      index++;
    }
  cout << "\nEntries:" << endl;
  for (int i=0;i<index;i++)
    {
      displayData(nds[i]);
    }
     return 0;
}




bool getData(NameDataSet& nds)
{
  cout << "\nEnter first name:";
  cin >> nds.firstName;
  if(wal_stricmp(nds.firstName, "exit")==0)
    {
      return false;
    }
  cout << "Enter last name:";
  cin >> nds.lastName;

  cout << "Enter credit card number:";
  cin >> nds.creditCard;
  return true;
}

void displayData(NameDataSet& nds)
{
  cout << nds.firstName
       << " "
       << nds.lastName
       << "/ "
       << nds.creditCard
       << endl;
}
