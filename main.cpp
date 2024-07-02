// #include <iostream>
// #include "Node.hpp"
// #include "Tree.hpp"
// #include "TreePrinter.hpp"
// #include "imgui.h"
// #include "imgui_impl_sdl.h"
// #include "imgui_impl_opengl3.h"
// #include <SDL.h>
// #include <GL/glew.h>

// using namespace std;

// int main(int argc, char** argv) {
//     // Initialize SDL
//     if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER) != 0) {
//         std::cerr << "Error: " << SDL_GetError() << std::endl;
//         return -1;
//     }

//     // Setup window
//     SDL_Window* window = SDL_CreateWindow("Tree Visualization", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
//     SDL_GLContext gl_context = SDL_GL_CreateContext(window);
//     SDL_GL_MakeCurrent(window, gl_context);
//     SDL_GL_SetSwapInterval(1); // Enable vsync

//     // Initialize OpenGL loader
//     bool err = glewInit() != GLEW_OK;
//     if (err) {
//         std::cerr << "Failed to initialize OpenGL loader!" << std::endl;
//         return -1;
//     }

//     // Setup Dear ImGui context
//     IMGUI_CHECKVERSION();
//     ImGui::CreateContext();
//     ImGuiIO& io = ImGui::GetIO(); (void)io;

//     // Setup Dear ImGui style
//     ImGui::StyleColorsDark();

//     // Setup Platform/Renderer bindings
//     ImGui_ImplSDL2_InitForOpenGL(window, gl_context);
//     ImGui_ImplOpenGL3_Init("#version 130");

//     bool done = false;

//     // Create a tree
//     Node<double> root_node(1.1);
//     Tree<double> tree; // Binary tree that contains doubles.
//     tree.add_root(root_node);
//     Node<double> n1(1.2);
//     Node<double> n2(1.3);
//     Node<double> n3(1.4);
//     Node<double> n4(1.5);
//     Node<double> n5(1.6);

//     tree.add_sub_node(&root_node, &n1);
//     tree.add_sub_node(&root_node, &n2);
//     tree.add_sub_node(&n1, &n3);
//     tree.add_sub_node(&n1, &n4);
//     tree.add_sub_node(&n2, &n5);

//     // Main loop
//     while (!done) {
//         SDL_Event event;
//         while (SDL_PollEvent(&event)) {
//             ImGui_ImplSDL2_ProcessEvent(&event);
//             if (event.type == SDL_QUIT)
//                 done = true;
//             if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE && event.window.windowID == SDL_GetWindowID(window))
//                 done = true;
//         }

//         // Start the ImGui frame
//         ImGui_ImplOpenGL3_NewFrame();
//         ImGui_ImplSDL2_NewFrame(window);
//         ImGui::NewFrame();

//         // Render your GUI
//         visualizeTree(tree.get_root());

//         // Rendering
//         ImGui::Render();
//         glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
//         glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
//         glClear(GL_COLOR_BUFFER_BIT);
//         ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

//         SDL_GL_SwapWindow(window);
//     }

//     // Cleanup
//     ImGui_ImplOpenGL3_Shutdown();
//     ImGui_ImplSDL2_Shutdown();
//     ImGui::DestroyContext();

//     SDL_GL_DeleteContext(gl_context);
//     SDL_DestroyWindow(window);
//     SDL_Quit();

//     return 0;
// }
