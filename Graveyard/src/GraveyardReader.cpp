#include "GraveyardReader.h"

GraveyardReader::GraveyardReader(string filename)
{
   this -> filename = filename;
}

void GraveyardReader::makeGraveyards()
{
    ifstream inputfile(filename.c_str());
    string currentLine;

    while(getline(inputfile, currentLine))
    {
        int height = 0;
        int width = 0;

        /// Make Graveyard
        stringstream widthHeight;
        widthHeight << currentLine;
        widthHeight >> width >> height;

        Graveyard thisGraveyard(width, height);


        /// Make Gravestones
        stringstream numOfGraves;
        numOfGraves << getline(inputfile, currentLine);
        int totalGraves = 0;
        numOfGraves >> totalGraves;

        for(int i = 0; i < totalGraves; i++)
        {
            stringstream graveCoordSS;
            graveCoordSS << getline(inputfile, currentLine);
            int graveX, graveY;
            graveCoordSS >> graveX >> graveY;



            ///Change that position to the gravestone
        }

        ///Make haunted holes
        stringstream numOfHoles;
        numOfHoles << getline(inputfile, currentLine);
        int totalHoles;
        numOfHoles >> totalHoles;

        for(int i = 0; i < totalHoles; i++)
        {
            stringstream holeData;
            holeData << getline(inputfile, currentLine);
            int holeX, holeY, warpX, warpY, timeWarp;
            holeData >> holeX >> holeY >> warpX >> warpY >> timeWarp;

            HauntedHole* thisHole = new HauntedHole(holeX, holeY, warpX, warpY, timeWarp);

            ///Change that position to the hole
        }

    }
}

vector<Graveyard> GraveyardReader::getGraveyards()
{
    return graveyards;
}
