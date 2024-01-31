#include <iostream>

int power(int base, int exp)
{
  if (exp == 0)
  {
    return 1;
  }
   else
   {
     return (base * power(base, exp-1));
   }
}
int sum=0;
int crazysum(int n)
{
  if(n == 0)
  {
    return sum;
  }
  sum = sum + power(n, n);
  n--;
  return crazysum(n);
}



int main() {
  std::cout << power(10, 2) << std::endl;
  std::cout << crazysum(4) << std::endl;
}