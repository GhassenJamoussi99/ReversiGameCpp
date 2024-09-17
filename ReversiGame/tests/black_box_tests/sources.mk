############################################################
####################  DIRECTORIES  #########################
############################################################

# Add your include paths to this variable
INCLUDE = placeholder_test/		\
		  ../../include/ 		\
		  ../../include/game 	\
		  ../../include/ui 		\
		  ../../include/players \
		  ../../external		\

INCLUDE_DIR = $(addprefix -I,$(INCLUDE))

# Add your source paths to this variable
SOURCE_DIR = . 					\
			 placeholder_test/	\
			 ../../src/game 	\
			 ../../src/ui 		\
			 ../../src/players	\


# Add your build path to this variable
BUILD_DIR = build
