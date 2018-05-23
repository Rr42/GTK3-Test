Compile using gcc
gcc `pkg-config --cflags gtk+-3.0` -o example-0 example-0.c `pkg-config --libs gtk+-3.0`

Compile using cmake
cd build
cmake ..
make
