#include <string>

class Person
{
private:
  std::string firstname = "first";
  std::string lastname = "last";
  int arbitrarynumber;

public:
  std::string getName();

};
