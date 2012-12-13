#-------------------------------------------------
#
# Project created by QtCreator 2012-11-07T22:00:35
#
#-------------------------------------------------

QT       += core gui
QT       += opengl

TARGET = 3DGalactic
TEMPLATE = app


SOURCES +=\
    Core/core.cpp \
    Managers/Files/filemanager.cpp \
    Managers/Files/filedata.cpp \
    Managers/Files/file3d.cpp \
    Managers/Memory/memorymanager.cpp \
    Managers/Memory/memoryadder.cpp \
    Managers/Memory/memorydestroyer.cpp \
    Managers/Mode/modemanager.cpp \
    Managers/Mode/modechanger.cpp \
    Managers/Mode/modepreparer.cpp \
    Managers/ReMode/remodemanager.cpp \
    Managers/ReMode/retexturechanger.cpp \
    Models/AbstractModels/emptymodel.cpp \
    Models/AbstractModels/phisicalobject.cpp \
    Models/AbstractModels/spaceobject.cpp \
    Models/Texture/texturestar.cpp \
    Models/Fog/fog.cpp \
    Models/Spline/spline.cpp \
    Models/Factory/emptymodelfactory.cpp \
    Models/System/system.cpp \
    Models/Star/star.cpp \
    Models/Planet/planet3d.cpp \
    Models/Satellite/satallite.cpp \
    Models/Asteroid/asteroid.cpp \
    Managers/Mathematics/mathematicsmanager.cpp \
    Managers/Mathematics/formulla.cpp \
    Managers/Mathematics/modelingconfiguration.cpp \
    Managers/Mathematics/Creator/creatorobjects.cpp \
    Managers/Mathematics/Creator/creatorgalactic.cpp \
    Managers/Mathematics/Creator/creatorfrog.cpp \
    Managers/Mathematics/Creator/creatorsystem.cpp \
    Managers/Mathematics/Creator/creatorplanet.cpp \
    Managers/Draw/draw.cpp \
    Managers/Stream/streams.cpp \
    Managers/User/user.cpp \
    Managers/Memory/memorycollection.cpp \
    main.cpp \
    Managers/ReMode/remodelchanger.cpp \
    Models/Star/star3d.cpp \
    Managers/Draw/qopenglwidget.cpp \
    Managers/Draw/DrawTest.cpp

HEADERS  += \
    Core/core.h \
    Managers/Files/filemanager.h \
    Managers/Files/filedata.h \
    Managers/Files/file3d.h \
    Managers/Memory/memorymanager.h \
    Managers/Memory/memoryadder.h \
    Managers/Memory/memorydestroyer.h \
    Managers/Mode/modemanager.h \
    Managers/Mode/modechanger.h \
    Managers/Mode/modepreparer.h \
    Managers/ReMode/remodemanager.h \
    Managers/ReMode/retexturechanger.h \
    Models/AbstractModels/emptymodel.h \
    Models/AbstractModels/phisicalobject.h \
    Models/AbstractModels/spaceobject.h \
    Models/Texture/texturestar.h \
    Models/Fog/fog.h \
    Models/Spline/spline.h \
    Models/Factory/emptymodelfactory.h \
    Models/System/system.h \
    Models/Star/star.h \
    Models/Planet/planet3d.h \
    Models/Satellite/satallite.h \
    Models/Asteroid/asteroid.h \
    Managers/Mathematics/mathematicsmanager.h \
    Managers/Mathematics/formulla.h \
    Managers/Mathematics/modelingconfiguration.h \
    Managers/Mathematics/Creator/creatorobjects.h \
    Managers/Mathematics/Creator/creatorgalactic.h \
    Managers/Mathematics/Creator/creatorfrog.h \
    Managers/Mathematics/Creator/creatorsystem.h \
    Managers/Mathematics/Creator/creatorplanet.h \
    Managers/Draw/draw.h \
    Managers/Stream/streams.h \
    Managers/User/user.h \
    Models/ModelsLibrary.h \
    Managers/Memory/memorycollection.h \
    Managers/ReMode/remodelchanger.h \
    Models/Star/star3d.h \
    Managers/Draw/qopenglwidget.h \
    Managers/Draw/glext.h \
    Managers/ManagersLibrary.h

RESOURCES += \
    images.qrc
