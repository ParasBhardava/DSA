#include <bits/stdc++.h>
using namespace std;

class sparseTable
{
    int n;
    int size;
    vector<vector<int>> sparse;

public:
    sparseTable(int n)
    {
        this->n = n;
        this->size = log2(n) + 1;

        sparse.resize(n);
        for (int i = 0; i < n; i++)
            sparse[i] = vector<int>(size);
    }

    void build(vector<int> &arr)
    {
        for (int j = 0; j < size; j++)
        {
            for (int i = 0; (i + (1 << j) - 1) < n; i++)
            {
                if (j == 0)
                    sparse[i][j] = arr[i];

                else
                    sparse[i][j] = min(sparse[i][j - 1], sparse[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int getMin(int l, int r)
    {
        int len = log2(r - l + 1);
        return min(sparse[l][len], sparse[r - (1 << len) + 1][len]);
    }
};

int main()
{

    int n = 10;
    vector<int> arr = {4, 7, 1, 9, 2, 12, 8, 3, 24, 5};

    sparseTable st(n);
    st.build(arr);

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << st.getMin(l, r) << "\n";
    }

    return 0;
}