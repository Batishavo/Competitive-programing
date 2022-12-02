#include<bits/stdc++.h>
using namespace std;
double x[10],y[10];
double polygonArea(double dX0, double dY0, double dX1, double dY1, double dX2, double dY2)
{
    double dArea = ((dX1 - dX0)*(dY2 - dY0) - (dX2 - dX0)*(dY1 - dY0))/2.0;
    return (dArea > 0.0) ? dArea : -dArea;
}
bool calcula(){
    double principal=polygonArea(x[1],y[1],x[2],y[2],x[3],y[3]);
    double v1=polygonArea(x[0],y[0],x[2],y[2],x[3],y[3]);
    double v2=polygonArea(x[1],y[1],x[0],y[0],x[3],y[3]);
    double v3=polygonArea(x[1],y[1],x[2],y[2],x[0],y[0]);
    ///////////////////
    /*printf("v1:%lf v2:%lf v3:%lf sum:%lf principal:%lf\n",
           v1,v2,v3,v1+v2+v3,principal);*/
    if(v1+v2+v3>principal){
        return false;
    }
    return true;
}
int main(){
    int test;
    scanf("%d",&test);
    for(int k=1;k<=test;k++){
        for(int i=0;i<4;i++){
            scanf("%lf %lf",&x[i],&y[i]);
        }
        bool can=calcula();
        if(can){
            printf("Case #%d: IN\n",k);
        }
        else{
            printf("Case #%d: OUT\n",k);
        }
    }
    return 0;
}
