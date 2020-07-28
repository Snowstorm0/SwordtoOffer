


// input int
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main()
{

    int n, m;
    vector<int> vec;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x; scanf_s("%d", &x);
            vec.push_back(x);
        }
    }
    for (int i = 0; i < n * m; i++)
        cout << vec[i] << endl;
    system("pause");

    return 0;
}




// input string
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string line, word;
    vector<string> vec;
    getline(cin, line);
    stringstream linestream;
    linestream.str(line);
    while (linestream >> word)
        vec.push_back(word);
    for (int i = 0; i<vec.size(); i++)
        cout << vec[i] << endl;
    system("pause");


    return 0;
}












