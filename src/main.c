#include "lv_drivers/wayland/wayland.h"
#include "lvgl/examples/lv_examples.h"

#include <errno.h>
#include <limits.h>
#include <poll.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

static bool loop = true;


static void *
tick_thread(void *data)
{
    while (loop) {
        usleep(5 * 1000);
        lv_tick_inc(5);
    }
    LV_LOG_WARN("Uscito!");
    return NULL;
}

static bool
on_close(lv_disp_t *disp)
{
    loop = false;
    return true;
}

int
main(int argc, char **argv)
{
    pthread_t ticker;
    lv_disp_t *disp;
    uint32_t time_till_next;

    LV_UNUSED(argc);
    LV_UNUSED(argv);

    lv_init();
    lv_wayland_init();

    disp = lv_wayland_create_window(LV_HOR_RES, LV_VER_RES,
                                    "LVGL demo", on_close);

    pthread_create(&ticker, NULL, tick_thread, NULL);

    /* Uncomment one example file */
    //lv_example_get_started_1();
    lv_example_arc_1();
    //lv_example_meter_3();

#if LV_WAYLAND_TIMER_HANDLER
    struct pollfd pfd;
    int timeout;

    pfd.fd = lv_wayland_get_fd();
    pfd.events = POLLIN;

    while (loop) {
        /* Handle any Wayland/LVGL timers/events */
        time_till_next = lv_wayland_timer_handler();

        /* Run until the last window closes */
        if (!lv_wayland_window_is_open(NULL)) {
            break;
        }

        /* Wait for something interesting to happen */
        if (time_till_next == LV_NO_TIMER_READY) {
            timeout = -1;
        } else if (time_till_next > INT_MAX) {
            timeout = INT_MAX;
        } else {
            timeout = time_till_next;
        }

        while ((poll(&pfd, 1, timeout) < 0) && (errno == EINTR));
    }
#else
    while (loop) {
        time_till_next = lv_timer_handler();
        usleep(time_till_next * 1000);
    }
#endif

    pthread_join(ticker, NULL);
    lv_disp_remove(disp);
    lv_wayland_deinit();
    lv_deinit();

    return 0;
}
