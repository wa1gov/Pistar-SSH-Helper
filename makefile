# the compiler: gcc for C program, define as g++ for C++
  CC = c++

  # compiler flags:
  #  -g    adds debugging information to the executable file
  #  -Wall turns on most, but not all, compiler warnings
  #CFLAGS  = -std=c++0x -g -Wall
  CFLAGS  = -std=c++0x

  # the build target executable:
  TARGET = showlh

  all: $(TARGET)

  $(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp

  clean:
	$(RM) $(TARGET)
