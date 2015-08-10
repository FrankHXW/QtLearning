/********************************************************************************
** Form generated from reading UI file 'sortdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SORTDIALOG_H
#define UI_SORTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SortDialog
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *primaryGroupBox;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QComboBox *primaryOrderCombo;
    QLabel *primaryColumnLabel;
    QComboBox *primaryColumnCombo;
    QLabel *primaryOrderLabel;
    QVBoxLayout *verticalLayout;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QPushButton *moreButton;
    QGroupBox *secondaryGroupBox;
    QGridLayout *gridLayout_2;
    QLabel *secondaryOrderLabel;
    QComboBox *secondaryOrderCombo;
    QLabel *secondaryColumnLabel;
    QComboBox *secondaryColumnCombo;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *tertiaryGroupBox;
    QGridLayout *gridLayout_4;
    QLabel *tertiaryColumnLabel;
    QComboBox *tertiaryColumnCombo;
    QSpacerItem *horizontalSpacer_4;
    QLabel *tertiaryOrderLabel;
    QComboBox *tertiaryOrderCombo;

    void setupUi(QDialog *SortDialog)
    {
        if (SortDialog->objectName().isEmpty())
            SortDialog->setObjectName(QStringLiteral("SortDialog"));
        SortDialog->resize(321, 357);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SortDialog->sizePolicy().hasHeightForWidth());
        SortDialog->setSizePolicy(sizePolicy);
        gridLayout_3 = new QGridLayout(SortDialog);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        primaryGroupBox = new QGroupBox(SortDialog);
        primaryGroupBox->setObjectName(QStringLiteral("primaryGroupBox"));
        gridLayout = new QGridLayout(primaryGroupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer = new QSpacerItem(39, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        primaryOrderCombo = new QComboBox(primaryGroupBox);
        primaryOrderCombo->setObjectName(QStringLiteral("primaryOrderCombo"));

        gridLayout->addWidget(primaryOrderCombo, 1, 1, 1, 2);

        primaryColumnLabel = new QLabel(primaryGroupBox);
        primaryColumnLabel->setObjectName(QStringLiteral("primaryColumnLabel"));

        gridLayout->addWidget(primaryColumnLabel, 0, 0, 1, 1);

        primaryColumnCombo = new QComboBox(primaryGroupBox);
        primaryColumnCombo->setObjectName(QStringLiteral("primaryColumnCombo"));

        gridLayout->addWidget(primaryColumnCombo, 0, 1, 1, 1);

        primaryOrderLabel = new QLabel(primaryGroupBox);
        primaryOrderLabel->setObjectName(QStringLiteral("primaryOrderLabel"));

        gridLayout->addWidget(primaryOrderLabel, 1, 0, 1, 1);


        gridLayout_3->addWidget(primaryGroupBox, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        okButton = new QPushButton(SortDialog);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setDefault(true);

        verticalLayout->addWidget(okButton);

        cancelButton = new QPushButton(SortDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        verticalLayout->addWidget(cancelButton);

        moreButton = new QPushButton(SortDialog);
        moreButton->setObjectName(QStringLiteral("moreButton"));
        moreButton->setCheckable(true);

        verticalLayout->addWidget(moreButton);


        gridLayout_3->addLayout(verticalLayout, 0, 1, 1, 1);

        secondaryGroupBox = new QGroupBox(SortDialog);
        secondaryGroupBox->setObjectName(QStringLiteral("secondaryGroupBox"));
        gridLayout_2 = new QGridLayout(secondaryGroupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        secondaryOrderLabel = new QLabel(secondaryGroupBox);
        secondaryOrderLabel->setObjectName(QStringLiteral("secondaryOrderLabel"));

        gridLayout_2->addWidget(secondaryOrderLabel, 1, 0, 1, 1);

        secondaryOrderCombo = new QComboBox(secondaryGroupBox);
        secondaryOrderCombo->setObjectName(QStringLiteral("secondaryOrderCombo"));

        gridLayout_2->addWidget(secondaryOrderCombo, 1, 1, 1, 2);

        secondaryColumnLabel = new QLabel(secondaryGroupBox);
        secondaryColumnLabel->setObjectName(QStringLiteral("secondaryColumnLabel"));

        gridLayout_2->addWidget(secondaryColumnLabel, 0, 0, 1, 1);

        secondaryColumnCombo = new QComboBox(secondaryGroupBox);
        secondaryColumnCombo->setObjectName(QStringLiteral("secondaryColumnCombo"));

        gridLayout_2->addWidget(secondaryColumnCombo, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 2, 1, 1);


        gridLayout_3->addWidget(secondaryGroupBox, 1, 0, 1, 1);

        tertiaryGroupBox = new QGroupBox(SortDialog);
        tertiaryGroupBox->setObjectName(QStringLiteral("tertiaryGroupBox"));
        gridLayout_4 = new QGridLayout(tertiaryGroupBox);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        tertiaryColumnLabel = new QLabel(tertiaryGroupBox);
        tertiaryColumnLabel->setObjectName(QStringLiteral("tertiaryColumnLabel"));

        gridLayout_4->addWidget(tertiaryColumnLabel, 0, 0, 1, 1);

        tertiaryColumnCombo = new QComboBox(tertiaryGroupBox);
        tertiaryColumnCombo->setObjectName(QStringLiteral("tertiaryColumnCombo"));

        gridLayout_4->addWidget(tertiaryColumnCombo, 0, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_4, 0, 2, 1, 1);

        tertiaryOrderLabel = new QLabel(tertiaryGroupBox);
        tertiaryOrderLabel->setObjectName(QStringLiteral("tertiaryOrderLabel"));

        gridLayout_4->addWidget(tertiaryOrderLabel, 1, 0, 1, 1);

        tertiaryOrderCombo = new QComboBox(tertiaryGroupBox);
        tertiaryOrderCombo->setObjectName(QStringLiteral("tertiaryOrderCombo"));

        gridLayout_4->addWidget(tertiaryOrderCombo, 1, 1, 1, 2);


        gridLayout_3->addWidget(tertiaryGroupBox, 2, 0, 1, 1);

        QWidget::setTabOrder(okButton, cancelButton);
        QWidget::setTabOrder(cancelButton, moreButton);
        QWidget::setTabOrder(moreButton, primaryColumnCombo);
        QWidget::setTabOrder(primaryColumnCombo, primaryOrderCombo);
        QWidget::setTabOrder(primaryOrderCombo, secondaryColumnCombo);
        QWidget::setTabOrder(secondaryColumnCombo, secondaryOrderCombo);
        QWidget::setTabOrder(secondaryOrderCombo, tertiaryColumnCombo);
        QWidget::setTabOrder(tertiaryColumnCombo, tertiaryOrderCombo);

        retranslateUi(SortDialog);
        QObject::connect(okButton, SIGNAL(clicked()), SortDialog, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), SortDialog, SLOT(reject()));
        QObject::connect(moreButton, SIGNAL(toggled(bool)), secondaryGroupBox, SLOT(setVisible(bool)));
        QObject::connect(moreButton, SIGNAL(toggled(bool)), tertiaryGroupBox, SLOT(setVisible(bool)));

        QMetaObject::connectSlotsByName(SortDialog);
    } // setupUi

    void retranslateUi(QDialog *SortDialog)
    {
        SortDialog->setWindowTitle(QApplication::translate("SortDialog", "Sort", 0));
        primaryGroupBox->setTitle(QApplication::translate("SortDialog", "&Primary Key", 0));
        primaryOrderCombo->clear();
        primaryOrderCombo->insertItems(0, QStringList()
         << QApplication::translate("SortDialog", "Ascending", 0)
         << QApplication::translate("SortDialog", "Descending", 0)
        );
        primaryColumnLabel->setText(QApplication::translate("SortDialog", "Column:", 0));
        primaryColumnCombo->clear();
        primaryColumnCombo->insertItems(0, QStringList()
         << QApplication::translate("SortDialog", "None", 0)
        );
        primaryOrderLabel->setText(QApplication::translate("SortDialog", "Order:", 0));
        okButton->setText(QApplication::translate("SortDialog", "OK", 0));
        cancelButton->setText(QApplication::translate("SortDialog", "Cancel", 0));
        moreButton->setText(QApplication::translate("SortDialog", "&More", 0));
        secondaryGroupBox->setTitle(QApplication::translate("SortDialog", "&Secondary Key", 0));
        secondaryOrderLabel->setText(QApplication::translate("SortDialog", "Order:", 0));
        secondaryOrderCombo->clear();
        secondaryOrderCombo->insertItems(0, QStringList()
         << QApplication::translate("SortDialog", "Ascending", 0)
         << QApplication::translate("SortDialog", "Descending", 0)
        );
        secondaryColumnLabel->setText(QApplication::translate("SortDialog", "Column:", 0));
        secondaryColumnCombo->clear();
        secondaryColumnCombo->insertItems(0, QStringList()
         << QApplication::translate("SortDialog", "None", 0)
        );
        tertiaryGroupBox->setTitle(QApplication::translate("SortDialog", "&Tertiary Key", 0));
        tertiaryColumnLabel->setText(QApplication::translate("SortDialog", "Column:", 0));
        tertiaryColumnCombo->clear();
        tertiaryColumnCombo->insertItems(0, QStringList()
         << QApplication::translate("SortDialog", "None", 0)
        );
        tertiaryOrderLabel->setText(QApplication::translate("SortDialog", "Order:", 0));
        tertiaryOrderCombo->clear();
        tertiaryOrderCombo->insertItems(0, QStringList()
         << QApplication::translate("SortDialog", "Ascending", 0)
         << QApplication::translate("SortDialog", "Descending", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class SortDialog: public Ui_SortDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SORTDIALOG_H
