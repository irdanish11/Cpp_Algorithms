#include <iostream>
#include <stack>
using namespace std;


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

string reverse_prefix_str(string result){
    string infix;
    for (int i=result.length(); i>=0; i--){
        if(result[i]==')')
            infix += '(';
        else if(result[i]=='(')
            infix += ')';
        else{
            infix += result[i];
        }
    }
    return infix;
}

string prefix2infix(string exp){
    stack<char> stck;
    int len = exp.length();
    string result;
    for(int i=len-1; i>=0; --i){
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
    return reverse_prefix_str(result);
}

int main(){
    string exp = "+-*^ABCD//EF+GH";
    cout<<"Infix of given Prefix: "<<prefix2infix(exp)<<endl;
}