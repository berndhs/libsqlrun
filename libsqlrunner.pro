TEMPLATE = lib
TARGET = sqlrunner
QT += core sql
MAKEFILE=Make_lib$${TARGET}

VERSION = 0.1.0

CONFIG += dll
CONFIG += qt thread

OBJECTS_DIR = tmp/obj
MOC_DIR = tmp/moc

HEADERS = \
  src/sql-runner.h \
  src/sql-run-query.h \
  src/sql-run-database.h \


SOURCES = \
   src/sql-runner.cpp \
   src/sql-run-query.cpp \
   src/sql-run-database.cpp \


DESTDIR=bin/
!include ("options.pri") {
  LIBDIR=lib64
  PREFIX=/home/bernd/local
} 
target.path = $${PREFIX}/$${LIBDIR}
devel_headers.files = $${HEADERS}
devel_headers.path = $${PREFIX}/include

INSTALLS += target devel_headers