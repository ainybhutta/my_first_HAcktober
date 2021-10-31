//************************//
//*         TS           *//
//************************//
#include <iostream>
#include <vector>
using namespace std;
 
 
long long part1(long long N)//assuming that user enters a positive integer
{
   if(N==1||N==0)//O(1)
       return N;//O(1)
   return N + part1(N-1);//Tn=T(n-1)+O(1)= O(N)
}
 
 
long long part2(long long N)
{
   //try{
       //if(N%2!=1||N<0)
           //throw N;
       if(N==1)
           return 1;
   //}
   /*catch(...)
   {
       cout <<"Kindly enter a valid odd integer next time. Exception Code\t";
       return -404;
   }*/
   return N + part2(N-2);  // O(N)
}
 
long long part3Helper(long long &sum, long long N)
{
   if(N==0)//O(1)
   {
       sum=1;
       return 1  ;//O(1)
   }
   long long currentNumber =2*part3Helper(sum,N-1);
   sum+=  currentNumber;
   return currentNumber ;
}
long long part3(long long N)
{
   long long sum=0;
   part3Helper(sum,N);
   return sum;
}                        // O(N)
 
 
 
long long part4Helper(long long &sum, long long N)
{
   if(N==0)//O(1)
   {
       sum=1;
       return 1  ;//O(1)
   }
   long long currentNumber =3*part4Helper(sum,N-1);
   sum= sum + currentNumber;
   return currentNumber ;
}
long long part4(long long N)
{
   long long sum=0;
   part4Helper(sum,N);
   return sum;
}                        // O(N)
 
 
long long part5(long long N)
{
   if(N==1)
       return 1;  
   return N+part5(N/3);
}                     //O(log3N)
 
 
long long part6(long long N)
{
   if(N==1)
       return 1;  
   return N+part6(N/2);
}                         //O(log2N)
              
 
int main()
{
   int N=9;
   cout << "Sum of series " << 1 << " is:\t" << part1(N) << endl;//Assuming user enters N>0
   cout << "Sum of series " << 2 << " is:\t" << part2(N) << endl;//Assuming user enters Odd values. However check is commented out
   cout << "Sum of series " << 3 << " is:\t" << part3(N) << endl;//Assuming user enters Z+
   cout << "Sum of series " << 4 << " is:\t" << part4(N) << endl;//Assuming user enters Z+
   cout << "Sum of series " << 5 << " is:\t" << part5(27) << endl;//Assuming user enters N|∃ 3^k=N, where k ∈ Z+
   cout << "Sum of series " << 6 << " is:\t" << part6(16) << endl;//Assuming user enters N|∃ 2^k=N, where k ∈ Z+
   return 0;
}
