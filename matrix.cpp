#include <iostream>
using namespace std;
int main()
{
int a[2][2], b[2][2] , c[3][3] ;

cout<<"Here we fill matrix A :"<<endl;
for(int i=0 ; i<2 ;i++)
{
  for(int j=0 ; j<2 ;j++)
   {
    cout<<"("<<i<<","<<j<<") = " ;
    cin>>a[i][j] ;
   }   
}



cout<<"Here we fill matrix B :"<<endl;
for(int i=0 ; i<2 ;i++)
{
  for(int j=0 ; j<2 ;j++)
   {
    cout<<"("<<i<<","<<j<<") = " ;
    cin>>b[i][j] ;
   }   
}



cout<<"Here we add matrix A and matrix B  to matrix C :"<<endl;
for(int i=0 ; i<2 ;i++)
{
  for(int j=0 ; j<2 ;j++)
  {
    c[i][j] = a[i][j] + b[i][j] ;
    
    cout<<"("<<i<<","<<j<<") = " ;
    cout<<c[i][j]<<endl ;
  }   
}

return 0 ;
}