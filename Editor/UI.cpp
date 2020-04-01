#include "stdafx.h"

#include "App.h"
#include "UI.h"
#include "Viewport.h"
#include "SDL.h"
#include "GlobalDef.h"
#include "Mod.h"
#include "ConsoleWindow.h"
#include "DebugNew.h"

bool ToolKit::Editor::UI::m_windowMenushowMetrics = false;
bool ToolKit::Editor::UI::m_imguiSampleWindow = false;
float ToolKit::Editor::UI::m_hoverTimeForHelp = 1.0f;

// Icons
std::shared_ptr<ToolKit::Texture> ToolKit::Editor::UI::m_selectIcn;
std::shared_ptr<ToolKit::Texture> ToolKit::Editor::UI::m_cursorIcn;
std::shared_ptr<ToolKit::Texture> ToolKit::Editor::UI::m_moveIcn;
std::shared_ptr<ToolKit::Texture> ToolKit::Editor::UI::m_rotateIcn;
std::shared_ptr<ToolKit::Texture> ToolKit::Editor::UI::m_scaleIcn;
std::shared_ptr<ToolKit::Texture> ToolKit::Editor::UI::m_appIcon;

void ToolKit::Editor::UI::ApplyCustomTheme()
{
	ImGuiStyle* style = &ImGui::GetStyle();
	style->WindowRounding = 5.3f;
	style->GrabRounding = style->FrameRounding = 2.3f;
	style->ScrollbarRounding = 5.0f;
	style->FrameBorderSize = 1.0f;
	style->ItemSpacing.y = 6.5f;

	style->Colors[ImGuiCol_Text] = { 0.73333335f, 0.73333335f, 0.73333335f, 1.00f };
	style->Colors[ImGuiCol_TextDisabled] = { 0.34509805f, 0.34509805f, 0.34509805f, 1.00f };
	style->Colors[ImGuiCol_WindowBg] = { 0.23529413f, 0.24705884f, 0.25490198f, 0.94f };
	style->Colors[ImGuiCol_ChildBg] = { 0.23529413f, 0.24705884f, 0.25490198f, 0.00f };
	style->Colors[ImGuiCol_PopupBg] = { 0.23529413f, 0.24705884f, 0.25490198f, 0.94f };
	style->Colors[ImGuiCol_Border] = { 0.33333334f, 0.33333334f, 0.33333334f, 0.50f };
	style->Colors[ImGuiCol_BorderShadow] = { 0.15686275f, 0.15686275f, 0.15686275f, 0.00f };
	style->Colors[ImGuiCol_FrameBg] = { 0.16862746f, 0.16862746f, 0.16862746f, 0.54f };
	style->Colors[ImGuiCol_FrameBgHovered] = { 0.453125f, 0.67578125f, 0.99609375f, 0.67f };
	style->Colors[ImGuiCol_FrameBgActive] = { 0.47058827f, 0.47058827f, 0.47058827f, 0.67f };
	style->Colors[ImGuiCol_TitleBg] = { 0.04f, 0.04f, 0.04f, 1.00f };
	style->Colors[ImGuiCol_TitleBgCollapsed] = { 0.16f, 0.29f, 0.48f, 1.00f };
	style->Colors[ImGuiCol_TitleBgActive] = { 0.00f, 0.00f, 0.00f, 0.51f };
	style->Colors[ImGuiCol_MenuBarBg] = { 0.27058825f, 0.28627452f, 0.2901961f, 0.80f };
	style->Colors[ImGuiCol_ScrollbarBg] = { 0.27058825f, 0.28627452f, 0.2901961f, 0.60f };
	style->Colors[ImGuiCol_ScrollbarGrab] = { 0.21960786f, 0.30980393f, 0.41960788f, 0.51f };
	style->Colors[ImGuiCol_ScrollbarGrabHovered] = { 0.21960786f, 0.30980393f, 0.41960788f, 1.00f };
	style->Colors[ImGuiCol_ScrollbarGrabActive] = { 0.13725491f, 0.19215688f, 0.2627451f, 0.91f };
	// style->Colors[ImGuiCol_ComboBg]               = {0.1f, 0.1f, 0.1f, 0.99f};
	style->Colors[ImGuiCol_CheckMark] = { 0.90f, 0.90f, 0.90f, 0.83f };
	style->Colors[ImGuiCol_SliderGrab] = { 0.70f, 0.70f, 0.70f, 0.62f };
	style->Colors[ImGuiCol_SliderGrabActive] = { 0.30f, 0.30f, 0.30f, 0.84f };
	style->Colors[ImGuiCol_Button] = { 0.33333334f, 0.3529412f, 0.36078432f, 0.49f };
	style->Colors[ImGuiCol_ButtonHovered] = { 0.21960786f, 0.30980393f, 0.41960788f, 1.00f };
	style->Colors[ImGuiCol_ButtonActive] = { 0.13725491f, 0.19215688f, 0.2627451f, 1.00f };
	style->Colors[ImGuiCol_Header] = { 0.33333334f, 0.3529412f, 0.36078432f, 0.53f };
	style->Colors[ImGuiCol_HeaderHovered] = { 0.453125f, 0.67578125f, 0.99609375f, 0.67f };
	style->Colors[ImGuiCol_HeaderActive] = { 0.47058827f, 0.47058827f, 0.47058827f, 0.67f };
	style->Colors[ImGuiCol_Separator] = { 0.31640625f, 0.31640625f, 0.31640625f, 1.00f };
	style->Colors[ImGuiCol_SeparatorHovered] = { 0.31640625f, 0.31640625f, 0.31640625f, 1.00f };
	style->Colors[ImGuiCol_SeparatorActive] = { 0.31640625f, 0.31640625f, 0.31640625f, 1.00f };
	style->Colors[ImGuiCol_ResizeGrip] = { 1.00f, 1.00f, 1.00f, 0.85f };
	style->Colors[ImGuiCol_ResizeGripHovered] = { 1.00f, 1.00f, 1.00f, 0.60f };
	style->Colors[ImGuiCol_ResizeGripActive] = { 1.00f, 1.00f, 1.00f, 0.90f };
	style->Colors[ImGuiCol_PlotLines] = { 0.61f, 0.61f, 0.61f, 1.00f };
	style->Colors[ImGuiCol_PlotLinesHovered] = { 1.00f, 0.43f, 0.35f, 1.00f };
	style->Colors[ImGuiCol_PlotHistogram] = { 0.90f, 0.70f, 0.00f, 1.00f };
	style->Colors[ImGuiCol_PlotHistogramHovered] = { 1.00f, 0.60f, 0.00f, 1.00f };
	style->Colors[ImGuiCol_TextSelectedBg] = { 0.18431373f, 0.39607847f, 0.79215693f, 0.90f };
}

