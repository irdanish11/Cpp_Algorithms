#include<iostream>
using namespace std;

void print_inc_space(int n, int i){
    if (i <= n){ 
        cout << " "; 
        // recursively print rest of the spaces 
        // of the row 
        print_inc_space(n, i + 1); 
    }     
    else {
        return ;
    }
}

void arrow_up(int n, int i, int j){    
    if(n<1){
        //--cout<<"value of i"<<i<<endl;
        return ;   
    }

    if(i==j){
        print_inc_space(j-n, 1);
    }

    if(i>=n){
        cout<<"*";
        arrow_up(n, i-1, j);
    }
    else{
        cout<<endl;
        arrow_up(n-1, j, j);
    }
}

void arrow_dwn(int n, int i, int j){    
    if(n<1){
        return ;   
    }
    if(i==1){
        print_inc_space(n-1, 1);
    }

    if(i<=n){
        cout<<"*";
        arrow_dwn(n, i+1, j);
    }
    else{
        cout<<endl;
        arrow_dwn(n-1, 1, j);
    }
}

void arrow(int n){
    arrow_up(n, n, n);
    arrow_dwn(n-1, 1, n-1);
}

int main(){
    cout<<"Arrow:\n "<<endl;
    arrow(7);
    cout<<"\n";
    return 0;
}