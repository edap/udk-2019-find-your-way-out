#include "ofMain.h"

class Cell {
public:
    int i;
    int j;
    std::vector<bool> walls {true, true, true, true};
    bool visited = false;

    Cell(){};

    void setup(int ii, int jj) {
        i = ii;
        j = jj;
    }

//    Cell checkNeighbors() {
//        std::vector<Cell> neighbors;
//
//        Cell top    = grid.at(index(i, j-1));
//        Cell right  = grid.at(index(i+1, j));
//        Cell bottom = grid.at(index(i, j+1));
//        Cell left   = grid.at(index(i-1, j));
//
//        if (top != nullptr && !top.visited) {
//            neighbors.push_back(top);
//        }
//        if (right != nullptr && !right.visited) {
//            neighbors.push_back(right);
//        }
//        if (bottom != nullptr && !bottom.visited) {
//            neighbors.push_back(bottom);
//        }
//        if (left != nullptr && !left.visited) {
//            neighbors.push_back(left);
//        }
//
//        if (neighbors.size() > 0) {
//            int r = floor(ofRandom(0, neighbors.size()));
//            return neighbors.at(r);
//        } else {
//            return null;
//        }
//    }
//
    void highlight(const int w) {
        int x = i*w;
        int y = j*w;
        //noStroke();
        ofFill();
        ofSetColor(0, 0, 255, 100);
        ofDrawRectangle(x, y, w, w);

    }

    void show(const int w) {
        int x = i*w;
        int y = j*w;
        ofPushStyle();
        ofSetColor(255);
        if (walls[0]) {
            ofDrawLine(x    , y    , x + w, y);
        }
        if (walls[1]) {
            ofDrawLine(x + w, y    , x + w, y + w);
        }
        if (walls[2]) {
            ofDrawLine(x + w, y + w, x    , y + w);
        }
        if (walls[3]) {
            ofDrawLine(x    , y + w, x    , y);
        }
        
        if (visited) {
            //ofNoStroke();
            ofSetColor(255, 0, 255, 100);
            ofDrawRectangle(x, y, w, w);
        }
        ofPopStyle();
    }
};
