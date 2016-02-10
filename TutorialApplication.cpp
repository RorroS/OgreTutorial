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

//-------------------------------------------------------------------------------------
TutorialApplication::TutorialApplication(void)
{
}
//-------------------------------------------------------------------------------------
TutorialApplication::~TutorialApplication(void)
{
}

//-------------------------------------------------------------------------------------
void TutorialApplication::createScene(void)
{
    Ogre::Entity* ninjaEntity = mSceneMgr->createEntity("ninja.mesh");
    ninjaEntity->setCastShadows(true);

    mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(ninjaEntity);

    Ogre::Plane plane(Ogre::Vector3::UNIT_Y, 0);

    Ogre::MeshManager::getSingleton().createPlane(
            "ground",
            Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
            plane,
            1500, 1500, 20, 20,
            true,
            1, 5, 5,
            Ogre::Vector3::UNIT_Z
    );

    Ogre::Entity* groundEntity = mSceneMgr->createEntity("ground");
    mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(groundEntity);

    groundEntity->setCastShadows(false);
    groundEntity->setMaterialName("Examples/Rockwall");

    Ogre::Light* light = mSceneMgr->createLight("ninjaLight");
    light->setDirection(-1,-1,0);
    light->setPosition(Ogre::Vector3(200,200,0));
    light->setDiffuseColour(0,0,1.0);
    light->setSpecularColour(0,0,1.0);
    light->setSpotlightRange(Ogre::Degree(90), Ogre::Degree(50));
    light->setType(Ogre::Light::LT_SPOTLIGHT);

    Ogre::Light* directionalLight = mSceneMgr->createLight("DirectionalLight");
    directionalLight->setType(Ogre::Light::LT_DIRECTIONAL);
    directionalLight->setDiffuseColour(.4,0,0);
    directionalLight->setSpecularColour(.4,0,0);
    //directionalLight->setPosition(500,500,100);
    directionalLight->setDirection(0,-1,1);

    Ogre::Light* grayLight = mSceneMgr->createLight("GrayLight");
    grayLight->setType(Ogre::Light::LT_POINT);
    grayLight->setDiffuseColour(.3,.3,.3);
    grayLight->setSpecularColour(.3,.3,.3);

    grayLight->setPosition(Ogre::Vector3(0,150,250));



    mSceneMgr->setAmbientLight(Ogre::ColourValue(0,0,0));
    mSceneMgr->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_ADDITIVE);

}

void TutorialApplication::createCamera() {
    mCamera = mSceneMgr->createCamera("playerCamera");
    mCamera->setPosition(Ogre::Vector3(0,300,500));
    mCamera->lookAt(Ogre::Vector3(0,0,0));
    mCamera->setNearClipDistance(5);
    mCameraMan = new OgreBites::SdkCameraMan(mCamera);
}

void TutorialApplication::createViewports() {
    Ogre::Viewport* vp = mWindow->addViewport(mCamera);
    vp->setBackgroundColour(Ogre::ColourValue(0,0,0));
    mCamera->setAspectRatio(
            Ogre::Real(vp->getActualWidth()) /
            Ogre::Real(vp->getActualHeight()));
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
