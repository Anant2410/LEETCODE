//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
struct Node{
    Node* link[26];
    bool flag = false;

    bool containskey(char ch)
    {
        return link[ch-'a'] != nullptr;
    }

    void put(char ch, Node* node)
    {
        link[ch-'a'] = node;
    }
    Node* get(char ch)
    {
        return link[ch-'a'];
    }
    void set()
    {
        flag = true;
    }
    bool end()
    {
        return flag;
    }
};

class Trie{
    private: Node* root;

    public:

    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node* node = root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->containskey(word[i]))
            {
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
        }
        node->set();
    }
    bool checkprefix(string word)
    {
        Node* node = root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->containskey(word[i]))
            {
                return false;
            }
            else
            {
                node = node->get(word[i]);
                if(node->end() == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};

class Solution
{
public:
    string longestString(vector<string> &a)
    {
        Trie trie;
        for(auto it: a)
        {
            trie.insert(it);
        }
        string ans= "";
    
        for(auto& it: a)
        {
            if(trie.checkprefix(it))
            {
                if(it.size() > ans.size())
                {
                    ans = it;
                }
                else if(it.size() == ans.size() && it < ans)
                {
                    ans = it;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends