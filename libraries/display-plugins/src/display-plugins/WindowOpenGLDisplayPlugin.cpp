//
//  Created by Bradley Austin Davis on 2015/05/29
//  Copyright 2015 High Fidelity, Inc.
//
//  Distributed under the Apache License, Version 2.0.
//  See the accompanying file LICENSE or http://www.apache.org/licenses/LICENSE-2.0.html
//
#include "WindowOpenGLDisplayPlugin.h"

#include <gl/GLWidget.h>

#include "plugins/PluginContainer.h"

glm::uvec2 WindowOpenGLDisplayPlugin::getSurfacePixels() const {
    uvec2 result;
    if (_window) {
        result = toGlm(_window->geometry().size() * _window->devicePixelRatio());
    }
    return result;
}

glm::uvec2 WindowOpenGLDisplayPlugin::getSurfaceSize() const {
    uvec2 result;
    if (_window) {
        result = toGlm(_window->geometry().size());
    }
    return result;
}

bool WindowOpenGLDisplayPlugin::hasFocus() const {
    return _window ? _window->hasFocus() : false;
}

void WindowOpenGLDisplayPlugin::activate() {
    _window = _container->getPrimaryWidget();
    OpenGLDisplayPlugin::activate();
}

void WindowOpenGLDisplayPlugin::deactivate() {
    OpenGLDisplayPlugin::deactivate();
    _window = nullptr;
}

