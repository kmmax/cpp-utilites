#include <iostream>
#include <iomanip>
#include <string>

#include <boost/program_options.hpp>

#include "converter.h"


namespace po = boost::program_options;

using std::cout;
using std::endl;


int main(int argc, char** argv)
{
    po::options_description cmdline_options;
    po::options_description desc("Allowed options");

    int port;
    int length;
    std::string host = "localhost";
    uint16_t register_address;
    uint16_t slave;
    uint16_t number;

    desc.add_options()
        ("help", "produce help message")
        ("port,p", po::value<int>(&port)->default_value(10502), "tcp port (default 502)")
        ("length,l", po::value<int>(&length)->default_value(1), "number of registers (default 1)")
        ("address,a", po::value<uint16_t>(&register_address)->default_value(1), "register address")
        ("slave,s", po::value<uint16_t>(&slave)->default_value(255), "slave id")
        ("number,n", po::value<uint16_t>(&number)->default_value(1), "number")
        ("host", po::value<std::string>(), "host")
        ;
    cmdline_options.add(desc);

    po::positional_options_description p;
    p.add("host", -1);
    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv).options(cmdline_options).positional(p).run(), vm);
    po::notify(vm);

    if (vm.count("help") || vm.count("host") == 0) {
        std::cout << cmdline_options;
        return 0;
    }

    if (vm.count("host"))
        host = vm["host"].as<std::string>();

    namespace mc = max::convert;
    mc::bytes4 bytes;
    bytes[3] = 0x42;
    bytes[2] = 0xf6;
    bytes[1] = 0xcc;
    bytes[0] = 0xcd;
    float f1 = mc::to_float(bytes, mc::Direct);
    cout << f1 << endl;

    float f2 = mc::to_float(0x42, 0xf6, 0xcc, 0xcd, mc::Swap);
    cout << f2 << endl;

	return 0;

}
