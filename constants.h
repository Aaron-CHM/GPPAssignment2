#ifndef _CONSTANTS_H            // prevent multiple definitions if this 
#define _CONSTANTS_H            // ..file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include <windows.h>



//-----------------------------------------------
// Useful macros
//-----------------------------------------------
// Safely delete pointer referenced item
#define SAFE_DELETE(ptr)       { if (ptr) { delete (ptr); (ptr)=NULL; } }
// Safely release pointer referenced item
#define SAFE_RELEASE(ptr)      { if(ptr) { (ptr)->Release(); (ptr)=NULL; } }
// Safely delete pointer referenced array
#define SAFE_DELETE_ARRAY(ptr) { if(ptr) { delete [](ptr); (ptr)=NULL; } }
#define SAFE_ON_LOST_DEVICE(ptr)    { if(ptr) { ptr->onLostDevice(); } }
// Safely call onResetDevice
#define SAFE_ON_RESET_DEVICE(ptr)   { if(ptr) { ptr->onResetDevice(); } }
#define TRANSCOLOR  SETCOLOR_ARGB(0,255,0,255)  // transparent color (magenta)

//-----------------------------------------------
//                  Constants
//-----------------------------------------------
// window
const char CLASS_NAME[] = "SpaceWar";
const char GAME_TITLE[] = "So-Lo Odyssey";
const bool FULLSCREEN = false;              // windowed or fullscreen
const UINT GAME_WIDTH = 852;               // width of game in pixels
const UINT GAME_HEIGHT = 480;               // height of game in pixels

// game
const double PI = 3.14159265;
const double NINETY_DEGREE_RAD = PI / 2 ;  // 90 degrees in radian
const float FRAME_RATE = 60.0f;               // the target frame rate (frames/sec)
const float MIN_FRAME_RATE = 10.0f;             // the minimum frame rate
const float MIN_FRAME_TIME = 1.0f / FRAME_RATE;   // minimum desired time for 1 frame
const float MAX_FRAME_TIME = 1.0f / MIN_FRAME_RATE; // maximum time used in calculations
const int MAX_PROJECTILES = 100;


// graphic images
const char NEBULA_IMAGE[] = "pictures\\orion.jpg";     // placeholder for background
const char TEXTURES_IMAGE[] = "pictures\\textures.png";  // placeholder for ship
//const char TEXTURES_IMAGE[] = "pictures\\PlayerShip_spritesheet.png";
const char ASTEROID_IMAGE[] = "pictures\\Asteroid.png";
const char BOSS_IMAGE[] = "pictures\\Boss.png";
const char ENEMYSHIP1_IMAGE[] = "pictures\\EnemyShip1.png";
const char ENEMYSHIP2_SMALL_IMAGE[] = "pictures\\EnemyShip2_small.png";
const char ENEMYSHIP2_LARGE_IMAGE[] = "pictures\\EnemyShip2_large.png";
const char ENEMYPROJECTILE1_IMAGE[] = "pictures\\enemyProjectile1.png";
const char ENEMYPROJECTILE2_IMAGE[] = "pictures\\enemyProjectile2.png";

// key mappings
const UCHAR ESC_KEY = VK_ESCAPE;   // Escape key
const UCHAR ALT_KEY = VK_MENU;     // Alt key
const UCHAR ENTER_KEY = VK_RETURN;   // Enter key

//const UCHAR SHIP1_LEFT_KEY = VK_LEFT; // Left Arrow key
//const UCHAR SHIP1_RIGHT_KEY = VK_RIGHT; // Right Arrow key
//const UCHAR SHIP1_UP_KEY = VK_UP; // Up Arrow key
//const UCHAR SHIP1_DOWN_KEY = VK_DOWN; // Down Arrow key

const UCHAR SHIP1_LEFT_KEY = 'A';
const UCHAR SHIP1_RIGHT_KEY = 'D';
const UCHAR SHIP1_UP_KEY = 'W';
const UCHAR SHIP1_DOWN_KEY = ' S';

#endif
