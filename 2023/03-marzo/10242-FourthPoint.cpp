#include <iostream>
using namespace std;

int main()
{
    double x[4], y[4];
    while (cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2] >> x[3] >> y[3])
    {
        double x4, y4;
        if (x[0] == x[2] && y[0] == y[2])
        {
            x4 = x[1] + x[3] - x[2];
            y4 = y[1] + y[3] - y[2];
        }
        else if (x[0] == x[3] && y[0] == y[3])
        {
            x4 = x[1] + x[2] - x[3];
            y4 = y[1] + y[2] - y[3];
        }
        else if (x[1] == x[2] && y[1] == y[2])
        {
            x4 = x[0] + x[3] - x[2];
            y4 = y[0] + y[3] - y[2];
        }
        else
        {
            x4 = x[0] + x[2] - x[3];
            y4 = y[0] + y[2] - y[3];
        }
        printf("%.3lf %.3lf\n", x4, y4);
    
    }
    return 0;
}