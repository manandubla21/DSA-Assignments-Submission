#include <iostream>
#include <string.h>
using namespace std;

string concatenate(string str1,string str2) {
    string str3;
    for(int i=0;i<str1.size();i++) str3.push_back(str1[i]);
    for(int i=0;i<str2.size();i++) str3.push_back(str2[i]);

    return str3;
}

string reverse(string str1) {
    int start = 0;
    int end = str1.size()-1;

    while(start < end) {
        swap(str1[start++],str1[end--]);
    }
    return str1;
}

string removeVowels(string str) {
    for(int i=0;i<str.size();i++) {
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') str.erase(str.begin()+i);
    }

    return str;
}

string stringSort(string str) {
    for(int i=str.size()-1;i>=0;i--) {
        for(int j=0;j<i;j++) {
            if(str[j] > str[j+1]) swap(str[j],str[j+1]);
        }
    }
    return str;
}

char UpperToLower(char str) {
    if(str >= 65 && str <= 96) {
        int idx = str;
        char final = idx + 32;
        return final; 
    }
    return '*';
}

int main() {
    string str1 = "Hello";
    string str2 = "World";

    cout << concatenate(str1,str2) << endl;

    string rev = "reverse";
    cout << reverse(rev) << endl;

    cout << removeVowels(str1)<<endl;

    string str3 = "Alphabet";
    cout << stringSort(str3) << endl;

    cout << UpperToLower('T') << endl;

    return 0;
}