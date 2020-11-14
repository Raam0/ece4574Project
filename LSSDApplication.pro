QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    fooditems.cpp \
    main.cpp \
    lssdapplication.cpp \
    profile.cpp \
    workouts.cpp

HEADERS += \
    fooditems.h \
    lssdapplication.h \
    profile.h \
    workouts.h

FORMS += \
    lssdapplication.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Images.qrc

DISTFILES += \
    Images/apple.jpg \
    Images/bananas.jpg \
    Images/beans.jpg \
    Images/beef.jpg \
    Images/bread.jpg \
    Images/broccoli.jpg \
    Images/carrots.jpg \
    Images/chicken.jpg \
    Images/cycling.jpg \
    Images/dancing.jpg \
    Images/hiking.jpg \
    Images/pasta.jpg \
    Images/potatoes.jpg \
    Images/rice.jpg \
    Images/running.jpg \
    Images/seafood.jpg \
    Images/sports.jpg \
    Images/swimming.jpg \
    Images/walking.jpg \
    Images/weightlifting.jpg \
    Images/yoga.jpg
