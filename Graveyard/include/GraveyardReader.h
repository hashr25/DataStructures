#ifndef GRAVEYARDREADER_H
#define GRAVEYARDREADER_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include "Graveyard.h"

using namespace std;

class GraveyardReader
{
    public:
        GraveyardReader(string);

        void makeGraveyards();

        vector<Graveyard> getGraveyards();


    private:
        string filename;
        vector<Graveyard> graveyards;
};

#endif // GRAVEYARDREADER_H
