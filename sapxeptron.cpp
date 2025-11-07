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
void sapxeptron(int a[], int l, int r) 
{
    if (l >= r) return;
    int m = (l + r) / 2;
    sapxeptron(a, l, m);
    sapxeptron(a, m + 1, r);
    int i = l, j = m + 1, k = 0;
    int t[r - l + 1];
    while (i <= m && j <= r) 
    {
        if (a[i] <= a[j]) 
        {
            t[k++] = a[i++];
        } 
        else t[k++] = a[j++];
    }
    while (i <= m) {
        t[k++] = a[i++];
    }
    while (j <= r) {
        t[k++] = a[j++];
    }
    for (i = l, k = 0; i <= r; i++, k++) {
        a[i] = t[k];
    }
    intungdong(a, l, r);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sapxeptron(a, 0, n - 1);
    return 0;
}