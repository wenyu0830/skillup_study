//
//  ApplyEffect.h
//  teamLabCamera
//
//  Created by Kato Tetsuro on 12/08/01.
//
//

#pragma once

#include "EffectEventArgs.h"
#include "ResourceParams.h"
#include <ofThread.h>
#include <ofImage.h>

/*
 * 撮影後に一度だけかけるエフェクトのベースクラス
 * 処理はスレッドで行われるので、threadedFunctionをオーバーライドする
 * 処理が終わると非メインスレッドからEffectEventが飛ぶので、SceneLoadingは
 * updateなどのメインスレッド内の処理から、getResultImageを通じて画像を受け取る
 */

class AbstractPostEffect : public ofThread {
  protected:
    ofPixels kirinukiImage;
    ofPixels result;

    void notifySuccessEvent() {
        EffectEventArgs e;
        e.status = EffectEventArgs::SUCCESS;
        e.result = result;

        ofNotifyEvent(EffectEventArgs::effectEventDispatcher, e, this);
    }
    void notifyFailureEvent() {
        EffectEventArgs e;
        e.status = EffectEventArgs::FAILURE;
        ofNotifyEvent(EffectEventArgs::effectEventDispatcher, e, this);
    }

  public:
    explicit AbstractPostEffect(const std::map<std::string, std::string> &) {}
    virtual ~AbstractPostEffect() {}
    virtual void setup(ofPixelsRef image, bool mangaMode) {
        kirinukiImage = image;
    }
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void getResultImage(ofPixelsRef pixels) {
        if (lock()) {
            pixels = result;
            unlock();
        }
    };
};
