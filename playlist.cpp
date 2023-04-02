/*
Name: Sergio Pantoja
Class: COP 3330 Section 6
Assignment: Homework 4

The following is the class definitions for the playlist class. 
*/

#include "playlist.h"

using namespace std;

Playlist::Playlist()
{
	maxSize = 5;
	currentSize = 0;
	songList = new Song[maxSize];
}

Playlist::~Playlist() { delete[] songList; }	// cleanup (destructor)

void Playlist::AddSong(const Song& s)
{
	
	if(currentSize == maxSize) 		//if no space left
	{
		Grow(); 					//incrament maxSize by 5
		cout << "** Array being resized to  " << maxSize << " allocated slots.\n\n";
	}
	
	songList[currentSize++] = s; 	//allocate in next available slot
}

int Playlist::FindTitle(const char * title)
{
	for (int i = 0; i < currentSize; i++)	// Look at each entry.
	{
		if (strcmp(songList[i].GetTitle(), title) == 0)
			return i;						// return position and exit
	}
	return -1;								// if never found.
}

int Playlist::FindArtist(const char * artist)
{
	for (int i = 0; i < currentSize; i++)	// Look at each entry
	{
		if (strcmp(songList[i].GetArtist(), artist) == 0)
			return i;					// return position and exit
	}
	return -1;							// if never found
}

void Playlist::FromArtist(const char * artist)
{	
	for (int i = 0; i < currentSize; i++)	// Look at each entry
	{
		if (strcmp(songList[i].GetArtist(), artist) == 0)
		{
			cout << songList[i];		// if by artist, print song details
		}
	}
}

void Playlist::Lookup(const char * string)
{
	if(FindTitle(string) >= 0) 			//if function finds a match, print out first occurence
		cout << songList[FindTitle(string)];
	else if(FindArtist(string) >= 0)	//if function finds a match, print out all from artist
		FromArtist(string);
	else
		cout << string << ": Not Found\n\n";
}

void Playlist::Delete(const char * s)
{
	if(FindTitle(s) == -1) 	//title not found
		cout << s << " not found in playlist\n\n" << endl;
	else 					//title found
	{
		for (int i = FindTitle(s) + 1; i < currentSize; i++)
			songList[i - 1] = songList[i]; 	//shift empty slots over
			
		currentSize--;						// Decrement the current number of entries
		cout << "Entry removed\n\n";
	}
	
	if(maxSize - currentSize > 5) 	//if more than 5 slots are now available...
	{
		Shrink(); 					//shrink array by 5
		cout << "** Array being resized to  " << maxSize << " allocated slots.\n\n";
	}
}

void Playlist::ShowList() const
{
	if(currentSize == 0)
	{
		cout << "No songs currently in playlist\n\n";
	}
	else
	{
		cout.setf(ios::left);
		cout << setw(36) << "\n*Title*" << setw(21) << "*Artist*" << setw(10) << "*Style*" << "*Size (MB)*\n";
		for(int i = 0; i < currentSize; i++)
			cout << songList[i] << endl;
	}
	
	cout << "\nTotal songs in this playlist = " << currentSize << endl;
	cout << "Total file size = " << fixed << setprecision(1) << (GetSize()/1000.0) << " MB\n\n";
}

void Playlist::InCategory(const Style& search)
{
	int songCount = 0; 	//Number of songs in the category
	int catSize = 0; 	//Total memory space used by category
	
	cout << "\n";
	for(int i = 0; i < currentSize; i++)
	{
		if(search == songList[i].GetCategory()) //if song is in specified category...
		{
			songCount++;						
			catSize += songList[i].GetSize();
			cout << songList[i] << endl;
		}
	}
	
	cout << "\nTotal songs in this category = " << songCount << endl;
	cout << "Total file size = " << fixed << setprecision(1) << (catSize/1000.0) << " MB\n\n";

}

int Playlist::GetSize() const
{
	int memory = 0;
	
	for(int i = 0; i < currentSize; i++)
		memory += songList[i].GetSize();
		
	return memory;
}

void Playlist::Grow()
{
	maxSize = currentSize + 5;			// new array size
	Song* temp = new Song[maxSize];		// Allocate new array
	
	for (int i = 0; i < currentSize; i++)	// Copy in to new array
		temp[i] = songList[i];	
		
	delete songList;			// Deallocate the old array
	songList = temp;			// Point songList to new array
}

void Playlist::Shrink()
{
	maxSize = currentSize - 5;			// new array size
	Song* temp = new Song[maxSize];		// Allocate new array
	
	for (int i = 0; i < currentSize; i++)	// Copy into new array
		temp[i] = songList[i];		
		
	delete songList;			// Deallocate the old array
	songList = temp;			// Point songList to new array
}