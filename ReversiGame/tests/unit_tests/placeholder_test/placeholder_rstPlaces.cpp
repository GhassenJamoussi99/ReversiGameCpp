#include "placeholder_test.h"

TEST_F(PlaceholderTest, resetPlaceholderPlaces) {
  EXPECT_CALL(mockBoard, getBoardCell(_, _)).Times(64).WillRepeatedly(Return('+'));

   // Test case 1: reversiboard is NULL
  {
    EXPECT_EXIT(placeholder_uut->resetPlaceholderPlaces(NULL),
                ::testing::ExitedWithCode(1), 
                "");
  }
  
  //Testcase 2
  {
    EXPECT_CALL(mockBoard, setBoardCell(_, _, '-')).Times(64);

    placeholder_uut->resetPlaceholderPlaces(&mockBoard);
  }

  //Testcase 3
  {
    EXPECT_CALL(mockBoard, getBoardCell(_, _)).Times(64).WillRepeatedly(Return('-'));
    EXPECT_CALL(mockBoard, setBoardCell(_, _, '-')).Times(0);

    placeholder_uut->resetPlaceholderPlaces(&mockBoard);
  }

  // Verify that the mock objects were called as expected and then clear it
  testing::Mock::VerifyAndClearExpectations(&mockBoard);
}