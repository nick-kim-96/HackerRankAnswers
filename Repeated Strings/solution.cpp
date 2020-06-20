#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    double remainder = n % s.length();
    double division = n / s.length();

    int count = 0;
    int remainderCount = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == 'a')
        {
            count++;
        }
        if(i < remainder && s[i] == 'a')
        {
            remainderCount++;
        }
    }
    return (division * count) + remainderCount;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
