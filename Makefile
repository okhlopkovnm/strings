CC = gcc
CFLAGS = -Wall -I.
LDFLAGS = -lcheck -lsubunit -lm -lpthread -lrt
SRC_DIR = .
TEST_DIR = tests
OBJ_DIR = obj
LIB = $(SRC_DIR)/s21_string.a

SOURCES = $(filter-out $(SRC_DIR)/main.c, $(wildcard $(SRC_DIR)/*.c))
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
TEST_SOURCES = $(wildcard $(TEST_DIR)/*.c)
TEST_BINS = $(TEST_SOURCES:$(TEST_DIR)/%.c=$(OBJ_DIR)/%)

all: $(LIB) $(TEST_BINS)

$(LIB): $(OBJECTS)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%: $(TEST_DIR)/%.c $(LIB)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $< -o $@ $(LIB) $(LDFLAGS)

test: $(TEST_BINS)
	@for test in $(TEST_BINS); do ./$$test; done

clean:
	rm -rf $(OBJ_DIR)/*.o $(OBJ_DIR)/*test* $(LIB)

.PHONY: all test clean
