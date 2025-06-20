#ifndef STYLE_H
#define STYLE_H
#include <QProxyStyle>
#include <QStyleOption>
#include <QPainter>


const QString ButtonStyle = QString(R"(
    QPushButton
    {
        background: none;
        color: palette(text);
        border: 1px solid palette(dark);
        border-radius: 4px;
        padding: 6px 12px;
    }
    QPushButton:hover
    {
        background-color: palette(light);
    }
    QPushButton:pressed
    {
        background-color: palette(highlight);
    }
)");

const QString ComboBoxStyle = QString(R"(
    QComboBox
    {
        background-color: palette(window);
        color: palette(text);
        border: 1px solid palette(dark);
        border-radius: 4px;
        padding: 6px 12px;
    }
    QComboBox:hover
    {
        background-color: palette(light);
    }
    QComboBox:pressed
    {
        background-color: lightseagreen;
    }
    QComboBox::drop-down
    {
        border-left: 1px solid palette(highlight);
        width: 20px;
    }
    QComboBox::down-arrow
    {
        image: url(":/icons/down_arrow/assets/down_arrow.svg");
        width: 8px;
        height: 8px;
    }
)");

const QString LineEditStyle = QString(R"(
    QLineEdit
    {
        background-color: palette(base);
        color: palette(text);
        border: 1px solid palette(dark);
        border-radius: 4px;
        padding: 0px 0px;
        font-size: 20px;
    }
    QLineEdit:focus
    {
        border: 1px solid palette(highlight);
    }
)");

const QString LabelStyle = QString(R"(
    QLabel
    {
        color: palette(text);
        background-color: transparent;
        padding: 4px;
        border: 1px solid palette(dark);
        border-radius: 4px;
        font-size: 20px;
    }
)");

#endif // STYLE_H
