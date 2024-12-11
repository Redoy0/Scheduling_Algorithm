#include<bits/stdc++.h>
using namespace std;
int main()
{
    int frame[50],pages[100],fault=0;
    int n;
    cout<<"Enter no of page number: ";
    cin>>n;
    cout<<"Enter page number: ";
    for(int i=0;i<n;i++)
        cin>>pages[i];
    cout<<"Enter no of Frame: ";
    int no_f;
    cin>>no_f;

    int j=0;
    cout<<"Current Page\tpage frame \tHit/Fault\n";
    for(int i=0;i<n;i++)
    {
        cout<<pages[i]<<"\t\t";
        int flag=0;
        for(int k=0;k<no_f;k++)
        {
            if(frame[k]==pages[i])
            {
                flag=1;
                for(int l=0;l<no_f;l++)
                    cout<<frame[l]<<"\t";
                cout<<"H";

            }
        }
        if(flag==0)
        {
            frame[j]=pages[i];
            j=(j+1)%no_f;
            fault++;
            for(int k=0;k<no_f;k++)
            {
                cout<<frame[k]<<"\t";
            }
            cout<<"F";

        }
        cout<<endl;



    }
    cout<<"Total Page Fault: "<<fault<<endl;



    return 0;
}
