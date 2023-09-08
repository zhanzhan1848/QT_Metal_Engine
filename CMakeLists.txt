cmake_minimum_required(VERSION 3.16)
project(metaltextureimport LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT DEFINED INSTALL_EXAMPLESDIR)
    set(INSTALL_EXAMPLESDIR "/Users/imacb/Desktop/QT_Test")
endif()

set(INSTALL_EXAMPLEDIR "${INSTALL_EXAMPLESDIR}/qt_quick_test")

find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick Widgets)

qt_add_executable(metaltextureimport
    main.cpp
    metaltextureimport.h metaltextureimport.mm
    logger.h logger.cpp
)

set_target_properties(metaltextureimport PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE

    # Prevent name clash with build subdirectory on case_insensitive file systems
    OUTPUT_NAME metaltextureimportapp
)

target_link_libraries(metaltextureimport PUBLIC
    "-framework Metal"

    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
    Qt6::Widgets
)

if(MACOS)
    target_link_libraries(metaltextureimport PUBLIC
        "-framework AppKit"
    )
endif()

qt_add_qml_module(metaltextureimport
    URI MetalTextureImport
    QML_FILES
        main.qml
        Logger.qml
    RESOURCES
        squircle.frag
        squircle.vert
    RESOURCE_PREFIX /scenegraph/metaltextureimport
    NO_RESOURCE_TARGET_PATH
)

install(TARGETS metaltextureimport
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)
