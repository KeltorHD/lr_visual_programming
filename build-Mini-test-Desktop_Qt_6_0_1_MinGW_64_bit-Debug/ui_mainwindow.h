/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_4;
    QTabWidget *tabWidget;
    QWidget *info;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QPushButton *to_test;
    QSpacerItem *verticalSpacer_2;
    QWidget *testing;
    QVBoxLayout *verticalLayout_5;
    QProgressBar *progress_bar;
    QStackedWidget *type_answers;
    QWidget *start_test;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_7;
    QSpacerItem *verticalSpacer_6;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *start_testing;
    QSpacerItem *verticalSpacer_7;
    QWidget *installation_of_correspondence;
    QVBoxLayout *verticalLayout_11;
    QSpacerItem *verticalSpacer_16;
    QLabel *question_4;
    QFrame *line_4;
    QSpacerItem *verticalSpacer_15;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_7;
    QGridLayout *gridLayout_5;
    QComboBox *combo2;
    QLabel *text1;
    QComboBox *combo3;
    QLabel *text2;
    QLabel *text3;
    QComboBox *combo1;
    QLabel *text4;
    QComboBox *combo4;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer_14;
    QWidget *one_of_four;
    QVBoxLayout *verticalLayout_6;
    QSpacerItem *verticalSpacer_5;
    QLabel *question;
    QFrame *line;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout;
    QRadioButton *answer3;
    QRadioButton *answer1;
    QRadioButton *answer2;
    QRadioButton *answer4;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QWidget *some_of_four;
    QVBoxLayout *verticalLayout_9;
    QSpacerItem *verticalSpacer_10;
    QLabel *question_2;
    QFrame *line_2;
    QSpacerItem *verticalSpacer_9;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_4;
    QGridLayout *gridLayout_4;
    QCheckBox *answer1_3;
    QCheckBox *answer3_3;
    QCheckBox *answer2_3;
    QCheckBox *answer4_3;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_8;
    QWidget *write_answer;
    QVBoxLayout *verticalLayout_10;
    QSpacerItem *verticalSpacer_13;
    QLabel *question_3;
    QFrame *line_3;
    QSpacerItem *verticalSpacer_12;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *answer;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_11;
    QGridLayout *gridLayout_2;
    QPushButton *check_button;
    QPushButton *prev_button;
    QPushButton *next_button;
    QWidget *result;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(828, 555);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_4 = new QVBoxLayout(centralwidget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        info = new QWidget();
        info->setObjectName(QString::fromUtf8("info"));
        verticalLayout_2 = new QVBoxLayout(info);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetNoConstraint);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label = new QLabel(info);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        to_test = new QPushButton(info);
        to_test->setObjectName(QString::fromUtf8("to_test"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(to_test->sizePolicy().hasHeightForWidth());
        to_test->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(to_test);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        verticalLayout_2->addLayout(verticalLayout);

        tabWidget->addTab(info, QString());
        testing = new QWidget();
        testing->setObjectName(QString::fromUtf8("testing"));
        verticalLayout_5 = new QVBoxLayout(testing);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        progress_bar = new QProgressBar(testing);
        progress_bar->setObjectName(QString::fromUtf8("progress_bar"));
        progress_bar->setEnabled(false);
        progress_bar->setValue(0);
        progress_bar->setTextVisible(true);

        verticalLayout_5->addWidget(progress_bar);

        type_answers = new QStackedWidget(testing);
        type_answers->setObjectName(QString::fromUtf8("type_answers"));
        start_test = new QWidget();
        start_test->setObjectName(QString::fromUtf8("start_test"));
        verticalLayout_8 = new QVBoxLayout(start_test);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_6);

        label_2 = new QLabel(start_test);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        verticalLayout_7->addWidget(label_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        start_testing = new QPushButton(start_test);
        start_testing->setObjectName(QString::fromUtf8("start_testing"));
        sizePolicy.setHeightForWidth(start_testing->sizePolicy().hasHeightForWidth());
        start_testing->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(start_testing);


        verticalLayout_7->addLayout(horizontalLayout_4);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_7);


        verticalLayout_8->addLayout(verticalLayout_7);

        type_answers->addWidget(start_test);
        installation_of_correspondence = new QWidget();
        installation_of_correspondence->setObjectName(QString::fromUtf8("installation_of_correspondence"));
        verticalLayout_11 = new QVBoxLayout(installation_of_correspondence);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalSpacer_16 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_11->addItem(verticalSpacer_16);

        question_4 = new QLabel(installation_of_correspondence);
        question_4->setObjectName(QString::fromUtf8("question_4"));
        question_4->setAlignment(Qt::AlignCenter);

        verticalLayout_11->addWidget(question_4);

        line_4 = new QFrame(installation_of_correspondence);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_11->addWidget(line_4);

        verticalSpacer_15 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_11->addItem(verticalSpacer_15);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        combo2 = new QComboBox(installation_of_correspondence);
        combo2->setObjectName(QString::fromUtf8("combo2"));

        gridLayout_5->addWidget(combo2, 1, 1, 1, 1);

        text1 = new QLabel(installation_of_correspondence);
        text1->setObjectName(QString::fromUtf8("text1"));

        gridLayout_5->addWidget(text1, 0, 0, 1, 1);

        combo3 = new QComboBox(installation_of_correspondence);
        combo3->setObjectName(QString::fromUtf8("combo3"));

        gridLayout_5->addWidget(combo3, 2, 1, 1, 1);

        text2 = new QLabel(installation_of_correspondence);
        text2->setObjectName(QString::fromUtf8("text2"));

        gridLayout_5->addWidget(text2, 1, 0, 1, 1);

        text3 = new QLabel(installation_of_correspondence);
        text3->setObjectName(QString::fromUtf8("text3"));

        gridLayout_5->addWidget(text3, 2, 0, 1, 1);

        combo1 = new QComboBox(installation_of_correspondence);
        combo1->setObjectName(QString::fromUtf8("combo1"));

        gridLayout_5->addWidget(combo1, 0, 1, 1, 1);

        text4 = new QLabel(installation_of_correspondence);
        text4->setObjectName(QString::fromUtf8("text4"));

        gridLayout_5->addWidget(text4, 3, 0, 1, 1);

        combo4 = new QComboBox(installation_of_correspondence);
        combo4->setObjectName(QString::fromUtf8("combo4"));

        gridLayout_5->addWidget(combo4, 3, 1, 1, 1);


        horizontalLayout_7->addLayout(gridLayout_5);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_8);


        verticalLayout_11->addLayout(horizontalLayout_7);

        verticalSpacer_14 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_11->addItem(verticalSpacer_14);

        type_answers->addWidget(installation_of_correspondence);
        one_of_four = new QWidget();
        one_of_four->setObjectName(QString::fromUtf8("one_of_four"));
        verticalLayout_6 = new QVBoxLayout(one_of_four);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_5);

        question = new QLabel(one_of_four);
        question->setObjectName(QString::fromUtf8("question"));
        question->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(question);

        line = new QFrame(one_of_four);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_6->addWidget(line);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        answer3 = new QRadioButton(one_of_four);
        answer3->setObjectName(QString::fromUtf8("answer3"));

        gridLayout->addWidget(answer3, 0, 1, 1, 1);

        answer1 = new QRadioButton(one_of_four);
        answer1->setObjectName(QString::fromUtf8("answer1"));

        gridLayout->addWidget(answer1, 0, 0, 1, 1);

        answer2 = new QRadioButton(one_of_four);
        answer2->setObjectName(QString::fromUtf8("answer2"));

        gridLayout->addWidget(answer2, 1, 0, 1, 1);

        answer4 = new QRadioButton(one_of_four);
        answer4->setObjectName(QString::fromUtf8("answer4"));

        gridLayout->addWidget(answer4, 1, 1, 1, 1);


        horizontalLayout_3->addLayout(gridLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_6->addLayout(horizontalLayout_3);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_3);

        type_answers->addWidget(one_of_four);
        some_of_four = new QWidget();
        some_of_four->setObjectName(QString::fromUtf8("some_of_four"));
        verticalLayout_9 = new QVBoxLayout(some_of_four);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_10);

        question_2 = new QLabel(some_of_four);
        question_2->setObjectName(QString::fromUtf8("question_2"));
        question_2->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(question_2);

        line_2 = new QFrame(some_of_four);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_9->addWidget(line_2);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_9);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        answer1_3 = new QCheckBox(some_of_four);
        answer1_3->setObjectName(QString::fromUtf8("answer1_3"));

        gridLayout_4->addWidget(answer1_3, 0, 0, 1, 1);

        answer3_3 = new QCheckBox(some_of_four);
        answer3_3->setObjectName(QString::fromUtf8("answer3_3"));

        gridLayout_4->addWidget(answer3_3, 0, 1, 1, 1);

        answer2_3 = new QCheckBox(some_of_four);
        answer2_3->setObjectName(QString::fromUtf8("answer2_3"));

        gridLayout_4->addWidget(answer2_3, 1, 0, 1, 1);

        answer4_3 = new QCheckBox(some_of_four);
        answer4_3->setObjectName(QString::fromUtf8("answer4_3"));

        gridLayout_4->addWidget(answer4_3, 1, 1, 1, 1);


        horizontalLayout_5->addLayout(gridLayout_4);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout_9->addLayout(horizontalLayout_5);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_8);

        type_answers->addWidget(some_of_four);
        write_answer = new QWidget();
        write_answer->setObjectName(QString::fromUtf8("write_answer"));
        verticalLayout_10 = new QVBoxLayout(write_answer);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalSpacer_13 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_13);

        question_3 = new QLabel(write_answer);
        question_3->setObjectName(QString::fromUtf8("question_3"));
        question_3->setAlignment(Qt::AlignCenter);

        verticalLayout_10->addWidget(question_3);

        line_3 = new QFrame(write_answer);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_10->addWidget(line_3);

        verticalSpacer_12 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_12);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);

        answer = new QLineEdit(write_answer);
        answer->setObjectName(QString::fromUtf8("answer"));

        horizontalLayout_6->addWidget(answer);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);


        verticalLayout_10->addLayout(horizontalLayout_6);

        verticalSpacer_11 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_11);

        type_answers->addWidget(write_answer);

        verticalLayout_5->addWidget(type_answers);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        check_button = new QPushButton(testing);
        check_button->setObjectName(QString::fromUtf8("check_button"));
        check_button->setEnabled(false);

        gridLayout_2->addWidget(check_button, 0, 1, 1, 1);

        prev_button = new QPushButton(testing);
        prev_button->setObjectName(QString::fromUtf8("prev_button"));
        prev_button->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(prev_button->sizePolicy().hasHeightForWidth());
        prev_button->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(prev_button, 0, 0, 1, 1);

        next_button = new QPushButton(testing);
        next_button->setObjectName(QString::fromUtf8("next_button"));
        next_button->setEnabled(false);

        gridLayout_2->addWidget(next_button, 0, 2, 1, 1);


        verticalLayout_5->addLayout(gridLayout_2);

        tabWidget->addTab(testing, QString());
        result = new QWidget();
        result->setObjectName(QString::fromUtf8("result"));
        tabWidget->addTab(result, QString());

        verticalLayout_4->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 828, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        type_answers->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\234\320\270\320\275\320\270-\321\202\320\265\321\201\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\255\321\202\320\276 \320\262\320\262\320\265\320\264\320\265\320\275\320\270\320\265 \320\262 \321\202\320\265\321\201\321\202 \320\270 \321\200\320\260\321\201\321\201\320\272\320\260\320\267, \320\272\320\260\320\272 \320\265\320\263\320\276 \320\277\321\200\320\276\321\205\320\276\320\264\320\270\321\202\321\214", nullptr));
        to_test->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\271\321\202\320\270 \320\272 \321\202\320\265\321\201\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\216", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(info), QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\265\320\275\320\270\320\265 \320\262 \321\202\320\265\321\201\321\202", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213 \320\263\320\276\321\202\320\276\320\262\321\213 \320\272 \321\202\320\265\321\201\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\216 \320\277\320\276 \321\202\320\265\320\274\320\265 \"\320\237\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\275\321\213\320\265 \321\201\321\200\320\265\320\264\321\201\321\202\320\262\320\260 \320\264\320\273\321\217 \321\201\320\276\320\267\320\264\320\260\320\275\320\270\321\217 \321\202\321\200\320\265\321\205\320\274\320\265\321\200\320\275\321\213\321\205 \320\270\320\263\321\200\"? \320\222\320\260\320\274 \320\261\321\203\320\264\320\265\321\202 \320\264\320\260\320\275\320\276 10 \320\274\320\270\320\275\321\203\321\202 \320\275\320\260 10 \320\262\320\276\320\277\321\200\320\276\321\201\320\276\320\262.", nullptr));
        start_testing->setText(QCoreApplication::translate("MainWindow", "\320\224\320\260, \320\275\320\260\321\207\320\260\321\202\321\214 \321\202\320\265\321\201\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        question_4->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\264\320\265\321\200\320\266\320\260\320\275\320\270\320\265 \320\262\320\276\320\277\321\200\320\276\321\201\320\260", nullptr));
        text1->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\276\321\202\320\275\320\265\321\201.1", nullptr));
        text2->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\276\321\202\320\275\320\265\321\201. 2", nullptr));
        text3->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\276\321\202\320\275\320\265\321\201. 3", nullptr));
        text4->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\276\321\202\320\275\320\265\321\201. 4", nullptr));
        question->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\264\320\265\321\200\320\266\320\260\320\275\320\270\320\265 \320\262\320\276\320\277\321\200\320\276\321\201\320\260", nullptr));
        answer3->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\262\320\265\321\2023", nullptr));
        answer1->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\262\320\265\321\2021", nullptr));
        answer2->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\262\320\265\321\2022", nullptr));
        answer4->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\262\320\265\321\2024", nullptr));
        question_2->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\264\320\265\321\200\320\266\320\260\320\275\320\270\320\265 \320\262\320\276\320\277\321\200\320\276\321\201\320\260", nullptr));
        answer1_3->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\262\320\265\321\2021", nullptr));
        answer3_3->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\262\320\265\321\2023", nullptr));
        answer2_3->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\262\320\265\321\2022", nullptr));
        answer4_3->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\262\320\265\321\2024", nullptr));
        question_3->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\264\320\265\321\200\320\266\320\260\320\275\320\270\320\265 \320\262\320\276\320\277\321\200\320\276\321\201\320\260", nullptr));
#if QT_CONFIG(tooltip)
        answer->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\276\321\202\320\262\320\265\321\202 \320\275\320\260 \320\262\320\276\320\277\321\200\320\276\321\201</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        answer->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\320\272\320\260\321\203\321\213\320\260</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        check_button->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\262\320\265\321\202\320\270\321\202\321\214", nullptr));
        prev_button->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\265\320\264\321\213\320\264\321\203\321\211\320\270\320\271 \320\262\320\276\320\277\321\200\320\276\321\201", nullptr));
        next_button->setText(QCoreApplication::translate("MainWindow", "\320\241\320\273\320\265\320\264\321\203\321\216\321\211\320\270\320\271 \320\262\320\276\320\277\321\200\320\276\321\201", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(testing), QCoreApplication::translate("MainWindow", "\320\242\320\265\321\201\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(result), QCoreApplication::translate("MainWindow", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\321\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
