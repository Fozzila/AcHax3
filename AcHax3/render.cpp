#include "includes.h"
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

WNDPROC originalWndProc = NULL;

LRESULT __stdcall hWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (true)
	{
		if (ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		{
			return true;
		}

		ImGuiIO& io = ImGui::GetIO();

		switch (uMsg)
		{
		case WM_LBUTTONDOWN:
			io.MouseDown[1] = !io.MouseDown[0];
			return 0;
		case WM_RBUTTONDOWN:
			io.MouseDown[1] = !io.MouseDown[1];
			return 0;
		case WM_MBUTTONDOWN:
			io.MouseDown[2] = !io.MouseDown[2];
			return 0;
		case WM_MOUSEWHEEL:
			return 0;
		case WM_MOUSEMOVE:
			io.MousePos.x = (signed short)(lParam);
			io.MousePos.y = (signed short)(lParam >> 16);
			return 0;
		}
	}

	return CallWindowProc(originalWndProc, hWnd, uMsg, wParam, lParam);
}

void render::initialize()
{
	ImGui_ImplOpenGL2_Init();
	HWND hwnd = NULL;
	if (hwnd == NULL)
	{
		hwnd = FindWindowA(NULL, "Assault Cube");
	}

	ImGui_ImplWin32_Init(hwnd);
	ImGui_ImplOpenGL2_Init();

	ImGuiStyle* style = &ImGui::GetStyle();

	style->WindowPadding = ImVec2(15, 15);
	style->WindowRounding = 5.0f;
	style->FramePadding = ImVec2(5, 5);
	style->FrameRounding = 4.0f;
	style->ItemSpacing = ImVec2(12, 8);
	style->ItemInnerSpacing = ImVec2(8, 6);
	style->IndentSpacing = 25.0f;
	style->ScrollbarSize = 15.0f;
	style->ScrollbarRounding = 9.0f;
	style->GrabMinSize = 5.0f;	style->GrabRounding = 3.0f;

	style->Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	style->Colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
	style->Colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.06f, 0.06f, 0.94f);
	style->Colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style->Colors[ImGuiCol_PopupBg] = ImVec4(0.20f, 0.22f, 0.26f, 0.94f);
	style->Colors[ImGuiCol_Border] = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
	style->Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style->Colors[ImGuiCol_FrameBg] = ImVec4(0.20f, 0.22f, 0.26f, 0.54f);
	style->Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.40f, 0.26f, 0.98f, 0.40f);
	style->Colors[ImGuiCol_FrameBgActive] = ImVec4(0.40f, 0.26f, 0.98f, 1.00f);
	style->Colors[ImGuiCol_TitleBg] = ImVec4(0.40f, 0.26f, 0.98f, 1.00f);
	style->Colors[ImGuiCol_TitleBgActive] = ImVec4(0.40f, 0.26f, 0.98f, 1.00f);
	style->Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
	style->Colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
	style->Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
	style->Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
	style->Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
	style->Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
	style->Colors[ImGuiCol_CheckMark] = ImVec4(0.40f, 0.26f, 1.00f, 1.00f);
	style->Colors[ImGuiCol_SliderGrab] = ImVec4(0.40f, 0.26f, 1.00f, 0.63f);
	style->Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.40f, 0.26f, 1.00f, 1.00f);
	style->Colors[ImGuiCol_Button] = ImVec4(0.40f, 0.26f, 1.00f, 1.00f);
	style->Colors[ImGuiCol_ButtonHovered] = ImVec4(0.40f, 0.26f, 1.00f, 0.51f);
	style->Colors[ImGuiCol_ButtonActive] = ImVec4(0.40f, 0.26f, 1.00f, 1.00f);
	style->Colors[ImGuiCol_Header] = ImVec4(0.40f, 0.26f, 1.00f, 1.00f);
	style->Colors[ImGuiCol_HeaderHovered] = ImVec4(0.40f, 0.26f, 1.00f, 0.50f);
	style->Colors[ImGuiCol_HeaderActive] = ImVec4(0.40f, 0.26f, 1.00f, 1.00f);
	style->Colors[ImGuiCol_Separator] = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
	style->Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
	style->Colors[ImGuiCol_SeparatorActive] = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
	style->Colors[ImGuiCol_ResizeGrip] = ImVec4(0.40f, 0.26f, 1.00f, 1.00f);
	style->Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.40f, 0.26f, 1.00f, 0.50f);
	style->Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.40f, 0.26f, 1.00f, 1.00f);
	style->Colors[ImGuiCol_Tab] = ImVec4(0.40f, 0.26f, 1.00f, 1.00f);
	style->Colors[ImGuiCol_TabHovered] = ImVec4(0.40f, 0.26f, 1.00f, 0.56f);
	style->Colors[ImGuiCol_TabActive] = ImVec4(0.20f, 0.22f, 0.26f, 0.54f);	style->Colors[ImGuiCol_TabUnfocused] = ImVec4(0.40f, 0.26f, 1.00f, 1.00f);
	style->Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.40f, 0.26f, 1.00f, 1.00f);
	style->Colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
	style->Colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
	style->Colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
	style->Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
	style->Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
	style->Colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
	style->Colors[ImGuiCol_NavHighlight] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	style->Colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
	style->Colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
	style->Colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);


	ImGui::SetNextWindowSize(ImVec2(800, 600), 0);

	originalWndProc = (WNDPROC)SetWindowLongPtr(hwnd, GWLP_WNDPROC, (LONG_PTR)hWndProc);

}
