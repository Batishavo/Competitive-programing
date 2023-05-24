#include <cstdio>
#include <map>

int main()
{
    freopen("entrada.txt", "r", stdin);
    freopen("salida.txt", "w", stdout);
    std::map<char, int> suitConversion;
    suitConversion['S'] = 0;
    suitConversion['H'] = 1;
    suitConversion['D'] = 2;
    suitConversion['C'] = 3;
    
    char back[4] = {'S', 'H', 'D', 'C'};
    
    // Is ordered 'S', 'H', 'D', 'C'
    bool ace[4], king[4], queen[4], jack[4], trump[4];
    int count[4], points, specialPoints, pos;
    
    char temp[3];
    
    
    while (scanf("%s", temp) == 1)
    {
        int num1 =0,
            num2=0,
            num3=0;

        for (int i = 0; i < 4; ++i)
        {
            ace[i] = king[i] = queen[i] = jack[i] = trump[i] = false;
            count[i] = 0;
        }
        
        points = specialPoints = 0; 
            
        for (int i = 0; i < 13; ++i)
        {
            if (i != 0)
                scanf("%s", temp);
            
            pos = suitConversion[temp[1]];
            
            switch (temp[0])
            {
            case 'A':
                ace[pos] = true;
                points += 4;
                num1+=4;
                break;
                
            case 'K':
                king[pos] = true;
                points += 3;
                num1+=3;
                break;
                
            case 'Q':
                queen[pos] = true;
                points += 2;
                num1+=2;
                break;
                
            case 'J':
                jack[pos] = true;
                points += 1;
                num1++;
            }
            
            ++count[pos];
        }
        
        // Subtractions
        for (int i = 0; i < 4; ++i)
        {
            if (ace[i])
                trump[i] = true;
                
            if (king[i] && count[i] < 2){
                --points;
                num2++;
            }
            else if (king[i])
                trump[i] = true;
                
            if (queen [i] && count[i] < 3){
                num2++;
                --points;
            }
            
            else if (queen[i])
                trump[i] = true;
                
            if (jack[i] && count[i] < 4){
                num2++;
                --points;
            }
            
            if (count[i] == 2){
                num3++;
                ++specialPoints;
            }
            
            else if (count[i] < 2){
                num3+=2;
                specialPoints += 2;
            }
        }
        printf("%d %d %d %d %d\n",points,trump[0] , trump[1] , trump[2] , trump[3]);
        printf("%d %d %d\n",num1,num2,num3);
        if (trump[0] && trump[1] && trump[2] && trump[3] && points >= 16)
            printf("BID NO-TRUMP\n");
            
        else if (points + specialPoints >= 14)
        {
            char output = 'S';
            int max = 0;
            for (int i = 1; i < 4; ++i)
            {
                if (count[i] > count[max])
                {
                    max = i;
                    output = back[i];
                }
                
                
            }
            printf("BID %c\n", output);
        }
        else
            printf("PASS\n");
    }
    
    
}