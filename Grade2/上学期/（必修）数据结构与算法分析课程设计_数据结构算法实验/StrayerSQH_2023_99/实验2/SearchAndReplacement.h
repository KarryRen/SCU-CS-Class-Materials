#ifndef SEARCHANDREPLACEMENT_H
#define SEARCHANDREPLACEMENT_H

#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

class SearchAndReplacement {
private:
    string matchTxt;
    string originalTxt;
    int next[100000];

public:
    SearchAndReplacement() {};

    SearchAndReplacement(string m, string o) : matchTxt(m), originalTxt(o) {}

    void GetNext()
    {
        int j = 0;
        next[0] = 0;
        for (int i = 0; i < matchTxt.size(); i++)
        {
            while (j > 0 && matchTxt[i] != matchTxt[j])
            {
                j = next[j - 1];
            }

            if (matchTxt[i] == matchTxt[j])
            {
                j++;
            }
            next[i] = j;
        }
    }

    int Search()
    {
        GetNext();

        for (int i = 0, j = 0; i < originalTxt.size(); i++)
        {
            while (j > 0 && originalTxt[i] != matchTxt[j])
            {
                j = next[j - 1];
            }

            if (originalTxt[i] == matchTxt[j])
            {
                j++;
            }

            if (j == matchTxt.size())
            {
                j = next[j - 1];
                return i - matchTxt.size() + 1;
            }
        }

        return -1;
    }
};

#endif SEARCHANDREPLACEMENT_H