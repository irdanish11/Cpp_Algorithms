#include <iostream>
#include <cstring>
#include <stack>
using namespace std; 

bool is_char(char chr, string s){
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

string infix2postfix(string exp){
    string operators = "^/*+-";
    int len = exp.length();
    string postfix;
    stack<char> stck;
    
    for(int i=0; i<len; i++){
        
        char chr = exp[i];
        
        bool op_cond = is_char(chr, operators);
        //condtion 2
        if((chr >= 'a' && chr <= 'z') || (chr>='A' && chr<='Z' || chr>='0'&&chr<='9')){
            //cout<<chr;
            postfix += chr;
        }
        //condtion 3
        else if(chr=='('){
            //cout<<chr;
            stck.push(chr);
        }
        //condtion 4
        else if(op_cond){
            //cout<<chr;
            if(stck.empty()|| stck.top()=='('){
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
                    postfix += c;
                }
                stck.push(chr);
            } 
        }
        //condtion 5
        else if(chr==')'){
            //cout<<chr;
            while(!stck.empty() && stck.top()!='('){
                char c = stck.top();
                stck.pop();
                postfix += c;
            }
            if(stck.top()=='('){
                stck.pop();
            }
        }
    }
    //condtion 6
    while(!stck.empty()){
        postfix += stck.top();
        stck.pop();
    }
    return postfix;
}
  
int main(){
    string exp = "(A+B)*(C^D-E)^(F+G*H)-I";
    string postfix = infix2postfix(exp);
    cout<<"The postfix for given experssion: "<<postfix;
}