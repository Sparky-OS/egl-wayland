/* SPDX-License-Identifier: MIT */

#include "wayland-stereo.h"

#include <assert.h>
#include <string.h>

static const struct wl_message *
find_request(const struct wl_interface *interface, const char *name)
{
    for (int i = 0; i < interface->method_count; i++) {
        if (strcmp(interface->methods[i].name, name) == 0) {
            return &interface->methods[i];
        }
    }
    return NULL;
}

int
main(void)
{
    const struct wl_message *create = find_request(
        &wl_egl_stereo_content_manager_interface, "create");
    const struct wl_message *set_content = find_request(
        &wl_egl_stereo_content_interface, "set_content");
    const struct wl_message *get_viewport = find_request(
        &wl_egl_stereo_viewporter_interface, "get_viewport");
    const struct wl_message *set_destination = find_request(
        &wl_egl_stereo_viewport_interface, "set_destination");

    assert(strcmp(wl_egl_stereo_content_manager_interface.name,
                  "kde_stereo_content_manager_v1") == 0);
    assert(strcmp(wl_egl_stereo_content_interface.name,
                  "kde_stereo_content_v1") == 0);
    assert(strcmp(wl_egl_stereo_viewporter_interface.name,
                  "wp_viewporter") == 0);
    assert(strcmp(wl_egl_stereo_viewport_interface.name,
                  "wp_viewport") == 0);
    assert(create && strcmp(create->signature, "no") == 0);
    assert(set_content && strcmp(set_content->signature, "u") == 0);
    assert(get_viewport && strcmp(get_viewport->signature, "no") == 0);
    assert(set_destination && strcmp(set_destination->signature, "ii") == 0);
    return 0;
}
