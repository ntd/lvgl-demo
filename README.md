LVGL demo
=========

LVGL 9.2 widgets demo on X11: update submodules and build with meson.
```
git submodule init
git submodule update
meson setup build
meson compile -C build
./build/lvgl-demo
```
