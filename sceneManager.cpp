
#include "sceneManager.h"

//=============================================================================
// Constructor
//=============================================================================
SceneManager::SceneManager()
{
    gameOver = new GameOver();
    levelSelect = new LevelSelect();
    menu = new Menu();
    soloOdyssey = new SoLoOdyssey();
    text = new TextDX();     // DirectX fonts
    currentScene = Scene::menuScene; //Set starting screen to be the current scene 



}

//=============================================================================
// Destructor
//=============================================================================
SceneManager::~SceneManager()
{
    releaseAll();           // call onLostDevice() for SceneManager graphics item

}

//=============================================================================
// Initializes the game
// Throws GameError on error
//=============================================================================
void SceneManager::initialize(HWND hwnd)
{

    //initialize main game
    Game::initialize(hwnd); // throws GameError

    if (text->initialize(graphics, 50, true, true, "Arial") == false)
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing DirectX font")); //initialize text for debugging purposes 


    soloOdyssey->initialize(graphics, this); //initialize different scenes
    //menu->initialize(graphics, this);
    //levelSelect->initialize(graphics, this);
    //gameOver->initialize(graphics, this);



}

//=============================================================================
// Update all game items
//=============================================================================
void SceneManager::update()
{
    switch (currentScene)
    {
    case SceneManager::menuScene:
        switch (menu->update(input))
        {
        case 1:
            currentScene = Scene::levelSelectScene;
            break;
        case 2:
            currentScene = Scene::optionsScene;
            break;
        case 3:
            exitGame();
            break;
        default:
            break;
        }
        break;
    case SceneManager::optionsScene:
        break;
    case SceneManager::levelSelectScene:
        switch (levelSelect->update(input))
        {
        case 1:
            soloOdyssey->setStage(SoLoOdyssey::Stage::level1);
            soloOdyssey->stage1Setup();
            currentScene = Scene::gameScene;
            break;
        case 2:
            soloOdyssey->setStage(SoLoOdyssey::Stage::level2);
            soloOdyssey->stage2Setup();
            currentScene = Scene::gameScene;
            break;
        case 3:
            soloOdyssey->setStage(SoLoOdyssey::Stage::level3);
            soloOdyssey->stage3Setup();
            currentScene = Scene::gameScene;
            break;
        default:
            break;
        }
        break;
    case SceneManager::gameScene:
        switch (soloOdyssey->update(frameTime))
        {
        case 1:
            gameOver->setGameOutcome(false);
            currentScene = Scene::gameOverScene;
            break;
        case 2:
            gameOver->setGameOutcome(true);
            currentScene = Scene::gameOverScene;
            break;
        default:
            break;
        }

        break;
    case SceneManager::gameOverScene:
        switch (gameOver->update(input))
        {
        case 1:
            currentScene = Scene::gameScene;
            break;
        case 2:
            currentScene = Scene::levelSelectScene;
            break;
        case 3:
            currentScene = Scene::menuScene;
            break;
        case 4:
            exitGame();
            break;
        };
        break;
    default:
        break;
    }



}

//=============================================================================
// Artificial Intelligence
//=============================================================================
void SceneManager::ai()
{}

//=============================================================================
// Handle collisions
//=============================================================================
void SceneManager::collisions()
{
    switch (currentScene)
    {
    case SceneManager::gameScene:
        soloOdyssey->collisions();
        break;
    }




}

//=============================================================================
// Render game items
//=============================================================================
void SceneManager::render()
{
    switch (currentScene)
    {
    case SceneManager::menuScene:
        menu->render();
        break;
    case SceneManager::optionsScene:
        break;
    case SceneManager::levelSelectScene:
        levelSelect->render();
        break;
    case SceneManager::gameScene:
        soloOdyssey->render();
        break;
    case SceneManager::gameOverScene:
        gameOver->render();
        break;
    default:
        break;
    }



}

//=============================================================================
// The graphics device was lost.
// Release all reserved video memory so graphics device may be reset.
//=============================================================================
void SceneManager::releaseAll()
{
    Game::releaseAll();
    return;
}

//=============================================================================
// The grahics device has been reset.
// Recreate all surfaces.
//=============================================================================
void SceneManager::resetAll()
{
    Game::resetAll();
    return;
}
