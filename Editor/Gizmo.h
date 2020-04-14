#pragma once

#include "Primative.h"
#include "MathUtil.h"

namespace ToolKit
{
	namespace Editor
	{
		class Cursor : public Billboard
		{
		public:
			Cursor();
			virtual ~Cursor();

		private:
			void Generate();
		};

		class Axis3d : public Billboard
		{
		public:
			Axis3d();
			virtual ~Axis3d();

		private:
			void Generate();
		};

		class Gizmo : public Billboard
		{
		public:
			Gizmo(const Billboard::Settings& set);
			virtual ~Gizmo();

			virtual AxisLabel HitTest(const Ray& ray) const;
			virtual void Update(float deltaTime) = 0;
			bool IsLocked(AxisLabel axis) const;
			void Lock(AxisLabel axis);
			void UnLock(AxisLabel axis);
			bool IsGrabbed(AxisLabel axis) const;
			void Grab(AxisLabel axis);
			AxisLabel GetGrabbedAxis() const;

		protected:
			typedef std::pair<AxisLabel, std::vector<BoundingBox>> LabelBoxPair;
			std::vector<LabelBoxPair> m_hitBoxes;
			std::vector<AxisLabel> m_lockedAxis;
			AxisLabel m_grabbedAxis;
		};

		class MoveGizmo : public Gizmo
		{
		public:
			MoveGizmo();
			virtual ~MoveGizmo();

			virtual void Update(float deltaTime) override;

		private:
			void Generate();

		private:
			std::shared_ptr<Mesh> m_lines[6];
			std::shared_ptr<Mesh> m_solids[6];
		};
	}
}
