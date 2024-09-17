//extern includes
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "log.h"
#include "macros.h"

//project includes
#include "placeholder.h"
#include "reversiboard.h"

using ::testing::_;
using ::testing::Return;

class PlaceholderTest: public ::testing::Test {
protected:
 virtual void SetUp() override {
	 placeholder_uut = new Placeholder();
 }

 virtual void TearDown() override
 {
    SAFE_DELETE(placeholder_uut);
 }

  Placeholder *placeholder_uut;

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

