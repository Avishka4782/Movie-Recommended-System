#include <iostream>
#pragma once

using namespace std;

class Movie
{
public:
	string Genre;
	string Title;
	string Year;
	string Director;
	string Streaming_Service;
	string Rating;

	Movie()
	{
		Genre = "";
		Title = "";
		Year = "";
		Director = "";
		Streaming_Service = "";
		Rating = "";
	}

	Movie(string g, string t, string y, string d, string s, string r)
	{
		Genre = g;
		Title = t;
		Year = y;
		Director = d;
		Streaming_Service = s;
		Rating = r;
	}


};