void ToolKit::Editor::UI::ShowUI()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplSDL2_NewFrame(g_window);
	ImGui::NewFrame();

	InitDocking();
	ShowAppMainMenuBar();

	for (Viewport* vp : g_app->m_viewports)
	{
		vp->Show();
	}

	g_app->m_console->Show();

	if (m_imguiSampleWindow)
	{
		ImGui::ShowDemoWindow(&m_imguiSampleWindow);
	}

	if (m_windowMenushowMetrics)
	{
		ImGui::ShowMetricsWindow(&m_windowMenushowMetrics);
	}

	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	ImGui::EndFrame();

	ImGui::UpdatePlatformWindows();
	ImGui::RenderPlatformWindowsDefault();
	SDL_GL_MakeCurrent(g_window, g_context);
}

void ToolKit::Editor::UI::InitDocking()
{
	static bool opt_fullscreen_persistant = true;
	bool opt_fullscreen = opt_fullscreen_persistant;
	static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

	ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
	if (opt_fullscreen)
	{
		ImGuiViewport* viewport = ImGui::GetMainViewport();
		ImGui::SetNextWindowPos(viewport->Pos);
		ImGui::SetNextWindowSize(viewport->Size);
		ImGui::SetNextWindowViewport(viewport->ID);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
		window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
		window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
	}

	if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
		window_flags |= ImGuiWindowFlags_NoBackground;

	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
	ImGui::Begin("DockSpace Demo", nullptr, window_flags);
	ImGui::PopStyleVar();

	if (opt_fullscreen)
		ImGui::PopStyleVar(2);

	// DockSpace
	ImGuiIO& io = ImGui::GetIO();
	if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
	{
		ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
		ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
	}

	ImGui::End();
}

void ToolKit::Editor::UI::ShowAppMainMenuBar()
{
	if (ImGui::BeginMainMenuBar())
	{
		if (ImGui::BeginMenu("File"))
		{
			ShowMenuFile();
			ImGui::EndMenu();
		}

		if (ImGui::BeginMenu("Windows"))
		{
			ShowMenuWindows();
			ImGui::EndMenu();
		}

		ImGui::EndMainMenuBar();
	}
}

void ToolKit::Editor::UI::ShowMenuFile()
{
	if (ImGui::MenuItem("Quit", "Alt+F4"))
	{
		g_app->OnQuit();
	}
}

