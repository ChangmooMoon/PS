#include <iostream>
#include <sstream>
using namespace std;

int main() {
    stringstream ss;

    int i = 12;
    double d = 34.56;
    ss << i << ' ' << d << ' ';  // 공백 꼭 주기
    string str1, str2;
    ss >> str1 >> str2;
    cout << str1 << ' ' << str2 << endl;

    int b = 1, c = 999;
    ss << b << ' ' << c << endl;

    string str3 = ss.str();
    cout << str3 << endl;

    string string1 = "25 1 3 .235\n1111\n2222";
    ss.str(string1);

    float num;
    while (ss >> num)
        cout << "num: " << num << endl;

    return 0;
}