#include<iostream>
using namespace std;
//class singleton{
//protected:
//    singleton(){}
//    static singleton * instance;
//public:
//    static singleton *getInstance(){
//        if(instance == nullptr)
//            instance = new singleton();
//        return instance;
//    }
//};
//singleton * singleton::instance=nullptr;

template<typename T>
class singleton{
    private:
        singleton(){};
        ~singleton(){};
        static T* _instance;
    public:
        static T *instance(){
            if(nullptr == _instance)
                _instance=new T();
            return _instance;
        }
};
template<typename T>
T *singleton<T>::_instance =0;

class foo{
    public:
       void print(){
            cout<<"hello word!!"<<endl;
        }
};
int main()
{
    singleton<foo>::instance()->print();
    return 0;
}
