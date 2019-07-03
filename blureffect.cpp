// 20190702

#include "blureffect.h"


//--------------------------------------------------------------
void blur_effect::setup(){
    ofSetFrameRate(60);
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    
    blur.setup(ofGetWidth(), ofGetHeight(), 32, .2, 1, 0.5);
    //fbo.allocate(ofGetWidth(), ofGetHeight(),GL_RGBA);
    //image.load("2018-12-18-17-26-09-613_user.png");
    ofLoadImage(kirinukiImage);
    ofImage bikers;
    bikers.setFromPixels( p );
}

void blur_effect::draw(){

    blur.begin();
    ofClear(255);
    image.draw(0,0);
    blur.end();
    blur.draw();
    
  
    
    //blur.draw();
}
