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

void rohmbus(int n, int i, int j){    
    if(n<1){
        return ;   
    }

    if(i==j){
        print_inc_space(n, 1);
    }

    if(i>=1){
        cout<<"* ";
        rohmbus(n, i-1, j);
    }
    else{
        
        //cout<<"\t"<<i;
        cout<<endl;
        rohmbus(n-1, j, j);
    }
}

int main(){
    cout<<"Rhombus:\n "<<endl;
    int n = 10;
    rohmbus(n, n, n);
    cout<<"\n";
    return 0;
}