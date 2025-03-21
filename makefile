CC = gcc

CFLAGS = -c -Wall

SRC_DIR = src

ERR_DIR = $(SRC_DIR)/Error
TEST_DIR = tests
TEST_DIR_INT = $(TEST_DIR)/INT_tests
TEST_DIR_DOUBLE = $(TEST_DIR)/DOUBLE_tests
TEST_DIR_COMPLEX = $(TEST_DIR)/COMPLEX_tests
TYPE_DIR = $(SRC_DIR)/types
TYPE_DIR_INT = $(TYPE_DIR)/INT
TYPE_DIR_DOUBLE = $(TYPE_DIR)/DOUBLE
TYPE_DIR_COMPLEX = $(TYPE_DIR)/COMPLEX

SLAE_DIR = SLAE


TEST = $(TEST_DIR_INT)/INT_tests.c $(TEST_DIR_DOUBLE)/DOUBLE_tests.c $(TEST_DIR_COMPLEX)/COMPLEX_INT_tests.c $(TEST_DIR_COMPLEX)/COMPLEX_DOUBLE_tests.c
ERR = $(ERR_DIR)/error.c
TYPE = $(TYPE_DIR_INT)/INT.c $(TYPE_DIR_DOUBLE)/DOUBLE.c $(TYPE_DIR_COMPLEX)/COMPLEX_INT.c $(TYPE_DIR_COMPLEX)/COMPLEX_DOUBLE.c
LU = $(SLAE_DIR)/LU.c $(SLAE_DIR)/vector_column.c

SRC = $(SRC_DIR)/main.c $(SRC_DIR)/square_matrix.c $(ERR) $(TYPE)
OBJ=$(SRC:.c=.o)
TARGET = main

TEST_SRC = $(TEST_DIR)/tests.c $(SRC_DIR)/square_matrix.c $(ERR) $(TYPE) $(TEST)
TEST_OBJ = $(TEST_SRC:.c=.o)
TEST_TARGET = test

LU_SRC = $(SLAE_DIR)/LU_main.c $(LU) $(SRC_DIR)/square_matrix.c $(ERR) $(TYPE)
LU_OBJ = $(LU_SRC:.c=.o)
LU_TARGET = lu
	
$(TARGET): $(OBJ) 
	$(CC) $(OBJ) -o $(TARGET)

$(TEST_TARGET): $(TEST_OBJ) 
	$(CC) $(TEST_OBJ) -o $(TEST_TARGET)

$(LU_TARGET): $(LU_OBJ) 
	$(CC) $(LU_OBJ) -o $(LU_TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -f main
	rm -f test
	rm -f src/*.o
	rm -f src/*.out
	rm -f src/types/INT/*.o
	rm -f src/types/DOUBLE/*.o
	rm -f src/types/COMPLEX/*.o
	rm -f tests/*.o
	rm -f tests/INT_tests/*.o
	rm -f tests/DOUBLE_tests/*.o
	rm -f tests/COMPLEX_tests/*.o
	rm -f src/Error/*.o
	rm -f SLAE/*.o