#pragma once

#include <memory>
#include "RenderState.h"
#include "Resource.h"
#include "ResourceManager.h"

namespace ToolKit
{

  class Texture;
  class CubeMap;
  class Shader;

  class Material : public Resource
  {
  public:
    Material();
    Material(String file);
    ~Material();

    virtual void Load() override;
    virtual void Init(bool flushClientSideArray = true) override;
		virtual void UnInit() override;
    virtual Material* GetCopy() override;
		RenderState* GetRenderState();

  public:
    std::shared_ptr<CubeMap> m_cubeMap;
    std::shared_ptr<Texture> m_diffuseTexture;
    std::shared_ptr<Shader> m_vertexShader;
    std::shared_ptr<Shader> m_fragmetShader;
    Vec3 m_color;

	private:
		RenderState m_renderState;
  };

  class MaterialManager : public ResourceManager<Material>
  {
  public:
    void Init();

    std::shared_ptr<Material> GetCopyOfSolidMaterial();
    std::shared_ptr<Material> GetCopyOfDefaultMaterial();
  };

}