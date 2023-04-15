#include "World.h"
#include <eigen3/Eigen/Dense>
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h> 


using namespace std;

World::World(const string val_file_path):
    _file_path(val_file_path)
{}

void World::apply_rule(int i, int j)
{
    int nb_voisin(0);
    nb_voisin = 
    _world((i-1+_dimensionX)%_dimensionX, (j-1+_dimensionY)%_dimensionY) + 
    _world((i + _dimensionX)%_dimensionX, (j-1+_dimensionY)%_dimensionY) + 
    _world((i+1+_dimensionX)%_dimensionX, (j-1+_dimensionY)%_dimensionY) + 
    _world((i-1+_dimensionX)%_dimensionX, (j + _dimensionY)%_dimensionY) + 
    _world((i + _dimensionX)%_dimensionX, (j + _dimensionY)%_dimensionY) + 
    _world((i+1+_dimensionX)%_dimensionX, (j + _dimensionY)%_dimensionY) + 
    _world((i-1+_dimensionX)%_dimensionX, (j+1+_dimensionY)%_dimensionY) + 
    _world((i + _dimensionX)%_dimensionX, (j+1+_dimensionY)%_dimensionY) + 
    _world((i+1+_dimensionX)%_dimensionX, (j+1+_dimensionY)%_dimensionY) ;
    if (_world(i, j)==_color)
    {
        if ((nb_voisin/_color==3) || (nb_voisin/_color==4))
        {
            _nextgen_world(i, j) = _color;
        }
    }
    else if (nb_voisin/_color == 3)
    {
        _nextgen_world(i, j) = _color;
    }
}


void World::update_world()
{
    for (int i=0; i<_dimensionX; i++)
    {
        for (int j=0; j<_dimensionY; j++)
        {
            apply_rule(i, j);
        }
    }
    _world = _nextgen_world;
    _nextgen_world = _nextgen_world * 0;
}


void World::create_world()
{
    _color = 16777215;
    int num_ligne(0);
    ifstream fichier(_file_path);
    string ligne;
    if (fichier)
    {
        while (getline(fichier, ligne))
        {
            num_ligne += 1;
            _dimensionY = ligne.size();
            _world.conservativeResize(num_ligne, _dimensionY);
            for (int i=0; i<_dimensionY; i++)
            {
                if (ligne[i] == '1')
                {
                    _world(num_ligne - 1, i) = _color;
                }
                else
                {
                    _world(num_ligne - 1, i) = 0;
                }
            }
        }
        _dimensionX = num_ligne;
        _nextgen_world.resize(_dimensionX, _dimensionY);
        _nextgen_world = 0 * _nextgen_world;
    }
    else
    {
        cout << "Error with file" << endl;
    }
}