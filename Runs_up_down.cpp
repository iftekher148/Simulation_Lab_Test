#include <bits/stdc++.h>
using namespace std;

int main(){
    int m,n,i,j,a,c,x,rng,number[1000],runs,mr;
    double mean,variance,z;
  ofstream fileout;
  ifstream filein;

  fileout.open("random_number_ups_down.txt");
  filein.open("random_number_ups_down.txt");

  n=3000;
  m=1000;
   cout<<"seletc 1 for lcm and 2 for random:";
   cin>>rng;

   if(rng==1){
    for(i=0;i<n;i++){
    cout<<"Enter the value of a x c";
    cin>>a>>x>>c;
        x=(a*x+c)%m;
        fileout<< x << " ";
    }
   }
   else{
    for(i=0;i<n;i++){
        fileout<<x<<" ";
    }
   }
   fileout.close();

   //segment 2

   runs=0;
   mr=-1;
  // mean_middle=((double)m-1.0+0)/2.0;

   freopen("up_down_up.txt","w",stdout);

   for(i=0;i<n;i++){
    filein>>number[i];
   }
   cout<<"+ - sequence for up down ";
   for(i=0;i<n;i++){
    if(number[i+1]>number[i]){
        cout<<"+" <<" ";
        if(mr!=1) runs++;
        mr=1;
    }
    else{
        cout<<"-"<<" ";
        if(mr!=0) runs++;
        mr=0;
    }
   }

   mean=(2*n-1)/3;
   variance=(16*n-29)/90;
   z=((double)runs-mean)/sqrt(variance);

   cout<<"Total number :"<<n<<endl;
   cout<<"Total runs :"<<runs<<endl;
   cout<<"Mean:"<<mean<<endl;
   cout<<"Variance"<<variance<<endl;
   cout<<"Test Z0"<<z<<endl;

   if(z>=-1.96 && z<=1.96)
    cout<<"accept";
   else
    cout<<"Don't accept";

   filein.close();

   return 0;

}
