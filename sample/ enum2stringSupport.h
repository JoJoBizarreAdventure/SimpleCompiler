#ifndef SIMPLECOMPILER_ENUM2STRINGSUPPORT_H
#define SIMPLECOMPILER_ENUM2STRINGSUPPORT_H

typedef std::function<std::string(int)> type2stringFunc;

template<typename T>
struct Type2StringSetter {
    explicit Type2StringSetter(const type2stringFunc &func);

    ~Type2StringSetter();
};


template<typename T>
Type2StringSetter<T>::Type2StringSetter(const type2stringFunc &func) {
    T::type2string = func;
}

template<typename T>
Type2StringSetter<T>::~Type2StringSetter() {
    T::type2string = nullptr;
}

template<typename T>
class Enum2stringSupport {
private:
    Type2StringSetter<T> setter;
public:
    explicit Enum2stringSupport(const type2stringFunc &func);
};

template<typename T>
Enum2stringSupport<T>::Enum2stringSupport(const type2stringFunc &func):setter(func) {}


#endif //SIMPLECOMPILER_ENUM2STRINGSUPPORT_H
