

1.string 转 int：int a = stoi(b);
2.int 转 string: string a = to_string(b);
3.string 转 char[]:

 string pp = "dagah";
 char p[8];
 int i;
 for( i=0;i<pp.length();i++)
	 p[i] = pp[i];
 p[i] = '\0';

 4.char[]转string
　　这里可以直接赋值。
 
 
 


1.输入：int 矩阵
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main()
{

    int n, m;
	int x; 
	
    vector<int> vec;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
			scanf_s("%d", &x);
            vec.push_back(x);
        }
    }
    for (int i = 0; i < n * m; i++)
        cout << vec[i] << endl;
    system("pause");

    return 0;
}


2.输入：
n
a[0],a[1]...a[n]
b[0],b[1]...b[n]

int main() 
{
    int n;
    vector<int> tmp;
    vector<vector<int>> vec;
    cin >> n;
    for (int i = 0; i < 2; i++) 
    {
        for (int j = 0; j < n; j++)
        {
            int x; scanf("%d", &x);
            int x; scanf_s("%d", &x);

            tmp.push_back(x);
        }
        vec.push_back(tmp);
        tmp.clear();
    }


    for (int i = 0; i < vec[0].size();i++)
        cout << vec[0][i];
    cout << endl;
    for (int j = 0; j < vec[1].size(); j++)
        cout << vec[1][j];
    system("pause");
    return 0;
}



3.输入：一行连续的字符串
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>
using namespace std;
int main()
{
    char s[1000];

    //gets_s(s);
	gets(s);
    int L = strlen(s);
    for (int i = 0; i < L; i++)
        cout << s[i];

    system("pause");
    return 0;
}



4.输入：一行字符串，多个单词，使用空格分开
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string str[200];
string res[200];
char s[200];
int n;
int cnt;

int main()
{
    cin >> n;
    gets_s(s);
    //gets(s);

    int L = strlen(s);

    for (int j = 0; j < L; j++)
    {
        if (s[j] == ' ' || s[j] == '\0')
            continue;
        cnt++;
        str[cnt] = s[j];
        while (j + 1 < L && s[j + 1] != ' ' && s[j + 1] != '\0')
        {
            j++;
            str[cnt] = str[cnt] + s[j];
        }
    }
    for (int j = 0; j <= cnt; j++)
        cout << str[j];

    system("pause");
    return 0;
}





5.输入：n行，每行多个单词

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string str[200][200]; // 存放输入的数据
string res[200];
char s[200];
int n;
int cnt[200];

int main()
{
    cin >> n;

    for (int i = 0; i <= n; i++)
    {
        gets_s(s);
        //gets(s);
        int L = strlen(s);
        for (int j = 0; j < L; j++)
        {
            if (s[j] == ' ' || s[j] == '\0')
                continue;
            cnt[i]++;
            str[i][cnt[i]] = s[j];
            while (j + 1 < L && s[j + 1] != ' ' && s[j + 1] != '\0')
            {
                j++;
                str[i][cnt[i]] += s[j];
            }
        }

    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= cnt[i]; j++)
            cout << str[i][j] << " ";
        cout << endl;
    }

    system("pause");
    return 0;
}




6.输入：多行字符串（事先不知道几行）

#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <cstring>

using namespace std;


int main(string s)
{
    char c[100][1000];
    int flag = 0;
    int len[1000];

    while (1)
    {
        //memset(c, '\0', sizeof(c));
        //gets(c[flag]);
        gets_s(c[flag]);
        len[flag] = strlen(c[flag]);

        if (len[flag] == 0)
            break;
        flag++;

    }
    for (int i = 0; i < flag; i++)
    {
        for (int j = 0; j < len[i]; j++)
            cout << c[i][j] << endl;
    }
	system("pause");
    return 0;
}
















