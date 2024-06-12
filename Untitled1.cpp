#include <iostream>
using namespace std;
int main()
{
   int *p, *q;
   int sum, first, second;
   cout << "Enter two integers to add\n";
   cin >> first;
   cin >> second;
   p = &first;
   q = &second;
 sum = *p + *q;
   cout << "Sum of entered numbers = " << sum << "\n";
   return 0;
}
