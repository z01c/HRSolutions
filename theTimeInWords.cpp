#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    int hour, mins, flag = 0;
    map<int, string> Time;  
    Time[1] = "one";
    Time[2] = "two";
    Time[3] = "three";
    Time[4] = "four";
    Time[5] = "five";
    Time[6] = "six";
    Time[7] = "seven";
    Time[8] = "eight";
    Time[9] = "nine";
    Time[10] = "ten";
    Time[11] = "eleven";
    Time[12] = "twelve";
    Time[13] = "thirteen";
    Time[14] = "fourteen";
    Time[15] = "fifteen";
    Time[16] = "sixteen";
    Time[17] = "seventeen";
    Time[18] = "eighteen";
    Time[19] = "nineteen";
    Time[20] = "twenty";
    Time[21] = "twenty one";
    Time[22] = "twenty two";
    Time[23] = "twenty three";
    Time[24] = "twenty four";
    Time[25] = "twenty five";
    Time[26] = "twenty six";
    Time[27] = "twenty seven";
    Time[28] = "twenty eight";
    Time[29] = "twenty nine";
    cin >> hour;
    cin >> mins;
    if (mins > 30) {
        mins = 60 - mins;
        flag = 1;
    }
    if (mins == 0) {
        cout << Time[hour] << " o' clock";
    }
    else if (mins == 15) {
        if (flag)
            cout << "quarter to " << Time[hour+1];
        else
            cout << "quarter past " << Time[hour];
    }
    else if (mins == 30) {
        cout << "half past " << Time[hour];
    }
    else {
        if (flag)
            cout << Time[mins] << " minutes to " << Time[hour+1];
        else
            cout << Time[mins] << " minutes past " << Time[hour];
    }
    return 0;
}
