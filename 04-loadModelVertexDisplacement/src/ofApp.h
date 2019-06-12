#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#include "ofxGui.h"


class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    ofxAssimpModelLoader model;
    ofEasyCam cam;
    ofMesh mesh;

    // The light is set in the fragment shader
    ofShader shader;
    ofImage img;

    ofxPanel gui;
    ofParameter<float> magNoise = {"magNoise", .03, 0.01, 1.0};
    ofParameter<float> freqNoise = {"freqNoise", 0.1, 0.1, 1.0};

    bool usePoints = false;
};
