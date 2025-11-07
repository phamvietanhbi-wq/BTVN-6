#include <iostream>
using namespace std;    
int n, a[1000000];
void intungdong(const int a[], int l, int r) {
    for (int i = l; i <= r; i++) {
        cout << a[i];
        if (i < r) cout << " ";
    }
    cout << "\n";
}

void sapxepnhanh(int a[], int l, int r) 
{
    int i = l, j = r;
    int m;
    int p = a[(l + r) / 2];
    while (i <= j) {
        while (a[i] < p) i++;
        while (a[j] > p) j--;
        if (i <= j) 
        {
            m = a[i];
            a[i] = a[j];
            a[j] = m;
            i++;
            j--;
        }
    }
    if (l < j)
        sapxepnhanh(a, l, j);
    if (i < r){
        sapxepnhanh(a, i, r);
    }    
    intungdong(a, l, r);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sapxepnhanh(a, 0, n - 1);
    return 0;
}