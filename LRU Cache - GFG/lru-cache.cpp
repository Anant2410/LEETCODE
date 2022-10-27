//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
    private:

    public:
    //Constructor for initializing the cache capacity with the given value.
    class node{
        public:
            int key,value;
            node* next;
            node* prev;
            
            node(int key1, int value1)
            {
                key = key1;
                value = value1;
            }
    };
    int capacity;
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    unordered_map<int,node*>mp;
    LRUCache(int cap)
    {
        capacity = cap;
        head->next = tail;
        tail->prev = head;
    }
    
    //Function to return value corresponding to the key.
    void addnode(node* curr)
    {
        node* temp = head->next;
        curr->next = temp;
        curr->prev = head;
        head->next = curr;
        temp->prev = curr;
    }
    void deletenode(node* curr)
    {
        node* dp = curr->prev;
        node* dn = curr->next;
        dp->next = dn;
        dn->prev = dp;
    }
    int get(int key1)
    {
        if(mp.find(key1)!= mp.end())
        {
            node* curr = mp[key1];
            int res = curr->value;
            mp.erase(key1);
            deletenode(curr);
            addnode(curr);
            mp[key1] = head->next;
            return res;
        }
        return -1;
    }
    
    //Function for storing key-value pair.
    void set(int key1, int value)
    {
        if(mp.find(key1) != mp.end())
        {
            node* curr = mp[key1];
            mp.erase(key1);
            deletenode(curr);
        }
        if(capacity == mp.size())
        {
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        
        addnode(new node(key1,value));
        mp[key1] = head->next;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends