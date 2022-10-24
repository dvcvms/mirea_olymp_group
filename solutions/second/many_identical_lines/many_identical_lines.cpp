// taskC


#include <iostream>
#include <vector>

using namespace std;


int main() {

    int n, k; cin >> n >> k;

    string str; cin >> str;

    int count = 0;
    for (int i = 1; i < n; i++) {

        bool flag = true;
        for (int j = 0; j < n; j++) {

            if (i + j >= n) 
                break;
            
            if (str[j] != str[j + i]) {
                flag = false;
                break;
            }

        }

        if (flag) {
            count = n - i;
            break;
        }
    }

    string slice = "";
    for (int i = count; i < str.size(); i++) { slice = slice + str[i]; }

    string result = str;
    for (int i = 1; i < k; i++) { result = result + slice; }
    
    cout << result;

    return 0;
}