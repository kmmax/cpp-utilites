#ifndef CALC_H
#define CALC_H

#include <vector>
#include <cstdint>
#include <iostream>
#include <algorithm>


using std::vector;
using std::uint16_t;
using std::cout;
using std::endl;



namespace Mb {


class Calc
{
public:
    using Ranges = vector<std::pair<uint16_t, uint16_t>>;
    using Numbers = vector<std::pair<std::uint16_t, std::uint8_t>>;
    Calc();
    static Ranges update_ranges(const Numbers& num, uint16_t max_size = 125) {
        Numbers v = num;
        std::sort(v.begin(), v.end(), std::greater<std::pair<uint16_t, uint16_t>>());

        vector<vector<uint16_t>> vglob;


        cout << "numbers[" << v.size() << "]: ";
        for (auto &v1: v) {
            cout << " " << v1.first;
        }
        cout << endl;


        while (!v.empty()) {
            vector<uint16_t> v_temp;
            auto min_addr = v.back().first;
            v.pop_back();
            v_temp.push_back(min_addr);

            while (!v.empty()) {
                auto elem = v.back();

                if (elem.first < (min_addr + max_size)) {
                    v_temp.push_back(elem.first);
                    v.pop_back();
                }
                else {
                    break;
                }
            }
            vglob.push_back(v_temp);
        }

        Ranges ranges;
        for (auto &range: vglob) {
            uint16_t min_value = *(std::min_element(range.begin(), range.end()));
            uint16_t max_value = *(std::max_element(range.begin(), range.end()));
            ranges.push_back(std::pair(min_value, max_value));
        }

        return ranges;
    };
};

}

inline std::ostream& operator<<(std::ostream &os, const Mb::Calc::Ranges& ranges) {
    os << "ranges[" << ranges.size() << "]:" << std::endl;
    for (auto &range: ranges) {
        os << "\t" << range.first << ", " << range.second << endl;
    }
    return os;
}

inline std::ostream& operator<<(std::ostream &os, const Mb::Calc::Numbers& numbers) {
    os << "numbers[" << numbers.size() << "]: ";
    for (auto &number: numbers) {
        os << " " << number.first << "[" << static_cast<uint16_t>(number.second) << "]";
    }
    os << endl;
    return os;
}

inline std::ostream& operator<<(std::ostream &os, const Mb::Calc& calc) {
    os << "this is calc";
    return os;
}

#endif // CALC_H
