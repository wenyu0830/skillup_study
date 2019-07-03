//2019/0701


#pragma once

#include "AbstractPostEffect.h"
#include "ContrastAmplify.h"
#include <ofThread.h>
#include <ofImage.h>

#include "ofMain.h"
#include "ofShader.h"
#include "ofxBlur.h"

#define NUM 500
#define SIZE 10


class blur_effect: public AbstractPostEffect {
    public:
        void setup();
        void update();
        void draw();
    
        void keyPressed(int key);
        void keyReleased(int key);
        void mouseMoved(int x, int y );
        void mouseDragged(int x, int y, int button);
        void mousePressed(int x, int y, int button);
        void mouseReleased(int x, int y, int button);
        void mouseEntered(int x, int y);
        void mouseExited(int x, int y);
        void windowResized(int w, int h);
        void dragEvent(ofDragInfo dragInfo);
        void gotMessage(ofMessage msg);
    
    private:
        ofxBlur blur;
        ofFbo fbo;
        ofImage image;
        ofPixels kirinukiImage;
    
    

};
