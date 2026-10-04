/* SPDX-License-Identifier: MIT */

#ifndef WAYLAND_STEREO_H
#define WAYLAND_STEREO_H

#include <wayland-client.h>

extern const struct wl_interface wl_egl_stereo_content_manager_interface;
extern const struct wl_interface wl_egl_stereo_content_interface;
extern const struct wl_interface wl_egl_stereo_viewporter_interface;
extern const struct wl_interface wl_egl_stereo_viewport_interface;

struct wl_proxy *wlEglStereoContentCreate(struct wl_proxy *manager,
                                           struct wl_surface *surface);
void wlEglStereoContentSetContent(struct wl_proxy *content, uint32_t layout);
struct wl_proxy *wlEglStereoViewportGet(struct wl_proxy *viewporter,
                                         struct wl_surface *surface);
void wlEglStereoViewportSetDestination(struct wl_proxy *viewport,
                                       int32_t width, int32_t height);

#endif
