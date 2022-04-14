#ifndef DARK_TRIAD_SERVICES_SERVICE_HPP
#define DARK_TRIAD_SERVICES_SERVICE_HPP

template<class T>
class Service {
public:
    static T* get()
    {
        static T instance;
        return &instance;
    }
};

#endif //DARK_TRIAD_SERVICES_SERVICE_HPP
