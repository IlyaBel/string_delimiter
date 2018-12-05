#ifndef STRING_DELIMITER_H
#define STRING_DELIMITER_H

#include <string>
#include <sstream>
#include <numeric>
#include <functional>

template <class T>
std::string JoinLoop(T begin, T end, const std::string& delim){
    if (begin == end)
        return std::string{};
    else {
        T tmp = begin;
        std::stringstream result;
        while (tmp != end) {
            result << *tmp;
            if (++tmp != end)
                result << delim;
        }
        return result.str();
    }
}

template <class T>
std::string JoinFunc(T begin, T end, const std::string& delim){
    if (begin == end)
        return std::string{};
    else{
        std::stringstream result;
        std::accumulate(std::next(begin), end, std::ref(result << *begin),
            [&delim](std::ostream& stream, const auto& arg) -> std::ostream&
            {return  stream << delim << arg;});
        return result.str();
    }
}

#endif // STRING_DELIMITER_H
