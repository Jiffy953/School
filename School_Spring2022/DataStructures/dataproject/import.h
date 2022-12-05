//
// Created by Jared See on 10/20/21.
//
/*
#ifndef DATAPROJECT_IMPORT_H
#define DATAPROJECT_IMPORT_H
#include<fstream>
#include <ios>
#include<iostream>
#include <vector>
#include <sstream>


using namespace std;

class import
{
    vector<string> row;
    string line, word, temp;

    void notimport()
    {
        fstream fin;
        fin.open("default.csv", ios::in);
        int uid, roll2, count = 0;
        cout << "Enter the uid "
             << "of the student to display details: ";
        cin >> uid;


        while (fin >> temp) {
            row.clear();
            std::getline(fin, line);
            stringstream s(line);

            roll2 = stoi(row[0]);
            if (roll2 == uid) {
                count = 1;
                cout << "Details of Roll " << row[0] << " : \n";
                cout << "Name: " << row[1] << "\n";
                cout << "Maths: " << row[2] << "\n";
                cout << "Physics: " << row[3] << "\n";
                cout << "Chemistry: " << row[4] << "\n";
                cout << "Biology: " << row[5] << "\n";
                break;
            }
        }
        if (count == 0)
            cout << "Record not found\n";
    }

    void getline()
    {
        while (getline(s, word, ', ')) {  //super broken need to figure out better implentation of this thing
            row.push_back(word);
        }
    }
};

#endif //DATAPROJECT_IMPORT_H
*/

