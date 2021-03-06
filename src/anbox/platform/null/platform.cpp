/*
 * Copyright (C) 2016 Simon Fels <morphis@gravedo.de>
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 3, as published
 * by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranties of
 * MERCHANTABILITY, SATISFACTORY QUALITY, or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "anbox/platform/null/platform.h"
#include "anbox/wm/window.h"
#include "anbox/logger.h"

namespace {
class NullWindow : public anbox::wm::Window {
 public:
  NullWindow(const anbox::wm::Task::Id &task,
             const anbox::graphics::Rect &frame,
             const std::string &title)
      : anbox::wm::Window(nullptr, task, frame, title) {}
};
}

namespace anbox {
namespace platform {
NullPlatform::NullPlatform() {}

std::shared_ptr<wm::Window> NullPlatform::create_window(
    const anbox::wm::Task::Id &task, const anbox::graphics::Rect &frame, const std::string &title) {
  return std::make_shared<::NullWindow>(task, frame, title);
}

void NullPlatform::set_clipboard_data(const ClipboardData &data) {
  (void)data;
  ERROR("Not implemented");
}

NullPlatform::ClipboardData NullPlatform::get_clipboard_data() {
  ERROR("Not implemented");
  return ClipboardData{};
}

std::shared_ptr<audio::Sink> NullPlatform::create_audio_sink() {
  ERROR("Not implemented");
  return nullptr;
}

std::shared_ptr<audio::Source> NullPlatform::create_audio_source() {
  ERROR("Not implemented");
  return nullptr;
}

void NullPlatform::set_renderer(const std::shared_ptr<Renderer> &renderer) {
  (void) renderer;
  ERROR("Not implemented");
}

void NullPlatform::set_window_manager(const std::shared_ptr<wm::Manager> &window_manager) {
  (void) window_manager;
  ERROR("Not implemented");
}

bool NullPlatform::supports_multi_window() const {
  ERROR("Not implemented");
  return false;
}

bool NullPlatform::supports_cursor() const {
  ERROR("Not implemented");
  return false;
}

EGLNativeDisplayType NullPlatform::native_display() const {
  ERROR("Not implemented");
  return reinterpret_cast<EGLNativeDisplayType>(0);
}

EGLDisplay NullPlatform::create_display() {
  return EGL_NO_DISPLAY;
}

bool NullPlatform::choose_config(EGLDisplay display, EGLConfig *config) {
  (void) display;
  (void) config;
  ERROR("Not implemented");
  return false;
}

EGLSurface NullPlatform::create_offscreen_surface(EGLDisplay display, EGLConfig config, unsigned int width, unsigned int height) {
  (void) display;
  (void) config;
  (void) width;
  (void) height;
  ERROR("Not implemented");
  return EGL_NO_SURFACE;
}

void NullPlatform::destroy_offscreen_surface(EGLDisplay display, EGLSurface surface) {
  (void) display;
  (void) surface;
  ERROR("Not implemented");
}

void NullPlatform::swap_buffers(EGLDisplay display, EGLSurface surface) {
  (void) display;
  (void) surface;
  ERROR("Not implemented");
}
}  // namespace wm
}  // namespace anbox
