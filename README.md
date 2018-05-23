To compile using gcc use the following command:

```gcc `pkg-config --cflags gtk+-3.0` -o GTK3_TEST GTK3_TEST.cpp `pkg-config --libs gtk+-3.0` ```

To cmpile using cmake use the following commands:
```
cd build
cmake ..
make
```

To run program in linux use the following command:

`./GTK3_TEST`
