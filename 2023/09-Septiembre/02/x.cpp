#include <iostream>
#include <vector>
#include <map>
using namespace std;

class SegmentTree
{
private:
    int n;
    vector<int> A, st;
    map<int, pair<int, int>> freqs;

    int left(int i) { return i << 1; }
    int right(int i) { return (i << 1) + 1; }

    int build(int L, int R, int idx)
    {
        if (L == R)
            return st[idx] = A[L];
        int left_val = build(L, (L + R) / 2, left(idx));
        int right_val = build(((L + R) / 2) + 1, R, right(idx));
        int left_freq = freq(left_val, L, R);
        int right_freq = freq(right_val, L, R);

        return st[idx] = (left_freq >= right_freq) ? left_val : right_val;
    }

    int rfq(int i, int j, int L, int R, int idx)
    {
        if (R < i || j < L)
            return -1;
        if (i <= L && R <= j)
            return st[idx];

        int left_val = rfq(i, j, L, (L + R) / 2, left(idx));
        int right_val = rfq(i, j, ((L + R) / 2) + 1, R, right(idx));

        if (left_val == -1)
            return right_val;
        if (right_val == -1)
            return left_val;

        return freq(left_val, i, j) >= freq(right_val, i, j) ? left_val : right_val;
    }

public:
    SegmentTree(vector<int> &_A)
    {
        A = _A;
        n = A.size();
        st.assign(4 * n, 0);
        build(0, n - 1, 1);
    }

    int rfq(int i, int j)
    {
        return rfq(i, j, 0, n - 1, 1);
    }

    int freq(int n, int i, int j)
    {
        auto it = freqs.find(n);
        if (it == freqs.end())
            return 0;

        int lo = max(it->second.first, i);
        int hi = min(it->second.second, j);
        return max(0, hi - lo + 1);
    }
};

int main()
{
    int n, q;
    while (cin >> n, n)
    {
        cin >> q;
        vector<int> a(n);
        for (auto &x : a)
            cin >> x;
        SegmentTree st(a);
        for (int qq = 0; qq < q; qq++)
        {
            int i, j;
            cin >> i >> j;
            i--;
            j--;
            int number = st.rfq(i, j);
            int freq = st.freq(number, i, j);
            cout << freq << '\n';
        }
    }

    return 0;
}
