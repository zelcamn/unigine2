cmake_minimum_required(VERSION 3.16)

project(unigine2 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Network)

file(COPY "Qt6Core.dll" DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY "Qt6Network.dll" DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY "Qt6Widgets.dll" DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY "Qt6Gui.dll" DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY "platforms" DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

set(PROJECT_SOURCES
        main.cpp
        paperrockscissors.cpp
        paperrockscissors.h
        paperrockscissors.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(unigine2
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        Game.h
        Game.cpp
        connector.h connector.cpp
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET unigine2 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(unigine2 SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(unigine2
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(unigine2 PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Network)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.unigine2)
endif()
set_target_properties(unigine2 PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS unigine2
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(unigine2)
endif()
