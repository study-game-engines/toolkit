#pragma once

#include "MathUtil.h"
#include "Types.h"

#include <assert.h>
#include <string.h>
#include <vector>

namespace ToolKit
{

  template<typename T>
  void ReadVec(XmlNode* node, T& val);
  template<typename T>
  void WriteVec(XmlNode* node, XmlDocument* doc, const T& val);
  void WriteAttr(XmlNode* node, XmlDocument* doc, const String& name, const String& val);

  void ReadAttr(XmlNode* node, const String& name, bool& val);
  void ReadAttr(XmlNode* node, const String& name, float& val);
  void ReadAttr(XmlNode* node, const String& name, int& val);
  void ReadAttr(XmlNode* node, const String& name, uint& val);
  void ReadAttr(XmlNode* node, const String& name, Byte& val);
  void ReadAttr(XmlNode* node, const String& name, UByte& val);
  void ReadAttr(XmlNode* node, const String& name, String& val);

  // File path operations
  bool CheckFile(const String& path);
  void DecomposePath(const String& fullPath, String* path, String* name, String* ext);
  void NormalizePath(String& path);
  String ConcatPaths(const StringArray& entries);
  enum class ResourceType GetResourceType(const String& ext);
  String GetResourcePath(enum class ResourceType type);
  String GetRelativeResourcePath(const String& fullPath);
  char GetPathSeparator();
  String GetPathSeparatorAsStr();
  bool SupportedImageFormat(const String& ext);
  bool SupportedMeshFormat(const String& ext);

  // String operations
  void Split(const String& s, const String& sep, StringArray& v);
  void ReplaceStringInPlace(String& subject, const String& search, const String& replace);
  class LineBatch* CreatePlaneDebugObject(PlaneEquation plane, float size);
  class LineBatch* CreateLineDebugObject(const Vec3Array& corners);
  class LineBatch* GenerateBoundingVolumeGeometry(const BoundingBox& box, Mat4* transform = nullptr);
  void ToEntityIdArray(EntityIdArray& idArray, const EntityRawPtrArray& ptrArray);
  bool IsInArray(const EntityRawPtrArray& nttArray, Entity* ntt);
  void GetRootEntities(const EntityRawPtrArray& entities, EntityRawPtrArray& roots);
  String ToLower(const String& str);

  template<typename T>
  void pop_front(std::vector<T>& vec)
  {
    assert(!vec.empty());
    vec.erase(vec.begin());
  }

}
