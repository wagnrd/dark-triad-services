#ifndef DATABASE_API_SERVICE_HPP
#define DATABASE_API_SERVICE_HPP

template<class T>
class Service {
public:
    static T* get()
    {
        static T instance;
        return &instance;
    }
};

#endif //DATABASE_API_SERVICE_HPP
