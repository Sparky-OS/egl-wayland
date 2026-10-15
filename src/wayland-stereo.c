/* SPDX-License-Identifier: MIT */

#include "wayland-stereo.h"

static const struct wl_interface *manager_types[] = {
    NULL, NULL, &wl_egl_stereo_content_interface, &wl_surface_interface,
};

static const struct wl_message manager_requests[] = {
    { "destroy", "", NULL },
    { "create", "no", manager_types + 2 },
};

const struct wl_interface wl_egl_stereo_content_manager_interface = {
    "kde_stereo_content_manager_v1", 2, 2, manager_requests, 0, NULL,
};

static const struct wl_message content_requests[] = {
    { "destroy", "", NULL },
    { "set_content", "u", NULL },
};

const struct wl_interface wl_egl_stereo_content_interface = {
    "kde_stereo_content_v1", 2, 2, content_requests, 0, NULL,
};

static const struct wl_interface *viewporter_types[] = {
    NULL, NULL, &wl_egl_stereo_viewport_interface, &wl_surface_interface,
};

static const struct wl_message viewporter_requests[] = {
    { "destroy", "", NULL },
    { "get_viewport", "no", viewporter_types + 2 },
};

const struct wl_interface wl_egl_stereo_viewporter_interface = {
    "wp_viewporter", 1, 2, viewporter_requests, 0, NULL,
};

static const struct wl_message viewport_requests[] = {
    { "destroy", "", NULL },
    { "set_source", "4ffff", NULL },
    { "set_destination", "ii", NULL },
};

const struct wl_interface wl_egl_stereo_viewport_interface = {
    "wp_viewport", 1, 3, viewport_requests, 0, NULL,
};

struct wl_proxy *
wlEglStereoContentCreate(struct wl_proxy *manager, struct wl_surface *surface)
{
    return wl_proxy_marshal_flags(manager, 1,
                                  &wl_egl_stereo_content_interface,
                                  wl_proxy_get_version(manager), 0, NULL,
                                  surface);
}

void
wlEglStereoContentSetContent(struct wl_proxy *content, uint32_t layout)
{
    wl_proxy_marshal_flags(content, 1, NULL, wl_proxy_get_version(content), 0,
                           layout);
}

struct wl_proxy *
wlEglStereoViewportGet(struct wl_proxy *viewporter, struct wl_surface *surface)
{
    return wl_proxy_marshal_flags(viewporter, 1,
                                  &wl_egl_stereo_viewport_interface,
                                  wl_proxy_get_version(viewporter), 0, NULL,
                                  surface);
}

void
wlEglStereoViewportSetDestination(struct wl_proxy *viewport,
                                   int32_t width, int32_t height)
{
    wl_proxy_marshal_flags(viewport, 2, NULL, wl_proxy_get_version(viewport), 0,
                           width, height);
}
