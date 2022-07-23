#ifndef BRIDGE_TEXT_RENDERER_H_
#define BRIDGE_TEXT_RENDERER_H_

#include "renderer.h"

namespace bad {
class TextRenderer : public Renderer {
 public:
  ~TextRenderer() override = default;

  // All interfaces of Renderer should be implemented.
  void Prepare() override;
  void Render() override;
  bool can_render() override;
};
}  // namespace bad

#endif