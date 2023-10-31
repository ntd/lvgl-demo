#!/bin/sh

srcdir="$MESON_SOURCE_ROOT/libs/lv_drivers/wayland"
builddir="$MESON_BUILD_ROOT"

if test -d "$srcdir/protocols"
then
    # Protocols already generated
    exit 0
fi

cmake -S "$srcdir" -B "$builddir"
make -C "$builddir"
