#include<iostream>
#include<conio.h>
using namespace std;
int a = 0;
struct Register
{
    int d;
    string email ,name, password;
}R[25];
void registerAccount()
{
    char ch;
    cout<<"\n\n ENTER USER ID->";
    cin>>R[a].id;
    cout<<"\n\n ENTER USER NAME->";
    cin>>R[a].name;
    cout<<"\n\n ENTER USER EMAIL->";
    cin>>R[a].email;
    cout<<"\n\n ENTE USER PASSWORD->";
    do{
        ch = getch();
        if(isdigit(ch) || isalpha(ch) || ispunct(ch))
        {
            R[a].password  += ch;
            cout<<"*";
        }
    }while(isdigit(ch) || isalpha(ch) || ispunct(ch));
    a++;
    cout<<"\n\nAccount Register successfully";
}

void loginAccount()
{
    if(a==0)
    {
        cout<<"\n\nNo any record available";
    }
    else
    {
       string t_email , t_password;
       cout<<"\n\n ENTER USER EMAIL->";
    cin>>R[a].email;
    cout<<"\n\n ENTE USER PASSWORD->";
    do{
        ch = getch();
        if(isdigit(ch) || isalpha(ch) || ispunct(ch))
        {
            R[a].password  += ch;
            cout<<"*";
        }
    }while(isdigit(ch) || isalpha(ch) || ispunct(ch));
    a++;

    }

}

int main()
{
    p:
    system(cls);
    int ascii = 178 , choice;
    char ch = ascii;
    cout<<"\n";
    for(int i = 1 ; i < 23 ; i++)
        cout<<ch;
    cout<<"C++ Mini Project";
    for(int i = 1 ; i < 23 ; i++)
        cout<<ch;
    cout<<"\n\n"<<ch<<ch<<"1. REGISTER ACCOUNT";
    cout<<"\n\n"<<ch<<ch<<"2. LOGIN ACCOUNT";
    cout<<"\n\n"<<ch<<ch<<"3. FORGOT EMAIL";
    cout<<"\n\n"<<ch<<ch<<"4. FORGOT PASSWORD";
    cout<<"\n\n"<<ch<<ch<<"5. EXIT\n";
    cout<<"\n\nEnter your choice;
    cin>>choice;
    switch(choice)
    {
       case 1:
         registerAccount();
         break;
       case 2:
         break;
       case 3:
         break;
       case 4:
         break;
       case 5:
         exit(0);
       default:
        cout<<Please select correct option;
    }





}
