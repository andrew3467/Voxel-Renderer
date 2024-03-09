//
// Created by Andrew Graser on 2/8/2024.
//

#ifndef PEARL_EVENT_H
#define PEARL_EVENT_H

#include <string>
#include <functional>


#define BIT(x) (1 << x)


enum class EventType {
    None = 0,
    WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
    AppTick, AppUpdate, AppRender,
    KeyPressed, KeyReleased, KeyTyped,
    MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
};

enum EventCategory {
    None = 0,
    EventCategoryApplication = BIT(0),
    EventCategoryInput = BIT(1),
    EventCategoryKeyboard = BIT(2),
    EventCategoryMouse = BIT(3),
    EventCategoryMouseButton = BIT(4),
};

#define  EVENT_CLASS_TYPE(type) static EventType GetStaticType() {return EventType::type; } \
                                virtual EventType GetEventType() const override { return GetStaticType(); } \
                                virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }


class Event {
    friend class EventDispatcher;

public:
    virtual EventType GetEventType() const = 0;
    virtual const char* GetName() const = 0;
    virtual int GetCategoryFlags() const = 0;
    virtual std::string ToString() const { return GetName(); }

    inline bool IsInCategory(EventCategory category) {
        return GetCategoryFlags() & category;
    }

    bool Handled = false;
};

class EventDispatcher {
    template<typename T>
    using EventFn = std::function<bool(T&)>;

public:
    EventDispatcher(Event &event)
            : mEvent(event)
    {
    }

    template<typename T>
    bool Dispatch(EventFn<T> func){
        if(mEvent.GetEventType() == T::GetStaticType()){
            mEvent.Handled = func(static_cast<T&>(mEvent));
            return true;
        }

        return false;
    }

private:
    Event &mEvent;
};

inline std::ostream& operator<<(std::ostream& os, const Event& e){
    return os << e.ToString();
}

#endif //PEARL_EVENT_H
