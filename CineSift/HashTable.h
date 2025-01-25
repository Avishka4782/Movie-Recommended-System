#include <iostream>
#include <list>
#include <sstream>
#include <vector>
#include <cctype>
#include "Movie.h"
#pragma once

using namespace std;

class HashTable
{
public:
	static const int size = 50;
	list<Movie> table[size];


	int getHash(string Genre) {
		int prime = 15;
		int hashValue = 1;

		for (char ch : Genre) {
			hashValue = (hashValue * prime) + static_cast<int>(ch);
		}
		return hashValue % size;
	}


	void insert(string Genre, string Title, string Year, string Director, string Streaming_Service, string Rating) {
		int index = getHash(Genre);
		Movie movie(Genre, Title, Year, Director, Streaming_Service, Rating);
		table[index].push_back(movie);
	}


	vector<string> splitBySpace(string inputString) {
		stringstream ss(inputString);
		vector<string> result;
		string substring;

		while (getline(ss, substring, ' ')) {
			result.push_back(substring);
		}

		return result;
	}


	string trimString(string str) {
		size_t first = str.find_first_not_of(" \t\n\r");
		size_t last = str.find_last_not_of(" \t\n\r");

		if (first == string::npos || last == string::npos) {
			// The string is entirely whitespace
			return "";
		}

		return str.substr(first, last - first + 1);
	}

	vector<string> removeMultipleValues(vector<string> inputResponse) {
		vector<string> returnResponse;
		int existTimes = 0;
		for (string item : inputResponse) {
			for (string existItem : returnResponse) {
				if (item == existItem) {
					existTimes++;
				}
			}
			if (existTimes == 0) {
				returnResponse.push_back(item);
			}
			existTimes = 0;
		}
		return returnResponse;
	}


	void searchByGenre(string Genre, string Director) {
		int index = getHash(Genre);
		list<Movie> selectedMovies;

		// Selecting Movies to Sort
		if (Director == "none") {
			for (Movie d : table[index]) {
				selectedMovies.push_back(d);
			}
		}
		else {
			for (Movie d : table[index]) {
				if (Director == trimString(d.Director)) {
					selectedMovies.push_back(d);
				}
			}
		}

		if (selectedMovies.size() == 0) {
			cout << "Oops! Movies Don't Exist" << endl;
		}
		else if (selectedMovies.size() == 1) {
			for (Movie movie : selectedMovies) {
				cout << "Title             : " << trimString(movie.Title) << endl;
				cout << "Release Year      : " << trimString(movie.Year) << endl;
				cout << "Genre             : " << trimString(movie.Genre) << endl;
				cout << "Movie Director    : " << trimString(movie.Director) << endl;
				cout << "Streaming Service : " << trimString(movie.Streaming_Service) << endl;
				cout << "IMDb Rating       : " << trimString(movie.Rating) << endl;
				cout << endl;
				cout << endl;
			}
		}
		else {
			string years = ""; 
			for (Movie movie : selectedMovies) { 
				years += movie.Year; 
			} 

			vector<string> result = splitBySpace(years); 

			// bubble sort
			for (int i = result.size() - 1; i > 0; i--) { 
				for (int j = 1; j < i; j++) { 
					int firstElem = stoi(result[j]); 
					int secElem = stoi(result[j + 1]); 
					if (firstElem < secElem) { 
						string temp = result[j]; 
						result[j] = result[j + 1]; 
						result[j + 1] = temp; 
					}
				}
			}

			vector<string> yearList = removeMultipleValues(result);

			for (string year : yearList) {
				for (Movie movie : selectedMovies) {
					if (year == trimString(movie.Year)) {
						cout << "Title             : " << trimString(movie.Title) << endl;
						cout << "Release Year      : " << trimString(movie.Year) << endl;
						cout << "Genre             : " << trimString(movie.Genre) << endl;
						cout << "Movie Director    : " << trimString(movie.Director) << endl;
						cout << "Streaming Service : " << trimString(movie.Streaming_Service) << endl;
						cout << "IMDb Rating       : " << trimString(movie.Rating) << endl;
						cout << endl;
						cout << endl;
					}
				}
			}
		}
	}

	void searchByDirector(string directorName) {
		vector<Movie> selectedMovies;
		for (int i = 0; i < size; i++) {
			for (Movie movie : table[i]) {
				if (directorName == trimString(movie.Director)) {
					selectedMovies.push_back(movie);
				}
			}
		}

		if (selectedMovies.size() == 0) {
			cout << "Oops! Movie Doesn't Extist" << endl;
		}
		else if (selectedMovies.size() == 1) {
			for (Movie movie : selectedMovies) {
				cout << "Title             : " << trimString(movie.Title) << endl;
				cout << "Release Year      : " << trimString(movie.Year) << endl;
				cout << "Genre             : " << trimString(movie.Genre) << endl;
				cout << "Movie Director    : " << trimString(movie.Director) << endl;
				cout << "Streaming Service : " << trimString(movie.Streaming_Service) << endl;
				cout << "IMDb Rating       : " << trimString(movie.Rating) << endl;
				cout << endl;
				cout << endl;
			}
		}
		else {
			string years = "";
			for (Movie movie : selectedMovies) {
				years += movie.Year;
			}

			vector<string> result = splitBySpace(years);

			// bubble sort
			for (int i = result.size() - 1; i > 0; i--) {
				for (int j = 1; j < i; j++) {
					int firstElem = stoi(result[j]);
					int secElem = stoi(result[j + 1]);
					if (firstElem < secElem) {
						string temp = result[j];
						result[j] = result[j + 1];
						result[j + 1] = temp;
					}
				}
			}

			vector<string> yearList = removeMultipleValues(result);
			for (string year : yearList) {
				for (Movie movie : selectedMovies) {
					if (year == trimString(movie.Year)) {
						cout << "Title             : " << trimString(movie.Title) << endl;
						cout << "Release Year      : " << trimString(movie.Year) << endl;
						cout << "Genre             : " << trimString(movie.Genre) << endl;
						cout << "Movie Director    : " << trimString(movie.Director) << endl;
						cout << "Streaming Service : " << trimString(movie.Streaming_Service) << endl;
						cout << "IMDb Rating       : " << trimString(movie.Rating) << endl;
						cout << endl;
						cout << endl;
					}
				}
			}
		}
	}
};

