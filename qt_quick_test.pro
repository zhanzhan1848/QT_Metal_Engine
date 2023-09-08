!macos:!ios: error("This project required macOS or iOS")

QT += quick qml widgets

CONFIG += qmltypes c++17
QML_IMPORT_NAME = MetalTextureImport
QML_IMPORT_MAJOR_VERSION = 1

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
HEADERS += metaltextureimport.h \
    logger.h
SOURCES += \
        logger.cpp \
        main.cpp \
        metaltextureimport.mm

RESOURCES += qml.qrc

LIBS += -framework Metal
macos: LIBS += -framework AppKit

# Default rules for deployment.
target.path = /User/imacb/Desktop/QT_Test/qt_quick_test
INSTALLS += target

DISTFILES += \
    CMakeLists.txt
