#include <iostream>
#include <type_traits>
#include <utility>
#include <vector>

template <typename T>
struct has_size_type {
private:
    template <typename U>
    static auto test(int) -> decltype(std::declval<typename U::size_type>(), std::true_type());

    template <typename U>
    static auto test(...) -> decltype(std::false_type());

public:
    using type = decltype(test<T>(0));
    static constexpr bool value = type::value;
};

template <typename T>
struct has_size {
private:
    template <typename U>
    static auto test(int) -> decltype(std::declval<U>().size(), std::true_type());

    template <typename U>
    static auto test(...) -> decltype(std::false_type());

public:
    using type = decltype(test<T>(0));
    static constexpr bool value = type::value;
};


int main() {
    std::cout
        << std::boolalpha
        << has_size_type<std::vector<int>>::value << std::endl   // true
        << has_size_type<int>::value << std::endl                // false
        << has_size<std::vector<int>>::value << std::endl        // true
        << has_size<int>::value << std::endl;                    // false


    return 0;
}
