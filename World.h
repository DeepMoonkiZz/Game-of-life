#include <iostream>
#include <eigen3/Eigen/Dense>
#include <string>

using namespace std;

class World {
    private:
        int _dimensionX;
        int _dimensionY;
        int _color;
        const string _file_path;
        Eigen::MatrixXi _world;
        Eigen::MatrixXi _nextgen_world;

    public:
        World(const string file_path);
        const Eigen::MatrixXi& getWorld() {return _world;};
        const int& getDimensionX() {return _dimensionX;};
        const int& getDimensionY() {return _dimensionY;};
        void apply_rule(int i,int j);
        void update_world();
        void create_world();
};