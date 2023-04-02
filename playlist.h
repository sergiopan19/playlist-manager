/*
Name: Sergio Pantoja
Class: COP 3330 Section 6
Assignment: Homework 4

The following is the header for the playlist class. 
*/

#include <iostream>
#include "song.h"

using namespace std;

class Playlist
{
	public:
		Playlist();
		~Playlist();
		void AddSong(const Song&);
		int FindTitle(const char * t);
		int FindArtist(const char * a);
		void FromArtist(const char * a);
		void Lookup(const char * s);
		void Delete(const char * s);
		void ShowList() const;
		void InCategory(const Style&);
		int GetSize() const;
		
	private:
		Song * songList;
		int maxSize;
		int currentSize;
		int memory;
		void Grow();
		void Shrink();
};