#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    


    
    quadric = gluNewQuadric();
    gluQuadricTexture(quadric, GL_TRUE);
    gluQuadricNormals(quadric, GLU_SMOOTH);
   // gluQuadricOrientation(quadric, GLU_INSIDE);
    
    //allie tests
    gluQuadricDrawStyle(quadric, GLU_LINE);
    
    ofBackground(0);
    ofSetVerticalSync(true);
    ofDisableArbTex();
    
    camWidth 		= 1024;	// try to grab at this size.
	camHeight 		= 768;
    
//fingerMovie.loadMovie("fingers.mov");
//fingerMovie.play();
    
 //  img.loadImage("stair.png");
    vidGrabber.initGrabber(camWidth,camHeight);
   img.bind();
    
    ofEnableAlphaBlending();
    ofSetColor(255,100);
    
    //glEnable(GL_CULL_FACE);
    //glCullFace(GL_FRONT_AND_BACK);
    //glEnable(GL_DEPTH_TEST);
}



//--------------------------------------------------------------

void testApp::update() {
    vidGrabber.grabFrame();
    
    if (vidGrabber.isFrameNew()) {
        unsigned char * pixels = vidGrabber.getPixels();
        img.setFromPixels(pixels, camWidth, camHeight, OF_IMAGE_COLOR, true);
        img.update();
        img.bind();
    }
    
    
//    
//    for(int i=0; i<NBALLS; i++)
//    {
//        arcball3[i].update();
//    }
    
    
    
}



//--------------------------------------------------------------

void testApp::draw() {
    
  //  fingerMovie.update();
    
   //   fingerMovie.draw(20,20);
    

    
    
    ofPushStyle();
    ofTranslate(ofGetWidth()/4, ofGetHeight()/4);
    arcball.begin();
    
    for (int i=0; i<20; i+=2) {
        gluSphere(quadric, 400+i, 50, 50);
    }
    
     arcball.end();
     ofPopStyle();
    
    
    //second sphere
    ofPushStyle();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    arcball2.begin();
    
    for (int i=0; i<20; i+=2) {
        gluSphere(quadric, 300+i, 50, 50);
    }
    
    arcball2.end();
    ofPopStyle();
    
    
    //third sphere
    ofPushStyle();
    ofTranslate(ofGetWidth()/3, ofGetHeight()/4);
    arcball2.begin();
    
    for (int i=0; i<20; i+=2) {
        gluSphere(quadric, 150+i, 50, 50);
    }
    
    arcball2.end();
    ofPopStyle();
    
    arcball2.end();
    ofPopStyle();
    
    
    //fourth sphere
    ofPushStyle();
    ofTranslate(200, 200);
    arcball4.begin();
    
    for (int i=0; i<20; i+=2) {
        gluSphere(quadric, 150+i, 50, 50);
    }
    
    arcball4.end();
    ofPopStyle();
    
    
//    ofPushStyle();
//    
//    float mosaicStep = ofMap(mouseX, 0, ofGetWidth(), 1, 20, true);
//    float scale = ofMap(mouseY, 0, ofGetHeight(), 1, 5, true);
//    
//    for (float y = 0; y < vidGrabber.getHeight(); y += mosaicStep){
//        for (float x = 0; x < vidGrabber.getWidth(); x += mosaicStep){
//            ofColor myColor = vidGrabber.getPixelsRef().getColor(x, y);
//            ofSetColor(myColor);
//            //ofRect(x*scale, y*scale, mosaicStep*scale, mosaicStep*scale);
//            ofCircle(x*scale, y*scale, mosaicStep*scale, mosaicStep*scale);
//        }
//    }
//    ofPopStyle();
    

    
}

//-----------------------------------


void testApp::mouseDragged(int x, int y, int button)  {
    //change
    arcball2.actOnMouseDragged();
}


//-----------------------------------

