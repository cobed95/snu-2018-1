import numpy as np;

def idxToCoordinate(idx, length):
    return [idx[1], length-idx[0]-1]

def coordinateToIdx(coordinate, rowCnt):
    return [length-coordinate[0]-1, coordinate[0]]

class Point:
    int x;
    int y;

    def __init__(self):
        self.x = 0;
        self.y = 0;

    def __init__(self, x, y):
        self.x = x;
        self.y = y;

    def equals(self, other):
        if type(other) == Point:
            return (self.x == other.x) && (self.y == other.y);
        else:
            return False;

    def get(self, direction):
        EAST  = 0; WEST  = 1;
        SOUTH = 2; NORTH = 3;
        if direction == EAST:
            return Point(self.x+1, self.y);
        elif direction == WEST:
            return Point(self.x-1, self.y);
        elif direction == SOUTH:
            return Point(self.x, self.y-1);
        elif direction == NORTH:
            return Point(self.x, self.y+1);

    def toString(self):
        return "(" + self.x + "," + self.y + ")";


class Position:
    Point point;
    bool isWall;

    def __init__(self, point, label):
        self.point = point;
        if label == 0:
            self.isWall = False;
        elif label == 1:
            self.isWall = True;


class Environment:
    np.array blueprint;
    Bot bot;

    def __init__(self):
        rowCnt = 0;
        colCnt = 0;
        with open('raw.txt') as raw:
            for line in raw:
                for char in line:
                    colCnt += 1;
                rowCnt += 1;

        with open('raw.txt') as raw:
            rowIdx = 0;
            for line in raw:
                colIdx = 0;
                for char in line:
                    coordinate = idxToCoordinate([rowIdx, colIdx], rowCnt);
                    self.blueprint[rowIdx].append(Position(Point(coordinate[0], coordinate[1]), char));

    def get(point):
        idx = coordinateToIdx([point.x, point.y]);
        return self.blueprint[idx[0]][idx[1]]


class Bot:
    Position current;

    def __init__(self, Position start):
        self.current = start;

    def move(self, direction):
        self.current = self.current.get(direction);
