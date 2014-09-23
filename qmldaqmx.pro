TEMPLATE = lib
TARGET = QmlDAQmx
QT += qml quick
CONFIG += qt plugin

TARGET = $$qtLibraryTarget($$TARGET)
uri = com.github.qmldaqmx

# Input
SOURCES += \
    qmldaqmx_plugin.cpp \
    qmldaqmx.cpp \
    aivoltagechan.cpp \
    sampleclock.cpp \
    digedgestarttrig.cpp \
    everynsamplesevent.cpp \
    readanalogf64.cpp \
    anlgedgestarttrig.cpp \
    digedgereftrig.cpp \
    anlgedgereftrig.cpp \
    aofuncgenchan.cpp \
    aovoltagechan.cpp \
    writeanalogf64.cpp \
    starttrigretriggerable.cpp \
    writeanalogscalarf64.cpp

HEADERS += \
    qmldaqmx_plugin.h \
    qmldaqmx.h \
    aivoltagechan.h \
    sampleclock.h \
    digedgestarttrig.h \
    everynsamplesevent.h \
    readanalogf64.h \
    anlgedgestarttrig.h \
    digedgereftrig.h \
    anlgedgereftrig.h \
    aofuncgenchan.h \
    aovoltagechan.h \
    writeanalogf64.h \
    starttrigretriggerable.h \
    writeanalogscalarf64.h

OTHER_FILES = qmldir

!equals(_PRO_FILE_PWD_, $$OUT_PWD) {
    copy_qmldir.target = $$OUT_PWD/qmldir
    copy_qmldir.depends = $$_PRO_FILE_PWD_/qmldir
    copy_qmldir.commands = $(COPY_FILE) \"$$replace(copy_qmldir.depends, /, $$QMAKE_DIR_SEP)\" \"$$replace(copy_qmldir.target, /, $$QMAKE_DIR_SEP)\"
    QMAKE_EXTRA_TARGETS += copy_qmldir
    PRE_TARGETDEPS += $$copy_qmldir.target
}

qmldir.files = qmldir
unix {
    installPath = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)
    qmldir.path = $$installPath
    target.path = $$installPath
    INSTALLS += target qmldir
}

#LIBS += $$quote(-Lc:/Program Files/IVI Foundation/VISA/Win64/Lib_x64/msc/) -lvisa32
#INCLUDEPATH += $$quote(C:/Program Files/IVI Foundation/VISA/Win64/Include)
#INCLUDEPATH += $$quote(c:/Program Files/IVI Foundation/VISA/Win64/Lib_x64/msc)
#DEPENDPATH += $$quote(c:/Program Files/IVI Foundation/VISA/Win64/Lib_x64/msc)

#C:\Program Files (x86)\National Instruments\Shared\ExternalCompilerSupport\C\include\NIDAQmx.h

LIBS += $$quote(-LC:/Program Files (x86)/National Instruments/Shared/ExternalCompilerSupport/C/lib64/msvc/) -lNIDAQmx
INCLUDEPATH += $$quote(C:/Program Files (x86)/National Instruments/Shared/ExternalCompilerSupport/C/include)
#INCLUDEPATH += $$quote(C:/Program Files (x86)/National Instruments/Shared/ExternalCompilerSupport/C/lib64/msvc)
DEPENDPATH += $$quote(C:/Program Files (x86)/National Instruments/Shared/ExternalCompilerSupport/C/lib64/msvc)

message(LIBSTR=$$LIBS)
message(INCPATH=$$INCLUDEPATH)
message(DEPPATH=$$DEPENDPATH)
