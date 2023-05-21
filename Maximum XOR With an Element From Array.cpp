#include <bits/stdc++.h>
struct Node
{
    Node *links[2];
    bool containsKey(int bit)
    {
        return links[bit] != NULL;
    }
    void put(int bit, Node *node)
    {
        links[bit] = node;
    }
    Node *get(int bit)
    {
        return links[bit];
    }
};

class Trie
{

private:
    Node *root;

public:
    Trie()
    {

        root = new Node();
    }

    void insert(int num)
    {

        Node *node = root;

        for (int i = 30; i >= 0; i--)
        {

            int bit = (num >> i) & 1;

            if (!node->containsKey(bit))
            {

                node->put(bit, new Node());
            }

            node = node->get(bit);
        }
    }

    int max_XOR(int num)
    {

        Node *node = root;

        int ans = 0;

        for (int i = 30; i >= 0; i--)
        {

            int bit = (num >> i) & 1;

            if (node->containsKey(!bit))
            {

                ans = ans ^ (1 << i);

                node = node->get(!bit);
            }
            else
            {

                node = node->get(bit);
            }
        }
        return ans;
    }
};
static bool cmp(vector<int> a, vector<int> b)
{
    return a[1] < b[1];
}

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries)
{
    int n = queries.size(), m = arr.size(), j = 0;
    Trie node;
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++)
    {
        queries[i].push_back(i);
    }
    sort(arr.begin(), arr.end());
    sort(queries.begin(), queries.end(), cmp);
    for (int i = 0; i < n; i++)
    {
        while (j < m && arr[j] <= queries[i][1])
        {
            node.insert(arr[j++]);
        }
        if (j > 0)
            ans[queries[i][2]] = node.max_XOR(queries[i][0]);
    }
    return ans;
}