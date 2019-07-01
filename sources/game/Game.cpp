#include "Game.hpp"

namespace fatanyu
{
    Game::Game()
    {
    }

    Game::~Game()
    {
    }

    BoardSize Game::giveMeBoardSizes()
    {
        BoardSize boardSize;
        while (!boardSize.hasValidSize())
        {
            std::cout << TextConstants::dashLine << std::endl;
            std::cout << "Give me Chessboard sizes\n";
            boardSize = Game::askForBoardSize();
        }
        return boardSize;
    }

    void Game::startGame()
    {
        const BoardSize boardSize = Game::giveMeBoardSizes();

        m_board = std::make_shared<Chessboard>(boardSize.getWidth(), boardSize.getHeight());

        // In case of fail, just reset and do it again
        // TODO random next step in case of multiple choices
        while (!m_board->warnsdorff())
        {
            m_board->reset();
        }

    }

    BoardSize Game::askForBoardSize()
    {
        BoardSize boardSize;
        boardSize.setWidth();
        boardSize.setHeight();
        boardSize.printSize();
        return boardSize;
    }
}