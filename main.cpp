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
    cout<<endl<<endl<<endl<<endl<<endl<<"Enter any key to continue";
    getch();
    system("cls");
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
int password_check()
{
cout<<"\t\t\t\t\t\t\tEnter the password:-";
    int i;
    char str[50];
    char str1[50];
    //char str1[5]="aman";
for(i=0;str[i]!='\13';i++)
    {
            str[i]=getch();
            if(str[i]==13)
                break;
            else
                cout<<"*";
    }
    str[i]='\0';
    ifstream fin;
    fin.open("pass.dat",ios::in|ios::binary);
    fin.seekg(0);
    while(!fin.eof())
    {
        fin.getline(str1,80,'\0');
    }
    fin.close();
    if(strcmp(str,str1)==0)
    {
        system("cls");
        cout<<endl<<endl<<endl<<endl<<endl<<"\t\t\t\t\t\t\tAccess Granted"<<endl<<endl<<endl<<endl<<"Press any key to continue";
        getch();
        system("cls");
        return 1;
    }
    else
    {
        system("cls");
        cout<<endl<<endl<<endl<<endl<<endl<<"\t\t\t\t\t\t\tAccess denied"<<endl<<endl<<endl<<endl<<"Press any key to go to the homepage";
        getch();
        system("cls");
        return 0;
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
int content()
{

    int a;
    cout<<"\n\n\n\t\t\t\t\t1.Add a new Entry\n\n\t\t\t\t\t2.View Entries\n\n\t\t\t\t\t3.Delete Entries\n\n\t\t\t\t\t4.Modify Entries\n\n\t\t\t\t\t5.Sort entries by website name\n\n\t\t\t\t\t6.Change the  password\n\n\t\t\t\t\t7.Delete all\n\n\tEnter the desired option:-";
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
    char* rid()
    {
        return (char*)id;
    }
    char* rpass()
    {
        return (char*)password;
    }
    char* rweb()
    {
        return (char*)website;
    }
    char* rnote()
    {
        return (char*)note;
    }
    void getdata()
    {   system("cls");
        fflush(stdin);
        cout<<endl<<endl<<endl;
        cout<<setw(50)<<"Enter the id:-";
        cin.getline(id,50);
        fflush(stdin);
        cout<<endl;
        cout<<setw(50)<<"Enter the website:-";
        cin.getline(website,50);
        fflush(stdin);
        cout<<endl;
        cout<<setw(50)<<"Enter the password:-";
        cin.getline(password,50);
        fflush(stdin);
        cout<<endl;
        cout<<setw(50)<<"Enter the note:-";
        cin.getline(note,500);
        fflush(stdin);
        cout<<endl<<endl<<endl;
        cout<<"Press any key to continue";
        getch();
    }
    void display_data()
    {

        cout<<setw(20)<<"ID:-"<<id<<endl;
        cout<<setw(20)<<"Password:-"<<password<<endl;
        cout<<setw(20)<<"Website:-"<<website<<endl;
        cout<<setw(20)<<"Note:-"<<note<<endl;
    }
      record change(record r1,record r2)
    {
            fflush(stdin);
            if(r2,id[0]=='.')
                strcpy(r2.id,r1.id);
            fflush(stdin);
            if(r2.password[0]=='.')
                strcpy(r2.password,r1.password);
            fflush(stdin);
            if(r2.website[0]=='.')       //new data
                strcpy(r2.website,r1.website);
            fflush(stdin);
            if(r2.note[0]=='.')       //new data
                strcpy(r2.note,r1.note);
            return r2;
    }
};
/////////////////////////////////////////////////////////////////////////////
void new_entry()
    {
        record r1;
        ofstream fout;
        fout.open("record.dat",ios::app|ios::binary);
        r1.getdata();
        cout<<endl<<endl;
        r1.display_data();
        fout.write((char*)&r1,sizeof(r1));
        fout.close();
        cout<<endl<<"Press any key to continue...";
        getch();
    }

/////////////////////////////////////////////////////////////////////////
void display_data_stack_all()
    {
        system("cls");
        record r1;
        int i=5;
        ifstream fin;
        fin.open("record.dat",ios::in|ios::binary);
        fin.seekg(0);
               while(fin.read((char*)&r1,sizeof(r1)))
        {

            if(i%5==0 && i!=0)
            {

                system("cls");

            }
            i++;
            cout<<"------------------------------------------------------------------"<<endl;
            r1.display_data();
            cout<<"------------------------------------------------------------------"<<endl;
            cout<<"Press any key to go to the next record"<<endl;
            getch();
        }
        cout<<"End of file is reached Press any key to continue...."<<endl;
        getch();
        fin.close();
    }

//////////////////////////////////////////////////////////////////////////
void delete_record()
{
    record r1,r2;
    ifstream fin;
    ofstream fout;
    int i;
    fin.open("record.dat",ios::in|ios::binary);
    fout.open("temp.dat",ios::app|ios::binary);
    int length;
    fin.seekg(0,ios::end);      //difference between 0,ios::end and ios::end
    length=fin.tellg();
    if(length==0)
    {
        fin.close();
        fout.close();
        remove("temp.dat");
        cout<<"No records found Press any key to continue...";
        getch();
    }
    else
    {
        fin.seekg(0);
        cout<<"Enter the data to be deleted:-";
        r1.getdata();               //r1 is the data which is to be deleted

        while(fin.read((char*)&r2,sizeof(r2)))
    {
        if(strcmp(r2.rid(),r1.rid())!=0 || strcmp(r2.rweb(),r1.rweb())!=0 || strcmp(r2.rpass(),r1.rpass())!=0)
        {
            fout.write((char*)&r2,sizeof(r2));
        }
        else
        {
            cout<<"\nAre you sure, You wanna delete the record:-\n";
            r2.display_data();
            char ch;
            i++;
            cout<<"Enter the option in y/n:-";
            cin>>ch;
            if(tolower(ch)=='n')
            {

                 fout.write((char*)&r2,sizeof(r2));
            }
            if(tolower(ch)=='y')
            {
                cout<<endl<<endl<<endl<<"\t\t\t\t\tDeleted";
                 cout<<endl<<endl<<endl<<"\t\t\t\tPress any key to go to the next record"<<endl;
            getch();
            }
        }
    }
    cout<<"\nEnd of file is reached, Press any key";
    getch();
    if(i==0)
    {
        cout<<"Sorry,Record not found";

     cout<<endl<<endl<<endl<<"\t\t\t\tPress any key to continue"<<endl;
            getch();
    }
    else
    {
         cout<<endl<<endl<<endl<<"\t\t\t\tPress any key to continue"<<endl;
            getch();
    }
    fout.close();
    fin.close();

 remove("record.dat");
    rename("temp.dat","record.dat");
    }
}
///////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void modify_record()
{
    record r3,r2,r1;
    char ch;
    ifstream fin;
    ofstream fout;

fin.open("record.dat",ios::in|ios::binary);
fout.open("temp.dat",ios::app|ios::binary);
fin.seekg(0,ios::end);
int length;
length=fin.tellg();
if(length==0)
{
        fin.close();
        fout.close();
        remove("temp.dat");
        cout<<"No records found Press any key to continue...";
        getch();
}
else
    {
        int i=0;
        fin.seekg(0);
        cout<<"Choose the record which you wanna modify:-"<<endl;
        while(fin.read((char*)&r1,sizeof(r1)))
        {
            r1.display_data();      //orignal data
            cout<<"Y/N";
            cin>>ch;
                if(tolower(ch)=='y')
                {
                    cout<<"Enter the modified data and to retain the data press \'.\'";
                    r2.getdata();
                    r3=r3.change(r1,r2);
                    fout.write((char*)&r3,sizeof(r3));
                }
                else
                {
                    fout.write((char*)&r1,sizeof(r1));
                }

        }
        fin.close();
        fout.close();
        cout<<"\nEnd of file is reached, Press any key"<<endl;
        getch();
        remove("record.dat");
        rename("temp.dat","record.dat");
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void sort_website()
{

    record r1;
    int i=0;
    fflush(stdin);
    system("cls");
    cout<<"Enter the required website:-";
    char reweb[50];
    gets(reweb);
    ifstream fin;
    fin.open("record.dat",ios::in|ios::binary);
    while(fin.read((char*)&r1,sizeof(r1)))
    {
        if(strcmpi(reweb,r1.rweb())==0)
           {
                i++;
                cout<<"-------------------------------------------------------------------------------------\n";
                r1.display_data();
                    cout<<"-------------------------------------------------------------------------------------\n";
           }

    }
       if(i==0)
           {
               cout<<"No record found\n";
           }
    fin.close();
    cout<<"Press any key to continue....";
getch();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void change_pass()
{
    int ch;
    ch=password_check();
    if(ch==1)
    {
        cout<<"Enter the new password";
        char str[50];
        fflush(stdin);
        gets(str);
        ofstream fout;
        fout.open("pass.dat",ios::out|ios::binary);
        fout<<str;
        fout.close();
    }
    else
    {
        cout<<" Incorrect password";
    }

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void delete_all()
{
    ofstream fout;
    fout.open("temp.dat",ios::out);
    fout.close();
    remove("record.dat");
    rename("temp.dat","record.dat");
    cout<<"All records are deleted \n Press any key to continue....";
    getch();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
int choice,authority;
l1:system("cls");
home_page();
authority=password_check();
if(authority==1)
    {
        choice=content();
        if(choice==1)           //Add a new Entry
        {
            new_entry();
        }

        else if(choice==2)      //View all entries
        {
            display_data_stack_all();
        }
        else if(choice==3)//delete a enrty
        {
            delete_record();
        }
        else if(choice==4)
        {
            modify_record();
        }
        else if(choice==5)
        {
            sort_website();
        }
        else if(choice==6)
        {
            change_pass();
        }
        else if(choice==7)
        {
            delete_all();
        }

        else
        {
            cout<<"invalid Input Bye";
        }



    }
else
    {
        cout<<"Wrong Password Bye";
    }
goto l1;
}
