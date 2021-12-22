#include<bits/stdc++.h>
using namespace std;
struct fPoint
{
  float x;
  float y;
};
float CalcTriArea(fPoint *v1, fPoint *v2, fPoint *v3)
{
  float det = 0.0f;
  det = ((v1->x - v3->x) * (v2->y - v3->y)) - ((v2->x - v3->x) * (v1->y - v3->y));
  return (det / 2.0f);
}
bool IsPointInTri(const fPoint *pt, const fPoint *v1, const fPoint *v2, const fPoint *v3)
{
  float TotalArea = CalcTriArea(v1, v2, v3);
  float Area1 = CalcTriArea(pt, v2, v3);
  float Area2 = CalcTriArea(pt, v1, v3);
  float Area3 = CalcTriArea(pt, v1, v2);

  if((Area1 + Area2 + Area3) > TotalArea)
    return false;
  else
    return true;
}
int main(){
    int test;
    scanf("%d",&test);
    for(int k=1;i<=k;k++){
        int ptx,pty,v1x,v1y,v2x,v2y;
        scanf("%d %d %d %d %d %d",&ptx,&pty,&v1x,&v1y,&v2x,&v2y);
        fPoint pt,v1,v2,v3;
        pt.x=ptx;
        pt.y=pty;
        v1.x=v1x;
        v1.y=v1y;
        v2.x=v2x;
        v2.y=v2y;
        bool can=IsPointInTri(pt,v1,v2,v3);
        if(can){
            printf("Case #%d: IN",k);
        }
        else{
            printf("Case #%d: OUT",k);
        }

    }
    return 0;
}
