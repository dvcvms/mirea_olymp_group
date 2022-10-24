// taskC


#include <iostream>
#include <vector>

using namespace std;


int main() {

    int n, k; cin >> n >> k;

    string str; cin >> str;

    int count = 0;
    bool flag = true;
    for (int i = 0; i < n - 1; i++) {
        flag = true;
        string new_str = "";
        for (int j = 0; j < i+1; j++) {
            new_str = str[str.length()-1-j] + new_str;
        }
        for (int j = 0; j < new_str.length(); j++) {
            if (str[j] != new_str[j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            count = i + 1;
        }
    }

    string obrez = "";
    for (int i = count; i < str.size(); i++) { obrez = obrez + str[i]; }

    string all = str;
    for (int i = 1; i < k; i++) { all = all + (obrez == "" ? str : obrez); }
    
    int result = n * k - ((k - 1) * (count));

    cout << all;

    return 0;
}