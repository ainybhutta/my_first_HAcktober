#include <iostream>
using namespace std;
 
int Mult( int A, int B)//O(N)
{ 
 if (B == 0 )
 return 0; 
 else
 {
 return A+ Mult(A, B-1);
 }
}
int F_Mult( int A, int B)//O(logN)
{ 
 if (B==0)
 return 0; 
 int T = A, C=1; 
 while( C+C <= B)
 {
   T+=T;
   C+=C;
 }
 return T + F_Mult(A, B-C);
}

 
int main(){
 cout << F_Mult(9,10);
 return 0;
}
