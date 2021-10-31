//************************//
//*         Q1           *//
//************************//
 
 
#include <iostream>
#include <vector>
using namespace std;
 
 
long long iteFibo(long long N)
{
   long long secondPreviousNumber=0; long long previousNumber =0; long long currentNumber=1;//O(1)
   for(long long i = 1; i<N; i++)//1+1+1+1+... N Times= O(N)
   {
       secondPreviousNumber = previousNumber; //1+1+1+1+... N Times= O(N)
       previousNumber = currentNumber;//1+1+1+1+... N Times= O(N)
       currentNumber = secondPreviousNumber + previousNumber;//1+1+1+1+... N Times= O(N)
 
   }
   return currentNumber; //O(1)
}//Overall Complexity=O(1)+4*O(N)=O(N)
 
 
long long recFibo(long long N)
{
   if(N==0 || N==1)//O()
       return N;//O(1)
   return recFibo(N-2) + recFibo(N-1);//This is upper bounded by 1+2+4+8..2^N=2^(n+1)
}//and lower bounded by 2^(N/2) which is approximately 2^(N).
 
 
long long memFiboHelper(vector<long long> &arrayFibo,long long N)
{
   if(arrayFibo[N]!=-1)//O(1)
       return arrayFibo[N];//O(1)
   arrayFibo[N]=memFiboHelper(arrayFibo,N-1)+arrayFibo[N-2];//Tn=O(N-1)+O(1)=O(N) Since, N-1, N-2,..2,1
   return arrayFibo[N];//O(1)
}//Overall Complexity= 3*O(1)+O(N)=O(N)
 
 
long long memFibo(long long N)
{
   vector<long long> arrayFibo(N+1,{-1});//O(1)
   arrayFibo[0]=0;//O(1)
   arrayFibo[1]=1;//O(1)
   return memFiboHelper(arrayFibo,N);//O(N)
}//Overall COmplexity = 3*O(1)+O(N)
 
 
 
 
int Q1()
{
   cout<<iteFibo(4)<<endl;
   cout << recFibo(4) << endl;
   cout<< memFibo(4)<<endl;
   return 0;
}
