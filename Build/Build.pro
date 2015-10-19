#-------------------------------------------------
#
# Project created by QtCreator 2015-10-10T17:03:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Build
TEMPLATE = app

CONFIG += debug_and_release \
    c++11

CONFIG(release, debug|release) {
    LIBS += "../GameLib/release/libGameLib.a"
} else {
    LIBS += "../GameLib/debug/libGameLib.a"
}

INCLUDEPATH += "../GameLib"

unix {
    CONFIG(release, debug|release) {
	DESTDIR = "release"
    } else {
	DESTDIR = "debug"
    }
}

# Copying resource files to build directory
unix {
    BUILDDIR = "."
    EXTRA_BINFILES += \
	"$$PWD/Files"
    for (FILE, EXTRA_BINFILES) {
	QMAKE_POST_LINK += $$quote(cp $${FILE}/* -a $${BUILDDIR}$$escape_expand(\n\t))
    }
}

win32 {
    EXTRA_BINFILES += \
	"$$PWD/Files"
    EXTRA_BINFILES_WIN = $${EXTRA_BINFILES}
    EXTRA_BINFILES_WIN ~= s,/,\\,g
    DESTDIR_WIN = $${DESTDIR}
    DESTDIR_WIN ~= s,/,\\,g
    for(FILE,EXTRA_BINFILES_WIN) {
	QMAKE_POST_LINK += $$quote(cmd /c copy /y $${FILE} $${DESTDIR_WIN}$$escape_expand(\n\t))
    }
}

SOURCES += main.cpp
