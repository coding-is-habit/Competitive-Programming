#include<bits/stdc++.h>
using namespace std;
char x;
int parseInt(char *a){
    int s = 0;
    for(int i = 0; a[i] != '\0'; ++i)s = s*10 + a[i] - '0';
    return s;
}
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int getRandom(int l, int r){
    uniform_int_distribution<int> uid(l,r);
    return uid(rng);
}

string randomString(int len){
    string s = "";
    while(len--){
        int op = getRandom(1,4);
        if(op == 1)s+=x;
        else s+=char(getRandom('a','z'));
    }
    return s;
}

int main(int argc, char **argv){
    freopen("input.txt","w",stdout);
    int test = getRandom(1,100);
    int n_low = parseInt(argv[1]);
    int n_high = parseInt(argv[2]);
    int n = getRandom(n_low,n_high);
    if(n < 10){
        test = getRandom(1,3);
    }
    cout << test << "\n";
    while(test--){
        int n = getRandom(n_low,n_high);
        x = char(getRandom('a','z'));
        cout << randomString(n) << " " << x;
        if(test)cout << "\n";
    }
    return 0;
}