
// Print "YES" (without the quotes), if string s contains two non-overlapping substrings "AB" and "BA", and "NO" otherwise.
// overlapping: No
// not overlapping: Yes

#include<bits/stdc++.h>
using namespace std;

main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s;
    bool f1=f2=0;

    cin >> s;
    // f1 = f2 = 0;
    for(int i(0); i < s.size() - 1; ++i)
        if(!f1)
        {
            if(s[i] == 'A' && s[i + 1] == 'B')
            f1 = 1,
            ++i;
        }
        else if(s[i] == 'B' && s[i + 1] == 'A')
            f2 = 1;

        if(f1 && f2)
        {
            cout << "YES";
            return 0;
        }

    f1 = f2 = 0;
    for(int i(0); i < s.size() - 1; ++i)
        if(!f1)
        {
            if(s[i] == 'B' && s[i + 1] == 'A')
            f1 = 1,
            ++i;
        }
        else if(s[i] == 'A' && s[i + 1] == 'B')
            f2 = 1;

        if(f1 && f2)
        {
            cout << "YES";
            return 0;
        }
    cout << "NO";

    return 0;
}
