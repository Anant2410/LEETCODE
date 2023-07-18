//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends


class twoStacks
{
    int *arr;
    int size;
    int top1, top2;
    public:
    
    twoStacks(int n=100)
    {
        size = n; 
        arr = new int[n]; 
        top1 = -1; 
        top2 = size;
    }
 
    //Function to push an integer into the stack1.
    stack<int>s,ss;
    void push1(int x)
    {
        s.push(x);
    }
    
    //Function to push an integer into the stack2.
    void push2(int x)
    {
       ss.push(x);
    }
    
    //Function to remove an element from top of the stack1.
    int pop1()
    {
        if(s.empty()) return -1;
        
        int x = s.top();
        s.pop();
        return x;
    }
    
    //Function to remove an element from top of the stack2.
    int pop2()
    {
       if(ss.empty()) return -1;
       int x = ss.top();
       ss.pop();
       return x;
    }
};



//{ Driver Code Starts.

int main()
{

    int T;
    cin>>T;
    while(T--)
    {
        twoStacks *sq = new twoStacks();

        int Q;
        cin>>Q;
        while(Q--){
        int stack_no;
        cin>>stack_no;
        int QueryType=0;
        cin>>QueryType;
        
        if(QueryType==1)
        {
            int a;
            cin>>a;
            if(stack_no ==1)
            sq->push1(a);
            else if(stack_no==2)
            sq->push2(a);
        }else if(QueryType==2){
        	if(stack_no==1)
            cout<<sq->pop1()<<" ";
            else if(stack_no==2)
            cout<<sq->pop2()<<" ";

        }
        }
        cout<<endl;
    }
}

// } Driver Code Ends