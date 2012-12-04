QT       +=  webkit svg network
SOURCES   =  wvc.cpp
HEADERS   =  wvc.hpp
CONFIG   +=  qt console

contains(CONFIG, static): {
  QTPLUGIN += qjpeg qgif qsvg qmng qico qtiff
  DEFINES  += STATIC_PLUGINS
}

