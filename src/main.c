#include "lvgl/demos/widgets/lv_demo_widgets.h"
#include <unistd.h>


static lv_display_t *create_display(int32_t width, int32_t height)
{
    lv_display_t *disp = lv_x11_window_create("lvgl-demo window", width, height);
    /* Specifying NULL as `mouse_img` hides the cursor,
     * so passing a (somewhat) sensible prebuilt symbol instead */
    lv_x11_inputs_create(disp, (const void *) LV_SYMBOL_CLOSE);
    return disp;
}

int main(void)
{
    lv_init();
    create_display(640, 480);
    lv_demo_widgets();

    while (1) {
        lv_timer_handler();
        usleep(5000);
    }
}
