#include <bits/stdc++.h>
using namespace std;

int main(){
 int x,m;
 cout<<"Enter modulas:";
 cin>> m;

 for(int i=0;i<10;i++){
    x=rand()%m;
    cout<<(double)x/(double)m << endl;
 }
}
