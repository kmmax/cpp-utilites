#ifndef CONVERTER_H
#define CONVERTER_H

#include <array>
#include <iostream>

namespace max
{
namespace convert
{
    enum Mode {
        Direct,
        Swap
    };

    using byte = char;
    using bytes2 = std::array<byte, 2>;
    using bytes4 = std::array<byte, 4>;
    using bytes8 = std::array<byte, 8>;



    inline float to_float(byte b[], int num, Mode mode = Mode::Direct)
    {
        int SIZE = 4;
        // Check num, it must be equal 4

        byte res_b[SIZE];
        switch (mode) {
        case Mode::Direct:
            res_b[0] = b[0];
            res_b[1] = b[1];
            res_b[2] = b[2];
            res_b[3] = b[3];
            break;
        case Mode::Swap:
            res_b[0] = b[3];
            res_b[1] = b[2];
            res_b[2] = b[1];
            res_b[3] = b[0];
            break;
        default:
            std::cout << "Error" << std::endl;
        }

        return *reinterpret_cast<float*>(res_b);
    }


    inline float to_float(byte b0, byte b1, byte b2, byte b3, Mode mode = Mode::Direct)
    {
        int SIZE = 4;

        byte temp_b[SIZE];
        temp_b[0] = b0;
        temp_b[1] = b1;
        temp_b[2] = b2;
        temp_b[3] = b3;
        float f = to_float(temp_b, SIZE, mode);
        return f;
    }


    inline float to_float(const std::array<byte, 4> bytes, Mode mode = Mode::Direct)
    {
        const int SIZE = 4;
        static_assert (SIZE == bytes.size(), "array must have size 4" );

        byte b[SIZE];
        b[0] = bytes.at(0);
        b[1] = bytes.at(1);
        b[2] = bytes.at(2);
        b[3] = bytes.at(3);
        float f = to_float(b, bytes.size(), mode);

        return f;
    }

}
}

#endif // CONVERTER_H
