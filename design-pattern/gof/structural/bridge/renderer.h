#ifndef BRIDGE_RENDERER_H_
#define BRIDGE_RENDERER_H_

namespace bad {
class Renderer {
 public:
  virtual ~Renderer() = default;

  virtual void Prepare() = 0;
  virtual void Render() = 0;
  virtual bool can_render() = 0;
};
}  // namespace bad

#endif