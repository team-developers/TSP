#include <iostream>
using namespace std;
#define v 100
void output(int n,int a[][v])
{
    int i,j;
    cout<<"The matrix is:-"<<endl<<"  ";
    for(i=0;i<n;i++)
    {
        cout<<(char)(65+i)<<"  ";
    }
    cout<<endl;
    for(i=0;i<n;i++)
    {
        cout<<(char)(65+i)<<" ";
        for(j=0;j<n;j++)
        {
            if(a[i][j]==9999)
            cout<<"X"<<" ";
            else
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
void calc(int k,int n,int a[][v])
{
    int i,j,c,p[n],k2=k,k1=0,s=0,k3=k;
    bool m[n];
    for(i=0;i<n;i++)
    m[i]=false;
    m[k2]=true;
    cout<<"the path is: "<<(char)(65+k)<<" --> ";
    for(i=0;i<n;i++)
    {
        c=9999;
        for(j=0;j<n;j++)
        {
            if(!m[j] && a[k2][j]<c)
            {
                c=a[k2][j];
                k=j;
            }
        }
        k2=k;
        if(c!=9999)
        {s+=c;
        m[k2]=true;
        p[k1]=c;
        k1++;
        cout<<(char)(65+k2)<<" --> ";}
    }
    cout<<(char)(65+k3)<<endl;
    s+=a[k2][k3];
    cout<<"the cost is: "<<s;
        
}
int main()
{
    int n,i,j,k;
    char ver;
    cout<<"Enter the number of vertices to be taken: ";
    cin>>n;
    int a[n][v];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
            a[i][j]=9999;
            else
            {
                cout<<"Enter the cost from node "<<(char)(65+i)<<" to node "<<(char)(65+j)<<": ";
                cin>>a[i][j];
            }
        }
    }
    output(n,a);
    cout<<"Enter the starting vertex in alphabet: ";
    cin>>ver;
    calc(int(ver)-65,n,a);
    return 0;
    
}
