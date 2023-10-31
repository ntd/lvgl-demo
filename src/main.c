#include "lv_drivers/wayland/wayland.h"
#include "lvgl/examples/lv_examples.h"

#include <unistd.h>


int
main(int argc, char **argv)
{
    lv_disp_t *disp;

    LV_UNUSED(argc);
    LV_UNUSED(argv);

    lv_init();
    lv_wayland_init();

    disp = lv_wayland_create_window(WAYLAND_HOR_RES, WAYLAND_VER_RES,
                                    WAYLAND_SURF_TITLE, NULL);
    LV_UNUSED(disp);

    lv_example_get_started_1();

    while (1) {
        lv_timer_handler();
        usleep(5 * 1000);
        lv_tick_inc(5);
    }

    lv_wayland_deinit();
    lv_deinit();

    return 0;
}
