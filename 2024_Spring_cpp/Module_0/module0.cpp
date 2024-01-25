#include <iostream>
#include <string>
using namespace std;

class song
{
private:
    string name;
    string artist;    
public:
    void setName(string n)
    {
        name = n;
    }
    void setArtist(string a)
    {
        artist = a;
    }

   string getName()
   {
    return name;
   }
   string getArtist()
   {
    return artist;
   }
};

int main()
{
    song newSong;
    string newSongName;
    string newArtistName;

    cout << "Please enter the name of the song: ";
    getline(cin, newSongName);
    newSong.setName(newSongName);

    cout << "Please enter the name of the artist: ";
    getline(cin, newArtistName);
    newSong.setArtist(newArtistName);

    cout << endl;

    cout << "The name of the song is " << newSong.getName() << endl;
    cout << "The name of the artist is " << newSong.getArtist() << endl;
    


}

/* SAMPLE OUTPUT
[vkeytiye@hills Module1]$ g++ module1.cpp 
[vkeytiye@hills Module1]$ ./a.out
Please enter the name of the song: Ring of Fire
Please enter the name of the artist: Johny Cash

The name of the song is Ring of Fire
The name of the artist is Johny Cash
[vkeytiye@hills Module1]$ 
*/