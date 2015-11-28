#include "Graveyard.h"

Graveyard::Graveyard(int width, int height)
{
    setWidth(width);
    setHeight(height);

    grid = new Tile*[width];
    for(int i = 0; i < width; i++)
    {
        grid[i] = new Tile[height];
    }
    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            grid[i][j] = new Tile(i,j);
        }
    }


    double** array = new double*[rowCnt];
for (int row = 0; row < rowCnt; ++row)
  array[row] = new double[colCnt];
for (int row = 0; row < rowCnt; ++row)
  for (int col = 0; col < colCnt; ++col)
    array[row][col] = 0;
}

int Graveyard::getWidth()
{
    return width;
}

void Graveyard::setWidth(int width)
{
    if(width >= 1)
    {
        this -> width = width;
    }
    else
    {
        cout << "Incorrect width" << endl;
    }
}


int Graveyard::getHeight()
{
    return height;
}

void Graveyard::setHeight(int height)
{
    if(height >= 1 && height <= 30)
    {
        this -> height = height;
    }
    else
    {
        cout << "Incorrect height" << endl;
    }

}


Tile** Graveyard::getGrid()
{
    return grid;
}
