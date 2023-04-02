#include <iostream>
#include "song.h"

using namespace std;

class Playlist
{
	public:
		Playlist();
		~Playlist();
		void AddSong(const Song&);
		int FindTitle(const string t);
		int FindArtist(const string a);
		void FromArtist(const string a);
		void Lookup(const string s);
		void Delete(const string s);
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