Magi API
===========

This is a C++ wrapper library for Magi JSON-RPC. It allows developers to communicate with the Magi daemon without the need to pack and unpack JSON-RPC messages.

Building the library
--------------------

**Dependencies**

Install [CMake](http://www.cmake.org/cmake/resources/software.html), [Curl](http://curl.haxx.se/libcurl/), [libjson-cpp](https://github.com/open-source-parsers/jsoncpp): 

```sh
sudo apt-get install cmake libcurl4-openssl-dev libjsoncpp-dev
```

Install [libjson-rpc-cpp](https://github.com/cinemast/libjson-rpc-cpp): 

```sh
sudo apt-get install libcurl4-openssl-dev libmicrohttpd-dev libjsoncpp-dev libargtable2-dev cmake
git clone git://github.com/cinemast/libjson-rpc-cpp.git
mkdir -p libjson-rpc-cpp/build
cd libjson-rpc-cpp/build
cmake .. && make
sudo make install
sudo ldconfig          #only required for linux
```

**Build and install**

Navigate to the root directory, and then:

```sh
mkdir build
cd build
cmake ..
make
sudo make install
```

Using the library
-----------------
**"example.cpp"**

```
#include <magiapi/magiapi.h>

int main()
{
    std::string username = "rpcuser";
    std::string password = "rpcpass";
    std::string address = "127.0.0.1";
    int port = 8232;

    /* Constructor to connect to the magi daemon */
    MagiAPI xmg(username, password, address, port);

    /* Example method - getbalance */
    std::cout << "Wallet balance: " << xmg.getbalance() << std::endl;
}
```

**Set library path**

```
LD_LIBRARY_PATH=/usr/local/lib
export LD_LIBRARY_PATH
```

**Compile**
```
g++ example.cpp -lmagiapi
```

License
-------

The magi-api-cpp library is released under the terms of [MIT](http://en.wikipedia.org/wiki/MIT_License).

Acknowledgements
----------------
The original C++ wrapper for JSON-RPC communication was coded by [bitcoinapi](https://github.com/mmgrant73/bitcoinapi) and [bitcoin-api-cpp](https://github.com/minium/bitcoin-api-cpp).
