#include<iostream>
#include<stdio.h>
#include<strings.h>
#include<conio.h>
#include<fstream>
#include<stdlib.h>
#include<iomanip>
/////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
void home_page()
{
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"\t\t\t\t\t\tWelcome to the password manager"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t-Aman Agarwal"<<endl;
    getch();
    system("cls");
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
int password_check()
{
cout<<"Enter the password:-";
    int i;
    char str[50];
    char str1[5]="aman";
for(i=0;i<10;i++)
    {
        str[i]=getch();
            if(str[i]==13)
            break;
    else
        cout<<"*";
    }
    str[i]='\0';
    if(strcmpi(str,str1)==0)
       return 1;
    else
        return 0;

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
int content()
{

    int a;
    cout<<"\n1.Add a new Entry\n2.View Entries\n3.Delete Entries\n4.Modify Entries\n5.Sort entries by website name\n6.Search password";
    cin>>a;
    return a;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class record
{
private:
    char id[50];
    char website[50];
    char password[50];
    char note[500];
public:
    void getdata()
    {
        fflush(stdin);
        cout<<setw(20)<<"\nEnter the id:-";
        cin.getline(id,50);\
        fflush(stdin);
        cout<<setw(20)<<"Enter the website:-";
        cin.getline(website,50);
        fflush(stdin);
        cout<<setw(20)<<"Enter the password:-";
        cin.getline(password,50);
        fflush(stdin);
        cout<<setw(20)<<"Enter the note:-";
        cin.getline(note,500);
        fflush(stdin);
    }
    void display_data()
    {
        cout<<setw(10)<<"ID:-"<<id<<endl;
        cout<<setw(10)<<"Password:-"<<password<<endl;
        cout<<setw(10)<<"Website:-"<<website<<endl;
        cout<<setw(10)<<"Note:-"<<note<<endl;
    }



};
/////////////////////////////////////////////////////////////////////////////
    void new_entry(record r1)
    {
        ofstream fout;
        fout.open("record.dat",ios::app|ios::binary);
        r1.getdata();
        r1.display_data();
        fout.write((char*)&r1,sizeof(r1));
        fout.close();
    }

/////////////////////////////////////////////////////////////////////////
void display_data_stack_all(record r1)
    {
        int i=5;
        ifstream fin;
        fin.open("record.dat",ios::in|ios::binary);
        fin.seekg(0);
        while(fin)
        {
            fin.read((char*)&r1,sizeof(r1));
            if(i%5==0 && i!=0)
            {
                system("cls");
            }
            i++;
            r1.display_data();
            cout<<"------------------------------------------------------------------"<<endl;
        }

        fin.close();
    }

//////////////////////////////////////////////////////////////////////////
int main()
{
int choice,authority;
home_page();
authority=password_check();
if(authority==1)
    {
        record r1;
        choice=content();
        if(choice==1)           //Add a new Entry
        {
            new_entry(r1);
        }

        else if(choice==2)
        {
            display_data_stack_all(r1);
        }
  //      else if(choice==3)
    //    else if(choice==4)
      //  else if(choice==5)
        //else if(choice==6)
        else
        {
            cout<<"invalid Input Bye";
        }


    }
else
    {
        cout<<"Wrong Password Bye";
    }

}
