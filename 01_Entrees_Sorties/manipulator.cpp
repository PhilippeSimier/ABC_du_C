#include <iostream>
#include <iomanip>



std::ostream &scientific(std::ostream &Out)
{

  Out << std::setiosflags(std::ios::showpoint |std::ios::scientific);
  Out << std::setprecision(2);

  return(Out);
}

int main(int argc,char *argv[])
{

  float Num = 3452.2334;
  //will insert 3.45e+03 into the stream
  std::cout << scientific << Num << std::endl;

}
