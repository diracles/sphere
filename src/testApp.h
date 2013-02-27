#pragma once

#include "ofMain.h"
#include "ofxArcBall.h"

#define NBALLS 5

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();


//		void keyPressed  (int key);
//		void keyReleased(int key);
//		void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
//		void mousePressed(int x, int y, int button);
//		void mouseReleased(int x, int y, int button);
//		void windowResized(int w, int h);
//		void dragEvent(ofDragInfo dragInfo);
//		void gotMessage(ofMessage msg);
    

 
        
        ofxArcBall arcball;
        ofxArcBall arcball2;
        ofxArcBall arcball4;
    
   // ofxArcBall arcball3[NBALLS];
    
    
        ofImage img;
       ofVideoGrabber vidGrabber;
        GLUquadricObj *quadric;
   int 				camWidth;
    int 				camHeight;
    ofVideoPlayer 		fingerMovie;
    
    
//private:
//    ofxArcBall  *myArc;
    
		
};
