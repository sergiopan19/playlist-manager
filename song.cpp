/*
Name: Sergio Pantoja
Class: COP 3330 Section 6
Assignment: Homework 4

The following is the definition for the song class.
*/

#include "song.h"

using namespace std;

ostream& operator<<(ostream& os, const Song& s)
{
	os.setf(ios::left);
	os << setw(36) << s.title << setw(21) << s.artist;	
	os.width(10);
	
	switch (s.category)
	{
		case POP:
			os << "Pop";
			break;
		case ROCK:
			os << "Rock";
			break;
		case ALTERNATIVE:
			os << "Alt";
			break;
		case COUNTRY:
			os << "Country";
			break;
		case HIPHOP:
			os << "Hip-Hop";
			break;
		case PARODY:
			os << "Parody";
			break;
	}
	
	os << fixed << setprecision(2) << (s.size/1000.0);

	return os;
}

Song::Song()// default constructor, sets up blank song object
{
	strcpy(title, "");
	strcpy(artist, "");
	size = 0;
	
	//enumeration should default to 0
}

void Song::Set(const char* t, const char* a, Style st, int sz)
{
	strcpy(title, t);
	strcpy(artist, a);
	category = st;
	
	if(sz > 0)
		size = sz;
	else
		size = 0;
}

const char* Song::GetTitle() const {return title;} // returns the title stored in the object

const char* Song::GetArtist() const	{return artist;} // returns the artist

int Song::GetSize() const {return size;}	// returns the file size in kilobytes

Style Song::GetCategory() const {return category;} // returns the song category