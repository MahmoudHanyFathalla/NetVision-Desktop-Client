cmake_minimum_required(VERSION 3.5)

project(untitled VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools)

# Find libcurl
set(CURL_DIR "C:/Users/hp/Downloads/curl-8.5.0_4-win64-mingw/curl-8.5.0_4-win64-mingw")

set(OpenCV_DIR "C:/Users/hp/Downloads/OpenCV-MinGW-Build-OpenCV-4.5.2-x64/OpenCV-MinGW-Build-OpenCV-4.5.2-x64")  # Adjust this path to your OpenCV build directory

# Use OpenCVConfig.cmake directly
include("${OpenCV_DIR}/OpenCVConfig.cmake")
find_package(CURL REQUIRED)

set(TS_FILES untitled_en_US.ts)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    ${TS_FILES}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(untitled
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(untitled SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(untitled
            ${PROJECT_SOURCES}
        )
    endif()
    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

# Include libcurl headers
target_include_directories(untitled PRIVATE ${CURL_INCLUDE_DIRS})

# Link against libcurl
target_link_libraries(untitled PRIVATE Qt${QT_VERSION_MAJOR}::Widgets ${CURL_LIBRARIES})

target_include_directories(untitled PRIVATE
    "${OpenCV_DIR}/include"
)

# Link your target with the OpenCV libraries
target_link_libraries(untitled PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    opencv_core
    opencv_highgui
    opencv_imgcodecs
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.untitled)
endif()
set_target_properties(untitled PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS untitled
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(untitled)
endif()
