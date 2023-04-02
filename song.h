#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#ifndef _SONG_H
#define _SONG_H

enum Style {POP, ROCK, ALTERNATIVE, COUNTRY, HIPHOP, PARODY};

class Song
{
  // operator overload -- described at bottom
  friend ostream& operator<<(ostream& os, const Song& s);

public:
  Song();		// default constructor, sets up blank song object

  void Set(const string t, const string a, Style st, int sz);

  // the Set function should allow incoming data to be received through
  //  parameters and loaded into the member data of the object.  (i.e.
  //  this function "sets" the state of the object to the data passed in).
  //  The parameters t, a, st, and sz represent the title, artist, style, 
  //  and size of the song file, respectively.

  string GetTitle() const;		// returns the title stored in the object
  string GetArtist() const;	// returns the artist
  int GetSize() const;			// returns the file size in kilobytes
  Style GetCategory() const;		// returns the song category

private:
  string title;
  string artist;
  Style category;	// style of the given song
  int size;		// file size, stored in kilobytes
};

/* operator<< function

The operator<< overload should print out a Song object on one line (to 
the given ostream) -- use no more than 80 characters per line -- as 
follows, in an organized manner. Size should be printed in Megabytes 
(use 1000 kilobytes = 1 MB for this calculation), to 1 decimal place.  
The category abbreviations used should be: Pop, Rock, Alt, Ctry, HH, Par

Title		                   Artist	       Style   Size (MB)

Examples:
Pictures of You                    The Cure            Alt       4.4
Bohemian Rhapsody                  Queen               Rock      5.7
What Does the Fox Say              Ylvis               Par      12.6

*/ 

#endif