#ifndef BRIDGE_IMAGE_RENDERER_H_
#define BRIDGE_IMAGE_RENDERER_H_

#include "renderer.h"

namespace bad {
class ImageRenderer : public Renderer {
 public:
  ~ImageRenderer() override = default;

  // All interfaces of Renderer should be implemented.
  void Prepare() override;
  void Render() override;
  bool can_render() override;
};

}  // namespace bad

#endif