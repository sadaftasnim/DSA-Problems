#include<iostream>
#include<conio.h>

using namespace std;
int a = 0;
struct Register
{
    int id;
    string email ,name, password;
}R[25];
void registerAccount()
{
    system("cls");
    char d;
     int ascii = 178;
    char ch = ascii;
    cout<<"\n";
    for(int i = 1 ; i < 23 ; i++)
        cout<<ch;
    cout<<"  ";
    cout<<"C++ Mini Project";
    cout<<"  ";
    for(int i = 1 ; i < 23 ; i++)
        cout<<ch;
    cout<<"\n\n ENTER USER ID -> ";
    cin>>R[a].id;
    cout<<"\n ENTER USER NAME -> ";
    cin>>R[a].name;
    cout<<"\n ENTER USER EMAIL -> ";
    cin>>R[a].email;
    cout<<"\n ENTER USER PASSWORD -> ";
    do{
        d = getch();
        if(isdigit(d) || isalpha(d) || ispunct(d))
        {
            R[a].password  += d;
            cout<<"*";
        }
    }while(isdigit(d) || isalpha(d) || ispunct(d));
    a++;
    cout<<"\n\n Account Register successfully";
}

void loginAccount()
{
    system("cls");
    int ascii = 178;
    char ch = ascii;
    cout<<"\n";
    for(int i = 1 ; i < 23 ; i++)
        cout<<ch;
    cout<<"  ";
    cout<<"C++ Mini Project";
    cout<<"  ";
    for(int i = 1 ; i < 23 ; i++)
        cout<<ch;
    if(a==0)
    {
        cout<<"\n\nNo any record available";
    }
    else
    {
        int found = 0;
        char d;
        string t_email , t_password;
        cout<<"\n\n ENTER USER EMAIL -> ";
        cin>>t_email;
        cout<<"\n ENTER USER PASSWORD -> ";
        do{

            d = getch();
            if(isdigit(d) || isalpha(d) || ispunct(d))
            {
                t_password  += d;
                cout<<"*";
            }
          }while(isdigit(d) || isalpha(d) || ispunct(d));
           for(int k  = 0  ; k < a ; k++)
           {

               if(((t_email.compare(R[k].email))==0 )&& ((t_password.compare(R[k].password))==0))
               {
                   cout<<"\n\n USER ID -> "<<R[k].id;
                   cout<<"\n\n USER NAME -> "<<R[k].name;
                   cout<<"\n\n USER EMAIL -> "<<R[k].email;
                   cout<<"\n\n USER PASSWORD -> "<<R[k].password;
                   found++;
                   break;

               }
           }
           if(found == 0)
           {
               cout<<"\n\n User Data Incorrect";
           }
    }
}
void forgotEmail()
{
    system("cls");
    int ascii = 178;
    char ch = ascii;
    cout<<"\n";
    for(int i = 1 ; i < 23 ; i++)
        cout<<ch;
    cout<<"  ";
    cout<<"C++ Mini Project";
    cout<<"  ";
    for(int i = 1 ; i < 23 ; i++)
        cout<<ch;
    if(a==0)
    {
        cout<<"\n\nNo any record available";
    }
    else
    {
        int found = 0;
        char d;
        string t_password;
        cout<<"\n\n ENTE USER PASSWORD -> ";
        do{

            d = getch();
            if(isdigit(d) || isalpha(d) || ispunct(d))
            {
                t_password  += d;
                cout<<"*";
            }
          }while(isdigit(d) || isalpha(d) || ispunct(d));
           for(int k  = 0  ; k < a ; k++)
           {
               if(t_password == R[k].password)
               {
                   cout<<"\n\n USER ID -> "<<R[k].id;
                   cout<<"\n\n USER NAME -> "<<R[k].name;
                   cout<<"\n\n USER EMAIL -> "<<R[k].email;
                   cout<<"\n\n USER PASSWORD -> "<<R[k].password;
                   found++;
                   break;

               }
           }
           if(found == 0)
           {
               cout<<"\n\nUser Data Incorrect";
           }
    }
}
void forgotPassword()
{
    system("cls");
    int ascii = 178;
    char ch = ascii;
    cout<<"\n";
    for(int i = 1 ; i < 23 ; i++)
        cout<<ch;
    cout<<"  ";
    cout<<"C++ Mini Project";
    cout<<"  ";
    for(int i = 1 ; i < 23 ; i++)
        cout<<ch;
    if(a==0)
    {
        cout<<"\n\nNo any record available";
    }
    else
    {
        int found = 0;
        char d;
        string t_email ;
        cout<<"\n\n ENTER USER EMAIL -> ";
        cin>>t_email;

           for(int k  = 0  ; k < a ; k++)
           {
               if(t_email == R[k].email)
               {
                   cout<<"\n\n USER ID -> "<<R[k].id;
                   cout<<"\n\n USER NAME -> "<<R[k].name;
                   cout<<"\n\n USER EMAIL -> "<<R[k].email;
                   cout<<"\n\n USER PASSWORD -> "<<R[k].password;
                   found++;
                   break;

               }
           }
           if(found == 0)
           {
               cout<<"\n\nUser Data Incorrect";
           }
    }

}

int main()
{
    p:
    system("cls");
    int ascii = 178 , choice;
    char ch = ascii;
    cout<<"\n";
    for(int i = 1 ; i < 23 ; i++)
        cout<<ch;
    cout<<"  ";
    cout<<"C++ Mini Project";
    cout<<"  ";
    for(int i = 1 ; i < 23 ; i++)
        cout<<ch;
    cout<<"\n\n"<<ch<<ch<<"1. REGISTER ACCOUNT";
    cout<<"\n\n"<<ch<<ch<<"2. LOGIN ACCOUNT";
    cout<<"\n\n"<<ch<<ch<<"3. FORGOT EMAIL";
    cout<<"\n\n"<<ch<<ch<<"4. FORGOT PASSWORD";
    cout<<"\n\n"<<ch<<ch<<"5. EXIT\n";
    cout<<"\n\nEnter your choice -> ";
    cin>>choice;
    switch(choice)
    {
       case 1:
         registerAccount();
         break;
       case 2:
         loginAccount();
         break;
       case 3:
         forgotEmail();
         break;
       case 4:
        forgotPassword();
         break;
       case 5:
         exit(0);
       default:
        cout<<"Please select correct option";
    }


    getch();
    goto p;


}
