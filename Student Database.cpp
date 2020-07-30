#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <iomanip>

using namespace std;
int main()
{
    FILE *fp, *ft;
    char repeat, choice;

    struct student
    {
        char first_name[50], last_name[50];
        char course[100];
        char section;
    };

    struct student s;
    char xfirst_nams[50], xlast_name[50];
    long int recsize;

    fp=fopen("users.txt","rb+");//opening binary file to read only.

    if (fp == NULL)//if it is nonexistent
    {
        fp = fopen("users.txt","wb+");//it will create new file to write into with names users.txt 
        if (fp==NULL)
        {
            puts("Cannot open file");//if unknown error in opening/creating file
            return 0;
        }
    }


    recsize = sizeof(s);//size of struct variable, i.e.,size of each object in buffer stream

    while(1)
    {
        system("cls");//only needed for TurboC compiler-it clears the output space

        cout << "\t\t====== STUDENT DATABASE MANAGEMENT SYSTEM ======";
        cout <<"\n\n                                          ";
        cout << "\n\n";
        cout << "\n \t\t 1. Add    Records";
        cout << "\n \t\t 2. List   Records";
        cout << "\n \t\t 3. Modify Records";
        cout << "\n \t\t 4. Delete Records";
        cout << "\n \t\t 5. Exit   Program";
        cout << "\n\n";
        cout << "\t\t\t Select Your Choice :=> ";
        fflush(stdin);//to clear the buffer stream so that we can take new input
        choice = getche();//waits for char input from keyboard and displays it without need to press enter key as output
        switch(choice)
        {
        case '1' :
            fseek(fp,0,SEEK_END);//to set position at 0 offset places from end of file, i.e., at last char of file.
            repeat ='Y';
            while(repeat == 'Y' || repeat == 'y')
            {
                system("cls");
                cout << "Enter the First Name : ";
                cin >> s.first_name;
                cout << "Enter the Last Name : ";
                cin >> s.last_name;
                cout << "Enter the Course    : ";
                cin >> s.course;
                cout << "Enter the Section   : ";
                cin >> s.section;
                fwrite(&s,recsize,1,fp);//writing 1 object of size 'recsize' in bytes from &s buffer stream into fp file stream 
                cout << "\n Add Another Record (Y/N) ";
                fflush(stdin);//to clear buffer stream and get ready to receive next input
                repeat = getchar();//enter Y/N
            }
            break;
        case '2':
            system("cls");
            rewind(fp);
            cout << "\t\tView the Records in the Database\t\t";
            cout << "\n";
            while (fread(&s,recsize,1,fp) == 1)
            {
                cout << "\n";
                cout <<"\n"<<s.first_name<<setw(10)<< s.last_name;//setw(10)=setwidth gap of 10 between first and last names
                cout << "\n";
                cout <<"\n"<<s.course<<setw(8)<<s.section;
            }
            cout << "\n\n";
            system("pause");
            break;

        case '3' :
            system("cls");
            repeat = 'Y';
            while (repeat == 'Y'|| repeat == 'y')
            {
                cout << "\n Enter the last name of the student : ";
                cin >> xlast_name;

                rewind(fp);//sets position to beginning of file stream fp again
                while (fread(&s,recsize,1,fp) == 1)//while fread is being done from fp file stream and object being read is stored in &s buffer memory, fread returns 1, until read is still being performed
                {
                    if (strcmp(s.last_name,xlast_name) == 0)//if lastname matches
                    {
                        cout << "Enter new First Name : ";
                        cin >> s.first_name;
                        cout << "Enter new Last Name : ";
                        cin >> s.last_name;
                        cout << "Enter new Course    : ";
                        cin >> s.course;
                        cout << "Enter new Section   : ";
                        cin >> s.section;
                        fseek(fp, - recsize, SEEK_CUR);//sets position to a point (size of s or of object) bytes before the current position (SEEK_CUR), so that it can write data the size of object s.
                        fwrite(&s,recsize,1,fp);//writes 1 object of size s(object) from buffer stream &s into file stream fp
                        break;
                    }
                    else
                        cout<<"record not found";
                }
                cout << "\n Modify Another Record (Y/N) ";
                fflush(stdin);//to clear the buffer stream so that we can take new input
                repeat = getchar();
            }
            break;


        case '4':
            system("cls");
            repeat = 'Y';
            while (repeat == 'Y'|| repeat == 'y')
            {
                cout << "\n Enter the last name of the student to delete : ";
                cin >> xlast_name;

                ft = fopen("temp.dat", "wb");

                rewind(fp);//sets position of stream to the beginning of file again
                while (fread (&s, recsize,1,fp) == 1)

                    if (strcmp(s.last_name,xlast_name) != 0)
                    {
                        fwrite(&s,recsize,1,ft);
                    }
                fclose(fp);
                fclose(ft);
                remove("users.txt");
                rename("temp.dat","users.txt");

                fp=fopen("users.txt","rb+");//open binary file for both reading and updating

                cout << "\n Delete repeat Record (Y/N) ";
                fflush(stdin);//to clear the buffer stream so that we can take new input
                repeat = getchar();
            }

            break;

        case '5':
            fclose(fp);
            cout << "\n\n";
            cout << "\t\t THANK YOU FOR USING THIS SOFTWARE";
            cout << "\n\n";
            exit(0);
        }
    }



    return 0;
}

