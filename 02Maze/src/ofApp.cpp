#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(5);
    cols = floor(ofGetWidth() / w);
    rows = ofGetHeight()/ w;

    for (int j = 0; j<rows; j++){
        for (int i = 0; i<cols; i++){
            auto c = Cell(i,j);
            grid.push_back(c);
        }
    }

    //TODO 3
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
    grid[current].visited = true;
    grid[current].highlight(w);

    int nextIndex = grid[current].checkNeighBours(grid, w, rows, cols);
    ofLog() << nextIndex;
    if (nextIndex >= 0) {
        grid[nextIndex].visited = true;
        current = nextIndex;
    }


}

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
