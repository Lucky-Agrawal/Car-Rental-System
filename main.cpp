#include<iostream>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<stdio.h>
#include<fstream>
using namespace std;
class car
{
	public:
	int carno;
	float no_of_hours;
	char  drivername[15],x,slot[50];
	void input()
	{
		system("CLS");
		int d;
		cout<<"\nEnter the name of driver : ";
		cin>>drivername;
		cout<<"\nEnter the car no : ";
		cin>>carno;
		cout<<"\nEnter the no of hours of stay : ";
		cin>>no_of_hours;
		cout<<"\nEnter the time slot : ";
		cin>>slot;
		if(d<20&&no_of_hours<8)
   			{
   				cout<<"\n\n\t\tYou can park your car. ";
   			}
   			else
   				cout<<"\n\n\t\t You can't park your car!!";
   			cout<<"\n\n\t\tCar got parked!!";

	}
	void cal()
	{
//	system("CLS");
	cout<<"\n\n\tThe total cost for parking is:   ";
	cout<<no_of_hours*50<<" rupees";
    }
	void output()
	{
		cout<<"\n\nThe Driver Name : "<<drivername;
		cout<<"\n The Car No is: "<<carno;
		cout<<"\nThe Hours Of Stay : " <<no_of_hours;
		cout<<"\nThe Time Slot Of Parking : " <<slot;

	}



}a,a1;
void delete_record()
{
	int n;
	system("CLS");
	cout<<"\n\n\t\t The car no you want to get depart : ";
	cin>>n;
	ifstream inFile;
    inFile.open("parking3.dat", ios::binary);
	ofstream outFile;
    outFile.open("temp.dat", ios::out | ios::binary);
    while(inFile.read((char*)&a, sizeof(a)))
    {
        if(a.carno!= n)
        {

            outFile.write((char*)&a, sizeof(a));
        }

    }
    cout<<"\n\n\t\t  Record Deleted";

    inFile.close();
    outFile.close();

    remove("parking3.dat");
    rename("temp.dat", "parking3.dat");
}

int main()
{
	int choice,vno1,d;
	while(1) {
	system("CLS");

     cout << "\t\t ============= CAR PARKING SYSTEM ================";
     cout <<"\n";
     cout << "\n  1. Enter The details of the car to get parked";
     cout << "\n  2. Details Of All Parking Car";
     cout << "\n  3. Delete The Record For Parked Car";
     cout << "\n  4. Exit Program";
     cout << "\n";
     cout << "\n Select Your Choice: ";
     cin>>choice;
     switch(choice)
     {
      case 1 :
        {
        	ofstream f1("parking3.dat",ios::app);
            a.input();
            a.cal();
            f1.write((char*)&a,sizeof(a));
            break;
        }
       case 2 :
           {
           	system("CLS");
           	const char *filename = "parking3.dat";
            std::ifstream in ( filename );

            if ( !in )
                std::cerr<< filename <<" failed to open\n";
            else {
               // Read a character, test for end-of-file
                bool empty = ( in.get(), in.eof() );
                if(empty){
                	cout<<"THE FILE IS EMPTY.";
				}else{
					cout << "\n\n\t\t=== View the Records in the Parking Database ===";
                    cout << "\n";
                    ifstream infile("parking3.dat",ios::binary|ios::in);
                    int d=1;
                    while (infile.read((char *)&a,sizeof (a))){
		                system("CLS");
                        cout << "\n";
                        cout<<"\n\n\tThe Car position in parking lot : "<<d;
                        d++;
                        a.output();
                        cout<<"\n";
                        cout<<"\n\n\n";
                        system("PAUSE");
                        cout<<endl;
       	            }
					break;
				}
            }
       	   }
        case 3:
		   {

		   delete_record();
		   break;
	       }

   		case 4:
		   {
		   	system("CLS");
		   	cout<<"\n\nTHANKU FOR VISITING US \n";
		   exit(0);
   			break;
   		}
   		default :
		   {
		   cout<<"\n\n Invalid input .  PLZZ ENTER VALID INPUT.";
   	}
   }
getch();
}}

