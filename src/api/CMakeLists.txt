FIND_PACKAGE(JSONCPP REQUIRED)
FIND_PACKAGE(JSONRPCCPP REQUIRED)
FIND_PACKAGE(CURL REQUIRED)

# Find header and source files
FILE(GLOB magiapi_header ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
FILE(GLOB magiapi_source ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

# Set target libraries
ADD_LIBRARY(magiapi SHARED ${magiapi_source})
ADD_LIBRARY(magiapi_static STATIC ${magiapi_source})

# Set output name of static library
SET_TARGET_PROPERTIES(magiapi_static PROPERTIES OUTPUT_NAME magiapi)

# Link the library with json-rpc-cpp libs
TARGET_LINK_LIBRARIES(magiapi
                        ${CURL_LIBRARY}
                        ${JSONCPP_LIBRARY}
                        jsonrpccpp-common
                        jsonrpccpp-client)

TARGET_LINK_LIBRARIES(magiapi_static
                        ${CURL_LIBRARY}
                        ${JSONCPP_LIBRARY}
                        jsonrpccpp-common
                        jsonrpccpp-client)

# Set version settings
SET(VERSION_STRING ${MAJOR_VERSION}.${MINOR_VERSION}.${PATCH_VERSION})
SET_TARGET_PROPERTIES(magiapi magiapi_static PROPERTIES
    VERSION "${VERSION_STRING}"
    SOVERSION "${SO_VERSION}")

# Install to appropriate destinations
INSTALL(FILES ${magiapi_header} DESTINATION include/magiapi)

INSTALL(TARGETS magiapi magiapi_static
            LIBRARY DESTINATION lib
            ARCHIVE DESTINATION lib)
