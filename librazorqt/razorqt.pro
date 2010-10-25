######################################################################
# Automatically generated by qmake (2.01a) Tue Oct 19 23:11:41 2010
######################################################################

TEMPLATE = lib

TARGET = razorqt

DEPENDPATH += . src
INCLUDEPATH += . src


headers_unix.files=src/*.h

 linux-g++ | linux-g++-32  | linux-g++-64{                                                                           
     message(Linux)                                                                                                  
     message(Installing in /usr/lib)                                                                                 
     target.path=/usr/lib/                                                                                           
     headers_unix.path=/usr/include/razorqt
 }                                                                                                                   
                                                                                                                     
freebsd-g++ | netbsd-g++ | openbsd-g++ {                                                                             
     message(*BSD)                                                                                                   
     message(Installing in /usr/local/lib)                                                                           
     target.path=/usr/local/lib/
     headers_unix.path=/usr/local/include/razorqt                                        
} 



QT += xml dbus
# Input
HEADERS += src/defs.h \
           src/readsettings.h \
           src/xdgautostart.h \
           src/xdgdesktopfile.h \
           src/xdgenv.h \
           src/xdgiconthemefile.h \
           src/xdgiconthememanager.h \
           src/xdgmanager.h \
           src/xdgmenu.h \
           src/xdgmenucross.h \
           src/xdgreader.h \
           src/xfitman.h
SOURCES += src/readsettings.cpp \
           src/xdgautostart.cpp \
           src/xdgdesktopfile.cpp \
           src/xdgenv.cpp \
           src/xdgiconthemefile.cpp \
           src/xdgiconthememanager.cpp \
           src/xdgmanager.cpp \
           src/xdgmenu.cpp \
           src/xdgmenucross.cpp \
           src/xdgreader.cpp \
           src/xfitman.cpp

INSTALLS+=target
INSTALLS+=headers_unix
