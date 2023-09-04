#pragma once
#include <string>
#include <utility>

class MyClass {
public:
    MyClass(std::string str, int num) : m_str(std::move(str)), m_int(new int(num)) { }
    ~MyClass() { delete m_int; }

    static const std::string &getStringFromInstance(const MyClass &mc) { return mc.m_str; }

    void setInt(int val) { *m_int = val; }

    [[nodiscard]]
    int getInt() const { return *m_int; }

    void incInt() { *m_int += 1; }
private:
    std::string m_str;
    int *m_int;
};
