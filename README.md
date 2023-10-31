LVGL demo
=========

Update git submodules and build using meson:
```
git submodule init
git submodule update
meson setup build
meson compile -C build
```

If everything is successful, a demo program will be generated in the
root build directory. Run it under a wayland compositor, e.g. using
[`cage`](https://github.com/cage-kiosk/cage):
```
cd build
cage ./lvgl-demo
```
