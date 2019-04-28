#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //ofSetFrameRate(5);
    cols = floor(ofGetWidth() / w);
    rows = ofGetHeight()/ w;

    for (int j = 0; j<rows; j++){
        for (int i = 0; i<cols; i++){
            auto c = Cell(i,j);
            grid.push_back(c);
        }
    }

    current = 0;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i<grid.size(); i++){
        grid[i].draw(w);
    }
    // step 1 alg. TODO1, read the alg and explain the 4 points.
    // https://en.wikipedia.org/wiki/Maze_generation_algorithm#Randomized_Depth-First_Search
    grid[current].visited = true;
    grid[current].highlight(w);

    int nextIndex = grid[current].checkNeighBours(grid, w, rows, cols);

    if (nextIndex >= 0) {
        grid[nextIndex].visited = true;

        // step 2
        // TODO2
        stack.push_back(current);

        // step 3
        removeWalls(current, nextIndex);

        // step 4
        current = nextIndex;
    }
    //TODO2
    // if nextIndex is less than 0, it means that the cursor does not
    // have free cells to visit, it means that we have to chek our stack.
    // we start from the last cell added in our stack, that will become our
    // new current cell, our new cursor.
    else if(stack.size() > 0){
        current = stack[stack.size()-1];
        stack.pop_back();
    }else{
        // all cells have been visited!
        ofLog() << "Done";
    }
}


// https://youtu.be/8Ju_uxJ9v44?t=273
// It takes two cells and it removes the wall between them
void ofApp::removeWalls(int _current,int _next){
    // this value is the difference between curr
    int x = grid[_current].i - grid[_next].i;

    // tho check if the two cells are adjacent, we confront
    // the i (col number) and y (row number). Is the difference is 1, or -1,
    // it means they are adjacent.

    //remove the vertical walls. the right one or the left one?
    // it depends on the x value
    if (x == 1) {
        // Why we remove two walls for each side? because there
        // is the wall of the cell current and the wall of the cell next.
        grid[_current].walls[3] = false;
        grid[_next].walls[1] = false;
    } else if(x == -1) {
        grid[_current].walls[1] = false;
        grid[_next].walls[3] = false;
    }

    int y = grid[_current].j - grid[_next].j;
    // remove the horizontal walls
    if (y == 1) {
        grid[_current].walls[0] = false;
        grid[_next].walls[2] = false;
    } else if(y == -1) {
        grid[_current].walls[2] = false;
        grid[_next].walls[0] = false;
    }
};

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
