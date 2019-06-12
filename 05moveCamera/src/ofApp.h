#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);

    float camAcceleration;
    float camVel;
    ofEasyCam came;
    ofLight light;
    ofCamera cam;
    ofPlanePrimitive plane;
    ofMaterial planeMaterial;
    ofMaterial cubeMaterial;
    vector<ofBoxPrimitive>cubes;

};
