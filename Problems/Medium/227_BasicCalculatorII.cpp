/*
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, 
+, -, *, / operators and empty spaces . The integer division should 
truncate toward zero.

Example 1:

Input: "3+2*2"
Output: 7
Example 2:

Input: " 3/2 "
Output: 1
Example 3:

Input: " 3+5 / 2 "
Output: 5
*/

//solution
class Solution {
    stack<char> op;
    stack<int> num;
public:
    int calculate(string s) {
        string temp;
        for(int i = 0; s[i] != '\0'; i++){
            if(s[i]!=' ')
                temp+=s[i];
        }
        s = move(temp);
        temp.clear();
        int val = 0;
        char pop = '$';
        for(int i = 0; s[i] != '\0'; i++){
            if(s[i]>='0'&&s[i]<='9'){
                temp+=s[i];
            }else{
                val = 0;
                if(temp.length() > 0)
                    val = atoi(temp.c_str());
                num.push(val);
                if(pop=='*'){
                    int b = num.top();num.pop();
                    int a = num.top();num.pop();
                    op.pop();
                    num.push(a*b);
                }else if(pop=='/'){
                    int b = num.top();num.pop();
                    int a = num.top();num.pop();
                    op.pop();
                    num.push(a/b);
                }
                op.push(s[i]);
                pop = s[i];
                temp.clear();
            }
        }

        val = 0;
        if(temp.length() > 0)
            val = atoi(temp.c_str());
        num.push(val);
        if(pop=='*'){
            int b = num.top();num.pop();
            int a = num.top();num.pop();
            op.pop();
            num.push(a*b);
        }else if(pop=='/'){
            int b = num.top();num.pop();
            int a = num.top();num.pop();
            op.pop();
            num.push(a/b);                    
        }
        temp.clear();
        
        stack<char> nop;
        while(!op.empty()){
            nop.push(op.top());
            cout<<op.top()<<" ";op.pop();
        }
        stack<int> nnum;
        while(!num.empty()){
            nnum.push(num.top());
            cout<<num.top()<<" ";num.pop();
        }
        
        cout<<endl;
        int res = 0;
        char pchar = '+';
        while(!nnum.empty()){
            int val = nnum.top();nnum.pop();
            cout<<res<<" "<<pchar<<" "<<val;
            switch(pchar){
                case '+': res += val;break;
                case '-': res -= val;break;
            }
            if(nop.empty())break;
            pchar = nop.top();nop.pop();
        }
        
        return res;
    }
};


/*

123*123+2343/123+1231

*/