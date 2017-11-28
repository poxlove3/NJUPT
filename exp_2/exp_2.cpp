#include <iostream>  
using namespace std;  
int const MAX = 1000;    
int matrix[MAX][MAX];   //矩阵  
int n;                  //集合元素个数  
bool flag1, flag2, flag3, flag4, flag5;  
  
void Reflexive() //自反  
{  
    flag1 = true;  
    for(int i = 0; i < n; i++)  
    {  
        //只要有一个对角元素为0就不具有自反性  
        if(!matrix[i][i])  
        {  
            flag1 = false;  
            break;     
        }  
    }  
}  
  
void Irreflexive() //反自反  
{  
    flag2 = true;  
    for(int i = 0; i < n; i++)  
    {  
        //只要有一个对角元素为1就不具有反自反性  
        if(matrix[i][i])  
        {  
            flag2 = false;  
            break;        
        }  
    }  
}  
  
void Symmetry()  //对称  
{  
    flag3 = true;  
    for(int i = 0; i < n; i++)  
        for(int j = 0; j < n; j++)  
            //矩阵中对称元素都相等则具有对称性  
            if(matrix[i][j] != matrix[j][i])  
            {  
                flag3 = false;  
                break;  
            }  
}  
  
void Dissymmetry() //反对称  
{  
    flag4 = true;  
    for(int i = 0; i < n; i++)  
        for(int j = 0; j < n; j++)  
            //矩阵中对称元素中有相等的1则不具有反对称性  
            if(matrix[i][j] && matrix[i][j] == matrix[j][i] && i != j)  
            {  
                flag4 = false;  
                break;  
            }  
}  
  
void Transitivity() //传递  
{  
    flag5 = true;  
    for(int i = 0; i < n; i++)  
        for(int j = 0; j < n; j++)  
            for(int k = 0; k < n; k++)  
                //判断是否满足传递关系  
                if(matrix[i][j] && matrix[j][k] && !matrix[i][k])  
                {  
                    flag5 = false;  
                    break;  
                }  
}  
  
void Answer()  
{  
    cout << "该二元关系满足以下性质 :" << endl;  
    if(flag1)  
        cout << "自反性" << endl;  
    if(flag2)  
        cout << "反自反性" << endl;  
    if(flag3)  
        cout << "对称性" << endl;  
    if(flag4)  
        cout << "反对称性" << endl;  
    if(flag5)  
        cout << "传递性" << endl;  
}  
  
int main()  
{  
    cout << "请输入集合中元素个数 n = ";  
    cin >> n;  
    int *a = new int[n];  
    cout << "请输入集合元素: ";  
    for(int i = 0; i < n; i++)  
        cin >> a[i];  
    cout << "集合为 A = {";  
    for(int i = 0; i < n - 1; i++)  
        cout << a[i] << ",";  
    cout << a[n - 1] << "}" << endl;  
    cout << "请输入关系矩阵:\n";  
    for(int i = 0; i < n; i++)  
        for(int j = 0; j < n; j++)  
            cin >> matrix[i][j];  
    cout << endl;  
    Reflexive();  
    Irreflexive();  
    Symmetry();  
    Dissymmetry();  
    Transitivity();  
    Answer();  
    delete []a;  
    return 0;  
} 
