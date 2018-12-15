#include <iostream>
#include <type_traits>
#include <vector>
#include <experimental/type_traits>

template <typename T, typename =void>
struct has_size_type : std::false_type {};

template <typename T>
struct has_size_type<T, std::void_t<typename T::size_type>> : std::true_type {};

template <typename T>
using size_func = decltype(std::declval<T>().size());

template <typename T>
using has_size = std::experimental::is_detected<size_func, T>;

int main() {
    std::cout
        << std::boolalpha
        << has_size_type<std::vector<int>>::value << std::endl   // true
        << has_size_type<int>::value << std::endl                // false
        << has_size<std::vector<int>>::value << std::endl        // true
        << has_size<int>::value << std::endl;                    // false

    return 0;
}