#include "Game.h"

namespace gamens {

void Game::proceed_game(bool isEnemyReady, int enemyChoice)
{
    if (isReady)
    {
        if (isEnemyReady)
        {
            if (compare_variants(enemyChoice))
            {
                resultText = "You won!";
                isReady = false;
                return;
            }
            else
            {
                resultText = "You lose";
                isReady = false;
                return;
            }
        }

        resultText = "Enemy is not ready yet";
    }
}

bool Game::compare_variants(int enemyChoice)
{
    if (chosenVariant == Variants::Rock)
    {
        switch (enemyChoice)
        {
        case 0: return false;
        case 1: return false;
        case 2: return true;
        }
    }

    if (chosenVariant == Variants::Paper)
    {
        switch (enemyChoice)
        {
        case 0: return true;
        case 1: return false;
        case 2: return false;
        }
    }

    if (chosenVariant == Variants::Scissors)
    {
        switch (enemyChoice)
        {
        case 0: return false;
        case 1: return true;
        case 2: return false;
        }
    }
    return false;
}

bool Game::get_is_ready()
{
    return isReady;
}

void Game::set_is_ready(bool isReady)
{
    this->isReady = isReady;
}

Variants Game::get_chosenVariant()
{
    return chosenVariant;
}

void Game::set_chosenVariant(Variants variant)
{
    if ((int) variant <= 2 and (int) variant >= 0)
    {
        chosenVariant = variant;
    }
}

QString Game::get_resultText()
{
    return resultText;
}

}
