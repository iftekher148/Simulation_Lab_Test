#include <bits/stdc++.h>
using namespace std;

int main(){
    int m,n,i,j,a,c,k,d,expec,rn,occurrance[1000],temp,rng,x,in;
    double chi,total;
  ofstream fileout;
  ifstream filein;

  fileout.open("chi_randon_number.txt");
  filein.open("chi_randon_number.txt");

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

   //segment2
  k=10;
  d=m/k;
  expec=n/k;
  rn=0;
  total=0;

  freopen("chi_squar.txt","w",stdout);

  for(i=0;i<n;i++){
    filein>>x;
    in=(x/d)+1;
    occurrance[in]++;
  }
  puts("| class |  range |  occurranceOi  |  Expectation occEi  |(Oi-Ei)^2 | (O-E)^2/E| ");
  puts("---------------------------------------------------------------------------------");

  for(i=0;i<k;i++){
    temp=(occurrance[i]-expec)*(occurrance[i]-expec);
    chi=(double)temp/expec;
    total+=chi;
    printf("| %2d | %4d -%4d |   %4d | %4d  |   %4d |  %10.2lf |\n",i,rn,rn+d-1,occurrance[i],expec,temp,chi);
    rn+=d;
  }

   printf("|                                            Total chi-square = %10.4lf   |\n",total);

    if(total>=1.73 && total <= 23.6) puts("Result : ACCEPTED");
    else puts("Result : NOT ACCEPTED");

    filein.close();

    return 0;
}


