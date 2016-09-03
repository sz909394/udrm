#ifndef __UDRM_UDRM_H
#define __UDRM_UDRM_H

/*
 * Copyright (C) 2015-2016 Red Hat, Inc.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation; either version 2.1 of the License, or (at your
 * option) any later version.
 */

#include <drm/drmP.h>
#include <drm/drm_crtc.h>
#include <drm/drm_gem.h>
#include <linux/kernel.h>

struct miscdevice;
struct udrm_cdev;
struct udrm_device;

/* udrm devices */

struct udrm_device *udrm_device_new(struct device *parent);
struct udrm_device *udrm_device_ref(struct udrm_device *udrm);
struct udrm_device *udrm_device_unref(struct udrm_device *udrm);
struct udrm_cdev *udrm_device_acquire(struct udrm_device *udrm);
struct udrm_cdev *udrm_device_release(struct udrm_device *udrm,
				      struct udrm_cdev *cdev);
int udrm_device_register(struct udrm_device *udrm, struct udrm_cdev *cdev);
void udrm_device_unregister(struct udrm_device *udrm);

/* udrm gem */

struct udrm_bo {
	struct drm_gem_object base;
};

struct udrm_bo *udrm_bo_new(struct drm_device *ddev, size_t size);
void udrm_bo_free(struct drm_gem_object *dobj);

int udrm_dumb_create(struct drm_file *dfile,
		     struct drm_device *ddev,
		     struct drm_mode_create_dumb *args);
int udrm_dumb_map_offset(struct drm_file *dfile,
			 struct drm_device *ddev,
			 uint32_t handle,
			 uint64_t *offset);

/* udrm cdevs */

extern struct miscdevice udrm_cdev_misc;

#endif /* __UDRM_UDRM_H */
