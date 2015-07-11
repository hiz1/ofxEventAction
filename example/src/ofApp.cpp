#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){
    chara.updateEvent();
}

//--------------------------------------------------------------
void ofApp::draw(){
    chara.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'a' || key == 'w' || key == 's' || key == 'd') {
        chara.repeatEvent(key);
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key == 'a' || key == 'w' || key == 's' || key == 'd') {
        chara.stopEvent(key);
    }
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
