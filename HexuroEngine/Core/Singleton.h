#ifndef _HEXURO_SINGLETON_
#define HEXURO_SINGLETON_

namespace Hexuro {
    class Singleton {
    public:
        Singleton(Singleton& rhs) = delete;
        void operator=(Singleton& rhs) = delete;
        static Singleton* GetInstance() {
            if (instancePtr == nullptr)
                    instancePtr = new Singleton();
            return instancePtr;
        }

    protected:
        Singleton() {}
        static Singleton* instancePtr;
    };

    Singleton* Singleton::instancePtr = nullptr;
}


#endif