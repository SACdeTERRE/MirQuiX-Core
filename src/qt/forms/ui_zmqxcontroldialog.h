/********************************************************************************
** Form generated from reading UI file 'zmqxcontroldialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZMQXCONTROLDIALOG_H
#define UI_ZMQXCONTROLDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ZmqxControlDialog
{
public:
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QLabel *labelQuantity;
    QLabel *labelQuantity_int;
    QLabel *labelZmqx;
    QLabel *labelZmqx_int;
    QPushButton *pushButtonAll;
    QVBoxLayout *verticalLayout;
    QTreeWidget *treeWidget;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ZmqxControlDialog)
    {
        if (ZmqxControlDialog->objectName().isEmpty())
            ZmqxControlDialog->setObjectName(QStringLiteral("ZmqxControlDialog"));
        ZmqxControlDialog->resize(681, 384);
        ZmqxControlDialog->setMinimumSize(QSize(681, 384));
        gridLayout = new QGridLayout(ZmqxControlDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        labelQuantity = new QLabel(ZmqxControlDialog);
        labelQuantity->setObjectName(QStringLiteral("labelQuantity"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelQuantity);

        labelQuantity_int = new QLabel(ZmqxControlDialog);
        labelQuantity_int->setObjectName(QStringLiteral("labelQuantity_int"));

        formLayout->setWidget(0, QFormLayout::FieldRole, labelQuantity_int);

        labelZmqx = new QLabel(ZmqxControlDialog);
        labelZmqx->setObjectName(QStringLiteral("labelZmqx"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelZmqx);

        labelZmqx_int = new QLabel(ZmqxControlDialog);
        labelZmqx_int->setObjectName(QStringLiteral("labelZmqx_int"));

        formLayout->setWidget(1, QFormLayout::FieldRole, labelZmqx_int);

        pushButtonAll = new QPushButton(ZmqxControlDialog);
        pushButtonAll->setObjectName(QStringLiteral("pushButtonAll"));

        formLayout->setWidget(2, QFormLayout::LabelRole, pushButtonAll);


        gridLayout->addLayout(formLayout, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        treeWidget = new QTreeWidget(ZmqxControlDialog);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(3, QStringLiteral("Confirmations"));
        __qtreewidgetitem->setText(2, QStringLiteral("zmqx Public ID"));
        __qtreewidgetitem->setText(1, QStringLiteral("Denomination"));
        __qtreewidgetitem->setText(0, QStringLiteral("Select"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setMinimumSize(QSize(0, 250));
        treeWidget->setAlternatingRowColors(true);
        treeWidget->setSortingEnabled(true);
        treeWidget->setColumnCount(5);
        treeWidget->header()->setDefaultSectionSize(100);

        verticalLayout->addWidget(treeWidget);

        buttonBox = new QDialogButtonBox(ZmqxControlDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        gridLayout->addLayout(verticalLayout, 1, 0, 1, 1);


        retranslateUi(ZmqxControlDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ZmqxControlDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ZmqxControlDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ZmqxControlDialog);
    } // setupUi

    void retranslateUi(QDialog *ZmqxControlDialog)
    {
        ZmqxControlDialog->setWindowTitle(QApplication::translate("ZmqxControlDialog", "Select zmqx to Spend", 0));
        labelQuantity->setText(QApplication::translate("ZmqxControlDialog", "Quantity", 0));
        labelQuantity_int->setText(QApplication::translate("ZmqxControlDialog", "0", 0));
        labelZmqx->setText(QApplication::translate("ZmqxControlDialog", "zmqx", 0));
        labelZmqx_int->setText(QApplication::translate("ZmqxControlDialog", "0", 0));
        pushButtonAll->setText(QApplication::translate("ZmqxControlDialog", "Select/Deselect All", 0));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(4, QApplication::translate("ZmqxControlDialog", "Is Spendable", 0));
    } // retranslateUi

};

namespace Ui {
    class ZmqxControlDialog: public Ui_ZmqxControlDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZMQXCONTROLDIALOG_H
