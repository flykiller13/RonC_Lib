
CC = gcc
CFLAGS = -g -O0

TARGET = tester
COMMON_SRC = ./programs/timefn.c \
			./programs/util.c \
			./lib/common/error_private.c \
			./lib/common/zstd_common.c \
			./lib/common/xxhash.c \
			./lib/common/pool.c \
			./lib/common/fse_decompress.c \
			./lib/common/entropy_common.c
COMMON_OBJ = $(patsubst %.c, %.o, $(COMMON_SRC))
ZSTD_OBJ = $(patsubst %.c, %.o, $(ZSTD_SRC))

INCLUDES = -I./programs -I./lib -I./lib/compress -I./lib/decompress  -I./lib/dictBuilder \
			-I./lib/common -I./contrib/seekable_format \


all: $(TARGET) 

# Main tester compilation
$(TARGET): $(COMMON_OBJ) $(ZSTD_OBJ) decodecorpus.c zstd_decompress.c
	$(CC) $(INCLUDES) $(COMMON_OBJ) $(ZSTD_OBJ) decodecorpus.c zstd_decompress.c -o $(TARGET) $(CFLAGS)

# Source file compilation recipes
$(COMMON_OBJ): $(COMMON_SRC)
$(ZSTD_OBJ): $(ZSTD_SRC)

# Rule for compiling source files
%.o: %.c
	$(CC) -c -o $@ $<

# Clean
clean:
	rm -f $(TARGET)
	rm -f $(ZSTD_OBJ)
	rm -f $(COMMON_OBJ)

#./contrib/seekable_format/zstdseek_compress.c 