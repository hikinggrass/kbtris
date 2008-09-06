/********************************************************************************
** Form generated from reading ui file 'test005.ui'
**
** Created: Sat 6. Sep 14:21:50 2008
**      by: Qt User Interface Compiler version 4.4.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_TEST005_H
#define UI_TEST005_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_test005Class
{
public:
    QLabel *background;
    QLabel *lblLevel;
    QLabel *lblReihen;
    QLabel *lblScore;
    QLabel *menubg;
    QPushButton *btnSpielstarten;
    QPushButton *btnHighscores;
    QPushButton *btnCredits;
    QPushButton *btnBeenden;

    void setupUi(QWidget *test005Class)
    {
    if (test005Class->objectName().isEmpty())
        test005Class->setObjectName(QString::fromUtf8("test005Class"));
    test005Class->resize(361, 511);
    QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(test005Class->sizePolicy().hasHeightForWidth());
    test005Class->setSizePolicy(sizePolicy);
    background = new QLabel(test005Class);
    background->setObjectName(QString::fromUtf8("background"));
    background->setGeometry(QRect(0, 0, 361, 511));
    lblLevel = new QLabel(test005Class);
    lblLevel->setObjectName(QString::fromUtf8("lblLevel"));
    lblLevel->setGeometry(QRect(325, 214, 20, 13));
    QPalette palette;
    QBrush brush(QColor(255, 255, 255, 255));
    brush.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
    QBrush brush1(QColor(0, 0, 0, 255));
    brush1.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Text, brush1);
    palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
    palette.setBrush(QPalette::Inactive, QPalette::Text, brush1);
    QBrush brush2(QColor(117, 116, 118, 255));
    brush2.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
    palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
    lblLevel->setPalette(palette);
    QFont font;
    font.setFamily(QString::fromUtf8("Arial"));
    lblLevel->setFont(font);
    lblLevel->setLayoutDirection(Qt::RightToLeft);
    lblLevel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
    lblReihen = new QLabel(test005Class);
    lblReihen->setObjectName(QString::fromUtf8("lblReihen"));
    lblReihen->setGeometry(QRect(325, 264, 20, 13));
    QPalette palette1;
    palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
    palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
    palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
    lblReihen->setPalette(palette1);
    lblReihen->setFont(font);
    lblReihen->setLayoutDirection(Qt::RightToLeft);
    lblScore = new QLabel(test005Class);
    lblScore->setObjectName(QString::fromUtf8("lblScore"));
    lblScore->setGeometry(QRect(325, 314, 20, 13));
    QPalette palette2;
    palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
    palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
    palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
    lblScore->setPalette(palette2);
    lblScore->setFont(font);
    lblScore->setLayoutDirection(Qt::RightToLeft);
    menubg = new QLabel(test005Class);
    menubg->setObjectName(QString::fromUtf8("menubg"));
    menubg->setGeometry(QRect(0, 0, 361, 511));
    btnSpielstarten = new QPushButton(test005Class);
    btnSpielstarten->setObjectName(QString::fromUtf8("btnSpielstarten"));
    btnSpielstarten->setGeometry(QRect(130, 130, 75, 23));
    btnHighscores = new QPushButton(test005Class);
    btnHighscores->setObjectName(QString::fromUtf8("btnHighscores"));
    btnHighscores->setGeometry(QRect(130, 160, 75, 23));
    btnCredits = new QPushButton(test005Class);
    btnCredits->setObjectName(QString::fromUtf8("btnCredits"));
    btnCredits->setGeometry(QRect(130, 190, 75, 23));
    btnBeenden = new QPushButton(test005Class);
    btnBeenden->setObjectName(QString::fromUtf8("btnBeenden"));
    btnBeenden->setGeometry(QRect(130, 220, 75, 23));

    retranslateUi(test005Class);

    QMetaObject::connectSlotsByName(test005Class);
    } // setupUi

    void retranslateUi(QWidget *test005Class)
    {
    test005Class->setWindowTitle(QApplication::translate("test005Class", "test005", 0, QApplication::UnicodeUTF8));
    background->setText(QString());
    lblLevel->setText(QApplication::translate("test005Class", "10", 0, QApplication::UnicodeUTF8));
    lblReihen->setText(QApplication::translate("test005Class", "10", 0, QApplication::UnicodeUTF8));
    lblScore->setText(QApplication::translate("test005Class", "10", 0, QApplication::UnicodeUTF8));
    menubg->setText(QString());
    btnSpielstarten->setText(QApplication::translate("test005Class", "Spiel starten", 0, QApplication::UnicodeUTF8));
    btnHighscores->setText(QApplication::translate("test005Class", "Highscores", 0, QApplication::UnicodeUTF8));
    btnCredits->setText(QApplication::translate("test005Class", "Credits", 0, QApplication::UnicodeUTF8));
    btnBeenden->setText(QApplication::translate("test005Class", "Beenden", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(test005Class);
    } // retranslateUi

};

namespace Ui {
    class test005Class: public Ui_test005Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST005_H
