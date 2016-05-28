#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;
ofstream fout ("parking.in");

int main () {
    srand((unsigned)time(NULL));                                                                                                                        
    int n = rand() % 10 + 1;
    fout << n << "\n";
    for (int i = 1; i <= n; i++) {
        fout << rand() % n + 1 << ' ';
    }
    return 0;
}
