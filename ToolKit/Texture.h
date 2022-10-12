#pragma once

#include "Resource.h"
#include "ResourceManager.h"
#include "Types.h"

#include <vector>

namespace ToolKit
{

  class TK_API Texture : public Resource
  {
   public:
    TKResourceType(Texture);

    explicit Texture(bool floatFormat = false);
    explicit Texture(String file, bool floatFormat = false);
    explicit Texture(uint textureId);
    virtual ~Texture();

    void Load() override;
    void Init(bool flushClientSideArray = false) override;
    void UnInit() override;

   protected:
    virtual void Clear();

   public:
    uint m_textureId   = 0;
    int m_width        = 0;
    int m_height       = 0;
    int m_bytePP       = 0;
    bool m_floatFormat = false;
    uint8* m_image     = nullptr;
    float* m_imagef    = nullptr;
  };

  class TK_API CubeMap : public Texture
  {
   public:
    TKResourceType(CubeMap)

    CubeMap();
    explicit CubeMap(String file);
    explicit CubeMap(uint cubemapId);
    ~CubeMap();

    void Load() override;
    void Init(bool flushClientSideArray = false) override;
    void UnInit() override;

   protected:
    void Clear() override;

   public:
    std::vector<uint8*> m_images;
  };

  struct CubeMapSettings
  {
    int level;
    int internalformat;
    int width;
    int height;
    uint format;
    uint type;
    void* pixels;
    int wrapSet;
    int filterSet;
  };

  class TK_API Hdri : public Texture
  {
   public:
    TKResourceType(Hdri);

    Hdri();
    explicit Hdri(const String& file);
    virtual ~Hdri();

    void Load() override;
    void Init(bool flushClientSideArray = false) override;
    void UnInit() override;

    bool IsTextureAssigned();
    uint GetCubemapId();
    void SetCubemapId(uint id);
    uint GetIrradianceCubemapId();
    void SetIrradianceCubemapId(uint id);

   protected:
    void CreateFramebuffersForCubeMaps();
    void DeleteFramebuffers();
    void GenerateCubemapFrom2DTexture();
    void GenerateIrradianceMap();

   private:
    uint GenerateCubemapBuffers(struct CubeMapSettings cubeMapSettings);
    void RenderToCubeMap(uint fbo,
                         const Mat4 views[6],
                         CameraPtr cam,
                         uint cubeMapTextureId,
                         int width,
                         int height,
                         MaterialPtr mat);

   public:
    CubeMapPtr m_cubemap           = nullptr;
    CubeMapPtr m_irradianceCubemap = nullptr;
    float m_exposure               = 1.0f;

   protected:
    MaterialPtr m_texToCubemapMat           = nullptr;
    MaterialPtr m_cubemapToIrradiancemapMat = nullptr;
    TexturePtr m_equirectangularTexture     = nullptr;

    uint m_fbo           = 0;
    uint m_rbo           = 0;
    uint m_irradianceFbo = 0;
    uint m_irradianceRbo = 0;
  };

  struct RenderTargetSettigs
  {
    byte Msaa                   = 0;
    bool useBorderColor         = false;
    GraphicTypes Target         = GraphicTypes::Target2D;
    GraphicTypes WarpS          = GraphicTypes::UVRepeat;
    GraphicTypes WarpT          = GraphicTypes::UVRepeat;
    GraphicTypes WarpR          = GraphicTypes::UVRepeat;
    GraphicTypes MinFilter      = GraphicTypes::SampleNearest;
    GraphicTypes MagFilter      = GraphicTypes::SampleNearest;
    GraphicTypes InternalFormat = GraphicTypes::FormatRGBA;
    GraphicTypes Format         = GraphicTypes::FormatRGBA;
    GraphicTypes Type           = GraphicTypes::TypeUnsignedByte;
    Vec4 borderColor            = Vec4(0.0f);
  };

  class TK_API RenderTarget : public Texture
  {
   public:
    TKResourceType(RenderTarget)

    RenderTarget();
    RenderTarget(uint widht,
                 uint height,
                 const RenderTargetSettigs& settings = RenderTargetSettigs());

    void Load() override;
    void Init(bool flushClientSideArray = false) override;
    void Reconstrcut(uint width,
                     uint height,
                     const RenderTargetSettigs& settings);
    void ReconstrcutIfNeeded(uint width, uint height);
    const RenderTargetSettigs& GetSettings() const;

   public:
    RenderTargetSettigs m_settings;
  };

  class TK_API TextureManager : public ResourceManager
  {
   public:
    TextureManager();
    virtual ~TextureManager();
    bool CanStore(ResourceType t) override;
    ResourcePtr CreateLocal(ResourceType type) override;
    String GetDefaultResource(ResourceType type) override;
  };

} // namespace ToolKit
