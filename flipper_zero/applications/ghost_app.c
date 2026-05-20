int32_t ghost_app(void* p) {
    Gui* gui = furi_record_open(RECORD_GUI);
    ViewPort* viewport = view_port_alloc();
    view_port_draw_callback_set(viewport, ghost_draw_callback, NULL);
    view_port_input_callback_set(viewport, ghost_input_callback, NULL);
    gui_add_view_port(gui, viewport, GuiLayerFullscreen);

    ui_themes_init();
    ui_theme_apply(THEME_MATRIX);
    ui_draw_boot_splash();

    bool exit_app = false;
    while (!exit_app) {
        furi_delay_ms(50);
        // Проверка на выход через BACK
        if (furi_hal_console_is_rx_ready()) {
            char c = furi_hal_console_rx();
            if (c == 0x1B) exit_app = true; // ESC = выход
        }
    }

    view_port_enabled_set(viewport, false);
    gui_remove_view_port(gui, viewport);
    view_port_free(viewport);
    furi_record_close(RECORD_GUI);
    return 0;
}
