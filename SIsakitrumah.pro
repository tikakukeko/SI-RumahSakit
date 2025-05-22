QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aboutwindow.cpp \
    adminwindow.cpp \
    main.cpp \
    loginwindow.cpp \
    patientlist.cpp \
    userwindow.cpp

HEADERS += \
    aboutwindow.h \
    adminwindow.h \
    loginwindow.h \
    patientlist.h \
    userwindow.h

FORMS += \
    aboutwindow.ui \
    adminwindow.ui \
    loginwindow.ui \
    userwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc
