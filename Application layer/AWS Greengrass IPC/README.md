Use AWS IoT Device SDK for CPP v2

## Install AWS IoT Device SDK for C++

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
# Develop publish and subscribe components

Create 2 component's folders **gg_ipc_sub** and **gg_ipc_pub**, the working directory hierachy now will be:

```sh
├── aws-iot-device-sdk # This is sdk-library folder
|     ├── include
|     └── lib
├── gg_ipc_pub
|      ├── artifacts
|      │    └── gg_ipc_pub
|      │           └── 0.1.0
|      │               ├── gg_ipc_pub.cpp
|      │               └── CMakeLists.txt
|      └── recipes
|          └── gg_ipc_pub.json
├── gg_ipc_sub
|      ├── artifacts
|      │    └── gg_ipc_sub
|      │           └── 0.1.0
|      │               ├── gg_ipc_sub.cpp
|      │               └── CMakeLists.txt
|      └── recipes
|          └── gg_ipc_sub.json
└── sdk-ws
      ├── aws-iot-device-sdk-cpp-v2 # aws-iot-device-sdk-cpp-v2.git Github repo
      └── sdk-build
```
``CMakeLists.txt`` of each 2 components:
```cmake
cmake_minimum_required(VERSION 3.1)
project (<proj_name_also_the_binary_output>)

file(GLOB MAIN_SRC
        "*.h"
        "*.cpp"
        )
add_executable(${comp_name} ${MAIN_SRC})

set_target_properties(${comp_name} PROPERTIES
        LINKER_LANGUAGE CXX
        CXX_STANDARD 11)
find_package(aws-crt-cpp PATHS <path_to_the_sdk_library>)
find_package(EventstreamRpc-cpp PATHS <path_to_the_sdk_library>)
find_package(GreengrassIpc-cpp PATHS <path_to_the_sdk_library>)
target_link_libraries(${comp_name} AWS::GreengrassIpc-cpp)
```
Example of ``CMakeLists.txt`` for ``gg_ipc_sub`` component with ``<path_to_the_sdk_library>`` is ``/home/username/wip/aws-iot-device-sdk``:

```cmake
cmake_minimum_required(VERSION 3.1)
project (gg_ipc_pub)

file(GLOB MAIN_SRC
        "*.h"
        "*.cpp"
        )
add_executable(${PROJECT_NAME} ${MAIN_SRC})

set_target_properties(${PROJECT_NAME} PROPERTIES
        LINKER_LANGUAGE CXX
        CXX_STANDARD 11)
find_package(aws-crt-cpp PATHS /home/username/wip/aws-iot-device-sdk)
find_package(EventstreamRpc-cpp PATHS /home/username/wip/aws-iot-device-sdk)
find_package(GreengrassIpc-cpp PATHS /home/username/wip/aws-iot-device-sdk)
target_link_libraries(${PROJECT_NAME} AWS::GreengrassIpc-cpp)
```
As the source code is CPP, we must [avoid building source code in recipes script](https://github.com/TranPhucVinh/Linux-Shell/blob/master/Platforms%20interaction/AWS/Greengrass/C%20source%20code%20component.md#avoid-building-source-code-in-recipes-script) so we have to build them separately (inside the component ``artifacts`` folder) then run ``make`` to generate binary file, before deploying:

```sh
cmake -DCMAKE_PREFIX_PATH="<absolute path to sdk-library>" --build .
make
```
```sh
username@hostname:~/workspace/gg_ipc_pub/artifacts/gg_ipc_pub/0.1.0$ cmake -DCMAKE_PREFIX_PATH="/home/username/wip/aws-iot-device-sdk" --build .
username@hostname:~/workspace/gg_ipc_pub/artifacts/gg_ipc_pub/0.1.0$ make
```
# Deploy publish and subscribe components

To enable GG components to publish and subscribe IPC message, the recipes json file must have the **authorization policies** to support those features:

In the recipe file, in the object ``ComponentConfiguration`` -> ``DefaultConfiguration``, add the ``accessControl`` object. This will allow the component to communicate IPC

```json
"accessControl": {
    "aws.greengrass.ipc.pubsub": {
        "<comp_name>:pubsub:1": {
        "policyDescription": "Allows access to subscribe to test/topic.",
        "operations": [
            "aws.greengrass#SubscribeToTopic"
        ],
        "resources": [
            "<topic_string>"
        ]
        }
    }
}
```
There are two variables we need to fill in here
* ``<comp_name>``: component's name
* ``<topic_string>``: topic to subscribe or publish to

In ``operations`` field, we have ``"aws.greengrass#SubscribeToTopic"`` for subscribe component.

* [gg_ipc_sub.json](gg_ipc_sub.json) as gg_ipc_sub recipe
* [gg_ipc_pub.json](gg_ipc_pub.json) as gg_ipc_pub recipe

Source code:

* [gg_ipc_sub.cpp](gg_ipc_sub.cpp)
* [gg_ipc_pub.cpp](gg_ipc_pub.cpp)

Finally deploy those subscribe and publish components:

```sh
sudo /greengrass/v2/bin/greengrass-cli deployment create --recipeDir $(pwd)/recipes --artifactDir $(pwd)/artifacts --merge "gg_ipc_sub=0.1.0"
sudo /greengrass/v2/bin/greengrass-cli deployment create --recipeDir $(pwd)/recipes --artifactDir $(pwd)/artifacts --merge "gg_ipc_pub=0.1.0"
```

As ``gg_ipc_pub`` is deployed later to publish message to ``gg_ipc_sub``, ``gg_ipc_sub`` (with log ``/greengrass/v2/logs/gg_ipc_sub.log``) will be able to get the message ``Hello, World ! from gg_ipc_pub`` from ``gg_ipc_pub``

