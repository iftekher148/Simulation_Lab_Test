#include <bits/stdc++.h>
using namespace std;

int main(){
 // double N;
 // cout<<"Enter the total numbers:";
  //cin>>N;
  int m,n,rng,a,c,x,runs,n1,n2,mr,number[1000],i;
  double mean,variance,mean_middle,z;

  ofstream fileout;
  ifstream filein;

  fileout.open("random_number_above_below.txt");
  filein.open("random_number_above_below.txt");

  //segment1---random_number_generator
  n=5000;
  m=1000;
  cout<<"Enter 1 for LCM and 2 for build function";
  cin>>rng;

  if(rng==1){
    //int a,c,x;
    cout<<"Enter x a c value:";
    cin>>x>>a>>c;
    for(int i=0;i<n;i++){
      x=( x=a*x+c)%m;
      fileout<< x <<" ";
    }
  }
  else{
    for(int i=0;i<n;i++){
       x=rand()%m;
       fileout<<x<<" ";
    }
  }
   fileout.close();

   //segment2

   runs=n1=n2=0;
   mr=-1;
   mean_middle=((double)m-1.0+0)/2.0;

   freopen("above_below_run.txt","w",stdout);

   for(i=0;i<n;i++){
    filein>>number[i];
   }

   cout<<"+ - sequence for above below";
   for(i=0;i<n;i++){
    if(number[i]>mean_middle){
        cout<<" +"<<" ";
        if(mr!=1) runs++,n1++;
        mr=1;
    }
    else{
        cout<<"-"<<" ";
        if(mr!=0) runs++,n2++;
        mr=0;
    }
   }

   mean=2*n1*n2/n+.5;
   variance= 2*n1*n2*(2*n1*n2-n)/n*n*(n-1);
   z=((double)runs-mean)/sqrt(variance);

   cout<<"Above from mean :"<<n1<<endl;
    cout<<"Below the mean :"<<n2<<endl;
     cout<<"Middle position mean  :"<<mean_middle<<endl;
     cout<<"total number :"<<n<<endl;
      cout<<"Above from mean :"<<n1<<endl;
       cout<<"Number of runs : "<<runs<<endl;
    cout<<"Mean : "<<mean<<endl;
    cout<<"Variance : "<<variance<<endl;
    cout<<"Z0 : "<<z<<endl;

    if(z>=-1.96 && z<=1.96)
        cout<<"Result:Accept";
    else
        cout<<"Result:Not accept";

      filein.close();
    return 0;
}
