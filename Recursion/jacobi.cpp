#include <iostream>

using namespace std;

/* Precondition: a, n >= 0; n is odd */
int jacobi(int a, int n) {
    int ans;

    if (a == 0)
        ans = (n == 1) ? 1 : 0;
    else if (a == 2) {
        switch ( n % 8 ) {
            case 1:
            case 7:
                    ans = 1;
                    break;
            case 3:
            case 5:
                    ans = -1;
                    break;
        }
    }
    else if ( a >= n )
        ans = jacobi(a%n, n);
    else if ( a % 2 == 0 )
        ans = jacobi(2,n)*jacobi(a/2, n);
    else
        ans = ( a % 4 == 3 && n % 4 == 3 ) ? -jacobi(n,a) : jacobi(n,a);
    return ans;
}

int main()
{
    int a, n;

    cout << "\na? ";
    cin >> a;
    cout << "\nn? ";
    cin >> n;

    cout << "\nThe Jacobi symbol is " << jacobi(a,n) << endl;

    return 0;
}