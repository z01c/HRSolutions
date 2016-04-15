#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

int min(int a, int b) {
    return a < b? a: b;
}

int main() {
    int n, count; 
    cin >> n;
    int *a = new int[n];
    int *b = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    count = 0;
    multiset<int> myset;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i] == b[j]) {
                if (!myset.empty()) {
                    if (myset.find(a[i]) == myset.end()) {
                        myset.insert(a[i]);
                    }
                } else {
                    myset.insert(a[i]);
                }
            }
        }
    }
    
    int rem_from_a = 0;
    int rem_from_b = 0;
    map<int,int> freq_a;
    map<int,int> freq_b;
    for (int i = 0; i < n; i++) {
        if (myset.find(a[i]) == myset.end())
            rem_from_a++;
        if (freq_a.empty()) {
            freq_a.emplace(a[i], 1);
        } else {
            if (freq_a.find(a[i]) != freq_a.end())
                freq_a[a[i]]++;
            else
                freq_a.emplace(a[i], 1);
        }
    }
    for (int i = 0; i < n; i++) {
        if (myset.find(b[i]) == myset.end())
            rem_from_b++;
        if (freq_b.empty()) {
            freq_b.emplace(b[i], 1);
        } else {
            if (freq_b.find(b[i]) != freq_b.end())
                freq_b[b[i]]++;
            else
                freq_b.emplace(b[i], 1);
        }
    }
    /*
    for (auto& x: freq_a)
        cout << " [" << x.first << ':' << x.second << ']';
    cout << '\n';
    for (auto& x: freq_b)
        cout << " [" << x.first << ':' << x.second << ']';
    cout << '\n';
    */
    for (auto& x: freq_a) {
        if (freq_b.find(x.first) != freq_b.end()) {
            count = count + min(x.second, freq_b[x.first]);
        }
    }
    if (!rem_from_a && !rem_from_b)
        count--;
    else
        count++;
        
    //cout << rem_from_a << " " << rem_from_b << endl;
    cout << count << endl;
    /*
    while (!myset.empty())
    {
        cout << ' ' << *myset.begin();
        myset.erase(myset.begin());
    }
    cout << '\n';
    */
    delete[] a;
    delete[] b;
    return 0;
}
