#pragma once

#include "Component.h"
#include "Mesh.h"
#include "Material.h"

namespace ToolKit
{

  ULongID Component::m_handle = NULL_HANDLE;

  Component::Component()
  {
    m_id = ++m_handle;
  }

  Component::~Component()
  {
  }

  ComponentType Component::GetType() const
  {
    return ComponentType::Base;
  }

  MeshComponent::MeshComponent()
  {
  }

  MeshComponent::~MeshComponent()
  {
  }

  void MeshComponent::Serialize(XmlDocument* doc, XmlNode* parent) const
  {
  }

  void MeshComponent::DeSerialize(XmlDocument* doc, XmlNode* parent)
  {
  }

  ComponentPtr MeshComponent::Copy()
  {
    MeshComponentPtr mc = std::make_shared<MeshComponent>();

    // If expensive copies needed, do it explicitly.
    mc->m_mesh = m_mesh;
    if (m_material)
    {
      mc->m_material = m_material->Copy<Material>();
    }

    return mc;
  }

  BoundingBox MeshComponent::GetAABB()
  {
    return m_mesh->m_aabb;
  }

  void MeshComponent::Init(bool flushClientSideArray)
  {
    if (m_mesh)
    {
      m_mesh->Init(flushClientSideArray);
    }

    if (m_material)
    {
      m_material->Init(flushClientSideArray);
    }
  }

}  // namespace ToolKit
