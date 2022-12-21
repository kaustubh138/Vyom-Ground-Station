QT += quick core gui charts qml

SOURCES += \
        Data.cpp \
        main.cpp

resources.files = main.qml 
resources.prefix = /$${TARGET}
RESOURCES += resources \
    res.qrc

# build dir
BUILD_DIR = $$PWD/build

CONFIG(debug, debug|release) {
    DESTDIR = $$BUILD_DIR/bin/debug
}
CONFIG(release, debug|release) {
    DESTDIR = $$BUILD_DIR/bin/release
}

OBJECTS_DIR = $$BUILD_DIR/bin-int/.obj
MOC_DIR = $$DESTDIR/.moc
RCC_DIR = $$DESTDIR/.qrc
UI_DIR = $$DESTDIR/.u

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Data.hpp
