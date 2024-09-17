############################################################
####################  DIRECTORIES  #########################
############################################################

# Add your include paths to this variable
INCLUDE = .

INCLUDE_DIR = $(addprefix -I,$(INCLUDE))

# Add your source paths to this variable
SOURCE_DIR = .

# Add your build path to this variable
BUILD_DIR = build