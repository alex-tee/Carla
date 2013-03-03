# QtCreator project file

QT = core gui xml

CONFIG    = debug link_pkgconfig qt warn_on
PKGCONFIG = jack liblo fluidsynth linuxsampler

TARGET   = carla-bridge-qtcreator
TEMPLATE = app
VERSION  = 0.5.0

# -----------------------------------------------------------

SOURCES = \
    ../CarlaBridgeClient.cpp \
    ../CarlaBridgeOsc.cpp \
    ../CarlaBridgePlugin.cpp

HEADERS = \
    ../CarlaBridge.hpp \
    ../CarlaBridgeClient.hpp \
    ../CarlaBridgeOsc.hpp

# -----------------------------------------------------------

# carla-engine
SOURCES += \
    ../../backend/engine/CarlaEngine.cpp \
    ../../backend/engine/CarlaEngineOsc.cpp \
    ../../backend/engine/CarlaEngineThread.cpp \
    ../../backend/engine/CarlaEngineJack.cpp \
    ../../backend/engine/CarlaEnginePlugin.cpp \
    ../../backend/engine/CarlaEngineRtAudio.cpp

# carla-plugin
SOURCES += \
    ../../backend/plugin/CarlaPlugin.cpp \
    ../../backend/plugin/CarlaPluginThread.cpp \
    ../../backend/plugin/BridgePlugin.cpp \
    ../../backend/plugin/NativePlugin.cpp \
    ../../backend/plugin/LadspaPlugin.cpp \
    ../../backend/plugin/DssiPlugin.cpp \
    ../../backend/plugin/Lv2Plugin.cpp \
    ../../backend/plugin/VstPlugin.cpp \
    ../../backend/plugin/FluidSynthPlugin.cpp \
    ../../backend/plugin/LinuxSamplerPlugin.cpp

# carla-standalone
SOURCES += \
    ../../backend/standalone/CarlaStandalone.cpp

# -----------------------------------------------------------

# common
HEADERS += \
    ../../backend/CarlaBackend.hpp \
    ../../backend/CarlaEngine.hpp \
    ../../backend/CarlaNative.h \
    ../../backend/CarlaNative.hpp \
    ../../backend/CarlaPlugin.hpp \
    ../../backend/CarlaStandalone.hpp

# engine
HEADERS += \
    ../../backend/engine/CarlaEngineInternal.hpp \
    ../../backend/engine/CarlaEngineOsc.hpp \
    ../../backend/engine/CarlaEngineThread.hpp \
    ../../backend/engine/distrho/DistrhoPluginInfo.h

# plugin
HEADERS += \
    ../../backend/plugin/CarlaPluginInternal.hpp \
    ../../backend/plugin/CarlaPluginThread.hpp

# includes
HEADERS += \
    ../../includes/CarlaDefines.hpp \
    ../../includes/CarlaMIDI.h \
    ../../includes/ladspa_rdf.hpp \
    ../../includes/lv2_rdf.hpp

# utils
HEADERS += \
    ../../utils/CarlaBackendUtils.hpp \
    ../../utils/CarlaJuceUtils.hpp \
    ../../utils/CarlaLadspaUtils.hpp \
    ../../utils/CarlaLibUtils.hpp \
    ../../utils/CarlaLv2Utils.hpp \
    ../../utils/CarlaOscUtils.hpp \
    ../../utils/CarlaStateUtils.hpp \
    ../../utils/CarlaVstUtils.hpp \
    ../../utils/CarlaUtils.hpp \
    ../../utils/CarlaMutex.hpp \
    ../../utils/CarlaString.hpp \
    ../../utils/CarlaThread.hpp \
    ../../utils/lv2_atom_queue.hpp \
    ../../utils/RtList.hpp

INCLUDEPATH = .. \
    ../../backend \
    ../../backend/engine \
    ../../backend/plugin \
    ../../backend/utils \
    ../../includes \
    ../../libs \
    ../../utils

# -----------------------------------------------------------

DEFINES  = QTCREATOR_TEST HAVE_CPP11_SUPPORT
DEFINES += DEBUG
#DEFINES += VESTIGE_HEADER
DEFINES += BUILD_BRIDGE BUILD_BRIDGE_PLUGIN BRIDGE_PLUGIN

DEFINES += WANT_JACK
DEFINES += WANT_NATIVE WANT_LADSPA WANT_DSSI WANT_LV2 WANT_VST
DEFINES += WANT_FLUIDSYNTH WANT_LINUXSAMPLER

LIBS     = -ldl \
    ../../libs/lilv.a \
    ../../libs/rtmempool.a

QMAKE_CXXFLAGS *= -std=c++0x
