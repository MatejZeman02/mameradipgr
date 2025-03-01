#include "pgr.h"
export module constants;

export constexpr int INITIAL_WIDTH = 1280; // 16*80
export constexpr int INITIAL_HEIGHT = 720; // 9*80
export constexpr char WINDOW_TITLE[] = "Tutorial Application";
export constexpr unsigned ESC = 27; // key value for 'escape'
export constexpr unsigned FPS = 60;
export constexpr unsigned MILISECONDS = 1000 / FPS; // for timer
