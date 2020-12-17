#include<iostream>
using namespace std;

void arrow(int n, int i, int j){    
    if(n<1){
        //--cout<<"value of i"<<i<<endl;
        return ;   
    }

    if(i<=n){
        cout<<"*";
        arrow(n, i+1, j);
    }
    else{
        cout<<"\t"<<i;
        cout<<endl;
        arrow(n-1, 1, j);
    }
}

int main(){
    cout<<"Arrow:\n "<<endl;
    arrow(5, 1, 5);
    cout<<"\n";
    return 0;
}