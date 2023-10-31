project('lvgl-demo', 'c',
    meson_version: '>=0.53.0',
    version:       '0.0.1',
    license:       'GPL-2.0-only'
)

# Hack to be able to generate protocols inside the `lv_drivers` project
run_command('libs/update-protocols.sh', check: true)

lvgl_sources = [
    'libs/lvgl/src/core/lv_disp.c',
    'libs/lvgl/src/core/lv_event.c',
    'libs/lvgl/src/core/lv_group.c',
    'libs/lvgl/src/core/lv_indev.c',
    'libs/lvgl/src/core/lv_indev_scroll.c',
    'libs/lvgl/src/core/lv_obj.c',
    'libs/lvgl/src/core/lv_obj_class.c',
    'libs/lvgl/src/core/lv_obj_draw.c',
    'libs/lvgl/src/core/lv_obj_pos.c',
    'libs/lvgl/src/core/lv_obj_scroll.c',
    'libs/lvgl/src/core/lv_obj_style.c',
    'libs/lvgl/src/core/lv_obj_style_gen.c',
    'libs/lvgl/src/core/lv_obj_tree.c',
    'libs/lvgl/src/core/lv_refr.c',
    'libs/lvgl/src/core/lv_theme.c',

    'libs/lvgl/src/draw/lv_draw.c',
    'libs/lvgl/src/draw/lv_draw_arc.c',
    'libs/lvgl/src/draw/lv_draw_img.c',
    'libs/lvgl/src/draw/lv_draw_label.c',
    'libs/lvgl/src/draw/lv_draw_layer.c',
    'libs/lvgl/src/draw/lv_draw_line.c',
    'libs/lvgl/src/draw/lv_draw_mask.c',
    'libs/lvgl/src/draw/lv_draw_rect.c',
    'libs/lvgl/src/draw/lv_draw_transform.c',
    'libs/lvgl/src/draw/lv_img_buf.c',
    'libs/lvgl/src/draw/lv_img_cache.c',
    'libs/lvgl/src/draw/lv_img_decoder.c',

    'libs/lvgl/src/draw/sw/lv_draw_sw.c',
    'libs/lvgl/src/draw/sw/lv_draw_sw_arc.c',
    'libs/lvgl/src/draw/sw/lv_draw_sw_blend.c',
    'libs/lvgl/src/draw/sw/lv_draw_sw_gradient.c',
    'libs/lvgl/src/draw/sw/lv_draw_sw_img.c',
    'libs/lvgl/src/draw/sw/lv_draw_sw_layer.c',
    'libs/lvgl/src/draw/sw/lv_draw_sw_letter.c',
    'libs/lvgl/src/draw/sw/lv_draw_sw_line.c',
    'libs/lvgl/src/draw/sw/lv_draw_sw_polygon.c',
    'libs/lvgl/src/draw/sw/lv_draw_sw_rect.c',
    'libs/lvgl/src/draw/sw/lv_draw_sw_transform.c',

    'libs/lvgl/src/extra/lv_extra.c',
    'libs/lvgl/src/extra/layouts/flex/lv_flex.c',
    'libs/lvgl/src/extra/layouts/grid/lv_grid.c',
    'libs/lvgl/src/extra/themes/default/lv_theme_default.c',
    'libs/lvgl/src/extra/widgets/calendar/lv_calendar.c',
    'libs/lvgl/src/extra/widgets/calendar/lv_calendar_header_arrow.c',
    'libs/lvgl/src/extra/widgets/calendar/lv_calendar_header_dropdown.c',
    'libs/lvgl/src/extra/widgets/chart/lv_chart.c',
    'libs/lvgl/src/extra/widgets/colorwheel/lv_colorwheel.c',
    'libs/lvgl/src/extra/widgets/keyboard/lv_keyboard.c',
    'libs/lvgl/src/extra/widgets/led/lv_led.c',
    'libs/lvgl/src/extra/widgets/list/lv_list.c',
    'libs/lvgl/src/extra/widgets/menu/lv_menu.c',
    'libs/lvgl/src/extra/widgets/meter/lv_meter.c',
    'libs/lvgl/src/extra/widgets/msgbox/lv_msgbox.c',
    'libs/lvgl/src/extra/widgets/spinbox/lv_spinbox.c',
    'libs/lvgl/src/extra/widgets/spinner/lv_spinner.c',
    'libs/lvgl/src/extra/widgets/tabview/lv_tabview.c',
    'libs/lvgl/src/extra/widgets/tileview/lv_tileview.c',
    'libs/lvgl/src/extra/widgets/win/lv_win.c',

    'libs/lvgl/src/font/lv_font.c',
    'libs/lvgl/src/font/lv_font_fmt_txt.c',
    'libs/lvgl/src/font/lv_font_montserrat_14.c',

    'libs/lvgl/src/hal/lv_hal_disp.c',
    'libs/lvgl/src/hal/lv_hal_indev.c',
    'libs/lvgl/src/hal/lv_hal_tick.c',

    'libs/lvgl/src/misc/lv_anim.c',
    'libs/lvgl/src/misc/lv_area.c',
    'libs/lvgl/src/misc/lv_async.c',
    'libs/lvgl/src/misc/lv_bidi.c',
    'libs/lvgl/src/misc/lv_color.c',
    'libs/lvgl/src/misc/lv_fs.c',
    'libs/lvgl/src/misc/lv_gc.c',
    'libs/lvgl/src/misc/lv_ll.c',
    'libs/lvgl/src/misc/lv_log.c',
    'libs/lvgl/src/misc/lv_math.c',
    'libs/lvgl/src/misc/lv_mem.c',
    'libs/lvgl/src/misc/lv_printf.c',
    'libs/lvgl/src/misc/lv_style.c',
    'libs/lvgl/src/misc/lv_style_gen.c',
    'libs/lvgl/src/misc/lv_timer.c',
    'libs/lvgl/src/misc/lv_tlsf.c',
    'libs/lvgl/src/misc/lv_txt.c',
    'libs/lvgl/src/misc/lv_txt_ap.c',
    'libs/lvgl/src/misc/lv_utils.c',

    'libs/lvgl/src/widgets/lv_arc.c',
    'libs/lvgl/src/widgets/lv_bar.c',
    'libs/lvgl/src/widgets/lv_btn.c',
    'libs/lvgl/src/widgets/lv_btnmatrix.c',
    'libs/lvgl/src/widgets/lv_checkbox.c',
    'libs/lvgl/src/widgets/lv_dropdown.c',
    'libs/lvgl/src/widgets/lv_img.c',
    'libs/lvgl/src/widgets/lv_label.c',
    'libs/lvgl/src/widgets/lv_line.c',
    'libs/lvgl/src/widgets/lv_roller.c',
    'libs/lvgl/src/widgets/lv_slider.c',
    'libs/lvgl/src/widgets/lv_switch.c',
    'libs/lvgl/src/widgets/lv_table.c',
    'libs/lvgl/src/widgets/lv_textarea.c',
]

lv_drivers_sources = [
    'libs/lv_drivers/wayland/wayland.c',
    'libs/lv_drivers/wayland/protocols/wayland-xdg-shell-client-protocol.c',
]

lvgl_demo_sources = [
    'libs/lvgl/examples/get_started/lv_example_get_started_1.c',
    'src/main.c',
]

lvgl_demo_deps = [
    dependency('threads'),
    dependency('wayland-client'),
    dependency('wayland-cursor'),
    dependency('xkbcommon'),
]

executable('lvgl-demo',
    sources: lvgl_sources + lv_drivers_sources + lvgl_demo_sources,
    include_directories: 'libs',
    dependencies: lvgl_demo_deps
)
