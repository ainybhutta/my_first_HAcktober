#include <iostream>
using namespace std;
 
 
long long BS_rec(int* A, int si, long long ei, long long target)
{
 if( si > ei )
 return -1;
 
 long long mi = (ei+si) / 2;
 
 if ( A[mi] ==  target)
 return mi;
 
 else if ( A[mi]< target)
 return BS_rec(A,mi+1, ei ,  target);
 else
 return BS_rec( A, si, mi-1, target);
}
 
int Binary_Search( int* A, int size, int t)
{
 return BS_rec(A, 0, size-1, t);
}
int main()
{
 //intA[5];
 long long N = 10;
 
 int* A = new int [N];
 
 for ( int i=0; i< N;i++)
 A[i] = i;
 
   for ( long long i=0; i< N;i++)
       cout << A[i] << ",";
   cout << endl;
   cout << Binary_Search( A, N, 5);
}
