#include "../lib/Game.h"

void Game::beginGame() {
  randomTime = random(200, 1000);
  delay(randomTime * 10);
}