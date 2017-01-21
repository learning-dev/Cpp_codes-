/*
  Project name: Student Data
  Sem: 3rd Sem
  Coded by: Mohammed Ayaz S
  Topics: LinkedList, structures, pointers.
*/
#include <iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
using namespace std;
typedef struct date{
  int date;
  int month;
  int year;
}Date;
typedef struct Student {
    string usn;
    string name;
    int sem;
    float aggregate;
     Date Dob,Doj;
    struct Student * link;
}Std;

Std *root,*last;

void Insert()
{
    Std *temp=new Std();
    cout<<"\nEnter the USN:";
    cin>>temp->usn;
    cin.ignore();
    cout<<"\nEnter the name:";

    getline(cin,temp->name);
    cout<<"\nEnter your Date of Birth:";
    cin>>temp->Dob.date>>temp->Dob.month>>temp->Dob.year;
    cout<<"\nEnter your Date of Joining:";
    cin>>temp->Doj.date>>temp->Doj.month>>temp->Doj.year;
    cout<<"\nEnter your current semester:";
    cin>>temp->sem;
    cout<<"\nEnter your aggregate till now:";
    cin>>temp->aggregate;
    cout<<"All the data has been entered";


     if(root == NULL)
      {
          root=temp;
          last=temp;
      }
      last->link=temp;
      temp->link=NULL;

      return;
}
void Delete()
{
    Std *temp,*t;
    temp=root;
    if(root->link==NULL)
    {
        delete root;
        root=NULL;
    }
   else
   { while(temp->link!=last)
    {
        t=temp;
        temp=temp->link;
    }
     last=t;
    delete t->link;

   }
   cout<<"\nRecord has been deleted";
    return;
}
void  Display()
{

    if(root==NULL)
      cout<<"List is Empty\n";

     else
     {
        cout<<"\nDisplaying all the records";
        Std *temp;
        temp=root;


         while(temp!=NULL)
         {

            cout<<"\nRecord ";
            cout<<"\nEntered USN:";
            cout<<temp->usn;
            cout<<"\nEntered name:";
            cout<<temp->name;
            cout<<"\nEntered Date of Birth:";
            cout<<temp->Dob.date<<temp->Dob.month<<temp->Dob.year;
            cout<<"\nEntered Date of Joining:";
            cout<<temp->Doj.date<<temp->Doj.month<<temp->Doj.year;
            cout<<"\nEntered current semester:";
            cout<<temp->sem;
            cout<<"\nEntered aggregate till now:";
            cout<<temp->aggregate;
            temp=temp->link;

     }
    }
     return;
}
int main()
{
    int ch;
   while(ch!=4)
   {
         cout<<" 1.Add a record\n 2.View a record\n 3.Delete a record\n 4.Exit\n  Enter you choice:";
     cin>>ch;
       switch(ch)
        {
            case 1:  Insert();
                      break;
                    cin>>ch;
            case 2: Display();
                     break;
            case 3:   Delete();
                      break;
            case 4:   break;
            default: cout<<"Please enter  a valid option:";
                         break;
        }

   }


     return 0;
}
