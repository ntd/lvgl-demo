#define _DEFAULT_SOURCE /* needed for usleep() */
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#include "lv_drivers/wayland/wayland.h"
#include "lvgl/examples/lv_examples.h"


static void *
tick_thread(void *data)
{
    (void) data;
    while (1) {
        usleep(5 * 1000);
        lv_tick_inc(5); /*Tell LittelvGL that 5 milliseconds were elapsed*/
    }
    return NULL;
}

int
main(int argc, char **argv)
{
    pthread_t thread1;
    lv_disp_t *disp;

    LV_UNUSED(argc);
    LV_UNUSED(argv);

    lv_init();
    lv_wayland_init();

    disp = lv_wayland_create_window(WAYLAND_HOR_RES, WAYLAND_VER_RES,
                                    WAYLAND_SURF_TITLE, NULL);
    LV_UNUSED(disp);

    pthread_create(&thread1, NULL, tick_thread, NULL);

    lv_example_get_started_1();

    while (1) {
        /* Periodically call the lv_task handler.
         * It could be done in a timer interrupt or an OS task too.*/
        lv_timer_handler();
        usleep(5 * 1000);
    }

    pthread_join(thread1, NULL);
    lv_wayland_deinit();
    lv_deinit();

    return 0;
}
