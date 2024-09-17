//extern includes
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "log.h"
#include "macros.h"

//project includes
#include "discs.h"
#include "reversiboard.h"

using ::testing::_;
using ::testing::Return;

class DiscsTest: public ::testing::Test {
protected:
 virtual void SetUp() override {
	 discs_uut = new Discs();
 }

 virtual void TearDown() override
 {
    SAFE_DELETE(discs_uut);
 }

  Discs *discs_uut;

  //mockups
  ReversiBoard reversiboard;
};

// Template for comments
//       0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
// 0 A | - | - | - | - | - | - | - | - | 
// 1 B | - | - | - | - | - | - | - | - | 
// 2 C | - | - | - | + | - | - | - | - | 
// 3 D | - | - | + | B | W | - | - | - | 
// 4 E | - | - | - | W | B | + | - | - | 
// 5 F | - | - | - | - | + | - | - | - | 
// 6 G | - | - | - | - | - | - | - | - | 
// 7 H | - | - | - | - | - | - | - | - | 

