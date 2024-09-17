#include <iostream>

#include "macros.h"
#include "globals.h"

int main()
{ 
    //setup logger for debugging
    LOGCFG.headers = true; 
    LOGCFG.ENABLE = true;
    LOGCFG.level = DEBUG;
    
    //start game
    LOG(INFO) << "Start game";
    ReversiGame *game = new ReversiGame();
    system("clear");
    game->startMenu(); //wenn man aktuell save_file111 lädt, wo isPlayerBlack=0 ist, dann ist das Spielfeld richtig, aber dann beim speichern mit save() wird bei isPlayerBlack() eine 1 zurückgegeben. variable playerblack muss irgendwo nochmal verändert werden, aber wo? BEHEBEN!
    SAFE_DELETE(game);
    return 0;
}


/* TODOs:
 * wenn man aktuell save_file111 lädt, wo isPlayerBlack=0 ist, dann ist das Spielfeld richtig, 
 * aber dann beim speichern mit save() wird bei isPlayerBlack() eine 1 zurückgegeben. 
 * variable playerblack muss irgendwo nochmal verändert werden, aber wo? BEHEBEN!
 * 
 * ADHOC test placeholders
 * 
 * 
 * 
 * Optional features to add later: Add disc counters for User/Computer
 *                                 Add an output, where the user/computer has placed his disc
 *                                 Add unique_ptrs
 * 
 * Start with unittests
 * 
 * 
 * Add if (user == null) when needed
 */