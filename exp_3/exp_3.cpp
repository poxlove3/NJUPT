#include<iostream>
using namespace std;
int a[100];
int num;
void factor(int n)//显示各因子；
{

    int i,j=0,k,t;
    int judge =0;
    cout<<"能整除的因子有：";
    for(i=1;i<=n;i++)
    {
        if(n%i==0)
        {
            cout<<i<<" ";
            a[j]=i;
            j++;
        }
    }
    cout<<endl;
    num=j-1;
    cout<<"cov "<<n<<"={";
    for(k=0;k<=num;k++)
    {
        for(i=k+1;i<=num;i++)
        {
            if(a[i]%a[k]==0)
            {
                judge=2;
                if(i-k>1)
                {
                    for(t=k+1;t<i;t++)
                    {
                    if(a[t]%a[k]==0)
                        judge=1;
                    }
                }
            }
            if(judge==2&&k!=(num-1))
            {
                cout<<"<"<<a[k]<<","<<a[i]<<">,";
            }else{
                if(judge==2)
                    cout<<"<"<<a[k]<<","<<a[i]<<">";
                }
            judge=0;
        }
    }
    cout<<"}"<<endl;

}
int gcd(int x, int y)   //最大公约数
{
    int r = 1;
    while(r != 0)
    {
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}

void solve()           //判断是否为有补格
{
    bool flag;
    int Gcd, Lcm;
    for(int i = 1; i < num; i++)
    {
        flag = false;
        for(int j = 1; j < num; j++)
        {
            if(i == j)
                continue;
            Gcd = gcd(a[i],a[j]);
            Lcm = a[i] / Gcd * a[j];
            if(Gcd == a[0] && Lcm == a[num])
            {
                flag = true;
                break;
            }
            if(!flag)
            {
                //cout << "该格不是有补格!" << endl;
                return;
            }
        }
    }
    //cout << "该格是有补格!" << endl;
    return;
}

int main()
{
    int n;
    cout<<"please input the number:";
    cin>>n;
    factor(n);
    solve();
    return 0;
}
