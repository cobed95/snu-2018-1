#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

struct Coordinates {
    Coordinates(): x(0), y(0) {};
    Coordinates(int x, int y, int size): x(x), y(y), size(size) {};
    int x, y, size;
    
    Coordinates moved(int dx, int dy) {
        return Coordinates(x + dx, y + dy, size);
    }
};

std::ostream& operator<<(std::ostream &strm, const Coordinates& coordinates) {
    return strm << (coordinates.size * coordinates.x) + coordinates.y + 1;
}

struct Path {
    Path() {
        path = vector<Coordinates>();
    }

    Path(Coordinates starting_coordinates) {
        path = vector<Coordinates>();
        path.push_back(starting_coordinates);
    }

    vector<Coordinates> path;

    void append(Coordinates element) { path.push_back(element); }
};

std::ostream& operator<<(std::ostream &strm, const Path& path) {
    for (int i = 0; i <  path.path.size() - 1; i++) 
        strm << path.path[i] << "-";
    strm << path.path[path.path.size()-1];
    return strm;
}

struct MazeBlock {
    MazeBlock(): coordinates(Coordinates(0, 0, 0)), can_pass(false), size(0) {}

    MazeBlock(Coordinates coordinates, bool can_pass, int size): coordinates(coordinates), can_pass(can_pass), size(size) {};

    Coordinates coordinates;
    bool can_pass; 
    int size;
};

class Maze {
public:
    Maze(vector<vector<bool> > raw_grid, int size) {
        vector<vector<MazeBlock> > _blocks;
        for (int x = 0; x < size; x++) {
            vector<MazeBlock> block_line(0);
            for (int y = 0; y < size; y++)
                block_line.push_back(MazeBlock(Coordinates(x, y, size), raw_grid[x][y], size));
            _blocks.push_back(block_line);
        }

        this->blocks = _blocks;
        this->size = size;
    }

    int size;
    vector<vector<MazeBlock> > blocks;
};

class PathFinder {
private:
    Maze* maze;    
    Coordinates start, end;
    Path path;
    
    vector<vector<bool> > visited;
    vector<vector<Coordinates> > prev;
public:
    PathFinder(Maze* maze, Coordinates start, Coordinates end): 
        start(Coordinates(0, 0, maze->size)), end(Coordinates(0, 0, maze->size))
    {
        this->maze = maze;
        this->start = start;
        this->end = end;
    };

    void traverse() {
        vector<vector<bool> > _visited(maze->size, vector<bool>(maze->size, false));
        vector<vector<Coordinates> > _prev(maze->size, vector<Coordinates>(maze->size, Coordinates()));

        this->visited = _visited;
        this->prev = _prev;

        dfs(start); 
    }

    bool validate(Coordinates u) {
        return (0 <= u.x) && (u.x < maze->size) && (0 <= u.y) && (u.y < maze->size);
    }

    void dfs(Coordinates u) {
        visited[u.x][u.y] = true;

        for (int d = 0; d < 4; d++) {
            int _dx = dx[d];
            int _dy = dy[d];

            Coordinates v = u.moved(_dx, _dy);

            if (!validate(v) || visited[v.x][v.y] || !maze->blocks[v.x][v.y].can_pass) 
                continue;

            prev[v.x][v.y] = u;
            dfs(v);
        }
    }
    
    Path get_path()  {
        traverse();
        
        if (visited[end.x][end.y]) {
            vector<Coordinates> backtrace = vector<Coordinates>();
            Coordinates c = end;
            while (!(c.x == start.x && c.y == start.y)) {
                backtrace.push_back(c);
                c = prev[c.x][c.y];
            }
            backtrace.push_back(start);

            Path path = Path();
            for (int i = (int)backtrace.size() - 1; i >= 0; i--)
                path.append(backtrace[i]);

            return path;
        } else {
            return Path();
        }
    }
};

int main(int argc, char* argv[]) {
    ifstream fin(argv[1]);

    vector<vector<bool> > grid;
    string line;
    if (fin.is_open()) {
        while (getline(fin, line)) {
            istringstream sin(line);
            vector<bool> maze_line;

            int val;
            while (sin >> val) {
                maze_line.push_back(val ? true : false);
            }

            grid.push_back(maze_line);
        }
    }
    int size = grid.size();

    Maze* maze = new Maze(grid, size);
    PathFinder* path_finder = new PathFinder(maze, Coordinates(size - 1, 0, size), Coordinates(0, size - 1, size));
    Path path = path_finder->get_path();

    ofstream fout(argv[2]);
    if (fout.is_open()) {
        fout << path << endl;
    }
    return 0;
}
