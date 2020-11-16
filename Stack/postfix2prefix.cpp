#include <iostream>
#include <stack>
using namespace std;

bool find_char(char chr, string s){
    int len = s.length();
    for(int i=0; i<=len; i++){
        if(chr==s[i]){
            return true;
        }
    }
    return false;
} 

int get_precedence(char chr){
    if(chr=='^')
        return 3;
    else if(chr=='/' || chr=='*')
        return 2;
    else if(chr=='+' || chr=='-')
        return 1; 
    else
        return 0; 
}

string infix2prefix(string exp){
    string operators = "^/*+-";
    int len = exp.length();
    string prefix;
    stack<char> stck;
    
    for(int i=len; i>=0; --i){
        char chr = exp[i];
        //cout<<chr;
        bool op_cond = find_char(chr, operators);
        //condtion 2
        if((chr >= 'a' && chr <= 'z') || (chr>='A' && chr<='Z' || chr>='0'&&chr<='9')){
            prefix = chr+prefix;
        }
        //condtion 3
        else if(chr==')'){
            stck.push(chr);
        }
        //condtion 4
        else if(op_cond){
            if(stck.empty()|| stck.top()==')'){
                stck.push(chr);
            }
            else if(get_precedence(chr)>get_precedence(stck.top())){
                stck.push(chr);
            }
            else{
                while(!stck.empty() && (get_precedence(stck.top()) >=
                                            get_precedence(chr))){
                    char c = stck.top();
                    stck.pop();
                    prefix = c + prefix;
                }
                stck.push(chr);
            } 
        }
        //condtion 5
        else if(chr=='('){
            while(!stck.empty() && stck.top()!=')'){
                char c = stck.top();
                stck.pop();
                prefix = c+prefix;
            }
            if(stck.top()==')'){
                stck.pop();
            }
        }
    }
    //condtion 6
    while(!stck.empty()){
        prefix = stck.top()+prefix;
        stck.pop();  
    }
    return prefix;
}

stack<char> push_ops(stack<char> stck, string oprnds[], char chr){
    //push functionality
    int len1 = oprnds[0].length();
    int len2 = oprnds[1].length();
    stck.push('(');
    for(int j=0; j<len2; j++){
        stck.push(oprnds[1][j]);
    }
    stck.push(chr);
    for(int j=0; j<len1; j++){
        stck.push(oprnds[0][j]);
    }
    stck.push(')');  
    return stck;
}

string postfix2infix(string exp){
    stack<char> stck;
    int len = exp.length();
    string result;
    for(int i=0; i<len; i++){
       char chr = exp[i];
        if(chr>='a'&&chr<='z' || chr>='A'&&chr<='Z' || chr>='0'&&chr<='9'){
            stck.push(chr);
        }
        else{
            //pop functionality
            int j=0; 
            string oprnds[2];
            while(j<2){
                if(stck.top()==')'){
                    int cnt_close=0; int cnt_open=0;
                    //cout<<stck.top();
                    while (stck.top()==')'){
                        //cout<<stck.top();
                        oprnds[j] = stck.top() + oprnds[j];
                        stck.pop();
                        cnt_close++;
                        
                    }
                    while (cnt_open!=cnt_close){
                        //cout<<stck.top();
                        oprnds[j] = stck.top() + oprnds[j];
                        
                        if(stck.top()=='(')
                            cnt_open++;
                        if(stck.top()==')')
                            cnt_close++;
                        stck.pop();
                    }
                    j++;
                }
                //If the operand starts with bracket
                else{
                    oprnds[j] = stck.top() + oprnds[j];
                    stck.pop();
                    j++;
                }
            }
            stck = push_ops(stck, oprnds, chr);
        }
    }
    while(!stck.empty()){
        char c = stck.top();
        //cout<<c;
        result = c + result;
        stck.pop();
    }
    return result;
}

string postfix2prefix(string exp){
    return infix2prefix(postfix2infix(exp));
}

int main(){
    string exp = "ABC/-AL/L-*";
    cout<<"Prefix of given Postfix: "<<postfix2prefix(exp);
}