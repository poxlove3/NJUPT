#include<iostream>  
#include<math.h> 
 
using namespace std;
  
int Value[10000][10000];  
char Variable[15] = {'-','P','Q','R','A','B','C','D','E','F'};  
  
class Result  
{  
public:  
    Result(int num)
	{
		n = num; 
		k = pow(2,num);
	}  
    void Input();  
    void Output(); 
    void OutputResult();  
    void aOutputResult();  
private:  
    int n;  
    int k;  
};  
  
void Result::Input() //输入真值并保存 
{  
    cout << "Please input the value......" << endl;  
    cout << "the '1' represent the ture and the '0' represent false......" << endl;
    for(int i = 0;i < k;i++)  
    {  
        cin >> Value[i][0]; // 输入表达式的真值结果  
    }  
    int m = 0;
	int memo = k;  
    while(k / 2)     
    {  
        k = k / 2;     
        m++;          
        int value = 0;                                     
        int i = 0; 
        cout << "this is the last k... " << endl << k << endl;
		for(1; i < memo; i++) //循环打表    
        {      
            if(value == 1 && !(i % k)) 
				value = 0;  
            else if(value == 0 && !(i % k)) 
				value = 1;  
            Value[i][m] = value;  
            //cout << Value[i][m] << endl;
        } 
		cout << "this is the new k... " << endl << k << endl;    
    }  
    k = memo;// 保证K值不变 
}  
  
void Result::Output() //  输出真值表 
{  
    cout << "the value of form is:" << endl;  
    for(int j = 0;j <= n; j++)  
    {  
        cout << Variable[j] << "\t";  
        if(j == n) 
			cout << endl;  
    }  
    for(int i = 0;i < k;i++)
	{  
        for(int j = 0;j <= n;j++)  
        {  
            cout << Value[i][j] <<"\t";  
            if (j == n) 
				cout<<endl;  
        }  
    }
}  
  
void Result::OutputResult()  
{  
    cout << "主析取范式:" << endl;  
    int count = 0 - 1;
    for(int t = 0;t < k; t++) 
		if(Value[t][0] == 1) 
			count++;  
    for(int i = 0;i < k; i++)  
    {  
        if(Value[i][0] == 1)  
        {  
            for(int j = 1;j <= n;j++)  
            {  
                if(!Value[i][j])   
                	cout<<" ! ";  
                	cout<<Variable[j];  
                if(j < n)
					cout<<" ∧ ";  
            }  
            if(i < k && count)   
            {  
                cout<<" V ";  
                count--;  
            }  
        }  
    }  
    cout<<endl;  
}  
  
  
void Result::aOutputResult()  
{  
    cout << "主合取范式:" << endl;  
    int count = 0 - 1;  
    for(int t = 0;t < k;t++) 
	if(Value[t][0] == 0) 
		count++;  
    for(int i = 0;i < k;i++)    
    {  
        if(Value[i][0] == 0)   
        {  
            for(int j = 1;j <= n;j++)  
            {  
                if(!Value[i][j])   
                	cout<<" ! ";  
                	cout<<Variable[j];  
                if(j < n) 
					cout<<" V ";
            }  
            if(i < k && count)   
            {  
				cout<<" ∧ ";  
                count--;  
            }  
        }  
    }  
    cout<<endl;  
}  
int main()  
{  
    int n;  
    cout << "Please input Variable num:";  
    cin >> n;  
    Result ms(n);  
    ms.Input();  
    ms.Output();  
    ms.OutputResult();  
    ms.aOutputResult();  
    return 0;
}
