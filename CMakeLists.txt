cmake_minimum_required(VERSION 3.16)

project(book-management VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# Grouped sources
set(SOURCES
    Sources/main.cpp
    Sources/mainwindow.cpp
    Sources/addbox.cpp
    Sources/purchasebox.cpp
)

set(HEADERS
    Headers/mainwindow.h
    Headers/addbox.h
    Headers/purchasebox.h
)

set(FORMS
    Forms/mainwindow.ui
    Forms/addbox.ui
    Forms/purchasebox.ui
)

set(CMAKE_AUTOUIC_SEARCH_PATHS
    ${CMAKE_CURRENT_SOURCE_DIR}/Forms
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(book-management
        MANUAL_FINALIZATION
        ${SOURCES}
        ${HEADERS}
        ${FORMS}
    )
else()
    if(ANDROID)
        add_library(book-management SHARED
            ${SOURCES}
            ${HEADERS}
            ${FORMS}
        )
    else()
        add_executable(book-management
            ${SOURCES}
            ${HEADERS}
            ${FORMS}
        )
    endif()
endif()

target_include_directories(book-management
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/Headers
)

target_link_libraries(book-management PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.book-management)
endif()
set_target_properties(book-management PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS book-management
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(book-management)
endif()
