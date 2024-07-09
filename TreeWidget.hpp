#ifndef TREEWIDGET_HPP
#define TREEWIDGET_HPP
#pragma once
#include <QWidget>
#include <QPainter>
#include <QString>
#include "Tree.hpp"
#include "Complex.hpp"
#include "Iterators.hpp"

template <typename T, int K = 2>
class TreeWidget : public QWidget {
public:
    TreeWidget(Tree<T, K>& tree, QWidget *parent = nullptr) : QWidget(parent), m_tree(tree) {}

protected:
    void paintEvent(QPaintEvent *event) override {
        Q_UNUSED(event);
        QPainter painter(this);
        drawTree(&painter, m_tree.begin_bfs_scan(), width() / 2, 50, width() / 4);
    }

private:
    Tree<T, K>& m_tree;

    void drawTree(QPainter* painter, bfs_scan_iterator<T> it, int x, int y, int xOffset) {
        if (it == m_tree.end_bfs_scan()) return;

        painter->drawEllipse(x - 20, y - 20, 40, 40);
        
        QString valueStr = valueToString(it->get_value());
        painter->drawText(x - 15, y + 5, valueStr);

        int childCount = it->get_children().size();
        int childX = x - (childCount - 1) * xOffset / 2;

        for (const auto& child : it->get_children()) {
            painter->drawLine(x, y + 20, childX, y + 80);
            drawTree(painter, bfs_scan_iterator<T>(child), childX, y + 100, xOffset / K);
            childX += xOffset;
        }
    }

    QString valueToString(const T& value) {
        if constexpr (std::is_same_v<T, double> || std::is_same_v<T, int> || std::is_same_v<T, float>) {
            return QString::number(value);
        } else if constexpr (std::is_same_v<T, Complex>) {
            return QString("%1 + %2i").arg(value.getReal()).arg(value.getImag());
        } else if constexpr (std::is_same_v<T, std::string>) {
            return QString::fromStdString(value);
        } else {
            return QString::fromStdString(std::to_string(value));
        }
    }
};
#endif // TREEWIDGET_HPP