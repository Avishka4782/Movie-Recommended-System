#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#define NOMINMAX
#include <Windows.h>
#include "HashTable.h"

using namespace std;


void logoDisplay() {
    cout << "                                                         " << endl;
    cout << "                                                         " << endl;
    cout << " .d8888b.  d8b                   .d8888b.  d8b  .d888 888    " << endl;
    cout << "d88P  Y88b Y8P                  d88P  Y88b Y8P d88P\"  888    " << endl;
    cout << "888    888                      Y88b.          888    888    " << endl;
    cout << "888        888 88888b.   .d88b.  \"Y888b.   888 888888 888888 " << endl;
    cout << "888        888 888 \"88b d8P  Y8b    \"Y88b. 888 888    888    " << endl;
    cout << "888    888 888 888  888 88888888      \"888 888 888    888    " << endl;
    cout << "Y88b  d88P 888 888  888 Y8b.    Y88b  d88P 888 888    Y88b.  " << endl;
    cout << " \"Y8888P\"  888 888  888  \"Y8888  \"Y8888P\"  888 888     \"Y888 " << endl;
    cout << "                                                         " << endl;
    cout << "                                                         " << endl; 
}

vector<string> split(string inputString) {
    stringstream ss(inputString);
    vector<string> result;
    string substring;

    while (getline(ss, substring, ',')) {
        result.push_back(substring);
    }

    return result;
}

void readMovies(const string& filename, HashTable& ht) {
    ifstream file(filename);

    if (file.is_open()) {
        string line;
        vector<string> split_string; 
        while (getline(file, line)) {
            split_string = split(line);
            ht.insert(split_string[0], split_string[1], split_string[2], split_string[3], split_string[4], split_string[5]);
        }
    }
    else {
        cout << "Error Opening File." << endl;
    }
}

void animation() {
    system("cls");
    cout << "LOADING";
    for (int i = 0; i < 3; i++) {
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << ".";
    }
    system("cls");
}

int main()
{
    HashTable ht;
    readMovies("movies.txt", ht);
    logoDisplay();
    cout << "Press <ENTER> Key" << endl;
    cin.ignore();
    animation();
    cout << endl;
    cout << "=============================================================" << endl;
    cout << "||                   WELCOME TO CINESIFT                   ||" << endl;
    cout << "=============================================================" << endl;
    cout << "             - A MOVIE RECOMMENDATIOIN SYSTEM -              " << endl;
    cout << endl;
    cout << endl;


    int genre;
    string directorName;
    bool is_on = true;

    while (is_on) {
        cout << "                       --- MENU ---                          " << endl;
        cout << endl;
        cout << endl;
        cout << "1 - Find a Movie by Genre         2 - Find a Movie by Director" << endl;
        cout << endl;
        cout << "Please Select an Option (Enter the Number): ";
        int menuInput;
        cin >> menuInput;
        if (menuInput == 1) {
            system("cls");
            cout << "1 - Action    2 - Comedy    3 - Drama    4 - Sci-Fi    5 - Horror    6 - Romance" << endl;
            cout << "Please Select the Genre (Enter the Number): ";
            cin >> genre;
            cout << endl;
            cout << "Movie Director (Please type 'none' if you don't have any preference.): " << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, directorName);

            string Genre;
            switch (genre) {
            case 1:
                Genre = "Action";
                break;
            case 2:
                Genre = "Comedy";
                break;
            case 3:
                Genre = "Drama";
                break;
            case 4:
                Genre = "Sci-Fi";
                break;
            case 5:
                Genre = "Horror";
                break;
            case 6:
                Genre = "Romance";
                break;
            }
            animation(); 
            ht.searchByGenre(Genre, directorName); 
        }
        else if (menuInput == 2) {
            string directorName;
            cout << "Please Enter the Director's Name: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            getline(cin, directorName);
            animation();
            ht.searchByDirector(directorName);
        }
        else {
            system("cls");
            cout << "Invalid Input. Please Try Again!" << endl;
            continue;
        }
        
        cout << endl;
        cout << "Looking for More...?" << endl;
        cout << "Y - Yes    N - No" << endl;
        string continueVar;
        cin >> continueVar;
        cout << endl;
        if (continueVar == "N") {
            system("cls");
            cout << "Thank You for Using CineSift!" << endl;
            is_on = false;
        }
        else if (continueVar == "Y") {
            animation();
        }
    }
    
    /*
    cout << ht.getHash("Action")  << endl;
    cout << ht.getHash("Comedy")  << endl;
    cout << ht.getHash("Drama")   << endl;
    cout << ht.getHash("Sci-Fi")  << endl;
    cout << ht.getHash("Horror")  << endl;
    cout << ht.getHash("Romance") << endl;
    */
}