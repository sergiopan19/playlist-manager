#include <iostream>
#include <ctype.h> //toupper
#include "playlist.h"

using namespace std;

void Menu(); 				//prints menu
void Selection(Playlist p);	//allows for user selection and mnipulation of playlist object
Song Create();				//create new song object
Style ChooseCategory();		//Select category
string GetInput();

int main()
{
	Playlist p1;
	cout << "*** Welcome to Playlist Manager ***\n\n";

	Selection(p1);
	
	return 0;
}

void Menu()
{
	cout << "        *** PLAYLIST MENU ***\n";
	cout << "A:   Add a song to the playlist\n";
	cout << "F:   Find a song on the playlist\n";
	cout << "D:   Delete a song from the playlist\n";
	cout << "S:   Show the entire playlist\n";
	cout << "C:   Category summary\n"; 
	cout << "Z:   Show playlist size\n";
	cout << "M:   Show this Menu\n"; 
	cout << "X:   Exit the program\n\n"; 
}

void Selection(Playlist p)
{
	char choice;
	bool exit = false;
	
	Menu(); //display
	
	do
	{
		cout << "> ";
		cin >> choice;
		switch(choice)
		{
			case 'A':
			case 'a':
				p.AddSong(Create());
				break;
				
			case 'F':
			case 'f':
				cin.ignore();
				cout << "Enter search string (title or artist) > ";

				p.Lookup(GetInput()); //Checks for matches in both title and artist and prints accordingly 
				break;
			
			case 'D':
			case 'd':
				cin.ignore();
				cout << "Enter title to delete > ";
				p.Delete(GetInput());
				break;
				
			case 'S':
			case 's':
				p.ShowList(); //show entire playlist
				break;
			case 'C':
			case 'c':
				p.InCategory(ChooseCategory());
				break;
			case 'Z':
			case 'z':
				cout << "Total size of playlist = " << p.GetSize() << " kilobytes\n\n";
				break;
			case 'M':
			case 'm':
				Menu();
				break;
			case 'X':
			case 'x':
				exit = true; //End execution
				break;
			default:
				cout << "Invalid menu selection. Please re-enter\n\n";
				break;
		}
	}while(exit == false);
}

Song Create()
{
	int size;
	string title, artist;
	Style st;
	Song input;
	
	cin.ignore();
	
	cout << "\nEnter song title: ";
	title = GetInput();
				
	cout << "Enter artist: ";
	artist = GetInput();
			
	st = ChooseCategory();
				
	cout << "Enter song size in Kb: ";
	do{	
		cin >> size;
					
		if(size < 0)
		{
			cout << "Must enter a positive size. Please re-enter: ";
		}
		else
			break;
	}while(size < 0);
	
	cout << endl;
	
	input.Set(title, artist, st, size);
	return input;
}

Style ChooseCategory()
{
	bool valid = true; //Error checks whether input is valid
	char c;
	Style result = ROCK;

	do
	{
		cout << "Enter Category - (P)op, (R)ock, (A)lternative, (C)ountry, (H)iphop, or Parod(Y): ";
		cin >> c;
		
		switch (c) {
		case 'P':
		case 'p':
			result = POP;
			break;
		case 'R':
		case 'r':
			result = ROCK;
			break;
		case 'A':
		case 'a':
			result = ALTERNATIVE;
			break;
		case 'C':
		case 'c':	
			result = COUNTRY;
			break;
		case 'H':
		case 'h':
			result = HIPHOP;
			break;
		case 'Y':
		case 'y':
			result = PARODY;
			break;
		default:
			cout << "Invalid Category entry.  Please re-enter\n\n";
			valid = false;
		}
	} while(valid == false);	

	return result;
}

string GetInput() {
	string input;

	getline(cin, input);

	return input;
}