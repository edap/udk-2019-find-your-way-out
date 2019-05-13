#pragma once

#include "ofMain.h"

// Exercise taken from Daniel Shiffman video https://www.youtube.com/watch?v=_p5IH0L63wo&t=231s

// TODO1 have a look at the wiki article. We did step 1 and 4
// 2 and 3 are missing.
// TODO1 add the remove walls method

// TODO2, eventually, after a while, the cursor stops because there are no cells
// around it that still need to be visit. How can we solve this problem? The solution
// is in the "backtrack" part of the name of this algorithm.
// The cursor need to keep track of where it has been previously so that it can
// go back to places that still have available cells to go(meaning not visited cells).
// Explain the term stack, make a parallel with an array, explain push_back and
// pop_back

class Cell{
public:
    Cell(){};
    Cell(int _i, int _j){
        i = _i; // col number
        j = _j; // row number

        walls = {true, true, true, true};

    };

    void draw(int w){
        ofPushStyle();
        ofSetColor(ofFloatColor::red);
        ofNoFill();

        auto x = i*w;
        auto y = j*w;
        if (walls[0]) {
            ofDrawLine(x  , y  , x+w, y);
        }
        if (walls[1]) {
            ofDrawLine(x+w, y  , x+w, y+w);
        }
        if (walls[2]) {
            ofDrawLine(x+w, y+w, x,   y+w);
        }
        if (walls[3]) {
            ofDrawLine(x  , y+w, x,   y+w);
        }

        ofPopStyle();

        if (visited) {
            ofPushStyle();
            ofSetColor(255,0,240,100);
            ofDrawRectangle(i*w, j*w, w, w);
            ofPopStyle();
        }
    };

    int getIndex(int _i, int _j, int w, int rows, int cols){
        if (_i > cols-1 || _j > rows-1 || _i < 0 || _j < 0) {
            return -1;
        }
        return _i+_j*cols;
    }

    int checkNeighBours(vector<Cell> grid, int w, int rows, int cols){
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

        if (neighbours.size() > 0) {
            int randomIndex = floor(ofRandom(0, neighbours.size()));
            return neighbours[randomIndex];
        } else {
            return -1;
        }
    }

	int checkNeighBoursBias(vector<Cell> grid, int w, int rows, int cols) {
		// horizontal bias
		vector<int> neighboursVert;
		vector<int> neighboursHor;

		int topIndex = getIndex(i, j - 1, w, rows, cols);
		int rightIndex = getIndex(i + 1, j, w, rows, cols);
		int bottomIndex = getIndex(i, j + 1, w, rows, cols);
		int leftIndex = getIndex(i - 1, j, w, rows, cols);

		if (topIndex >= 0 && grid[topIndex].visited == false) {
			neighboursVert.push_back(topIndex);
		}
		if (rightIndex >= 0 && grid[rightIndex].visited == false) {
			neighboursHor.push_back(rightIndex);
		}
		if (bottomIndex >= 0 && grid[bottomIndex].visited == false) {
			neighboursVert.push_back(bottomIndex);
		}
		if (leftIndex >= 0 && grid[leftIndex].visited == false) {
			neighboursHor.push_back(leftIndex);
		}

		int randomIndex;
		if (neighboursHor.size() > 0 && neighboursVert.size() > 0) {
			float random = ofRandom(0.0, 1.0f);
			float bias = 0.2f; // just 20 percent of probability to pick an horizontal neighbours
			if (random > bias) {
				randomIndex = floor(ofRandom(0, neighboursHor.size()));
				return neighboursHor[randomIndex];
			}
			else {
				randomIndex = floor(ofRandom(0, neighboursVert.size()));
				return neighboursVert[randomIndex];
			};
		}
		else if (neighboursHor.size() > 0) {
			randomIndex = floor(ofRandom(0, neighboursHor.size()));
			return neighboursHor[randomIndex];
		}
		else if (neighboursVert.size()) {
			randomIndex = floor(ofRandom(0, neighboursVert.size()));
			return neighboursVert[randomIndex];
		}
		else {
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

    // TODO2
    vector<int> stack;

    int current;
    // TODO1
    void removeWalls(int c, int n);
};
