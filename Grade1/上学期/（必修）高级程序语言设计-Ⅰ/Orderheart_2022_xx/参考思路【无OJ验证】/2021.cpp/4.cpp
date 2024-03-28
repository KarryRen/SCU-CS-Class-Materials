//唯神另解
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	char a[10][7][6]={
	"*****","*   *","*   *","*   *","*   *","*   *","*****",    //数字0的7层
    "    *","    *","    *","    *","    *","    *","    *",    //数字1的7层
    "*****","    *","    *","*****","*    ","*    ","*****",    //数字2的7层
    "*****","    *","    *","*****","    *","    *","*****",    //数字3的7层
	"*   *","*   *","*   *","*****","    *","    *","    *",    //数字4的7层
	"*****","*    ","*    ","*****","    *","    *","*****",    //数字5的7层
	"*****","*    ","*    ","*****","*   *","*   *","*****",    //数字6的7层
	"*****","    *","    *","    *","    *","    *","    *",    //数字7的7层
	"*****","*   *","*   *","*****","*   *","*   *","*****",    //数字8的7层
	"*****","*   *","*   *","*****","    *","    *","*****"};   //数字9的7层
	int k;cin>>k;
	while(k--)
	{
		char x[5];scanf(" %s",x);cout<<x<<":"<<endl;
		for(int i=0;i<7;i++)//循环每一层
        {
			for(int j=0;x[j]!='\0';j++)//每次遍历 strlen(x)次,一层一层的打印
            {
				int p=x[j]-'0';
				cout<<a[p][i]<<"  ";
			}
			cout<<endl;
		}
	}
}







#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>

using namespace std;
char map[7][70] = {
        " *****      *  *****  *****  *   *  *****  *****  *****  *****  *****",
        " *   *      *      *      *  *   *  *      *          *  *   *  *   *",
        " *   *      *      *      *  *   *  *      *          *  *   *  *   *",
        " *   *      *  *****  *****  *****  *****  *****      *  *****  *****",
        " *   *      *  *          *      *      *  *   *      *  *   *      *",
        " *   *      *  *          *      *      *  *   *      *  *   *      *",
        " *****      *  *****  *****      *  *****  *****      *  *****  *****"};

int main() {
    int q;
    cin >> q;
    for (int z = 1; z <= q; z++) {
        int nx=0, ny=0, sum = 1;
        int num, a[100],step,now=0;
        char ans[7][10000];

        cin >> num;
        while (num / 10 != 0) {
            a[sum++] = num % 10;
            num /= 10;
        }
        a[sum] = num;
        for (int k = sum; k >= 1; k--)
        {
        	if(a[k]==0)
			step=1; 
			else
			step=7*a[k]+1;
			
			    for (int i = 0,nx=0; i <= 6; i++, nx++)
                for (int j = step,ny=now;j <= step+6; j++, ny++)
                    ans[nx][ny] = map[i][j];
            
			now+=7;
		}
		
        for (int i = 0; i <= 6; i++) {
            for (int j = 0; j <= 7 * sum - 3; j++)
                cout << ans[i][j];
            cout << endl;
        }
        cout<<endl;

    }
    return 0;
}
