// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_BROWSER_RENDERER_HOST_MEDIA_DESKTOP_CAPTURE_DEVICE_ASH_H_
#define CONTENT_BROWSER_RENDERER_HOST_MEDIA_DESKTOP_CAPTURE_DEVICE_ASH_H_

#include <string>

#include "base/memory/scoped_ptr.h"
#include "content/common/content_export.h"
#include "content/public/common/desktop_media_id.h"
#include "media/video/capture/video_capture_device.h"

namespace aura {
class Window;
}  // namespace aura

namespace content {

class VideoCaptureDeviceImpl;

// An implementation of VideoCaptureDevice that mirrors the desktop on Ash.
class CONTENT_EXPORT DesktopCaptureDeviceAsh
    : public media::VideoCaptureDevice {
 public:
  // Creates a VideoCaptureDevice for the Ash desktop.
  static media::VideoCaptureDevice* Create(const DesktopMediaID& source);

  virtual ~DesktopCaptureDeviceAsh();

  // VideoCaptureDevice implementation.
  virtual void AllocateAndStart(const media::VideoCaptureParams& params,
                                scoped_ptr<Client> client) OVERRIDE;
  virtual void StopAndDeAllocate() OVERRIDE;

 private:
  DesktopCaptureDeviceAsh(const DesktopMediaID& source);

  const scoped_ptr<class VideoCaptureDeviceImpl> impl_;

  DISALLOW_COPY_AND_ASSIGN(DesktopCaptureDeviceAsh);
};


}  // namespace content

#endif  // CONTENT_BROWSER_RENDERER_HOST_MEDIA_DESKTOP_CAPTURE_DEVICE_ASH_H_