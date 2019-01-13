#include <bits/stdc++.h>
using namespace std;
#define SIZE 10
int main()
{
    int *p = NULL;
    p = new int[SIZE];
    p[9] = 120;
    cout << p[SIZE - 1] << endl;
    return 0;
}