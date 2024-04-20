#include "../lib/Game.h"

uint16_t Game::beginGame() {;
  interval = random(100, 500);
  return interval * 10;
}
