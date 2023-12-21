AWS IoT Device SDK for C++ supports:
* Local components'communication by AWS GG IPC
* Components'communication through Internet by MQTT
# Install AWS IoT Device SDK for C++
Use AWS IoT Device SDK for CPP v2
```sh
# Create a workspace to hold all the component.
mkdir sdk-ws # SDK workspace
cd sdk-ws

# clone the repo sdk
git clone --recursive https://github.com/aws/aws-iot-device-sdk-cpp-v2.git

# Create a directory to hold the output build products
mkdir sdk-build
cd sdk-build

# Configure CMAKE before build
cmake -DCMAKE_INSTALL_PREFIX="<absolute path to sdk library>" -DCMAKE_BUILD_TYPE="Debug" ../aws-iot-device-sdk-cpp-v2
# The "<absolute path to sdk library>" is important, that will be the place for us to link to all the output libraries component

cmake --build . --target install
```
``sdk-library`` is the folder where the github repo ``aws-iot-device-sdk-cpp-v2`` are built into. This is an example of this path: ``/home/username/wip/aws-iot-device-sdk``

```sh
cmake -DCMAKE_INSTALL_PREFIX="/home/username/wip/aws-iot-device-sdk" -DCMAKE_BUILD_TYPE="Debug" ../aws-iot-device-sdk-cpp-v2
```

The ```<absolute path to sdk library>``` will contains two folders like this
```sh
$ ls
include  lib
```
Those 2 folders contain header files, and shared library files.

The working directory hierachy now will be:
```sh
├── aws-iot-device-sdk # This is sdk-library folder
|     ├── include
|     └── lib
└── sdk-ws
      ├── aws-iot-device-sdk-cpp-v2 # aws-iot-device-sdk-cpp-v2.git Github repo
      └── sdk-build
```
After successfully building the ``sdk-library`` folder (``aws-iot-device-sdk``), folder ``sdk-ws`` (included ``aws-iot-device-sdk-cpp-v2`` and ``sdk-build``) can be removed.