void ToolKit::Editor::UI::ShowMenuWindows()
{
	if (ImGui::BeginMenu("Viewport"))
	{
		for (int i = (int)g_app->m_viewports.size() - 1; i >= 0; i--)
		{
			Viewport* vp = g_app->m_viewports[i];
			if (ImGui::MenuItem(vp->m_name.c_str(), nullptr, false, !vp->IsOpen()))
			{
				vp->SetVisibility(true);
			}

			if (vp->IsOpen())
			{
				ImGui::SameLine();
				if (ImGui::Button("x"))
				{
					g_app->m_viewports.erase(g_app->m_viewports.begin() + i);
					SafeDel(vp);
					continue;
				}
			}
		}

		if (ImGui::MenuItem("Add Viewport", "Alt+V"))
		{
			Viewport* vp = new Viewport(640, 480);
			g_app->m_viewports.push_back(vp);
		}
		ImGui::EndMenu();
	}

	if (ImGui::MenuItem("Console Window", "Alt+C", nullptr, !g_app->m_console->IsOpen()))
	{
		g_app->m_console->SetVisibility(true);
	}

	ImGui::Separator();

	if (!m_windowMenushowMetrics)
	{
		if (ImGui::MenuItem("Show Metrics", "Alt+M"))
		{
			m_windowMenushowMetrics = true;
		}
	}

	if (!m_imguiSampleWindow)
	{
		if (ImGui::MenuItem("Imgui Sample", "Alt+S"))
		{
			m_imguiSampleWindow = true;
		}
	}
}

void ToolKit::Editor::UI::HelpMarker(const char* desc, float* elapsedHoverTime)
{
	if (ImGui::IsItemHovered())
	{
		*elapsedHoverTime += ImGui::GetIO().DeltaTime;
		if (UI::m_hoverTimeForHelp > *elapsedHoverTime)
		{
			return;
		}

		ImGui::BeginTooltip();
		ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
		ImGui::TextUnformatted(desc);
		ImGui::PopTextWrapPos();
		ImGui::EndTooltip();
	}
	else
	{
		*elapsedHoverTime = 0.0f;
	}
}

void ToolKit::Editor::UI::InitIcons()
{
	m_selectIcn = Main::GetInstance()->m_textureMan.Create(TexturePath("Icons/select.png"));
	m_selectIcn->Init();
	m_cursorIcn = Main::GetInstance()->m_textureMan.Create(TexturePath("Icons/cursor.png"));
	m_cursorIcn->Init();
	m_moveIcn = Main::GetInstance()->m_textureMan.Create(TexturePath("Icons/move.png"));
	m_moveIcn->Init();
	m_rotateIcn = Main::GetInstance()->m_textureMan.Create(TexturePath("Icons/rotate.png"));
	m_rotateIcn->Init();
	m_scaleIcn = Main::GetInstance()->m_textureMan.Create(TexturePath("Icons/scale.png"));
	m_scaleIcn->Init();

	// Set application Icon.
	m_appIcon = Main::GetInstance()->m_textureMan.Create(TexturePath("Icons/app.png"));
	m_appIcon->Init(false);
	SDL_Surface* surface = SDL_CreateRGBSurfaceWithFormatFrom(m_appIcon->m_image.data(), m_appIcon->m_width, m_appIcon->m_height, 8, m_appIcon->m_width * 4, SDL_PIXELFORMAT_ABGR8888);
	SDL_SetWindowIcon(g_window, surface);
	SDL_FreeSurface(surface);
}

void ToolKit::Editor::UI::DispatchSignals()
{
	ImGuiIO& io = ImGui::GetIO();
		
	if (io.MouseClicked[0])
	{
		ModManager::GetInstance()->DispatchSignal(LeftMouseBtnDownSgnl());
	}

	if (io.MouseReleased[0])
	{
		ModManager::GetInstance()->DispatchSignal(LeftMouseBtnUpSgnl());
	}

	if (ImGui::IsMouseDragging(0))
	{
		ModManager::GetInstance()->DispatchSignal(LeftMouseBtnDragSgnl());
	}
}

bool ToolKit::Editor::UI::ToggleButton(ImTextureID user_texture_id, const ImVec2& size, bool pushState)
{
	ImGuiStyle& style = ImGui::GetStyle();
	if (pushState)
	{
		ImGui::PushID(1);
		ImGui::PushStyleColor(ImGuiCol_Button, style.Colors[ImGuiCol_ButtonHovered]);
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, style.Colors[ImGuiCol_ButtonHovered]);
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, style.Colors[ImGuiCol_ButtonHovered]);
	}
	bool newPushState = pushState | ImGui::ImageButton((void*)(intptr_t)user_texture_id, ImVec2(32, 32));
	if (pushState)
	{
		ImGui::PopStyleColor(3);
		ImGui::PopID();
	}

	return newPushState;
}
