#include <iostream>
#include <vector>

template <typename T>
struct has_size_type {
private:
    typedef short ok;
    typedef long ng;

    template <typename U>
    static ok test(typename U::size_type);

    template <typename U>
    static ng test(...);

public:
    static const bool value = sizeof(test<T>(0)) == sizeof(ok);
};

int main() {
    std::cout 
        << std::boolalpha
        << has_size_type<std::vector<int> >::value << std::endl  // true
        << has_size_type<int>::value << std::endl;               // false

    return 0;
}
