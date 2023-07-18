//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int minEle;
    stack<int> s;
    public:
    
       int getMin(){
           if(s.empty()) return -1;
           return minEle;
       }
       
       int pop(){
            //if empty 
            if(s.empty()) return -1;
            //if not empty then two cases
            else{
                if(s.top() >= minEle){
                    int temp = s.top();
                    s.pop();
                    return temp;
                }
                else if(s.top() < minEle){
                    //means jo stack ke top pe hai vo ek flag value  hai aur asliyat mai minEle return kario
                    //but ab minEle change bhi ho jeyag so pehle store karao kahein taki return kar sake artend 
                    int toReturn = minEle;
                    minEle= 2*minEle - s.top();
                    s.pop();
                    return toReturn;
                }
            }
          
       }
       
       void push(int x){
            //2 cases here also
            if(s.empty()){
                s.push(x);
                minEle =x;
            }
            else{
                //what to push depend on x 2 cases
                if(x >=minEle) s.push(x);
                else{
                    s.push(2*x -minEle);
                    minEle =x;
                }
            }
       }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends