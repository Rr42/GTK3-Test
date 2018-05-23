Compile using gcc use the following comand: 
``` gcc `pkg-config --cflags gtk+-3.0` -o GTK3_TEST GTK3_TEST.cpp `pkg-config --libs gtk+-3.0` ```

Compile using cmake
```
cd build
cmake ..
make
```
