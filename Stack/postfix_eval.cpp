#include <iostream>
#include <stack>
using namespace std;



int evaluate(int oprnd1, int oprnd2, char op){
    int value;
    if(op=='^'){
        value = oprnd2^oprnd1;
    }
    else if(op=='/'){
        value = oprnd2/oprnd1;
    }
    else if(op=='*'){
        value = oprnd2*oprnd1;
    }
    else if(op=='+'){
        value = oprnd2+oprnd1;
    }
    else if(op=='-'){
        value = oprnd2-oprnd1;
    }
    return value;
}

int postfix_eval(string exp){
    stack<int> stck;
    int len = exp.length();
    for(int i=0; i<len; i++){
        char chr = exp[i];
        if(chr>='0'&&chr<='9'){
            //converting char into int
            int num = static_cast<int>(chr) - 48;
            stck.push(num);
        }
        else{
            int oprnd1 = stck.top();
            stck.pop();
            int oprnd2 = stck.top();
            stck.pop();
            stck.push(evaluate(oprnd1, oprnd2, chr));
        }
        
    }
    int result = stck.top();
    stck.pop();
    return result;
}

int main(){
    string exp = "23*21-/53*+";
    cout<<"The result of the given Postfix expression is: "<<postfix_eval(exp);
}