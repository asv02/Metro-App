#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <iomanip>

using namespace std;

namespace station_list
{
    string red_line[21] = {	"Dilshad Garden:none", "Jhil Mil:none", "Mansarovar Park:none", "Shahdara:none", "Welcome:Pink Line", "Seelampur:none",
                            "Shastri Park:none", "Kashmere Gate:Violet Line", "Tis Hazari:none", "Pul Bangash:none", "Pratap Nagar:none",
                            "Shastri Nagar:none", "Inder Lok:Green Line", "Kanhaiya Nagar:none", "Keshav Puram:none", "Netaji Subhash Place:Pink Line",
                            "Kohat Enclave:none", "Pitam Pura:none", "Rohini East:none", "Rohini West:none", "Rithala:none"};

    string yellow_line[37] = {	"Samaypur Badli:none", "Rohini Sector 18,19:none","Haiderpur Badli Mor:none", "Jahangirpuri:none",
    							"Adarsh Nagar:none", "Azadpur:none", "Model Town:none", "G.T.B. Nagar:none", "Vishwavidyalaya:none",
    							"Vidhan Sabha:none", "Civil Lines:none", "Kashmere Gate:none", "Chandni Chowk:none", "Chawri Bazar:none",
    							"New Delhi:none", "Rajiv Chowk:none", "Patel Chowk:none", "Central Secretariat:none", "Udyog Bhawan:none",
    							"Lok Kalyan Marg:none", "Jorbagh:none", "INA:none", "AIIMS:none", "Green Park:none", "Hauz Khas:none",
    							"Malviya Nagar:none", "Saket:none", "Qutab Minar:none", "Chhattarpur:none", "Sultanpur:none", "Ghitorni:none",
    							"Arjan Garh:none", "Guru Dronacharya:none", "Sikandarpur:none", "MG Road:none", "IFFCO Chowk:none",
    							"Huda City Centre:none"};
}

void clrscr()
{
	system("cls");
}
class station
{
	string name;
	string connection;

	public:														//specifies if the station is connected to some other line

	void getdata(string nameConnection)
	{
		int pos = nameConnection.find(":");
		name = nameConnection.substr(0,pos);
		connection = nameConnection.substr(pos+1);
	}

	string return_name()
	{
	    return name;
	}
	string return_connection()
	{
        return connection;
	}
};

class metroline
{
	string color;
    char condition;
    station stations[50];
    station test;

public:

	metroline(const char* clr)
	{
	    if(clr == "red")
        {
            color = clr;
            condition = 'k';
            for(int i=0; i<21; i++)
            {
                stations[i].getdata(station_list::red_line[i]);
            }
		}
		else if (clr == "yellow")
		{
			color = clr;
			condition = 'k';

			for(int i=0; i<37; i++)
            {
                stations[i].getdata(station_list::yellow_line[i]);
            }
		}
	}

	void display_color()
	{
		cout<<color;
	}

	void display_condition()
	{
		if(condition == 'k')
			cout<<"The "<<color<<" line is functioning properly!"<<endl;
		else
			cout<<"The "<<color<<" line is currently being investigated for technical faults!"<<endl;
	}

	void show_station(int num)
	{
	    cout<<setw(10)<<left<<num+1<<setw(30)<<left<<stations[num].return_name()<<setw(50)<<left<<stations[num].return_connection()<<endl;
	}

	void modify_condition()
	{
		cout<<"Are you sure you want to update the working condition of "<<color<<" line? ";
		char choice;
		cin>>choice;

		if(choice=='y' || choice=='Y')
			if(condition == 'k' || condition == 'K')
			{
				condition = 'n';
				cout<<"Condition of "<<color<<" line successfully set to not working!"<<endl;
			}
			else
			{
				condition = 'k';
				cout<<"Condition of "<<color<<" line successfully set to okay!"<<condition<<endl;
			}
		else
			return;
	}

	void path_finder(string starting, string ending)
	{
		int start_station, end_station, no_of_stations;

		for(int i=0; i<21; i++)
		{
			if(starting == stations[i].return_name())
			{
				start_station = i;
			}
		}
		for(int i=0; i<21; i++)
		{
			if(ending == stations[i].return_name())
			{
				end_station = i;
			}
		}

		no_of_stations = end_station - start_station;
		
		if(no_of_stations > 0)
		{
			cout<<"\nStarting Station: ";
			cout<<starting;
			cout<<"\n\nEnding Station: ";
			cout<<ending;
			cout<<"\n\nPlease board the train moving towards Rithala from platform number 1"<<endl;
			cout<<"\nYour total fare will be Rs. "<<(((no_of_stations)*15)>50) ? (50) : (no_of_stations*15);
		}
		else
        {
            cout<<"\nStarting Station: ";
			cout<<starting;
			cout<<"\n\nEnding Station: ";
			cout<<ending;
			cout<<"\n\nPlease board the train moving towards Dilshad Garden from platform number 2"<<endl;
			cout<<"\nYour total fare will be Rs. "<<(((-no_of_stations)*15)>50) ? (50) : (-no_of_stations*15);;
        }
	}
};

int main()
{
	clrscr();
	metroline red("red"),yellow("yellow");
	int choice,ch;
	char char_choice;

	do
	{
		clrscr();
		cout<<"#################### MENU ####################"<<endl;
		cout<<"1. Show Station List."<<endl;
		cout<<"2. Show operating metro lines."<<endl;
		cout<<"3. Find your way."<<endl;
		cout<<"4. Modify operating metro lines."<<endl;
		cout<<"Enter your choice: ";
		cin>>choice;

		switch(choice)
		{
			case 1: clrscr();
					cout<<"Show station list for: "<<endl;
					cout<<"1. Red line"<<endl;
					cout<<"2. Yellow line"<<endl;
					cout<<"Enter your choice: ";
					cin>>ch;
                    cout<<endl;
                    cout<<setw(10)<<left<<"S. No."<<setw(30)<<left<<"Station Name"<<setw(50)<<left<<"Connects to"<<endl;
					if(ch == 1)
	                {
	                    for(int i=0; i<21; i++)
                            red.show_station(i);
	                }
	                else if(ch == 2)
	                {
	                    for(int i=0; i<37; i++)
                            yellow.show_station(i);
	                }
					break;

			case 2: clrscr();
					cout<<"Show operating conditions for: "<<endl;
					cout<<"1. Red line"<<endl;
					cout<<"2. Yellow line"<<endl;
					cout<<"Enter your choice: ";
					cin>>ch;

					if(ch==1)
					{
						red.display_condition();
					}
					else if(ch==2)
					{
						yellow.display_condition();
					}
					break;

			case 3: clrscr();
					{
						cout<<"This feature is still in beta! Use at your own risk!"<<endl;
						cout<<"\n\nCurrently this feature works for only one line no interchanges are supported!"<<endl;
						cout<<"\nEnter the starting station name: ";
						string start, ends;
						cin>>start;
						cout<<"\nEnter where you want to get off: ";
						cin>>ends;
						cout<<"\n\nYour path is as follows: ";
						red.path_finder(start,ends);
					}
					break;

			case 4: clrscr();
					cout<<"Which Metro line's condition would you like to update? \n1. Red \n2. Yellow"<<endl;
					cin>>ch;

					if(ch==1)
					{
						red.modify_condition();
					}
					else if(ch==2)
					{
						yellow.modify_condition();
					}

					break;
		}

		cout<<"\nWould you rather continue?: ";
		cin>>char_choice;

	} while(char_choice == 'y' || char_choice == 'Y');
	return 0;
}