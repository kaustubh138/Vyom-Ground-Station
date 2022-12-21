QT += quick core gui charts qml

SOURCES += \
        lib/src/Data.cpp \
        ui-qml/src/main.cpp


resources.files = ui-qml/views/main.qml
resources.prefix = /$${TARGET}
RESOURCES += resources \
    ui-qml/res.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += lib/public/

HEADERS += \
    lib/public/Data.hpp

DISTFILES += \
    .gitignore \
    ui-qml/views/main.qml
