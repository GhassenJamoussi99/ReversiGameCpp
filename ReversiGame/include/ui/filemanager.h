#pragma once

class ReversiGame;

/**
 * \class FileManager
 * \brief Provides functionality for saving and reloading a Reversi game using text files.
 */
class FileManager
{
public: 
    /**
     * \brief Constructs a new FileManager object.
     */
    FileManager();

     /**
     * \brief Saves the current state of the game in a file.
     * 
     * \param game Pointer to the ReversiGame object representing the current state of the game.
     */
    void save(ReversiGame *game);

     /**
     * \brief Reloads the game from a saved state.
     * 
     * \param game Pointer to the ReversiGame object representing the current state of the game.
     */
    void reload(ReversiGame *game);
};
