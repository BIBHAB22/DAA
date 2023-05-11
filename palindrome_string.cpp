#include<bits/stdc++.h>
using namespace std;

class Solution{   
public: 
	int addMinChar(string str){    
        int i = 0, j = str.size() - 1, count = 0;
        while(i <= j) {
            if(str[i] != str[j]) {
                count++;
                i = 0; // add characters to front
                j = str.size() - 1 - count;
            } else i++, j--;
        }
        return count;
    }
};

// Driver code
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.addMinChar(str) << endl;
	}
	return 0;
}
