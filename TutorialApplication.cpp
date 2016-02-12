/*
-----------------------------------------------------------------------------
Filename:    TutorialApplication.cpp
-----------------------------------------------------------------------------

This source file is part of the
   ___                 __    __ _ _    _ 
  /___\__ _ _ __ ___  / / /\ \ (_) | _(_)
 //  // _` | '__/ _ \ \ \/  \/ / | |/ / |
/ \_// (_| | | |  __/  \  /\  /| |   <| |
\___/ \__, |_|  \___|   \/  \/ |_|_|\_\_|
      |___/                              
      Tutorial Framework
      http://www.ogre3d.org/tikiwiki/
-----------------------------------------------------------------------------
*/
#include "TutorialApplication.h"

TutorialApplication::TutorialApplication()
        : mTerrainGroup(0),
          mTerrainGlobals(0),
          mInfoLabel(0)
{
}

TutorialApplication::~TutorialApplication()
{
}

void TutorialApplication::createScene() {

}

void TutorialApplication::createFrameListener() {
    BaseApplication::createFrameListener();
}

void TutorialApplication::destroyScene() {
}

bool TutorialApplication::frameRenderingQueued(const Ogre::FrameEvent& fe) {
    bool ret = BaseApplication::frameRenderingQueued(fe);

    return ret;
}

void getTerrainImage(bool flipX, bool flipY, Ogre::Image& img) {
}

void TutorialApplication::defineTerrain(long x, long y) {
}

void TutorialApplication::initBlendMaps(Ogre::Terrain* terrain) {
}

void TutorialApplication::configureTerrainDefaults(Ogre::Light* light) {
}

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
    INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT )
#else
    int main(int argc, char *argv[])
#endif
    {
        // Create application object
        TutorialApplication app;

        try {
            app.go();
        } catch( Ogre::Exception& e ) {
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
            MessageBox( NULL, e.getFullDescription().c_str(), "An exception has occured!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
            std::cerr << "An exception has occured: " <<
                e.getFullDescription().c_str() << std::endl;
#endif
        }

        return 0;
    }

#ifdef __cplusplus
}
#endif
