#include "World.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    string file_path("test.txt");
    World world(file_path);
    world.create_world();
    cout << world.getDimensionY() << " " << world.getDimensionX() << endl;
    cout << "#\n" << world.getWorld() << endl;
    for (int i = 0; i < atoi(argv[argc-1]) ; i++)
    {
        world.update_world();
        cout << "#\n" << world.getWorld() << endl;
    }

    return 0;
}