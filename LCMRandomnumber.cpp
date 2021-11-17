#include <bits/stdc++.h>
using namespace std;

int main(){
 // int a=10,c=43,m=100,X[100], rand_number;
  // X[0]=27;
  int a,c,m,X[100], rand_number;
  cout<<"Constatant a"<< endl;
  cin>> a >> c >> m>> X[0];
      freopen("Linear_congruential_method.txt","w",stdout);

   for(int i=0; i<10;i++){
    rand_number = (a*X[i+1]+c)%m;
    cout<<"Random Number:"<< rand_number << endl;
   }
   return 0;
}

