//This file is generated  by TESTONA
#include "placeholder_test.h"


TEST_F(PlaceholderTest, setupPlaceholderRules) {

    //Pairwise Combination Testcase 1
    {
       //set playerPiece
       char playerPiece = 'X';

       //set reversibaord
       ReversiBoard *reversiboard = NULL;

       //check whether the code exits due to invalid input
       bool execStatus = false;
       if (false == execStatus) {
            EXPECT_EXIT(placeholder_uut->setupPlaceholderRules(playerPiece, reversiboard), ::testing::ExitedWithCode(1),"");
       } else {
            placeholder_uut->setupPlaceholderRules(playerPiece, reversiboard);
       }
       
       //check whether a placeholder is set
       bool isPlaceholderSet = false;
       if (NULL != reversiboard){
            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 8; j++){
                    if ('+' == reversiboard->getBoardCell(i,j)){
                        isPlaceholderSet = true;
                        placeholder_uut->resetPlaceholderPlaces(reversiboard); 
                        break;
                    }
                }
            }
       }

       EXPECT_EQ(isPlaceholderSet, false);
    
    }


    //Pairwise Combination Testcase 2
    {
       //set playerPiece
       char playerPiece = 'W';

       //set reversibaord
       ReversiBoard *reversiboard = &emptyBoard;

       //check whether the code exits due to invalid input
       bool execStatus = true;
       if (false == execStatus) {
            EXPECT_EXIT(placeholder_uut->setupPlaceholderRules(playerPiece, reversiboard), ::testing::ExitedWithCode(1),"");
       } else {
            placeholder_uut->setupPlaceholderRules(playerPiece, reversiboard);
       }
       
       //check whether a placeholder is set
       bool isPlaceholderSet = false;
       if (NULL != reversiboard){
            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 8; j++){
                    if ('+' == reversiboard->getBoardCell(i,j)){
                        isPlaceholderSet = true;
                        placeholder_uut->resetPlaceholderPlaces(reversiboard); 
                        break;
                    }
                }
            }
       }

       EXPECT_EQ(isPlaceholderSet, false);
    
    }


    //Pairwise Combination Testcase 3
    {
       //set playerPiece
       char playerPiece = 'B';

       //set reversibaord
       ReversiBoard *reversiboard = &validBoard;

       //check whether the code exits due to invalid input
       bool execStatus = true;
       if (false == execStatus) {
            EXPECT_EXIT(placeholder_uut->setupPlaceholderRules(playerPiece, reversiboard), ::testing::ExitedWithCode(1),"");
       } else {
            placeholder_uut->setupPlaceholderRules(playerPiece, reversiboard);
       }
       
       //check whether a placeholder is set
       bool isPlaceholderSet = false;
       if (NULL != reversiboard){
            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 8; j++){
                    if ('+' == reversiboard->getBoardCell(i,j)){
                        isPlaceholderSet = true;
                        placeholder_uut->resetPlaceholderPlaces(reversiboard); 
                        break;
                    }
                }
            }
       }

       EXPECT_EQ(isPlaceholderSet, true);
    
    }


    //Pairwise Combination Testcase 4
    {
       //set playerPiece
       char playerPiece = 'X';

       //set reversibaord
       ReversiBoard *reversiboard = &validBoard;

       //check whether the code exits due to invalid input
       bool execStatus = false;
       if (false == execStatus) {
            EXPECT_EXIT(placeholder_uut->setupPlaceholderRules(playerPiece, reversiboard), ::testing::ExitedWithCode(1),"");
       } else {
            placeholder_uut->setupPlaceholderRules(playerPiece, reversiboard);
       }
       
       //check whether a placeholder is set
       bool isPlaceholderSet = false;
       if (NULL != reversiboard){
            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 8; j++){
                    if ('+' == reversiboard->getBoardCell(i,j)){
                        isPlaceholderSet = true;
                        placeholder_uut->resetPlaceholderPlaces(reversiboard); 
                        break;
                    }
                }
            }
       }

       EXPECT_EQ(isPlaceholderSet, false);
    
    }


    //Pairwise Combination Testcase 5
    {
       //set playerPiece
       char playerPiece = 'B';

       //set reversibaord
       ReversiBoard *reversiboard = NULL;

       //check whether the code exits due to invalid input
       bool execStatus = false;
       if (false == execStatus) {
            EXPECT_EXIT(placeholder_uut->setupPlaceholderRules(playerPiece, reversiboard), ::testing::ExitedWithCode(1),"");
       } else {
            placeholder_uut->setupPlaceholderRules(playerPiece, reversiboard);
       }
       
       //check whether a placeholder is set
       bool isPlaceholderSet = false;
       if (NULL != reversiboard){
            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 8; j++){
                    if ('+' == reversiboard->getBoardCell(i,j)){
                        isPlaceholderSet = true;
                        placeholder_uut->resetPlaceholderPlaces(reversiboard); 
                        break;
                    }
                }
            }
       }

       EXPECT_EQ(isPlaceholderSet, false);
    
    }


    //Pairwise Combination Testcase 6
    {
       //set playerPiece
       char playerPiece = 'X';

       //set reversibaord
       ReversiBoard *reversiboard = &emptyBoard;

       //check whether the code exits due to invalid input
       bool execStatus = false;
       if (false == execStatus) {
            EXPECT_EXIT(placeholder_uut->setupPlaceholderRules(playerPiece, reversiboard), ::testing::ExitedWithCode(1),"");
       } else {
            placeholder_uut->setupPlaceholderRules(playerPiece, reversiboard);
       }
       
       //check whether a placeholder is set
       bool isPlaceholderSet = false;
       if (NULL != reversiboard){
            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 8; j++){
                    if ('+' == reversiboard->getBoardCell(i,j)){
                        isPlaceholderSet = true;
                        placeholder_uut->resetPlaceholderPlaces(reversiboard); 
                        break;
                    }
                }
            }
       }

       EXPECT_EQ(isPlaceholderSet, false);
    
    }


    //Pairwise Combination Testcase 7
    {
       //set playerPiece
       char playerPiece = 'W';

       //set reversibaord
       ReversiBoard *reversiboard = NULL;

       //check whether the code exits due to invalid input
       bool execStatus = false;
       if (false == execStatus) {
            EXPECT_EXIT(placeholder_uut->setupPlaceholderRules(playerPiece, reversiboard), ::testing::ExitedWithCode(1),"");
       } else {
            placeholder_uut->setupPlaceholderRules(playerPiece, reversiboard);
       }
       
       //check whether a placeholder is set
       bool isPlaceholderSet = false;
       if (NULL != reversiboard){
            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 8; j++){
                    if ('+' == reversiboard->getBoardCell(i,j)){
                        isPlaceholderSet = true;
                        placeholder_uut->resetPlaceholderPlaces(reversiboard); 
                        break;
                    }
                }
            }
       }

       EXPECT_EQ(isPlaceholderSet, false);
    
    }


    //Pairwise Combination Testcase 8
    {
       //set playerPiece
       char playerPiece = 'W';

       //set reversibaord
       ReversiBoard *reversiboard = &validBoard;

       //check whether the code exits due to invalid input
       bool execStatus = true;
       if (false == execStatus) {
            EXPECT_EXIT(placeholder_uut->setupPlaceholderRules(playerPiece, reversiboard), ::testing::ExitedWithCode(1),"");
       } else {
            placeholder_uut->setupPlaceholderRules(playerPiece, reversiboard);
       }
       
       //check whether a placeholder is set
       bool isPlaceholderSet = false;
       if (NULL != reversiboard){
            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 8; j++){
                    if ('+' == reversiboard->getBoardCell(i,j)){
                        isPlaceholderSet = true;
                        placeholder_uut->resetPlaceholderPlaces(reversiboard); 
                        break;
                    }
                }
            }
       }

       EXPECT_EQ(isPlaceholderSet, true);
    
    }


    //Pairwise Combination Testcase 9
    {
       //set playerPiece
       char playerPiece = 'B';

       //set reversibaord
       ReversiBoard *reversiboard = &emptyBoard;

       //check whether the code exits due to invalid input
       bool execStatus = true;
       if (false == execStatus) {
            EXPECT_EXIT(placeholder_uut->setupPlaceholderRules(playerPiece, reversiboard), ::testing::ExitedWithCode(1),"");
       } else {
            placeholder_uut->setupPlaceholderRules(playerPiece, reversiboard);
       }
       
       //check whether a placeholder is set
       bool isPlaceholderSet = false;
       if (NULL != reversiboard){
            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 8; j++){
                    if ('+' == reversiboard->getBoardCell(i,j)){
                        isPlaceholderSet = true;
                        placeholder_uut->resetPlaceholderPlaces(reversiboard); 
                        break;
                    }
                }
            }
       }

       EXPECT_EQ(isPlaceholderSet, false);
    
    }



}

