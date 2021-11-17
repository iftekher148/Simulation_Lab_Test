#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

int main(){
 double bx[1000],by[1000],fx[1000],fy[1000];
 double vf,dist,sin_theta,cos_theta;
 int i,posx=0,posy=0,time,mr=0;

 freopen("fighter_bomber.txt","r",stdin);

 int gd=DETECT,gm;
 initgraph(&gd,&gm," ");

 cin>>time;
 for(i=0;i<time;i++){
    cin>>bx[i]>>by[i];

    posx=min(posx,(int)bx[i]);
    posy=min(posy,(int)by[i]);
 }

 cin>>fx[0]>>fy[0];
 cin>>vf;

 for(i=0;i<time;i++){
    dist=sqrt((by[i]-fy[i])*by[i]-fy[i]+ bx[i]-fx[i]*bx[i]-fx[i]);
    sin_theta=(by[i]-fy[i])/dist;
    cos_theta=(bx[i]-fx[i])/dist;
    fx[i+1]=fx[i]+vf*cos_theta;
    fy[i+1]=fy[i]+vf*sin_theta;

    posx=min(posx,(int)fx[i]);
    posy=min(posy,(int)fy[i]);

    if(dist<=vf && i<time){
        cout<<"Time:"<<i <<"\nDistance:"<<dist<<endl;
        mr=1;
        time=1;
        break;
    }

 }

 if(!mr){
    cout<<"Escaped bomber";
 }

 //graph plotting

 int fct=3,inc=5;//graph boro dekhabe
 int ymx=getmaxy();
 posx=abs(posx);
 posy=abs(posy);

 setcolor(15);
 line((inc+posx)*fct,0,(inc+posx)*fct,getmaxy());
 line(0,getmaxy()-(inc+posx)*fct,getmaxy(),getmaxy()-(inc+posx)*fct);

 posx=posx+inc;
 posy=posy+inc;

  bx[0]=(bx[0]+posx)*fct;
  by[0]=(by[0]+posy)*fct;
  fx[0] = (fx[0]+posx)*fct;
  fy[0] = (fy[0]+posy)*fct;

  for(i=0;i<time;i++){
    bx[i]=(bx[i]+posx)*inc;
    by[i] = (by[i]+posy)*fct;
    fx[i] = (fx[i]+posx)*fct;
    fy[i] = (fy[i]+posy)*fct;

    setcolor(5);
    line(bx[i-1],ymx-bx[i-1],bx[i],ymx-bx[i]);
    delay(60);

    setcolor(6);
    line(fx[i-1], ymx - fy[i-1], fx[i], ymx - fy[i]);
        delay(50);

  }

   getch();
    closegraph();

    return 0;

}
