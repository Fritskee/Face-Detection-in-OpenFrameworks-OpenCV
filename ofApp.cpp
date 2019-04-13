#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    vid.load("faceDetection.mov");
    vid.play();
    
    if(!face_cascade.load("/Users/frederikcalsius/Documents/OpenFrameworks/of_v20181102_osx_release/apps/myApps/A3_Question1/bin/data/haarcascade_frontalface_default.xml")){
        cout<<"Error loading face cascade"<<endl;
    }

    if(!eye_cascade.load("/Users/frederikcalsius/Documents/OpenFrameworks/of_v20181102_osx_release/apps/myApps/A3_Question1/bin/data/haarcascade_eye.xml")){
        cout<<"Error loading eye cascade"<<endl;
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    vid.update();
    vid.getCurrentFrame();
    if(vid.isFrameNew()){
        ofPixels pixs = vid.getPixels();
        vidFrame.setFromPixels(pixs);
        vidFrameMat = toCv(vidFrame);
        cvtColor(vidFrameMat, vidFrameMatGray, CV_BGR2GRAY);
        face_cascade.detectMultiScale(vidFrameMatGray, faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, cv::Size(200, 200));
        eye_cascade.detectMultiScale(vidFrameMatGray, eyes, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, cv::Size(30, 30));
        }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetBackgroundColor(255, 255, 255);
    drawMat(vidFrameMat, 0, 0);

    if(faces.size() > 0 && eyes.size() > 0)
    {
        for(int i = 0; i < faces.size(); i++){
            ofNoFill();
            ofDrawRectangle(faces.at(i).x, faces.at(i).y, faces.at(i).width, faces.at(i).height);
        }
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
