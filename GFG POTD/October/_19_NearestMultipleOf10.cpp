// A string str is given to represent a positive number. The task is to round str to the nearest multiple of 10.  If you have two multiples equally apart from str, choose the smallest element among them.





#include <iostream>
using namespace std;

class Solution {
  public:
    string roundToNearest(string str) {
        int n = str.size();
        if (n == 0) return str;  

        if (str[n - 1] - '0' <= 5) {
            str[n - 1] = '0';  
            return str;  
        } 
        else {

            str[n - 1] = '0';  
            int i = n - 2;

            while (i >= 0) {
                if (str[i] != '9') {
                    str[i] = (char)((str[i] - '0') + 1 + '0');  
                    return str;
                }

                str[i] = '0';
                i--;
            }

            return "1" + str;
        }
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}