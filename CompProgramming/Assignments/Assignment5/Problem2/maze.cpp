#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Point {
    public:
        Point(int label);
        Point(int x, int y);
        Point GetUpper() const;
        Point GetLower() const;
        Point GetLeft() const;
        Point GetRight() const;
        bool Equals(Point &other) const;
    private:
        int label;
        int X;
        int Y;
        Point *Prev;
};

class Maze {
    public:
        Maze(const vector<vector<int>> &rawMaze, const int Size);
        bool IsPath(Point &point);
        bool PathExists(Point &point);
        Point Move(const Point &point);
        string GetPath();
    private:
        int Size;
        vector<vector<int>> RawMaze;
};
