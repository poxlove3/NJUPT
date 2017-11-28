#include <iostream>  
using namespace std;  
int const MAX = 1000;    
int matrix[MAX][MAX];   //����  
int n;                  //����Ԫ�ظ���  
bool flag1, flag2, flag3, flag4, flag5;  
  
void Reflexive() //�Է�  
{  
    flag1 = true;  
    for(int i = 0; i < n; i++)  
    {  
        //ֻҪ��һ���Խ�Ԫ��Ϊ0�Ͳ������Է���  
        if(!matrix[i][i])  
        {  
            flag1 = false;  
            break;     
        }  
    }  
}  
  
void Irreflexive() //���Է�  
{  
    flag2 = true;  
    for(int i = 0; i < n; i++)  
    {  
        //ֻҪ��һ���Խ�Ԫ��Ϊ1�Ͳ����з��Է���  
        if(matrix[i][i])  
        {  
            flag2 = false;  
            break;        
        }  
    }  
}  
  
void Symmetry()  //�Գ�  
{  
    flag3 = true;  
    for(int i = 0; i < n; i++)  
        for(int j = 0; j < n; j++)  
            //�����жԳ�Ԫ�ض��������жԳ���  
            if(matrix[i][j] != matrix[j][i])  
            {  
                flag3 = false;  
                break;  
            }  
}  
  
void Dissymmetry() //���Գ�  
{  
    flag4 = true;  
    for(int i = 0; i < n; i++)  
        for(int j = 0; j < n; j++)  
            //�����жԳ�Ԫ��������ȵ�1�򲻾��з��Գ���  
            if(matrix[i][j] && matrix[i][j] == matrix[j][i] && i != j)  
            {  
                flag4 = false;  
                break;  
            }  
}  
  
void Transitivity() //����  
{  
    flag5 = true;  
    for(int i = 0; i < n; i++)  
        for(int j = 0; j < n; j++)  
            for(int k = 0; k < n; k++)  
                //�ж��Ƿ����㴫�ݹ�ϵ  
                if(matrix[i][j] && matrix[j][k] && !matrix[i][k])  
                {  
                    flag5 = false;  
                    break;  
                }  
}  
  
void Answer()  
{  
    cout << "�ö�Ԫ��ϵ������������ :" << endl;  
    if(flag1)  
        cout << "�Է���" << endl;  
    if(flag2)  
        cout << "���Է���" << endl;  
    if(flag3)  
        cout << "�Գ���" << endl;  
    if(flag4)  
        cout << "���Գ���" << endl;  
    if(flag5)  
        cout << "������" << endl;  
}  
  
int main()  
{  
    cout << "�����뼯����Ԫ�ظ��� n = ";  
    cin >> n;  
    int *a = new int[n];  
    cout << "�����뼯��Ԫ��: ";  
    for(int i = 0; i < n; i++)  
        cin >> a[i];  
    cout << "����Ϊ A = {";  
    for(int i = 0; i < n - 1; i++)  
        cout << a[i] << ",";  
    cout << a[n - 1] << "}" << endl;  
    cout << "�������ϵ����:\n";  
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
