#include <fstream>
#include <string>
#include <vector>

using namespace std;

ifstream cin("nextpartition.in");
ofstream cout("nextpartition.out");

vector <int> a;
int num;
char c;

int main () {
    while (cin >> num >> c) {
        a.push_back(num);
    }
    cin >> num;
    a.push_back(num);
    if (a.size() == 2) {
        cout << "No solution";
        return 0;    
    }
    int i = a.size() - 1;
    a[i - 1]++;
    a[i]--;
    if (a[i - 1] > a[i]) {
        cout << a[0] << "=";
        for (int j = 1; j < a.size() - 2; j++) {
            cout << a[j] << '+';    
        }
        cout << a[i - 1] + a[i];
        return 0;
    } else {
        int num = a[i];
        cout << a[0] << '=';
        for (int j = 1; j < i; j++) {
            cout << a[j] << "+";
        }
        while (num >= 2 * a[i - 1]) {
            cout << a[i - 1];
            num -= a[i - 1];
            if (num != 0) cout << '+';
        }
        if (num != 0) cout << num;
    }
}
