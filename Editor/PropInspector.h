#pragma once

#include "FolderWindow.h"
#include "UI.h"

#include <functional>
#include <vector>

namespace ToolKit
{
  namespace Editor
  {

    class View
    {
     public:
      virtual ~View()
      {
      }
      virtual void Show() = 0;
      virtual void ShowVariant(ParameterVariant* var, ComponentPtr comp);
      void ShowAnimControllerComponent(ParameterVariant* var, ComponentPtr cmp);

      void DropZone(uint fallbackIcon,
                    const String& file,
                    std::function<void(const DirectoryEntry& entry)> dropAction,
                    const String& dropName = "");

      void DropSubZone(
          const String& title,
          uint fallbackIcon,
          const String& file,
          std::function<void(const DirectoryEntry& entry)> dropAction);

     protected:
      bool IsTextInputFinalized();

     public:
      Entity* m_entity = nullptr;
      int m_viewID     = 0;
    };

    class EntityView : public View
    {
     public:
      EntityView()
      {
        m_viewID = 1;
      }
      virtual ~EntityView()
      {
      }
      virtual void Show();
      virtual void ShowParameterBlock();
      virtual bool ShowComponentBlock(ComponentPtr& comp);

     protected:
      void ShowCustomData();
    };

    class PropInspector : public Window
    {
     public:
      explicit PropInspector(XmlNode* node);
      PropInspector();
      virtual ~PropInspector();

      void Show() override;
      Type GetType() const override;
      void DispatchSignals() const override;

     public:
      EntityView* m_view;
    };

  } // namespace Editor
} // namespace ToolKit
