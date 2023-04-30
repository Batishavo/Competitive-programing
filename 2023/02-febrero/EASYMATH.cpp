#include <bits/stdc++.h>

using namespace std;

long long t,
    n,
    m,
    a,
    d,
    answer;
vector<long long> nums;

long long pos(long long num, long long abs_pos, int flag)
{
    if(abs_pos%num == 0){
        return abs_pos;
    }
    return ((abs_pos / num) + flag) * num;
}

long long sum(long long num)
{
    long long ln = pos(num, n, 1),
              lm = pos(num, m, 0);
    long long suma = (lm / num) - (ln / num) + 1;
    // printf("num: %lld ln: %lld lm: %lld sum: %lld\n", num, ln, lm, suma);
    return (suma >= 0) ? suma : 0;
}
long long sum2(long long num)
{
    long long ln = pos(num, n, 1),
              lm = pos(num, m, 0);
    long long suma = (lm / num) - (ln / num) + 1;
    printf("num: %lld ln: %lld lm: %lld sum: %lld\n", num, ln, lm, suma);
    return (suma >= 0) ? suma : 0;
}
long long findlcm(string memo, int n)
{
    int pos = 0;
    vector<long long> arr;
    for (int i = 0; i < n; i++)
    {
        arr.push_back(nums[memo[i] - '0']);
        // cout<<arr[i]<<" ";
    }
    // cout<<endl;
    // Initialize result
    long long ans = arr[0];

    // ans contains LCM of arr[0], ..arr[i]
    // after i'th iteration,
    for (int i = 1; i < n; i++)
        ans = (((arr[i] * ans)) /
               (__gcd(arr[i], ans)));

    return ans;
}

long long u2()
{
    long long cont = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            cont += sum(nums[i] * nums[j] / __gcd(nums[i], nums[j]));
        }
    }
    return cont;
}
long long u3()
{
    // cout<<"entra"<<endl;
    long long answerAux = 0,
              arr[15];
    arr[0] = findlcm("012", 3);
    arr[1] = findlcm("013", 3);
    arr[2] = findlcm("014", 3);
    arr[3] = findlcm("023", 3);
    arr[4] = findlcm("024", 3);
    arr[5] = findlcm("034", 3);
    arr[6] = findlcm("123", 3);
    arr[7] = findlcm("124", 3);
    arr[8] = findlcm("134", 3);
    arr[9] = findlcm("234", 3);

    for (int i = 0; i < 10; i++)
    {
        answerAux += sum(arr[i]);
    }

    return answerAux;
}
long long u4()
{
    long long suma = 0;
    for (int i = 0; i < 5; i++)
    {
        string cad = "";
        for (int j = 0; j < 5; j++)
        {
            if (i == j)
            {
                continue;
            }
            char memo = (j + '0');
            cad += memo;
        }
        long long ans = findlcm(cad, 4);
        // cout<<cad<<" "<<ans<<endl;
        //  if(sum(ans)==1){
        //      cout<<cad<<" "<<ans<<endl;
        //  }
        suma += sum(ans);
    }
    return suma;
}
long long u5()
{
    long long ans = findlcm("01234", 5);
    // cout<<ans<<endl;
    return sum(ans);
}
void brute_force(int num)
{

    int sum = 0;
    for (long long i = n; i <= m; i++)
    {
        int cont = 0;
        for (int j = 0; j < 5; j++)
        {
            if (i % nums[j] == 0)
            {
                cont++;
            }
        }
        if (num == 1)
        {
            sum += cont;
        }
    }
    printf("n%d: %d\n", num, sum);
}
int main()
{
    // cout<<"hola";
    scanf("%d", &t);

    while (t--)
    {
        cin >> n >> m >> a >> d;
        nums.push_back(a);
        for (int i = 1; i <= 4; i++)
        {
            long long aux = a + (i * d);
            nums.push_back(aux);
        }
        // int cont=0;
        // for(long long i=n;i<=m;i++){
        //     if(i%4==0){
        //         cont++;
        //     }
        // }
        // cout<<cont<<endl;
        for (int i = 0; i < 5; i++)
        {
            // cout<<sum(nums[i])<<" "<<nums[i]<<endl;
            answer += sum(nums[i]);
        }
        // cout << "u1 :" << answer << endl;
        // brute_force(1);
        // // cout << "-----" << endl;
        // cout << "u2 :" << u2() << endl;
        answer -= u2();
        // brute_force(2);
        // cout<<answer <<" "<<u2() << endl;
        // cout << "-----" << endl;
        // cout << "u3 :" << u3() << endl;
        answer += u3();
        // brute_force(3);
        // cout<<answer << endl;
        // cout<<answer <<" "<<u3() << endl;
        // cout<<"---------"<<endl;
        answer -= u4();
        // cout << "u4: " << u4() << endl;
        // brute_force(4);
        // cout<<"u5: "<<u5() << endl;
        answer += u5();
        // cout << "u5: " << u5() << endl;
        // brute_force(5);
        // cout<<findlcm("01234",5)<<endl;
        // cout << "--";
        cout << m - n - answer + 1 << endl;
        answer = 0;
        nums.clear();
    }
    return 0;
}