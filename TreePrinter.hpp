// #pragma once
// #include "Tree.hpp"
// #include "imgui.h"
// #include <vector>
// #include <algorithm>
// #include <functional>

// template <typename T>
// struct NodePosition {
//     Node<T>* node;
//     ImVec2 pos;
// };

// template <typename T>
// void visualizeTree(Node<T>* root) {
//     if (root == nullptr) return;

//     ImGui::Begin("Tree Visualization");

//     ImDrawList* draw_list = ImGui::GetWindowDrawList();
//     ImVec2 window_pos = ImGui::GetWindowPos();
//     ImVec2 window_size = ImGui::GetWindowSize();
//     ImVec2 canvas_pos = ImVec2(window_pos.x, window_pos.y); // top-left
//     ImVec2 canvas_size = window_size;

//     float node_radius = 20.0f;
//     float horizontal_spacing = 100.0f;
//     float vertical_spacing = 50.0f;

//     std::vector<NodePosition<T>> nodes_to_draw;
//     std::function<void(Node<T>*, float, float, float)> traverse = [&](Node<T>* node, float x, float y, float offset) {
//         if (node == nullptr) return;

//         ImVec2 node_pos = ImVec2(canvas_pos.x + x, canvas_pos.y + y);
//         nodes_to_draw.push_back({ node, node_pos });

//         float child_x = x - offset / 2.0f;
//         for (auto& child : node->get_children()) {
//             traverse(child, child_x, y + vertical_spacing, offset / 2.0f);
//             child_x += offset;
//         }
//     };
//     traverse(root, canvas_size.x / 2.0f, node_radius + 20.0f, canvas_size.x / 2.0f);

//     // Draw the nodes and connections
//     for (const auto& node_pos : nodes_to_draw) {
//         for (auto& child : node_pos.node->get_children()) {
//             auto it = std::find_if(nodes_to_draw.begin(), nodes_to_draw.end(), [&](const NodePosition<T>& np) { return np.node == child; });
//             if (it != nodes_to_draw.end()) {
//                 draw_list->AddLine(node_pos.pos, it->pos, IM_COL32(200, 200, 200, 255), 2.0f);
//             }
//         }
//         draw_list->AddCircleFilled(node_pos.pos, node_radius, IM_COL32(255, 255, 255, 255), 32);
//         draw_list->AddCircle(node_pos.pos, node_radius, IM_COL32(0, 0, 0, 255), 32, 2.0f);

//         char label[32];
//         sprintf(label, "%.1f", node_pos.node->get_value());
//         ImVec2 text_size = ImGui::CalcTextSize(label);
//         draw_list->AddText(ImVec2(node_pos.pos.x - text_size.x / 2, node_pos.pos.y - text_size.y / 2), IM_COL32(0, 0, 0, 255), label);
//     }

//     ImGui::End();
// }
