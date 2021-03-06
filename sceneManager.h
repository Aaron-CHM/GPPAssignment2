//  Module:             Gameplay Programming
//  Assignment2:        So-Lo Odyssey
//  Student Name:       Aaron Choo 
//  Student Number:     S10194746C

#ifndef _SCENEMANAGER_H             // prevent multiple definitions if this 
#define _SCENEMANAGER_H             // ..file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "soloOdyssey.h"
#include "game.h"
#include "textDX.h"


//=============================================================================
// Create game class 
//=============================================================================
class SceneManager : public Game //meant for managing between scenes 
{
protected:
    enum Scene
    {
        //menuScene,
        //optionsScene,
        //levelSelectScene,
        gameScene,
        //gameOverScene
    };


    Scene currentScene;
    //LevelSelect* levelSelect;
    //GameOver* gameOver;
    //Menu* menu;
    SoloOdyssey* soloOdyssey;
    TextDX* text;

public:
    // Constructor
    SceneManager();

    // Destructor
    virtual ~SceneManager();

    // Initialize the game
    void initialize(HWND hwnd);
    void update();
    void ai();
    void collisions();
    void render();
    void releaseAll();
    void resetAll();
    
};

#endif
