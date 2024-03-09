//
// Created by Andrew Graser on 2/8/2024.
//

#ifndef PEARL_MOUSEEVENT_H
#define PEARL_MOUSEEVENT_H

#include <sstream>
#include "Event.h"


class MouseMovedEvent : public Event {
public:
    MouseMovedEvent(float x, float y)
            : mMouseX(x), mMouseY(y) {

    }

    inline float GetX() const {return mMouseX;}
    inline float GetY() const {return mMouseY;}

    std::string ToString() const override {
        std::stringstream ss;
        ss << "MouseMovedEvent: " << mMouseX << ", " << mMouseY;
        return ss.str();
    }

    EVENT_CLASS_TYPE(MouseMoved)
    EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)


private:
    float mMouseX, mMouseY;
};

class MouseScrolledEvent : public Event {
public:
    MouseScrolledEvent(float xOffset, float yOffset)
            : mXOffset(xOffset), mYOffset(yOffset) {

    }

    inline float GetXOffset() const {return mXOffset;}
    inline float GetYOffset() const {return mYOffset;}

    std::string ToString() const override {
        std::stringstream ss;
        ss << "MouseScrolledEvent: ";
        return ss.str();
    }

    EVENT_CLASS_TYPE(MouseScrolled)

    EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

private:
    float mXOffset, mYOffset;
};

class MouseButtonEvent : public Event {
public:
    inline int GetMouseButton() const {return mButton;}

    EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

protected:
    MouseButtonEvent(int button)
            : mButton(button) {

    }

    int mButton;
};

class MouseButtonPressedEvent : public MouseButtonEvent {
public:
    MouseButtonPressedEvent(int button)
            : MouseButtonEvent(button) {

    }

    std::string ToString() const override {
        std::stringstream ss;
        ss << "MouseButtonPressedEvent: " << mButton;
        return ss.str();
    }

    EVENT_CLASS_TYPE(MouseButtonPressed)
};

class MouseButtonReleassedEvent : public MouseButtonEvent {
public:
    MouseButtonReleassedEvent(int button)
            : MouseButtonEvent(button) {

    }

    std::string ToString() const override {
        std::stringstream ss;
        ss << "MouseButtonReleassedEvent: " << mButton;
        return ss.str();
    }

    EVENT_CLASS_TYPE(MouseButtonReleased)
};


#endif //PEARL_MOUSEEVENT_H
