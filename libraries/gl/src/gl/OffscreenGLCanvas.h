//
//  OffscreenGLCanvas.h
//  interface/src/renderer
//
//  Created by Bradley Austin Davis on 2014/04/09.
//  Copyright 2015 High Fidelity, Inc.
//
//  Distributed under the Apache License, Version 2.0.
//  See the accompanying file LICENSE or http://www.apache.org/licenses/LICENSE-2.0.html
//
#pragma once
#ifndef hifi_OffscreenGLCanvas_h
#define hifi_OffscreenGLCanvas_h

#include <mutex>
#include <QObject>

class QOpenGLContext;
class QOffscreenSurface;
class QOpenGLDebugLogger;

class OffscreenGLCanvas : public QObject {
public:
    OffscreenGLCanvas();
    ~OffscreenGLCanvas();
    void create(QOpenGLContext* sharedContext = nullptr);
    bool makeCurrent();
    void doneCurrent();
    QOpenGLContext* getContext() {
        return _context;
    }
    QObject* getContextObject();
    
protected:
    std::once_flag _reportOnce;
    QOpenGLContext* _context;
    QOffscreenSurface* _offscreenSurface;
#ifdef DEBUG
    QOpenGLDebugLogger* _logger{ nullptr };
#endif

};

#endif // hifi_OffscreenGLCanvas_h
