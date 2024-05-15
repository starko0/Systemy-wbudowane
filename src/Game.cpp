#include "../lib/Game.h"

uint16_t Game::beginGame() {
    ;
    interval = random(200, 700);
    return interval * 10;
}
