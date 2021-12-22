#include<bits/stdc++.h>
using namespace std;
int x[10],y[10];
double polygonArea()
{
    double area = 0.0;
    // Calculate value of shoelace formula
    int j = 3 - 1;
    for (int i = 0; i < 3; i++)
    {
        area += ((double)x[j] + (double)x[i]) * ((double)y[j] - (double)y[i]);
        j = i;  // j is previous vertex to i
    }
    // Return absolute value
    return abs(area / 2.0);
}
bool calcula(){
    double v1=polygonArea();
    ////////////////
    int aux_x=x[0],aux_y=x[0];
    x[0]=x[3],y[0]=y[3];
    x[3]=aux_x,y[3]=aux_y;
    double principal=polygonArea();
    //////////
    aux_x=x[1],aux_y=x[1];
    x[1]=x[3],y[1]=y[3];
    x[3]=aux_x,y[3]=aux_y;
    double v2=polygonArea();
    //////////
    aux_x=x[2],aux_y=x[2];
    x[2]=x[2],y[2]=y[3];
    x[3]=aux_x,y[3]=aux_y;
    double v3=polygonArea();
    ///////////////////
    printf("v1:%lf v2:%lf v3:%lf sum:%lf principal:%lf\n",
           v1,v2,v3,v1+v2+v3,principal);
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
            scanf("%d %d",&x[i],&y[i]);
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
