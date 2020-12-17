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

void cross_up(int n, int i, int j){    
    if(n<1){
        //--cout<<"value of i"<<i<<endl;
        return ;   
    }
    if(i==1){
        print_inc_space(j-n, 1);
        cout<<"*";
        print_inc_space(n, 1);
    }

    if(i<=n){
        cout<<" ";
        cross_up(n, i+1, j);
    }
    else{
        cout<<"*";
        //cout<<"\t"<<i;
        cout<<endl;
        cross_up(n-1, 1, j);
    }
}

void cross_dwn(int n, int i, int j){    
    if(n<1){
        //--cout<<"value of i"<<i<<endl;
        return ;   
    }
    if(i==1){
        print_inc_space(n, 1);
        //print_inc_space(j-n, 1);
        cout<<"*";
        print_inc_space(j-n, 1);
        
    }

    if(i<=j-n+1){
        cout<<" ";
        cross_dwn(n, i+1, j);
    }
    else{
        cout<<"*";
        //cout<<"\t"<<i;
        cout<<endl;
        cross_dwn(n-1, 1, j);
    }
}

void cross(int n){
    cross_up(n, 1, n);
    print_inc_space(n+1, 1);
    cout<<"*\n";
    cross_dwn(n, 1, n);
}

int main(){
    cout<<"Cross:\n "<<endl;
    cross(50);
    cout<<"\n";
    return 0;
}