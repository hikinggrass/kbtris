/********************************************************************************
** Form generated from reading ui file 'test005.ui'
**
** Created: Mon 15. Sep 18:26:49 2008
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
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

//QT_BEGIN_NAMESPACE

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
    QLabel *highscore;
    QPushButton *btnSaveHighscore;
    QLineEdit *edtName;

    void setupUi(QWidget *test005Class)
    {
    if (test005Class->objectName().isEmpty())
        test005Class->setObjectName(QString::fromUtf8("test005Class"));
    test005Class->setWindowModality(Qt::NonModal);
    test005Class->setEnabled(true);
    test005Class->resize(361, 511);
    QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(test005Class->sizePolicy().hasHeightForWidth());
    test005Class->setSizePolicy(sizePolicy);
    test005Class->setMinimumSize(QSize(361, 511));
    test005Class->setMaximumSize(QSize(361, 511));
    QIcon icon;
    icon.addPixmap(QPixmap(QString::fromUtf8(":/icon/icon.ico")), QIcon::Normal, QIcon::Off);
    test005Class->setWindowIcon(icon);
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
    btnSpielstarten->setEnabled(true);
    btnSpielstarten->setGeometry(QRect(60, 150, 230, 34));
    btnSpielstarten->setIconSize(QSize(230, 34));
    btnSpielstarten->setAutoDefault(false);
    btnSpielstarten->setFlat(false);
    btnHighscores = new QPushButton(test005Class);
    btnHighscores->setObjectName(QString::fromUtf8("btnHighscores"));
    btnHighscores->setGeometry(QRect(60, 200, 230, 34));
    btnHighscores->setCheckable(false);
    btnHighscores->setChecked(false);
    btnCredits = new QPushButton(test005Class);
    btnCredits->setObjectName(QString::fromUtf8("btnCredits"));
    btnCredits->setGeometry(QRect(60, 250, 230, 34));
    btnBeenden = new QPushButton(test005Class);
    btnBeenden->setObjectName(QString::fromUtf8("btnBeenden"));
    btnBeenden->setGeometry(QRect(60, 300, 230, 34));
    highscore = new QLabel(test005Class);
    highscore->setObjectName(QString::fromUtf8("highscore"));
    highscore->setGeometry(QRect(30, 176, 300, 150));
    btnSaveHighscore = new QPushButton(test005Class);
    btnSaveHighscore->setObjectName(QString::fromUtf8("btnSaveHighscore"));
    btnSaveHighscore->setEnabled(true);
    btnSaveHighscore->setGeometry(QRect(215, 289, 115, 23));
    btnSaveHighscore->setIconSize(QSize(230, 34));
    btnSaveHighscore->setAutoDefault(false);
    btnSaveHighscore->setFlat(false);
    edtName = new QLineEdit(test005Class);
    edtName->setObjectName(QString::fromUtf8("edtName"));
    edtName->setGeometry(QRect(141, 262, 129, 21));

    retranslateUi(test005Class);

    QMetaObject::connectSlotsByName(test005Class);
    } // setupUi

    void retranslateUi(QWidget *test005Class)
    {
    test005Class->setWindowTitle(QApplication::translate("test005Class", "KB-TRIS", 0, QApplication::UnicodeUTF8));
    background->setText(QString());
    lblLevel->setText(QApplication::translate("test005Class", "10", 0, QApplication::UnicodeUTF8));
    lblReihen->setText(QApplication::translate("test005Class", "10", 0, QApplication::UnicodeUTF8));
    lblScore->setText(QApplication::translate("test005Class", "10", 0, QApplication::UnicodeUTF8));
    menubg->setText(QString());
    btnSpielstarten->setText(QApplication::translate("test005Class", "Spiel starten", 0, QApplication::UnicodeUTF8));
    btnHighscores->setText(QApplication::translate("test005Class", "Highscores", 0, QApplication::UnicodeUTF8));
    btnCredits->setText(QApplication::translate("test005Class", "Credits", 0, QApplication::UnicodeUTF8));
    btnBeenden->setText(QApplication::translate("test005Class", "Beenden", 0, QApplication::UnicodeUTF8));
    highscore->setText(QString());
    btnSaveHighscore->setText(QApplication::translate("test005Class", "Speichern", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(test005Class);
    } // retranslateUi

};

namespace Ui {
    class test005Class: public Ui_test005Class {};
} // namespace Ui

//QT_END_NAMESPACE

#endif // UI_TEST005_H
