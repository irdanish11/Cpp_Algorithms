#include <iostream>
#include <cstring>
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
  
int main(){
    string exp = "((A+B)*C-(D-E))*(F+G)";
    string prefix = infix2prefix(exp);
    cout<<"The prefix for given experssion: "<<prefix;
}