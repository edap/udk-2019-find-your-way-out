#pragma once

#include "ofMain.h"

// build a grid made out of cells
// draw the cell
// draw the walls
// The algorithm take the first top left cell and moves randomly, opening and closing walls and marking the cells as
// visited whenever it goes through

// let's start visiting the cells and moving randomly

class Cell{
public:
    Cell(){};
    Cell(int _i, int _j){
        i = _i;
        j = _j;

        walls = {true, true, true, true};

    };

    void draw(int w){
        ofPushStyle();
        ofSetColor(ofFloatColor::red);
        ofNoFill();
        //easy
        //ofDrawRectangle(i*w, j*w, w, w);

        // TODO 1 draw walls
//        auto x = i*w;
//        auto y = j*w;
//        ofDrawLine(x  , y  , x+w, y);
//        ofDrawLine(x+w, y  , x+w, y+w);
//        ofDrawLine(x+w, y+w, x,   y+w);
//        ofDrawLine(x  , y+w, x,   y+w);

        // TODO 2. Add walls variable and booleans
        auto x = i*w;
        auto y = j*w;
        if(walls[0]){
            ofDrawLine(x  , y  , x+w, y);
        }
        if(walls[1]){
            ofDrawLine(x+w, y  , x+w, y+w);
        }
        if(walls[2]){
            ofDrawLine(x+w, y+w, x,   y+w);
        }
        if(walls[3]){
            ofDrawLine(x  , y+w, x,   y+w);
        }

        // TODO 3
        // https://en.wikipedia.org/wiki/Maze_generation_algorithm#Randomized_Depth-First_Search
        // add visited member var
        // add current var to ofApp.h

        ofPopStyle();

        // TODO 3. Let's draw the visited cells.
        if(visited){
            ofPushStyle();
            ofSetColor(ofFloatColor::purple);
            ofDrawRectangle(i*w, j*w, w, w);
            ofPopStyle();
        }
    };

    int getIndex(int _i, int _j, int w, int rows, int cols){
        // what about the 4 cell on the edge of the grid?
        if (_i > cols-1 || _j > rows-1 || _i < 0 || _j < 0) {
            //return an invalid index
            return -1;
        }

        return _i+_j*cols;

    }

    int checkNeighBours(vector<Cell> grid, int w, int rows, int cols){
        // TODO 4 collect the neighbours cells already visited
        vector<int> neighbours;

        int topIndex = getIndex(i, j-1, w, rows, cols);
        int rightIndex = getIndex(i+1, j, w, rows, cols);
        int bottomIndex = getIndex(i, j+1, w, rows, cols);
        int leftIndex = getIndex(i-1, j, w, rows, cols);

        if (topIndex >=0 && grid[topIndex].visited == false) {
            neighbours.push_back(topIndex);
        }
        if (rightIndex >=0 && grid[rightIndex].visited == false) {
            neighbours.push_back(rightIndex);
        }
        if (bottomIndex >=0 && grid[bottomIndex].visited == false) {
            neighbours.push_back(bottomIndex);
        }
        if (leftIndex >=0 && grid[leftIndex].visited == false) {
            neighbours.push_back(leftIndex);
        }

        if(neighbours.size() > 0){
            int randomIndex = floor(ofRandom(0, neighbours.size()));
            return neighbours[randomIndex];
        }else{
            return -1;
        }
    }

    void highlight(int w){
        ofPushStyle();
        ofSetColor(ofFloatColor::yellow);
        ofDrawRectangle(i*w, j*w, w, w);
        ofPopStyle();
    }

    int i; // col number
    int j; // row number
    vector<bool> walls;
    bool visited = false;

};



class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

    int cols;
    int rows;

    int w = 40; // square width
    vector<Cell> grid;

    int current;
		
};
