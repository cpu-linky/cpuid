SRC_FOLDER=src
BIN_FOLDER=bin

default: all

all: cpuid

# create bin folder if it doesn't exist
$(BIN_FOLDER):
	mkdir -p $(BIN_FOLDER)

cpuid: $(BIN_FOLDER)
	gcc -o $(BIN_FOLDER)/cpuid \
	$(SRC_FOLDER)/cpuid.c \
	$(SRC_FOLDER)/vendor/vendor.c \
	$(SRC_FOLDER)/features/features.c \
	$(SRC_FOLDER)/power/power.c

