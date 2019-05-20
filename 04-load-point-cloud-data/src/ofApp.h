#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);

    ofxAssimpModelLoader model;
    ofEasyCam cam;

    ofMesh mesh;
    bool drawPointCloud = false;
    ofMaterial mat;
    ofLight light;
};
