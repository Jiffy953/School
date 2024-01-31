#include <iostream>
using namespace std;


int main() {
  
}

void towerOfHanoi(int n, char start, char end, char aux)
{
  if (n== 1)
  {
    cout << "\nMove disk 1 from rod " << start <<" to rod " << end;
    return;
  }
  towerOfHanoi(n-1, start, aux, end);
  cout <<"\nMove disk " <<n<<" from rod "<<start<<" to rod "<<end;
  towerOfHanoi(n-1, aux, end, start);
}