#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    movie.load("jellyfishes.mov");
    movie.setLoopState(OF_LOOP_NORMAL);
    movie.play();
    videoPixels.allocate(videoWidth, videoHeight, OF_PIXELS_RGB);


    ofSetVerticalSync(true);



    // we're going to load a ton of points into an ofMesh
    mesh.setMode(OF_PRIMITIVE_POINTS);
    
    ofEnableDepthTest();
    glEnable(GL_POINT_SMOOTH); // use circular points instead of square points
    glPointSize(10); // make the points bigger
}

//--------------------------------------------------------------
void ofApp::update(){
    mesh.clear();
    movie.update();
    if (movie.isFrameNew()) {
        videoPixels = movie.getPixels();

        int skip = 4; // load a subset of the points
        int meshIndex = 0;
        for(int y = 0; y < videoHeight; y += skip) {
            for(int x = 0; x < videoWidth; x += skip) {

                ofColor col = videoPixels.getColor(x,y);

                float z = ofMap(col.b, 0, 255, -300, 300);
                col.a = 255;
                mesh.addColor(col);
                auto pos = glm::vec3(x, y, z);
                mesh.addVertex(pos);
            }
        }

        int slice = (mouseX < videoWidth) ? mouseX : videoWidth/2;

        for (int y=0; y<videoHeight; y++){
            auto midColumnColor = videoPixels.getColor(slice, y);

        }

    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    if (debug) {
        movie.draw(0,0);
    } else {
        ofBackgroundGradient(ofColor::gray, ofColor::black, OF_GRADIENT_CIRCULAR);

        // even points can overlap with each other, let's avoid that
        cam.begin();
        //ofScale(2, -2, 2); // flip the y axis and zoom in a bit
        //ofRotateYDeg(90);
        ofTranslate(-videoWidth / 2, -videoHeight / 2);
        mesh.draw();
        cam.end();
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
